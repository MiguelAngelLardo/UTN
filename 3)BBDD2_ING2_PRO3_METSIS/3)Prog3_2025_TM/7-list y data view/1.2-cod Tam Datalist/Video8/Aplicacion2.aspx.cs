using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Video8
{
    public partial class Aplicacion2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnPersonas_Command(object sender, CommandEventArgs e)
        {
            if (e.CommandName == "comandoBoton")
            {
                lblMensaje.Text = e.CommandArgument.ToString();
            }
        }
    }
}