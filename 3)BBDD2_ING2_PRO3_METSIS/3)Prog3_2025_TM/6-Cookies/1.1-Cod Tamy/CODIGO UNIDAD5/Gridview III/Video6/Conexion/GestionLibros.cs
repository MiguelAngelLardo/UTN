using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

/// <summary>
/// Descripción breve de GestionLibros
/// </summary>
public class GestionLibros
{
	public GestionLibros()
	{
	}
    private DataTable ObtenerTabla(String Nombre, String Sql)
    {
        DataSet ds = new DataSet();
        AccesoDatos datos = new AccesoDatos();
        SqlDataAdapter adp = datos.ObtenerAdaptador(Sql);
        adp.Fill(ds, Nombre);
        return ds.Tables[Nombre];
    }

    public DataTable ObtenerTodosLosLibros()
    {
        return ObtenerTabla("Libros", "Select * from Libros");
    }

    public DataTable ObtenerTodosLosLibrosConTemas()
    {
        return ObtenerTabla("Libros", "Select Libros.IdLibro As IdLibro, Libros.Autor As Autor , Libros.Titulo As Titulo, Libros.Precio As Precio ," +
                                "Temas.IdTema as IdTema, Temas.Tema as Tema from Libros inner join Temas on Temas.IdTema = Libros.IdTema");
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
        SqlParametros = Comando.Parameters.Add("@IdTema", SqlDbType.Int);
        SqlParametros.Value = libro.IdTema;
        SqlParametros = Comando.Parameters.Add("@Titulo", SqlDbType.NVarChar, 40);
        SqlParametros.Value = libro.Titulo;
        SqlParametros = Comando.Parameters.Add("@Precio", SqlDbType.Money);
        SqlParametros.Value = libro.Precio;
        SqlParametros = Comando.Parameters.Add("@Autor", SqlDbType.NVarChar, 40);
        SqlParametros.Value = libro.Autor;
    }


    public bool ActualizarLibro(Libro lib)
    {
        SqlCommand Comando = new SqlCommand();
        ArmarParametrosLibros(ref Comando, lib);
        AccesoDatos ad = new AccesoDatos();
        int FilasInsertadas = ad.EjecutarProcedimientoAlmacenado(Comando, "spActualizarLibroConTema");
        if (FilasInsertadas == 1)
            return true;
        else
            return false;
    }

  

    public bool EliminarLibro(Libro lib)
    {
        SqlCommand Comando = new SqlCommand();
        ArmarParametrosLibrosEliminar(ref Comando, lib);
        AccesoDatos ad = new AccesoDatos();
        int FilasInsertadas = ad.EjecutarProcedimientoAlmacenado(Comando, "spEliminarLibro");
        if (FilasInsertadas == 1)
            return true;
        else
            return false;
    }
}