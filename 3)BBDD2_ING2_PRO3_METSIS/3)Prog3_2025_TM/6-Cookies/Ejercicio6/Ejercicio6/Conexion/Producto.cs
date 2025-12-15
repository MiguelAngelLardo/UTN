using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Ejercicio6.Conexion
{
  public class Producto
  {
    private int _idProducto;
    private string _nombreProducto;
    private string _cantidadPorUnidad;
    private decimal _pu;//para money en bbdd usamos decimal en backend

    //constructor fantasma: si no escribo nada C# me crea uno vacio por defecto
    //pero al crear uno con parametros necesito crear este vacio
    public Producto() { }

    public Producto(int IdProd, string nombreProd, string cantPorUni, decimal precUni)
    {
      _idProducto = IdProd;
      _nombreProducto = nombreProd;
      _cantidadPorUnidad = cantPorUni;
      _pu = precUni;
    }

    public int idProducto
    {
      get { return _idProducto; }
      set { _idProducto = value; }
    }
    //Producto miProducto = new Producto();
    //set => miProducto.idPRoducto = 10; // Así de simple, como si fuera una variable pública.
    //get => int elId = miProducto.idPRoducto; // También, como si fuera una variable.


    public string nombreProducto
    {
      get { return _nombreProducto; }
      set { _nombreProducto = value; }
    }

    public string cantidadPorUnidad
    {
      get { return _cantidadPorUnidad; }
      set { _cantidadPorUnidad = value; }
    }

    public decimal precioUnitario
    {
      get { return _pu; }
      set { _pu = value; }
    }

  }
}