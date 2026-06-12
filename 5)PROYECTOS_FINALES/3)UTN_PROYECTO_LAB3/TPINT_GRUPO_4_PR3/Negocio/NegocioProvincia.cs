using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using Dao;

namespace Negocio
{
  public class NegocioProvincia
  {
    
    private DaoProvincia _daoProvincia = new DaoProvincia();


    public DataTable Listar()
    {
      return _daoProvincia.ListarProvincias();
    }


  }
}
