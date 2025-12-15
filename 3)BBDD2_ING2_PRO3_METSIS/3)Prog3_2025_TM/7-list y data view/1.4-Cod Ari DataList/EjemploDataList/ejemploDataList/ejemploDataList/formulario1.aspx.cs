using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ejemploDataList
{
    public partial class formulario1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnPersonas_Command(object sender, CommandEventArgs e)
        {
            if(e.CommandName == "eventoBoton")
            {
                lblMensaje.Text = e.CommandArgument.ToString();
            }
        }
    }
}