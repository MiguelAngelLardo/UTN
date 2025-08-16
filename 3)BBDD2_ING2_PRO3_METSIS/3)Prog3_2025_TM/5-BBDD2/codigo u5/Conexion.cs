using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.SqlClient;

namespace AccesoDatos2
{
    public class Conexion
    {
        private String ruta = "Data Source = localhost\\sqlexpress; Initial Catalog = Neptuno; Integrated Security = True";


        public int ejecutaTransaccion(String consulta) //Insertar, eliminar o modificar
        {
            SqlConnection conexion = new SqlConnection(ruta);
            conexion.Open();
            //El sqlCommand me sirve para realizar instrucciones de tipo insert, delete y update
            SqlCommand comando = new SqlCommand(consulta, conexion);

            int filasAfectadas = comando.ExecuteNonQuery();
           // if (filasAfectadas == 0)
            //{
                //No se pudo agregar en la base de datos
            //}
            //else
            //{
                //Se agrego a la base de datos correctamente
            //}

            return filasAfectadas;
        }



    }
}