using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

public class AccesoDatos
{
    /// PROPIEDADES
    string rutaLibreria = @"Data Source=localhost\sqlexpress;Initial Catalog = Libreria; Integrated Security = True";

    /// METODO CONSTRUCTOR
    public AccesoDatos()
    {
        // TODO: Agregar aquí la lógica del constructor
    }

    /// METODOS
    public SqlConnection ObtenerConexion()
    {
        SqlConnection sqlConnection = new SqlConnection(rutaLibreria);
        try
        {
            sqlConnection.Open();
            return sqlConnection;
        }
        catch (Exception exception)
        {
            return null;
        }
    }
    public SqlDataAdapter ObtenerAdaptador(string consultaSql)
    {
        SqlDataAdapter sqlDataAdapter;
        try
        {
            sqlDataAdapter = new SqlDataAdapter(consultaSql, ObtenerConexion());
            return sqlDataAdapter;
        }
        catch (Exception exception)
        {
            return null;
        }
    }

    public int EjecutarProcedimientoAlmacenado(SqlCommand comandoSQL, string nombreProcedimientoAlmacenado) //comandoSQL recibe tiene los parametros incluidos
    {
        int FilasCambiadas;
        SqlConnection Conexion = ObtenerConexion();
        SqlCommand sqlCommand = new SqlCommand();
        sqlCommand = comandoSQL;
        sqlCommand.Connection = Conexion;
        sqlCommand.CommandType = CommandType.StoredProcedure;   /// INDICO QUE SE TRATA DE UN PROCEDIMIENTO ALMACENADO
        sqlCommand.CommandText = nombreProcedimientoAlmacenado; /// INDICO EL NOMBRE DEL PROCEDIMIENTO ALMACENADO
        FilasCambiadas = sqlCommand.ExecuteNonQuery();          /// EJECUTO EL PROCEDIMIENTO ALMACENADO
        Conexion.Close();
        return FilasCambiadas;
    }
}