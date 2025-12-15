using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace TP7_Codigo.Entidades_Modelos_
{
  public class Sucursal
  {
    public int IdSucursal { get; set; }
    public string Nombre { get; set; }
    public string Descripcion { get; set; }
    public string urlImagen { get; set; }
    public string IdProvinciaSucursal { get; set; }
  }
}