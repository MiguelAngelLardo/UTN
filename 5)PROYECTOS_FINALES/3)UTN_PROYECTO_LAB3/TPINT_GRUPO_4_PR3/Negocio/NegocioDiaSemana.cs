using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data;
using Dao;
namespace Negocio
{
  public class NegocioDiaSemana
  {
    private DaoDiaSemana _daoDiaSemana = new DaoDiaSemana();

    public DataTable Listar()
    {
      // (Pasamanos) Llama al DAO
      return _daoDiaSemana.ListarDias();
    }
  }
}
