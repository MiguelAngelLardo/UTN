using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Provincia
  {
    public int IdProvincia { get; set; }
    public string Nombre { get; set; }    
    public bool Estado { get; set; }

    public Provincia()
    {
      IdProvincia = 0;
      Nombre = "";
      Estado = true;//asumimos que al crear una provincia ya vienen activa
    }
  }
}
