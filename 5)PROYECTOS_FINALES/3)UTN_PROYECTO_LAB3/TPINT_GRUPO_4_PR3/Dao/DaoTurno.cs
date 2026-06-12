using Entidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace Dao
{
    public class DaoTurno
    {
        private AccesoDatos _accesoDatos = new AccesoDatos();

        public DataTable getTablaTurnoAdmnistrador()
        {
            DataTable tabla = _accesoDatos.ObtenerTabla("SP_Turnos_ObtenerTodos");
            return tabla;
        }

        public DataTable getTablaTurnoMedico(string usuarioMedico)
        {
            string consulta = @"
                SELECT 
                    T.IdTurno_T AS IdTurno,
                    T.Fecha_T AS Dia,
                    T.Hora_T AS Horario,
                    (PePac.Nombre_P + ' ' + PePac.Apellido_P) AS Paciente,
                    T.Observacion_T AS Observacion,
                    T.Atendido_T AS Atendido
                FROM Turnos T
                INNER JOIN Pacientes Pa ON T.Dni_P_Pa_T = Pa.Dni_P_Pa
                INNER JOIN Personas PePac ON Pa.Dni_P_Pa = PePac.Dni_P
                INNER JOIN Medicos M ON T.Dni_P_M_T = M.Dni_P_M
                WHERE M.Usuario_M = @UsuarioMedico
            ";

            List<SqlParameter> parametros = new List<SqlParameter>
            {
                new SqlParameter("@UsuarioMedico", usuarioMedico)
            };

            return _accesoDatos.ObtenerTabla("Turnos", consulta, parametros);
        }

        public string ObtenerDniPorLegajo(string legajo)
        {
            string nombreSP = "sp_ObtenerDniPorLegajo";
            List<SqlParameter> parametro = new List<SqlParameter>();
            parametro.Add(new SqlParameter("@Legajo_M", legajo));

            DataTable dtResultado = _accesoDatos.ObtenerTabla(nombreSP, parametro);

            if (dtResultado != null && dtResultado.Rows.Count > 0)
            {
                return dtResultado.Rows[0][0].ToString();
            }
            return null;
        }

        public bool AgregarTurno(Turno t)
        {
            string legajoLimpio = t.Medico.Legajo.Trim();
            string dniMedico = ObtenerDniPorLegajo(legajoLimpio);

            if (string.IsNullOrEmpty(dniMedico))
            {
                return false;
            }

            string nombreSP = "sp_AgregarTurno";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@dniMedico", dniMedico));
            parametros.Add(new SqlParameter("@dniPaciente", t.Paciente.Dni));
            parametros.Add(new SqlParameter("@idEspecialidad", SqlDbType.Int) { Value = t.Especialidad.IdEspecialidad });

            SqlParameter paramFecha = new SqlParameter("@fechaTurno", SqlDbType.Date);
            paramFecha.Value = t.Fecha.Date;
            parametros.Add(paramFecha);

            parametros.Add(new SqlParameter("@horaTurno", SqlDbType.Time) { Value = t.Hora });

            parametros.Add(new SqlParameter("@observacion", t.Observacion));
            parametros.Add(new SqlParameter("@atendido", t.Atendido));

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

            return filasAfectadas > 0;
        }

        public bool EditarTurno(Turno turno)
        {
            string legajoLimpio = turno.Medico.Legajo.Trim();
            string dniMedico = ObtenerDniPorLegajo(legajoLimpio);

            if (string.IsNullOrEmpty(dniMedico))
            {
                return false;
            }

            string nombreSP = "sp_EditarTurno";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@idTurno", turno.IdTurno));
            parametros.Add(new SqlParameter("@dniMedico", dniMedico));
            parametros.Add(new SqlParameter("@dniPaciente", turno.Paciente.Dni));
            parametros.Add(new SqlParameter("@idEspecialidad", SqlDbType.Int) { Value = turno.Especialidad.IdEspecialidad });

            SqlParameter paramFecha = new SqlParameter("@fechaTurno", SqlDbType.Date);
            paramFecha.Value = turno.Fecha.Date;
            parametros.Add(paramFecha);
            parametros.Add(new SqlParameter("@horaTurno", SqlDbType.Time) { Value = turno.Hora });

            parametros.Add(new SqlParameter("@observacion", turno.Observacion));
            parametros.Add(new SqlParameter("@atendido", turno.Atendido));

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

            return filasAfectadas > 0;
        }

        public void EliminarTurno(string idTurno)
        {
            SqlCommand comando = new SqlCommand();
            comando.Parameters.AddWithValue("@IdTurno", idTurno);
            _accesoDatos.EjecutarProcedimientoAlmacenado(comando, "sp_EliminarTurno");
        }

        public Turno GetDatosTurno(string idTurno)
        {
            Turno turno = new Turno();
            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@IdTurno", idTurno));
            DataTable tabla = _accesoDatos.ObtenerTabla("sp_ObtenerDatosTurno", parametros);

            if (tabla.Rows.Count > 0)
            {
                DataRow row = tabla.Rows[0];

                turno.IdTurno = Convert.ToInt32(row["IdTurno"]);
                turno.Especialidad.IdEspecialidad = Convert.ToInt32(row["IdEspecialidad"]);
                turno.Especialidad.Descripcion = row["Especialidad"].ToString();
                turno.Medico.Legajo = row["LegajoMedico"].ToString();
                turno.Medico.Nombre = row["NombreMedico"].ToString();
                turno.Medico.Apellido = row["ApellidoMedico"].ToString();
                turno.Medico.Dni = row["DniMedico"].ToString();
                turno.Paciente.Nombre = row["NombrePaciente"].ToString();
                turno.Paciente.Apellido = row["ApellidoPaciente"].ToString();
                turno.Paciente.Dni = row["DniPaciente"].ToString();
                turno.Fecha = Convert.ToDateTime(row["FechaTurno"]);
                turno.Hora = (TimeSpan)row["HoraTurno"];
            }
            return turno;
        }

        public bool ActualizarAtencionTurno(int idTurno, string observacion, bool asistio)
        {
            string nombreSP = "sp_ActualizarAtencionTurno";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@IdTurno", idTurno));

            if (string.IsNullOrEmpty(observacion))
                parametros.Add(new SqlParameter("@Observacion", DBNull.Value));
            else
                parametros.Add(new SqlParameter("@Observacion", observacion));

            parametros.Add(new SqlParameter("@Atendido", asistio));

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

            return filasAfectadas > 0;
        }

        public DataTable BuscarPacientes(string nomApe, string usuarioMedico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            if (!string.IsNullOrEmpty(nomApe))
                parametros.Add(new SqlParameter("@NombreApellido", nomApe));
            else
                parametros.Add(new SqlParameter("@NombreApellido", DBNull.Value));

            parametros.Add(new SqlParameter("@UsuarioMedico", usuarioMedico));

            return _accesoDatos.ObtenerTabla("SP_BuscarPacientesVistaMedico", parametros);
        }

        //a la fuerza le tengo que pasar los valores de lo que se completo en el filtrado, pued venir vacio naturalmente
        public DataTable BuscarTurnosAdministrador(
            string nombreApellidoMedico,
            string nombreApellidoPaciente,
            int? idEspecialidad,
            bool lunes,
            bool martes,
            bool miercoles,
            bool jueves,
            bool viernes,
            bool sabado)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            //aca aplique los ternarios para validar si habia valores en nombre de medico, paciente o si habia filtrado tambien con especialidad
            // valido esos 3 no mas porque los string tienen 3 estados, los bool de los dias solo 2 estados posibles.
            parametros.Add(new SqlParameter("@NombreApellidoMedico",
                string.IsNullOrEmpty(nombreApellidoMedico) ? (object)DBNull.Value : nombreApellidoMedico));

            parametros.Add(new SqlParameter("@NombreApellidoPaciente",
                string.IsNullOrEmpty(nombreApellidoPaciente) ? (object)DBNull.Value : nombreApellidoPaciente));

            parametros.Add(new SqlParameter("@IdEspecialidad",
                idEspecialidad.HasValue ? (object)idEspecialidad.Value : DBNull.Value));

            parametros.Add(new SqlParameter("@Lunes", lunes));
            parametros.Add(new SqlParameter("@Martes", martes));
            parametros.Add(new SqlParameter("@Miercoles", miercoles));
            parametros.Add(new SqlParameter("@Jueves", jueves));
            parametros.Add(new SqlParameter("@Viernes", viernes));
            parametros.Add(new SqlParameter("@Sabado", sabado));

            return _accesoDatos.ObtenerTabla("SP_BuscarTurnosAdministrador", parametros);
        }

        public DataTable ReportePresentismo(DateTime FechaDesde, DateTime FechaHasta)
        {
            string nombreSP = "sp_ObtenerReportePresentismo";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@FechaDesde", FechaDesde));
            parametros.Add(new SqlParameter("@FechaHasta", FechaHasta));
            return _accesoDatos.ObtenerTabla(nombreSP, parametros);
        }

        public DataTable ReportePresentismoDetalle(DateTime FechasDesde, DateTime FechaHasta)
        {
            string nombreSp = "sp_ListarDetallePresentismo";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@FechaDesde", FechasDesde));
            parametros.Add(new SqlParameter("@FechaHasta", FechaHasta));
            return _accesoDatos.ObtenerTabla(nombreSp, parametros);
        }

        public DataTable ObtenerReporteTurnosPorMedico(DateTime FechaDesde, DateTime FechaHasta)
        {
            string nombreSp = "sp_ObtenerReporteTurnosPorMedico";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@FechaDesde", FechaDesde));
            parametros.Add(new SqlParameter("@FechaHasta", FechaHasta));
            return _accesoDatos.ObtenerTabla(nombreSp, parametros);
        }

        public DataTable getTablaTurnoMedicoPorPaciente(string nombre, string usuarioMedico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            if (!string.IsNullOrEmpty(nombre))
            {
                parametros.Add(new SqlParameter("@NombreApellido", nombre));
            }
          
            parametros.Add(new SqlParameter("@UsuarioMedico", usuarioMedico));

            return _accesoDatos.ObtenerTabla("sp_BuscarTurnoDeMedicoPorPaciente", parametros);
        }
        public DataTable FiltrarTurnos(int asistio, DateTime? fecha, string usuarioMedico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@Asistio", asistio));

            if (fecha.HasValue)
            {
                parametros.Add(new SqlParameter("@Fecha", fecha.Value));
            }

            parametros.Add(new SqlParameter("@UsuarioMedico", usuarioMedico));

            return _accesoDatos.ObtenerTabla("sp_FiltrarTurnosMedico", parametros);
        }


    }
}