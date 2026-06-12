using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public abstract class Persona
  {
    public string Dni { get; set; } //FK
    public string Nombre { get; set; }
    public string Apellido { get; set; }
    public char Sexo { get; set; }
    public string Nacionalidad { get; set; }
    public DateTime FechaNacimiento { get; set; } // el SQL si es DATE ignora el TIME del DateTime
    public string Direccion { get; set; }
    public string CorreoElectronico { get; set; }
    public string Telefono { get; set; }
    public bool Estado { get; set; }

    public Localidad Localidad { get; set; }

    public Persona()
    {
      Dni = "";
      Nombre = "";
      Apellido = "";
      Sexo = '\0';
      Nacionalidad = "";
      FechaNacimiento = new DateTime(1900, 1, 1);// 1900-01-01 00:00:00
      CorreoElectronico = "";
      Telefono = "";
      Estado = true;
      Localidad = new Localidad(); 
    
    }
  }

}

