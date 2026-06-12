using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Dao;
namespace Negocio
{
  public class NegocioAdmin
  {
   private DaoAdmin _daoAdmin = new DaoAdmin();

    public bool LoginAdmin(string user, string pass)
    {
      return _daoAdmin.ExisteAdminYPass(user, pass);
    }

  }
}
