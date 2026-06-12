using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.SqlClient;
using System.Data;
using Entidades;
namespace Dao
{

  public class DaoMedico
  {

    private AccesoDatos _accesoDatos = new AccesoDatos();

    public DataTable getTablaMedicos()
    {
          string consulta = @"
      SELECT
          Medicos.Legajo_M AS Legajo,
          Personas.Nombre_P AS Nombre,
          Personas.Apellido_P AS Apellido,
          Especialidades.Descripcion_E AS Especialidad,
          Medicos.DiaAtencion_M AS Dias,
          Medicos.HorarioAtencion_M AS Horas,
          Medicos.Usuario_M,
          Medicos.UsuarioHabilitado_M
      FROM
          Medicos
      INNER JOIN
          Personas ON Personas.Dni_P = Medicos.Dni_P_M
      INNER JOIN
          Especialidades ON Especialidades.IdEspecialidad_E = Medicos.IdEspecialidad_E_M
          ";

          DataTable tabla = _accesoDatos.ObtenerTabla("MedicoEspecialidad", consulta);
          return tabla;
    }

        public int CrearUsuarioMedico(Medico medico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@LEGAJO", medico.Legajo));
            parametros.Add(new SqlParameter("@NOMBREUSUARIO", medico.Login.NombreUsuario));
            parametros.Add(new SqlParameter("@CONTRASENIA", medico.Login.Contrasenia));
            parametros.Add(new SqlParameter("@HABILITADO", medico.UsuarioHabilitado));

            return _accesoDatos.EjecutarSP("sp_CrearUsuario", parametros);
        }
        public bool ExisteUsuario(string usuario)
        {
            string consulta = "SELECT 1 FROM Medicos WHERE Usuario_M = @Usuario";
            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Usuario", usuario));

            return _accesoDatos.Existe(consulta, parametros);
        }

        public bool ExisteMedicoYPass(string user, string pass)
        {
            // *** CORRECCIÓN: Se eliminan las comillas simples alrededor de @User y @Pass ***
            string consulta = "SELECT 1 FROM Medicos WHERE Usuario_M = @User AND Contrasena_M = @Pass AND UsuarioHabilitado_M = 1";

            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@User", user));
            parametros.Add(new SqlParameter("@Pass", pass));

            return _accesoDatos.Existe(consulta, parametros);
        }




        public DataTable ListarBuscarTodoMedicos(string nombreApellido, string legajo, int idEspecialidad, DataTable dtDias)// llama al SP y le pasa los parámetros
    {
      string nombreSP = "sp_ListarBuscarTodoMedicos";
      List<SqlParameter> parametros = new List<SqlParameter>();

      //DBNull.Value es NULL para el SQL. Ademas uso el casteo para poder usar el operador ?? (si es null, uso DBNull.Value)
      //param txtBox
      parametros.Add(new SqlParameter("@NombreApellido", (object)nombreApellido ?? DBNull.Value));
      parametros.Add(new SqlParameter("@Legajo", (object)legajo ?? DBNull.Value));

      //param Especialidad
      parametros.Add(new SqlParameter("@IdEspecialidad", idEspecialidad));

      //param Dias (tipo tabla) =>  OJO en mi SP_LISTARBUSCARTODO lo declare como @TablaDias dbo.TipoTablaDia READONLY 
      SqlParameter paramDias = new SqlParameter("@TablaDias", SqlDbType.Structured);// sin Structures para enviar 3 dias deberia llamar 3 veces al SP => SqlDbType.Structured me permite darle DataTable
      paramDias.TypeName = "dbo.TipoTablaDia"; // El tipo de tabla que yo programador se que cree en el SQL
      paramDias.Value = dtDias; // El DataTable que viene desde el .aspx.cs
      parametros.Add(paramDias);
      return _accesoDatos.ObtenerTabla(nombreSP, parametros);
    }

