using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Dao;

namespace Negocio
{

  public class NegocioEspecialidad
  {

    private DaoEspecialidad _daoEspecialidad = new DaoEspecialidad();

    public System.Data.DataTable Listar()
    {
      return _daoEspecialidad.ListarEspecialidades();
    }


  }
}
