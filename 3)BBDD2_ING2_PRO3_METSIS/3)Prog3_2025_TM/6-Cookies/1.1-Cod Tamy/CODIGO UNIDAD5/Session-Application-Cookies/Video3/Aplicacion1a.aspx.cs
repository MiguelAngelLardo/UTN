using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion1a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnEnviar_Click(object sender, EventArgs e)
        {
            //Crear una variable de tipo session
            Session["nombreUsuario"] = txtNombre.Text;
            txtNombre.Text = "";
            Response.Redirect("Aplicacion1b.aspx");
        }
    }
}