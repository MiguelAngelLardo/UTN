using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
 public class Especialidad
  {
    public int IdEspecialidad { get; set; }
    public string Descripcion { get; set; }
    public bool Estado { get; set; }

    public Especialidad()
    {
      IdEspecialidad = 0;
      Descripcion = "";
      Estado = true;
    }

  }
}
