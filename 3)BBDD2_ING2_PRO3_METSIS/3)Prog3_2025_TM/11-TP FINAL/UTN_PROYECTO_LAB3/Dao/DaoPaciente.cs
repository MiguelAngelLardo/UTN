using Dao;
using Entidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;


namespace Datos
{
    public class DaoPaciente
    {

        private AccesoDatos _accesoDatos = new AccesoDatos();

        public DataTable BuscarPacientes(string nomApe, string dni)
        {
            List<SqlParameter> parametros = new List<SqlParameter>();

            if (nomApe != null)
                parametros.Add(new SqlParameter("@NombreApellido", nomApe));
            else
                parametros.Add(new SqlParameter("@NombreApellido", DBNull.Value));

            if (dni != null)
                parametros.Add(new SqlParameter("@DNI", dni));
            else
                parametros.Add(new SqlParameter("@DNI", DBNull.Value));

            return _accesoDatos.ObtenerTabla("SP_BuscarPacientes", parametros);
        }

        public int EliminarPaciente(string dni)
        {
            string nombreSP = "sp_EliminarPaciente";
            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Dni", dni));
            return _accesoDatos.EjecutarSP(nombreSP, parametros);
        }

        public bool ExisteDni(string dni)
        {
            string consulta = "SELECT 1 FROM Personas WHERE Dni_P = @Dni";
            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Dni", dni));

            return _accesoDatos.Existe(consulta, parametros);
        }
        public bool AgregarPaciente(Paciente nuevoPaciente)
        {
            string nombreSP = "sp_AgregarPaciente";
            List<SqlParameter> parametros = new List<SqlParameter>();
            //persona
            parametros.Add(new SqlParameter("@Dni_P", nuevoPaciente.Dni));
            parametros.Add(new SqlParameter("@IdLocalidad_L_P", nuevoPaciente.Localidad.IdLocalidad));
            parametros.Add(new SqlParameter("@Nombre_P", nuevoPaciente.Nombre));
            parametros.Add(new SqlParameter("@Apellido_P", nuevoPaciente.Apellido));
            parametros.Add(new SqlParameter("@Sexo_P", nuevoPaciente.Sexo));
            parametros.Add(new SqlParameter("@Nacionalidad_P", nuevoPaciente.Nacionalidad));
            parametros.Add(new SqlParameter("@FechaNacimiento_P", nuevoPaciente.FechaNacimiento));
            parametros.Add(new SqlParameter("@Direccion_P", nuevoPaciente.Direccion));
            parametros.Add(new SqlParameter("@CorreoElectronico_P", nuevoPaciente.CorreoElectronico));
            parametros.Add(new SqlParameter("@Telefono_P", nuevoPaciente.Telefono));
            parametros.Add(new SqlParameter("@Estado_P", nuevoPaciente.Estado));
            //paciente
            parametros.Add(new SqlParameter("@Diagnostico_Pa", nuevoPaciente.Diagnostico));

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);
            return filasAfectadas == 1;
        }

        // En DaoPaciente.cs

        public Paciente GetPacientePorDni(string dni, out int idProvincia)
        {
            string nombreSP = "sp_GetPacienteDetallePorDni";
            idProvincia = 0;
            Paciente paciente = null;

            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Dni", dni));

            DataTable tabla = _accesoDatos.ObtenerTabla(nombreSP, parametros);

            if (tabla.Rows.Count > 0)
            {
                DataRow row = tabla.Rows[0];
                paciente = new Paciente();

                paciente.Dni = row["Dni_P"].ToString();
                paciente.Nombre = row["Nombre_P"].ToString();
                paciente.Apellido = row["Apellido_P"].ToString();
                paciente.Sexo = Convert.ToChar(row["Sexo_P"]);
                paciente.Nacionalidad = row["Nacionalidad_P"].ToString();
                paciente.FechaNacimiento = Convert.ToDateTime(row["FechaNacimiento_P"]);
                paciente.Direccion = row["Direccion_P"].ToString();
                paciente.CorreoElectronico = row["CorreoElectronico_P"].ToString();
                paciente.Telefono = row["Telefono_P"].ToString();
                paciente.Estado = Convert.ToBoolean(row["Estado_P"]);
                paciente.Diagnostico = row["Diagnostico_Pa"].ToString();
                paciente.Localidad.IdLocalidad = Convert.ToInt32(row["IdLocalidad_L_P"]);
                idProvincia = Convert.ToInt32(row["IdProvincia_Pr_L"]);
            }

            return paciente;
        }
        public int editarPaciente(Paciente paciente)
        {
            string nombreSP = "sp_EditarPaciente";
            List<SqlParameter> parametros = new List<SqlParameter>();

            parametros.Add(new SqlParameter("@Dni", paciente.Dni));
            parametros.Add(new SqlParameter("@Nombre", paciente.Nombre));
            parametros.Add(new SqlParameter("@Apellido", paciente.Apellido));
            parametros.Add(new SqlParameter("@Sexo", paciente.Sexo));
            parametros.Add(new SqlParameter("@Nacionalidad", paciente.Nacionalidad));
            parametros.Add(new SqlParameter("@FechaNacimiento", paciente.FechaNacimiento));
            parametros.Add(new SqlParameter("@Direccion", paciente.Direccion));
            parametros.Add(new SqlParameter("@Correo", paciente.CorreoElectronico));
            parametros.Add(new SqlParameter("@Telefono", paciente.Telefono));
            parametros.Add(new SqlParameter("@IdLocalidad", paciente.Localidad.IdLocalidad));
            parametros.Add(new SqlParameter("@Diagnostico", paciente.Diagnostico));

            foreach (var p in parametros)
            {
                System.Diagnostics.Debug.WriteLine($"{p.ParameterName} = {p.Value}");
            }

            int filasAfectadas = _accesoDatos.EjecutarSP(nombreSP, parametros);

            return filasAfectadas;
        }

        public DataTable ObtenerPaciente(string dni)
        {
            string nombreSP = "sp_ObtenerDetallePaciente";
            List<SqlParameter> parametros = new List<SqlParameter>();
            parametros.Add(new SqlParameter("@Dni", dni));
            return _accesoDatos.ObtenerTabla(nombreSP, parametros);
        }

    public DataTable ListarPacientesActivos()
    {
      string nombreSP = "sp_ListarPacientesActivos";
      return _accesoDatos.ObtenerTabla(nombreSP);
    }

   }
}
