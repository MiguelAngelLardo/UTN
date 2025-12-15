using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnSaludar_Click(object sender, EventArgs e)
        {
            lblSaludar.Text = "Holaaaa";
        }

        protected void btnDespedir_Command(object sender, CommandEventArgs e)
        {
            if (e.CommandName == "eventoDespedir")
            {
                lblDespedir.Text = "Adiosss";
            }
        }
    }
}