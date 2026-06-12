using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Login
  {
    public string NombreUsuario { get; set; }
    public string Contrasenia { get; set; }
    public Login()
    {
      NombreUsuario = "";
      Contrasenia = "";
    }
  }

}
