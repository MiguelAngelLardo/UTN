using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp2Ej1_Formulario
{
  public partial class Ej4c_Error : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      lblTexto.Text = "<h1>USUARIO INVALIDO INGRESO NO PERMITIDO</h1><br />";
    }
  }
}