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
        private DaoProvincia daoProvincia = new DaoProvincia();

        public DataTable ObtenerProvincias()
        {
            return daoProvincia.ObtenerProvincias();
        }
    }
}
