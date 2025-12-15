using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Video9
{
    public partial class Aplicacion7 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnRedirigir_Click(object sender, EventArgs e)
        {
            Response.Redirect("Aplicacion6.aspx");
        }

        protected void btnGuardarUsuario_Click(object sender, EventArgs e)
        {
            lblMensaje1.Text = "Se guardo al usuario con exito";
        }

        protected void btnGuardarMail_Click(object sender, EventArgs e)
        {
            lblMensaje2.Text = "Se guardo el mail con exito";
        }
    }
}