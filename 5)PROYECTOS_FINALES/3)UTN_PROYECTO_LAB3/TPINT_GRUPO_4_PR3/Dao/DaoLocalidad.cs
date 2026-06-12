using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using System.Data.SqlClient;
namespace Dao
{
  public class DaoLocalidad
  {
    private AccesoDatos _accesoDatos = new AccesoDatos();

    public DataTable ListarPorProvincia(int idProvincia)
    {
      string nombreSP = "sp_ListarLocalidadesPorProvincia"; //idem bbdd
      
      List<SqlParameter> parametros = new List<SqlParameter>();
      parametros.Add(new SqlParameter("@idProvincia", idProvincia));

      return _accesoDatos.ObtenerTabla(nombreSP, parametros);
    }




  }
}
