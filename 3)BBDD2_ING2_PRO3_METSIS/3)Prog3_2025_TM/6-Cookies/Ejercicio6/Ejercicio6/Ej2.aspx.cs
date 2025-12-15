using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Ejercicio6
{
  public partial class Ej2 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void lbEliminarProd_Click(object sender, EventArgs e)
    {
      Session["tablaSessionSeleccionados"] = null;//elimine los datos de session
    }
  }
}