using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using System.Data.SqlClient;
using System.Data;
namespace Tp5
{
  public class Conexion
  {
    private String ruta = "Data Source=localhost\\sqlexpress;Initial Catalog=BDSucursales;Integrated Security=True";

    public int insertarEliminarModificar(String consulta)
    {
      SqlConnection cn = new SqlConnection(ruta);
      cn.Open();
      SqlCommand cmdInsertDeleteModify = new SqlCommand(consulta, cn);
      int filasAfectadas = cmdInsertDeleteModify.ExecuteNonQuery();//Non-Query es por que no me trae datos sino que yo doy una orden de modificar algo
      cn.Close();
      return filasAfectadas;
    }

    public int insertarEliminarModificar(String consulta, SqlParameter parametro)//sobre carga para pasar parametro "@id"
    {
      SqlConnection cn = new SqlConnection(ruta);
      cn.Open();
      SqlCommand cmdInsertDeleteModify = new SqlCommand(consulta, cn);
      cmdInsertDeleteModify.Parameters.Add(parametro);
      int filasAfectadas = cmdInsertDeleteModify.ExecuteNonQuery();//Non-Query es por que no me trae datos sino que yo doy una orden de modificar algo
      cn.Close();
      return filasAfectadas;
    }




    public DataTable seleccionarDatos(String consulta)
    {
      DataTable dt = new DataTable();
      
      SqlConnection cn = new SqlConnection(ruta);
      SqlDataAdapter adap = new SqlDataAdapter(consulta, cn);//metodo desconectado

      adap.Fill(dt);//la tabla dt es llenada con la consulta del adap -> el Fill abre y cierra la conexion solo

      return dt;
    }

    public DataTable seleccionarDatosConPlaceHoldder(String consulta, SqlParameter[] parametros)//espera el key value
    {
      DataTable dt = new DataTable();
      SqlConnection cn = new SqlConnection(ruta);
      
      SqlCommand cmdSelectPlaceHolder = new SqlCommand(consulta, cn);
      cmdSelectPlaceHolder.Parameters.AddRange(parametros);
      SqlDataAdapter adap = new SqlDataAdapter(cmdSelectPlaceHolder); //de esta manera no uso un DataReader que necesita una conexion abierta para funcionar
      
      adap.Fill(dt);
      return dt;
    }
  }
}