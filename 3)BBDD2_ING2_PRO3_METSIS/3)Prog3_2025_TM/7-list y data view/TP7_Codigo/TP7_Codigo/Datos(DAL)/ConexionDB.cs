using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace TP7_Codigo.Datos_DAL_
{
  public class ConexionDB
  {
    public static string ObtenerCadenaConexion()
    {
      return "Data Source=localhost;Initial Catalog=BDSucursales;User ID=sa;Password=Miguel-1234;Encrypt=False";
      //uso Encrypt=False para evitar el error de conexion
    }


  }
}