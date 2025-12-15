using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

public class GestionLibros
{
    /// PROPIEDADES
    
    /// CONSTRUCTORES
   	public GestionLibros()
	{
        /// CONSTRUCTOR POR DEFECTO O VACIO
	}

    /// METODOS
    private DataTable ObtenerTabla(string nombreTabla, string consultaSQL)
    {
        DataSet dataSet = new DataSet();
        AccesoDatos datos = new AccesoDatos();
        SqlDataAdapter sqlDataAdapter = datos.ObtenerAdaptador(consultaSQL);
        sqlDataAdapter.Fill(dataSet, nombreTabla);
        return dataSet.Tables[nombreTabla];
    }

    public DataTable ObtenerTodosLosLibros()
    {
        return ObtenerTabla("Libros", "SELECT * FROM Libros");
    }





































    private void ArmarParametrosLibrosEliminar(ref SqlCommand Comando, Libro libro)
    {
        SqlParameter SqlParametros = new SqlParameter();
        SqlParametros = Comando.Parameters.Add("@IdLibro", SqlDbType.Int);
        SqlParametros.Value = libro.IdLibro;
    }

    private void ArmarParametrosLibros(ref SqlCommand Comando, Libro libro)
    {
        SqlParameter SqlParametros = new SqlParameter();
        SqlParametros = Comando.Parameters.Add("@IdLibro", SqlDbType.Int);
        SqlParametros.Value = libro.IdLibro;
        SqlParametros = Comando.Parameters.Add("@Titulo", SqlDbType.NVarChar, 50);
        SqlParametros.Value = libro.Titulo;
        SqlParametros = Comando.Parameters.Add("@Precio", SqlDbType.Money);
        SqlParametros.Value = libro.Precio;
        SqlParametros = Comando.Parameters.Add("@Autor", SqlDbType.NVarChar, 50);
        SqlParametros.Value = libro.Autor;
    }

    public bool ActualizarLibro(Libro libro)
    {
        SqlCommand sqlCommand = new SqlCommand();
        ArmarParametrosLibros(ref sqlCommand, libro);
        AccesoDatos accesoDatos = new AccesoDatos();
        int FilasInsertadas = accesoDatos.EjecutarProcedimientoAlmacenado(sqlCommand, "spActualizarLibro");
        if (FilasInsertadas == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    public bool EliminarLibro(Libro libro)
    {
        SqlCommand sqlCommand = new SqlCommand();
        ArmarParametrosLibrosEliminar(ref sqlCommand, libro);
        AccesoDatos accesoDatos = new AccesoDatos();
        int FilasInsertadas = accesoDatos.EjecutarProcedimientoAlmacenado(sqlCommand, "spEliminarLibro");
        if (FilasInsertadas == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}