using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
namespace Dao
{
  public class DaoProvincia
  {
    private AccesoDatos _accesoDatos = new AccesoDatos();

    public DataTable ListarProvincias()
    {
      string nombreSP = "sp_ListarProvincias"; //idem bbdd
      return _accesoDatos.ObtenerTabla(nombreSP);
    }



  }
}