    public DataTable ListarPorEspecialidad(int idEspecialidad)//le paso a NegocioMedico para Agregar Turno
    {
      string nombreSP = "sp_ListarMedicosPorEspecialidad";
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@IdEspecialidad", idEspecialidad));

      return _accesoDatos.ObtenerTabla(nombreSP, parametros);
    }

    public bool ExisteDni(string dni)
    {
      string consulta = "SELECT 1 FROM Personas WHERE Dni_P = @Dni";
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@Dni", dni));
      return _accesoDatos.Existe(consulta, parametros);
    }

    /// <summary>
    /// Verifica si un Legajo ya existe en la tabla Medicos.
    /// </summary>
    public bool ExisteLegajo(string legajo)
    {
      string consulta = "SELECT 1 FROM Medicos WHERE Legajo_M = @Legajo";
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@Legajo", legajo));

      return _accesoDatos.Existe(consulta, parametros);
    }

    public bool AgregarMedico(Entidades.Medico medico)
    {
      string nombreSP = "sp_AgregarMedico";

      List<SqlParameter> parametros = new List<SqlParameter>();
      // --- Parámetros de Persona ---
      parametros.Add(new SqlParameter("@Dni_P", medico.Dni));
      parametros.Add(new SqlParameter("@IdLocalidad_L_P", medico.Localidad.IdLocalidad));
      parametros.Add(new SqlParameter("@Nombre_P", medico.Nombre));
      parametros.Add(new SqlParameter("@Apellido_P", medico.Apellido));
      parametros.Add(new SqlParameter("@Sexo_P", medico.Sexo));
      parametros.Add(new SqlParameter("@Nacionalidad_P", medico.Nacionalidad));
      parametros.Add(new SqlParameter("@FechaNacimiento_P", medico.FechaNacimiento));
      parametros.Add(new SqlParameter("@Direccion_P", medico.Direccion));
      parametros.Add(new SqlParameter("@CorreoElectronico_P", medico.CorreoElectronico));
      parametros.Add(new SqlParameter("@Telefono_P", medico.Telefono));
      parametros.Add(new SqlParameter("@Estado_P", medico.Estado));//el estado viene TRUE por CONSTRUCTOR

      // --- Parámetros de Medico ---
      parametros.Add(new SqlParameter("@Legajo_M", medico.Legajo));
      parametros.Add(new SqlParameter("@IdEspecialidad_E_M", medico.Especialidad.IdEspecialidad));
      parametros.Add(new SqlParameter("@HorarioAtencion_M", medico.HoraAtencion));

      // --- Parámetros de Medico_x_Dia ---
      // Creamos un tipo de dato 'Tabla' para pasar la lista de IDs
      DataTable dtDias = new DataTable();
      dtDias.Columns.Add("IdDia", typeof(int));//armo un "excel" con un header IdDia y el tipo de dato que acepta es int
      foreach (DiasSemana dia in medico.DiasSemanaMedico)
      {
        dtDias.Rows.Add(dia.IdDia);// dtDias.Rows.Add(1); (Lunes) + dtDias.Rows.Add(3); (Miércoles) + ...
      }
      SqlParameter paramDias = new SqlParameter("@Dias",SqlDbType.Structured); // empaqueto 1 o mas dias en una mini tabla de c# para no tener que hacer N inserts

      paramDias.TypeName = "dbo.TipoTablaDia"; // (Este tipo lo crea el SP 'sp_AgregarMedico') =Z le dice al SQL que tipo de tabla es la que le estoy pasando
      paramDias.Value = dtDias;//le asigno la mini tabla que arme arriba
      parametros.Add(paramDias);//la agrego a la lista de parámetros

      // Ejecutamos el SP (que es una transacción)
      int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

      return (filasAfectadas > 0);
    }


