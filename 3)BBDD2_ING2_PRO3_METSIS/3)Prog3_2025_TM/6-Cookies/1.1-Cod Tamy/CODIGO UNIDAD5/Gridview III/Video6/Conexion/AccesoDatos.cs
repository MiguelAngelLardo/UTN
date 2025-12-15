using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

/// <summary>
/// Descripción breve de AccesoDatos
/// </summary>
public class AccesoDatos
{
    String rutaBDLibreria =
    "Data Source=localhost\\sqlexpress;Initial Catalog=Libreria;Integrated Security=True";

    public AccesoDatos()
	{
		// TODO: Agregar aquí la lógica del constructor
	}

    public SqlConnection ObtenerConexion()
    {
        SqlConnection cn = new SqlConnection(rutaBDLibreria);
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
    public SqlDataAdapter ObtenerAdaptador(String consultaSql)
    {
        SqlDataAdapter adaptador;
        try
        {
            adaptador=new SqlDataAdapter(consultaSql,ObtenerConexion());
            return adaptador;
        }
        catch (Exception ex)
        {
            return null;
        }
    }

    public int EjecutarProcedimientoAlmacenado(SqlCommand Comando, String NombreSP) //comando que recibe tiene los parametros incluidos
    {
        int FilasCambiadas;
        SqlConnection Conexion = ObtenerConexion();
        SqlCommand cmd = new SqlCommand();
        cmd = Comando;
        cmd.Connection = Conexion;
        cmd.CommandType = CommandType.StoredProcedure;
        cmd.CommandText = NombreSP;
        FilasCambiadas = cmd.ExecuteNonQuery();
        Conexion.Close();
        return FilasCambiadas;
    }


}