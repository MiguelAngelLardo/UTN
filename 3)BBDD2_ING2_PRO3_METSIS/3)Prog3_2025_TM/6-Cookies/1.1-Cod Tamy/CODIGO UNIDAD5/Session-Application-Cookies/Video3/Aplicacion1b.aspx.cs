using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion1b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if ( Session["nombreUsuario"]!= null)
            {
                //Hay informacion en la variable session
                lblMensaje.Text = Session["nombreUsuario"].ToString();
            }
        }
    }
}