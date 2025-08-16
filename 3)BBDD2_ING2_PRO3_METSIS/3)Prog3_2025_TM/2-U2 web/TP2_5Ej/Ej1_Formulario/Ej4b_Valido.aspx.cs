using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp2Ej1_Formulario
{
  public partial class Ej4b_Valido : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      string nombreRecibido = Request.QueryString["varUsuario"];

      lblMensaje.Text = "<h1>Bienvenido a mi pagina Sr./a " + 
                        nombreRecibido + "</h1>";
    }
  }
}