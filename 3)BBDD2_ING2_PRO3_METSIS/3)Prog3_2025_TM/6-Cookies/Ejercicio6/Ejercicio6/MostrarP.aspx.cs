using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;//tiene dataTable
namespace Ejercicio6
{
  public partial class MostrarP : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (Session["tablaSessionSeleccionados"] != null) //si session tiene algo
      {
        grdProdSeleccionados.DataSource = (DataTable)Session["tablaSessionSeleccionados"];
        grdProdSeleccionados.DataBind();
      }
    }
  }
}