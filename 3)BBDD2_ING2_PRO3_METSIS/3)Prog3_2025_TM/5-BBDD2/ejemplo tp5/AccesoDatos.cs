using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;
using System.Data;

namespace TrabajandoConClases
{
    public class AccesoDatos
    {
        private static string rutaConexion = @"Data Source=localhost\sqlexpress;Initial Catalog=BDSucursales;Integrated Security=True";
        public DataTable ObtenerTablas(string consultaSQL, string nombreTabla)
        {
            SqlConnection conn = new SqlConnection(rutaConexion);
            conn.Open();
            SqlDataAdapter adap = new SqlDataAdapter(consultaSQL, conn);
            DataSet ds = new DataSet();
            adap.Fill(ds, "nombreTabla");
            conn.Close();
            return ds.Tables["nombreTabla"];
        }

        public int EjecutarConsulta(string consultaSQL)
        {
            SqlConnection conn = new SqlConnection(rutaConexion);
            conn.Open();
            SqlCommand cmd = new SqlCommand(consultaSQL, conn);
            int filas = (int)cmd.ExecuteNonQuery(); // PARA INSERT-UPDATE-DELETE
            conn.Close();
            return filas;
        }

        public int EjecutarSP(SqlCommand Comando, String NombreSP)
        {
            SqlConnection conn = new SqlConnection(rutaConexion);
            conn.Open();
            SqlCommand cmd = new SqlCommand();
            cmd = Comando;
            cmd.Connection = conn;
            cmd.CommandType = CommandType.StoredProcedure; // EJECUTA UN PROCEDIMIENTO ALMACENADO
            cmd.CommandText = NombreSP;
            int filas = cmd.ExecuteNonQuery(); // PARA INSERT-UPDATE-DELETE
            conn.Close();
            return filas;
        }
    }
}