    public DataTable ObtenerInfoDiasHorarioMedico(string Legajo)
    {
      string nombreSP = "sp_ObtenerDiasYHorarioMedico";
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@Legajo", Legajo));

      return _accesoDatos.ObtenerTabla(nombreSP, parametros); // Usamos ObtenerTabla porque el SP devuelve una tabla (una fila) HorarioBase    IdsDiasTrabajo
                                                                                                                                //08:00-12:00    1,2,3,4,5,6
    }


    public DataTable ObtenerHorasOcupadas(string Legajo, DateTime Fecha)
    {
      string nombreSP = "sp_ObtenerHorasOcupadas";
      List<SqlParameter> parametros = new List<SqlParameter>();

      parametros.Add(new SqlParameter("@LegajoMedico", Legajo));
      parametros.Add(new SqlParameter("@Fecha", SqlDbType.Date) { Value = Fecha });// Se usa SqlDbType.Date para asegurar que solo se pasa la fecha sin la hora

      return _accesoDatos.ObtenerTabla(nombreSP, parametros);// Obtener la tabla =>               una columna: 'Hora_T'          =>le pase fecha 2025-11-21 y 'L001' 
                                                                                                             // 08:00:00.000000
                                                                                                             // 09:00:00.000000
    }

    public int CambiarUsuarioMedico(Medico medico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>()
    {
        new SqlParameter("@LEGAJO", medico.Legajo),
        new SqlParameter("@NUEVOUSUARIO", medico.Login.NombreUsuario)
    };

            return _accesoDatos.EjecutarSP("sp_ModificarUsuario", parametros);
        }
        public int CambiarContraseniaMedico(Medico medico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>()
    {
        new SqlParameter("@LEGAJO", medico.Legajo),
        new SqlParameter("@NUEVACONTRASENIA", medico.Login.Contrasenia)
    };

            return _accesoDatos.EjecutarSP("sp_ModificarContrasenia", parametros);
        }

        public int CambiarEstadoUsuarioMedico(string legajo, bool habilitado)
        {
            string nombreSP = "sp_HabilitarUsuarioMedico";

            List<SqlParameter> parametros = new List<SqlParameter>
    {
        new SqlParameter("@Legajo", legajo),
        new SqlParameter("@Habilitado", habilitado)
    };

            return _accesoDatos.EjecutarSP(nombreSP, parametros);
        }


        public int EliminarMedico(string legajo)
    {
      string nombreSP = "sp_EliminarMedico";
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@Legajo", legajo));

      return _accesoDatos.EjecutarSP(nombreSP, parametros);
    }

    public Medico GetMedicoPorLegajo(string legajo, out int idProvincia)
        {
            string nombreSP = "sp_GetMedicoDetallePorLegajo";
            idProvincia = 0; 
            Medico medico = null;

            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Legajo", legajo));
            DataTable tabla = _accesoDatos.ObtenerTabla(nombreSP, parametros);

            if (tabla.Rows.Count > 0)
            {
                DataRow row = tabla.Rows[0];
                medico = new Medico();

                //Persona
                medico.Dni = row["Dni_P"].ToString();
                medico.Nombre = row["Nombre_P"].ToString();
                medico.Apellido = row["Apellido_P"].ToString();
                medico.Sexo = Convert.ToChar(row["Sexo_P"]);
                medico.Nacionalidad = row["Nacionalidad_P"].ToString();
                medico.FechaNacimiento = Convert.ToDateTime(row["FechaNacimiento_P"]);
                medico.Direccion = row["Direccion_P"].ToString();
                medico.CorreoElectronico = row["CorreoElectronico_P"].ToString();
                medico.Telefono = row["Telefono_P"].ToString();
                medico.Estado = Convert.ToBoolean(row["Estado_P"]);

                //Medico
                medico.Legajo = row["Legajo_M"].ToString();
                medico.HoraAtencion = row["HorarioAtencion_M"].ToString();

                medico.Localidad.IdLocalidad = Convert.ToInt32(row["IdLocalidad_L_P"]);
                medico.Especialidad.IdEspecialidad = Convert.ToInt32(row["IdEspecialidad_E_M"]);
                idProvincia = Convert.ToInt32(row["IdProvincia_Pr_L"]);

                medico.DiasSemanaMedico = new List<DiasSemana>();
                string diaIDs = row["DiaIDs"] != DBNull.Value ? row["DiaIDs"].ToString() : "";

                if (!string.IsNullOrEmpty(diaIDs))
                {
                    foreach (string id in diaIDs.Split(','))
                    {
                        medico.DiasSemanaMedico.Add(new DiasSemana { IdDia = int.Parse(id) });   // Parseamos la lista de Días (ej: "1,3,5")
                    }
                }
            }

            return medico;
        }
     
