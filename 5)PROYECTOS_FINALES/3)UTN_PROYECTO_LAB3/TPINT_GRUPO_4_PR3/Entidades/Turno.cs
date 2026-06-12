using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Turno
  {
    public int IdTurno { get; set; }
    public DateTime Fecha { get; set; }// Date
    public TimeSpan Hora { get; set; } // TimeSpan es == a Time de SQL
    public Paciente Paciente { get; set; }
    public Medico Medico { get; set; }
    public Especialidad Especialidad { get; set; }
    public string Observacion {  get; set; }
    public bool? Atendido { get; set; }//public Nullable<bool> Atendido { get; set; }


    public Turno()
    {
      IdTurno = 0;
      Fecha = new DateTime(1900, 1, 1); 
      Hora = new TimeSpan(0, 0, 0);
      Paciente = new Paciente();
      Medico = new Medico();
      Especialidad = new Especialidad();
      Observacion = "";
      Atendido = null;
    }
  }
}
