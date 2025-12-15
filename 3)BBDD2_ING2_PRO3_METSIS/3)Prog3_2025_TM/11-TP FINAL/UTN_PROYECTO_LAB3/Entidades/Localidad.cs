using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Localidad
  {
    public int IdLocalidad { get; set; }
    public string Nombre { get; set; }
    public Provincia Provincia { get; set; }

    public bool Estado { get; set; }


    public Localidad()
    {
      IdLocalidad = 0;
      Nombre = "";
      Provincia = new Provincia();
      Estado = true;//asumimos que al crear una localidad ya viene activa
    }

  }
}
