using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dao
{
  public class DaoEspecialidad
  {
   private AccesoDatos _accesoDatos = new AccesoDatos();

   public System.Data.DataTable ListarEspecialidades()
    {
      string nombreSP = "sp_ListarEspecialidades"; //idem bbdd
      return _accesoDatos.ObtenerTabla(nombreSP);
    }



  }
}
