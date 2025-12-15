using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Entidades;

namespace Dao
{
    public class DaoProvincia
    {
        private AccesoDatos ds = new AccesoDatos();

        public DataTable ObtenerProvincias()
        {
            string consulta = "SELECT Id_Provincia, DescripcionProvincia FROM Provincia";
            return ds.ObtenerTabla("Provincia", consulta);
        }
    }
}
