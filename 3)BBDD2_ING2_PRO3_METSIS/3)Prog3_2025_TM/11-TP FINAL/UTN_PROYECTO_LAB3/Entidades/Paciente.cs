using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Paciente : Persona
  {
    public string Diagnostico { get; set; }

    public Paciente() : base()
    {
      Diagnostico = "";
    }

  }
}
