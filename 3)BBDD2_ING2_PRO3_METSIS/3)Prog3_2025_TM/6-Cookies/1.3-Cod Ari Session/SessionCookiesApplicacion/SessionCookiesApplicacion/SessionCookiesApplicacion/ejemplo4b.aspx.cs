using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo4b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Request.Cookies["NombreUsuario"] != null && Request.Cookies["ContraseniaUsuario"] != null)
            {
                HttpCookie ck = Request.Cookies["NombreUsuario"];

                lblMensaje.Text = ck.Value + "  " + Request.Cookies["ContraseniaUsuario"].Value;
            }
        }

        protected void btnEliminarCookies_Click(object sender, EventArgs e)
        {
            if(Request.Cookies["NombreUsuario"] != null)
            {
                HttpCookie ck = Request.Cookies["NombreUsuario"];
                ck.Expires = DateTime.Now.AddDays(-1);
                this.Request.Cookies.Add(ck);
                lblMensaje.Text = string.Empty;
            }
        }
    }
}