        public bool ActualizarMedico(Medico medico)        // Llama al SP sp_ActualizarMedico para guardar los cambios.
        {
            string nombreSP = "sp_ActualizarMedico";

            List<SqlParameter> parametros = new List<SqlParameter>();

            // Persona
            parametros.Add(new SqlParameter("@Dni_P", medico.Dni)); // Clave WHERE
            parametros.Add(new SqlParameter("@IdLocalidad_L_P", medico.Localidad.IdLocalidad));
            parametros.Add(new SqlParameter("@Nombre_P", medico.Nombre));
            parametros.Add(new SqlParameter("@Apellido_P", medico.Apellido));
            parametros.Add(new SqlParameter("@Sexo_P", medico.Sexo));
            parametros.Add(new SqlParameter("@Nacionalidad_P", medico.Nacionalidad));
            parametros.Add(new SqlParameter("@FechaNacimiento_P", medico.FechaNacimiento));
            parametros.Add(new SqlParameter("@Direccion_P", medico.Direccion));
            parametros.Add(new SqlParameter("@CorreoElectronico_P", medico.CorreoElectronico));
            parametros.Add(new SqlParameter("@Telefono_P", medico.Telefono));

            // Medico
            parametros.Add(new SqlParameter("@Legajo_M", medico.Legajo)); // Clave WHERE
            parametros.Add(new SqlParameter("@IdEspecialidad_E_M", medico.Especialidad.IdEspecialidad));
            parametros.Add(new SqlParameter("@HorarioAtencion_M", medico.HoraAtencion));

            // Medico_x_Dia
            DataTable dtDias = new DataTable();
            dtDias.Columns.Add("IdDia", typeof(int));
            foreach (DiasSemana dia in medico.DiasSemanaMedico)
            {
                dtDias.Rows.Add(dia.IdDia);
            }

            SqlParameter paramDias = new SqlParameter("@Dias", SqlDbType.Structured);
            paramDias.TypeName = "dbo.TipoTablaDia";
            paramDias.Value = dtDias;
            parametros.Add(paramDias);

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

            return (filasAfectadas > 0);
        }
        public int EliminarUsuarioMedico(Medico medico)
        {
            List<SqlParameter> parametros = new List<SqlParameter>()
    {
        new SqlParameter("@LEGAJO", medico.Legajo),
    };

            return _accesoDatos.EjecutarSP("sp_EliminarUsuarioMedico", parametros);
        }
        public string ObtenerNombreUsuarioPorLegajo(Medico medico) 
        {
            List<SqlParameter> parametros = new List<SqlParameter>()
            {
                new SqlParameter("@LEGAJO", medico.Legajo)
            };
            DataTable tabla = _accesoDatos.ObtenerTabla("sp_ObtenerUsuarioPorLegajo", parametros);

            if (tabla.Rows.Count > 0)
            {
                object valor = tabla.Rows[0]["Usuario_M"];
                return valor == DBNull.Value ? "" : valor.ToString();
            }

            return "";
        }

        public DataTable ObtenerTablaDatosMedico(string legajo)
        {
            string nombreSP = "sp_ObtenerDetalleMedico";

            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Legajo", legajo));

            return _accesoDatos.ObtenerTabla(nombreSP, parametros);
        }

    }
}
