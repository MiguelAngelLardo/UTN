using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo1a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnEnviar_Click(object sender, EventArgs e)
        {
            /// CREAR VARIABLE DE TIPO SESSION
            Session["nombreUsuario"] = txtNombre.Text;

            /// REDIGIR AL FORMULARIO EJEMPLO 1B
            Response.Redirect("ejemplo1b.aspx");
        }
    }
}