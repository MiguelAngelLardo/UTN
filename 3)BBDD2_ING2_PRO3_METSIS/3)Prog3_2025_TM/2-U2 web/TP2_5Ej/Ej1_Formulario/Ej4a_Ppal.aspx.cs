using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp2Ej1_Formulario
{
  public partial class WebForm1 : System.Web.UI.Page
  {
    // 1. Declaramos las constantes a nivel de clase. Son los datos correctos.
    const string USUARIO_VALIDO = "claudio";
    const string CLAVE_VALIDA = "casas";


    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnValidar_Click(object sender, EventArgs e)
    {
      string usuarioIngresado = txtUsuario.Text;
      string claveIngresada = txtClave.Text;  

      if(USUARIO_VALIDO == usuarioIngresado && CLAVE_VALIDA == claveIngresada)
      {
        Response.Redirect("Ej4b_Valido.aspx?" +
        "varUsuario=" + usuarioIngresado);
      }
      else
      {
        Response.Redirect("Ej4c_Error.aspx?");
      }
          
    }
  }
}