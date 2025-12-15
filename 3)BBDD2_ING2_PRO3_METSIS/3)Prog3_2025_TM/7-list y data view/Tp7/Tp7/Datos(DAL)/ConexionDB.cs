using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using System.Data.SqlClient;
namespace Tp7.Datos_DAL_
{
  public class ConexionDB
  {
    private string _coneccion = "Data Source=localhost;Initial Catalog=BDSucursales;User ID=sa;Password=Miguel-1234;Encrypt=False";//le digo q no encripte la contraseña
    //"Server Certificate=True" => no anda en version antigua de .net 4.8 asp


    public SqlConnection conectarseBD()
    {
      SqlConnection cn = new SqlConnection(_coneccion);
      try
      {
        cn.Open();
        return cn;
      }
      catch (Exception ex)
      {
        return null;
      }


    }

  }
}