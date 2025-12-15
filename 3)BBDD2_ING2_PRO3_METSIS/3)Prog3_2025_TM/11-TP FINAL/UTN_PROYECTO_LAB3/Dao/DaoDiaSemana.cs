using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
namespace Dao
{
  public class DaoDiaSemana
  {
    private AccesoDatos _accesoDatos = new AccesoDatos();

   
    public DataTable ListarDias()    {
      string nombreSP = "sp_ListarDiasSemana";
      return _accesoDatos.ObtenerTabla(nombreSP);
    }
  }
}