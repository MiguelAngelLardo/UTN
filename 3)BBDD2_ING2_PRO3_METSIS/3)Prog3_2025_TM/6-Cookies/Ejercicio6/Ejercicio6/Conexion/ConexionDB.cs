using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Common;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Web;
namespace Ejercicio6.Conexion
{
  public class ConexionDB
  {
    //string cadenaConexion = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
    string cadenaConexion = "Data Source=localhost;Initial Catalog=Neptuno;User ID=sa;Password=Miguel-1234;TrustServerCertificate=True;";

    public ConexionDB() { }

    public SqlConnection conectarseABaseDatos()
    {
      SqlConnection cn = new SqlConnection(cadenaConexion);
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


    public SqlDataAdapter dataAdapterDesconectadoSelect (string consultaSqlSelect)
    {
      SqlDataAdapter adap;
      try
      {
        adap = new SqlDataAdapter(consultaSqlSelect, cadenaConexion);
        return adap;
      }
      catch (Exception ex)
      {
        return null;
      }
    }

    public int ejecutarProcAlmacenado(SqlCommand cmdInsertDeleteUpdate, string nombreSP)
    {
      int filasAfectadas;
      SqlConnection cn = conectarseABaseDatos();

      SqlCommand cmd = cmdInsertDeleteUpdate;
      cmd.Connection = cn;
      cmd.CommandText = nombreSP;//"spEliminarProducto"
      cmd.CommandType = System.Data.CommandType.StoredProcedure;

      filasAfectadas = cmd.ExecuteNonQuery();

      return filasAfectadas;
    }

  }
}

//System.Data.CommandType.Text es por defecto y significa que el comando es una consulta SQL tipo SELECT * FROM tabla
//System.Data.CommandType.StoredProcedure le dice al motor SQL "oye, esto es un procedimiento almacenado, no una consulta SQL" -> no sabrie si "spEmpleados" es una consulta mal escrita 
/*

enum ComamndType
{
  Text,
  StoredProcedure,
  TableDirect
}

public abstract class DbCommand
{
  private SqlConnection _connection;
  public SqlConnection GetConnection() { return _connection; }
  public void SetConnection(SqlConnection value) { _connection = value; }

  // ¡OJO! No hay un campo para CommandType aquí, porque al ser abstracta,
  // esta clase no guarda el dato, solo obliga a sus hijas a tener los métodos.
  public abstract CommandType GetCommandType();
  public abstract void SetCommandType(CommandType value);



}

public class SqlCommand : DbCommand // Hereda de MiDbCommand
{
  // Campo privado para guardar el valor
  private CommandType _commandType;

  public override CommandType GetCommandType()
  {
    return _commandType;
  }

  public override void SetCommandType(CommandType value)
  {
    _commandType = value;
  }

}*/

