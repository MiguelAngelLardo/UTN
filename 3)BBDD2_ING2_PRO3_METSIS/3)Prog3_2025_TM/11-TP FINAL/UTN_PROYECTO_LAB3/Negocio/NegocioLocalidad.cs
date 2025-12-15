using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Dao;
namespace Negocio
{
  public class NegocioLocalidad
  {
    private DaoLocalidad _daoLocalidad = new DaoLocalidad();

    public DataTable ListarLocalidadesPorProvincia(int idProvincia)
    {
      return _daoLocalidad.ListarPorProvincia(idProvincia);
    }

  }
}
