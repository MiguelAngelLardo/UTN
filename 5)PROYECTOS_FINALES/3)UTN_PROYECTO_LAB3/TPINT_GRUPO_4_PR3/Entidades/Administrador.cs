using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Entidades
{
  public class Administrador
  {

    Login Login { get; set; }
    public bool UsuarioHabilitado { get; set; }

    public Administrador()
    {
      Login = new Login();
      UsuarioHabilitado = false;// no tiene usuario habilitado por defecto
    }
  }
}
