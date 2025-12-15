using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Entidades;
namespace Dao
{

  public class DaoProvincia
  {

   private AccesoDatos _accesoDatos = new AccesoDatos();

   public List<Provincia> daoProvGetListaProv()
    {
      List<Provincia> listaProv = new List<Provincia>();
      string consultaSelect = "SELECT Id_Provincia, DescripcionProvincia FROM Provincia";

      DataTable dt = _accesoDatos.daoGetTablaAdap(consultaSelect);

      foreach (DataRow fila in dt.Rows)
      {
        Provincia provincia = new Provincia();

        provincia.propIdProvincia = Convert.ToInt32(fila["Id_Provincia"]);
        provincia.propDescripcionProvincia = fila["DescripcionProvincia"].ToString();


        listaProv.Add(provincia);
      }

      return listaProv;
    }


    public DataTable daoProvGetTablaProvincias()
    {
      string consulta = "SELECT Id_Provincia, DescripcionProvincia FROM Provincia";
      return _accesoDatos.daoGetTablaAdap(consulta); 
    }







  }

}
