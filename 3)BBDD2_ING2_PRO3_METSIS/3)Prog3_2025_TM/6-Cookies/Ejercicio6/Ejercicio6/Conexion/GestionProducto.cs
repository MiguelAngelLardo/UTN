using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;

namespace Ejercicio6.Conexion
{
  public class GestionProducto
  {
    public GestionProducto() { }

    private DataTable obtenerTabla(string nombreTabla, string consultaSqlSelect)
    {
      
      ConexionDB objConDb = new ConexionDB();
      SqlDataAdapter adapRetornado = objConDb.dataAdapterDesconectadoSelect(consultaSqlSelect);

      //forma corta
      DataTable dt = new DataTable(nombreTabla); //creo tabla simple
      adapRetornado.Fill(dt);//el DataAdapter me llena la caja
      return dt;

      //forma larga
      //DataSet ds = new DataSet();
      //adapRetornado.Fill(ds, nombreTabla);
      //return ds.Tables[nombreTabla];

    }

    public DataTable seleccionar4ColumnasFromProductos()
    {
      return obtenerTabla("tabla4ColProductos", "SELECT IdProducto, NombreProducto, CantidadPorUnidad, PrecioUnidad FROM Productos");
    }

    public DataTable seleccionar4ConIdProveedor()
    {
      return obtenerTabla("tabla4ColConIdProveedor", "SELECT IdProducto, NombreProducto, IdProveedor, PrecioUnidad FROM Productos");
    }

    private void parametrosParaEliminar(ref SqlCommand cmd, Producto prod)//al cmd le cargo parametros
    {
      //un SqlCommand tiene una lista de SqlParameter
      //SqlCommand.Paramters es una coleccion (lista) de SqlParameter
      //SqlParameter es un objeto que representa un parametro para un comando sql
      //->SqlParameter parametro = new SqlParameter();


      //Add("@id", txtProd.text) => es un atajo llamado AddWithValue -> ADO.NET debe adivinar q tipo de dato le paso, en este caso string
      //SqlDbType.Int, SqlDbType.VarChar, SqlDbType.Money, SqlDbType.DateTime, SqlDbType.Bit (booleano)es la forma correcta ya q no hay q adivinar
     //-> cmd.Parameters.Add("@idEliminar", SqlDbType.Int);

      //->parametro.Value = prod.idProducto;

      //forma correcta
      cmd.Parameters.AddWithValue("@IdProd", prod.idProducto); //va el mismo @ que tiene el SP en sql

    }

    public bool eliminarProducto(Producto prod)
    {
      SqlCommand cmd = new SqlCommand();

      parametrosParaEliminar(ref cmd, prod);
      ConexionDB conexionDB = new ConexionDB();
      int filasAfectadas = conexionDB.ejecutarProcAlmacenado(cmd, "sp_EliminarProducto");//tal cual lo hice en la bbdd

      //ternario para return
      if (filasAfectadas == 1)
        return true;
      else
        return false;
    }



    private void parametrosParaActualizar(ref SqlCommand cmdRef, Producto prod)
    {
      cmdRef.Parameters.AddWithValue("@IdProd", prod.idProducto);
      cmdRef.Parameters.AddWithValue("@NombreProd", prod.nombreProducto);
      cmdRef.Parameters.AddWithValue("@CantXUnid", prod.cantidadPorUnidad);
      cmdRef.Parameters.AddWithValue("@PrecUnid", prod.precioUnitario);
    }

    public bool actualizarProducto(Producto prodConNuevosDatos)//le doy el producto con los nuevos datos
    {
      SqlCommand cmd = new SqlCommand();

      parametrosParaActualizar(ref cmd, prodConNuevosDatos);

      ConexionDB conexionDB = new ConexionDB();
      int filasAfectadas = conexionDB.ejecutarProcAlmacenado(cmd, "sp_ActualizarProducto");

      if(filasAfectadas == 1)
        return true;
      else
        return false;
    }
  }
}