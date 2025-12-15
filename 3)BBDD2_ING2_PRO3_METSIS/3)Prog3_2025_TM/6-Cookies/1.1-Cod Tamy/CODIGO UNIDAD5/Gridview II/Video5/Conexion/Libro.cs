using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

/// <summary>
/// Descripción breve de Libro
/// </summary>
public class Libro
{
    private int i_IdLibro;
    private int i_IdTema;
    private String s_Titulo;
    private decimal d_Precio;
    private String s_Autor;
	public Libro()
	{
    }
    public Libro (int i_IdLibro,int i_IdTema,String s_Titulo, decimal d_Precio,String s_Autor)
    {
        this.i_IdLibro=i_IdLibro;
        this.i_IdTema=i_IdTema;
        this.s_Titulo=s_Titulo;
        this.d_Precio = d_Precio;
        this.s_Autor = s_Autor;
    }
    public int IdLibro
    { 
        get {return i_IdLibro;}
        set {i_IdLibro=value;}
    }
    public int IdTema
    {
        get { return i_IdTema; }
        set { i_IdTema = value; }
    }
    public String Titulo
    {
        get { return s_Titulo; }
        set { s_Titulo = value; }
    }
    public decimal Precio
    {
        get { return d_Precio; }
        set { d_Precio = value; }
    }
    public String Autor
    {
        get { return s_Autor; }
        set { s_Autor = value; }
    }
}