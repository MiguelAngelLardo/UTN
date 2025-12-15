using Dao;
using Entidades;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Negocio
{
  public class NegocioProvincia
  {

    private DaoProvincia _daoProvincia = new DaoProvincia();

    public List<Provincia> negProvGetListaProv()
    {
      return _daoProvincia.daoProvGetListaProv();
    }

    public DataTable getTablaProvincias()
    {
      // Simplemente llama al método del DAO y devuelve la tabla.
      return _daoProvincia.daoProvGetTablaProvincias();
    }


  }
}
