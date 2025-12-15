using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion2b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Application["cant"]!= null)
            {
                lblMensaje.Text = Application["cant"].ToString();
            }
        }
    }
}