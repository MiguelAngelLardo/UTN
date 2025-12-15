using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using System.Data.SqlClient;
using System.Data;
namespace TP7_Codigo.Datos_DAL_
{
  public class DatosSucursal
  {
    // La consulta SQL pertenece aquí, porque es específica para Sucursales.
    private const string _consultaGeneral = "SELECT Id_Sucursal, NombreSucursal, DescripcionSucursal, URL_Imagen_Sucursal, Id_ProvinciaSucursal FROM Sucursal";
  
    public DataTable obtenerSucursalesComoDataTable()
    {
      DataTable dt = new DataTable();
      SqlConnection cn = null;//declaro afuera por el scope

      try
      {
        cn = new SqlConnection(ConexionDB.ObtenerCadenaConexion());
        SqlDataAdapter sda = new SqlDataAdapter(_consultaGeneral, cn);//es ideal para llenar DataTables
        sda.Fill(dt);
        return dt;
        //SqlDataAdapter se encarga de abrir y cerrar la conexion
        //el metodo Fill llena el DataTable con los datos obtenidos abre y cierra la conexion

      }
      catch (Exception ex)
      {
        return new DataTable();
      }



    }
  
  
  }

}