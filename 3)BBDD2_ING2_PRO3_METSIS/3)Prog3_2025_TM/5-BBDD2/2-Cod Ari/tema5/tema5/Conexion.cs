using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;

namespace tema5
{
    public class Conexion
    {
        private const string cadenaConexion = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";

        /// DEVUELVE CANTIDAD DE FILAS AFECTADAS
        public int ejecutarTransaccion(string consultaSQL)
        {
            /// ESTABLECER UNA CONEXION A LA BASE DE DATOS SQL SERVER
            SqlConnection sqlConnection = new SqlConnection(cadenaConexion);
            sqlConnection.Open();

            SqlCommand sqlCommand = new SqlCommand(consultaSQL, sqlConnection);
            /// EJECUTAR CONSULTA
            int filasAfectadas = sqlCommand.ExecuteNonQuery(); /// INSERT, UPDATE, DELETE

            sqlConnection.Close();

            return filasAfectadas;
        }
    }
}