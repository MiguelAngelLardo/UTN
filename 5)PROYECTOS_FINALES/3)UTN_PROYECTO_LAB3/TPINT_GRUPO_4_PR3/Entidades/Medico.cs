using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Medico : Persona
  {
    public string Legajo { get; set; }
    public string HoraAtencion { get; set; }
    public bool UsuarioHabilitado { get; set; }
    public Login Login { get; set; }
    public Especialidad Especialidad { get; set; }
    public List<DiasSemana> DiasSemanaMedico { get; set; }


    public Medico() : base()
    {
      Legajo = "";
      HoraAtencion = "";
      UsuarioHabilitado = false;// no tiene usuario habilitado por defecto
      Login = new Login();      
      Especialidad = new Especialidad();
      DiasSemanaMedico = new List<DiasSemana>(); //lista vacia
    }
  }
}
