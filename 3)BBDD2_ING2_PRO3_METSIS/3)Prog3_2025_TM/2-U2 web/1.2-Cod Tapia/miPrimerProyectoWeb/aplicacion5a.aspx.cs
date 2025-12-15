using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion5a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnEnviar_Click(object sender, EventArgs e)
        {
            Response.Redirect("aplicacion5b.aspx?Nom="+txtNombre.Text+"&Ape="+txtApellido.Text);
        }
    }
}