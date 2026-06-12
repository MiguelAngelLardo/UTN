using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  [Serializable] //para que convierta la clase en bytes y lo use el ViewState el ddlMedic al txtDateCalendario
  public class DiasHorariosMedico
  {
    public string HorarioBase { get; set; } // Ej: "08:00-12:00"                                            
    public string IdsDiasTrabajo { get; set; }// cadena concatenada del SP (ej: "1,3,5")
    public string NombresDiasTrabajo { get; set; } // se llena en la capa de Negocio con los nombres (ej: "Lunes, Miércoles, Viernes")

    public DiasHorariosMedico()
    {
      HorarioBase = string.Empty;
      IdsDiasTrabajo = string.Empty;
      NombresDiasTrabajo = "Sin días o referencias"; 
    }

  }
}
