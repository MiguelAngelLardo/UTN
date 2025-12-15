using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion4b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Request.Cookies["NombreUsuario"]!= null && Request.Cookies["NombreClave"] != null)
            {
                HttpCookie ck = Request.Cookies["NombreUsuario"];

                lblResultado.Text = ck.Value +" "+ Request.Cookies["NombreClave"].Value;
            }
        }

        protected void btnEliminar_Click(object sender, EventArgs e)
        {
            if(Request.Cookies["NombreUsuario"] != null)
            {
                HttpCookie ck = Request.Cookies["NombreUsuario"];
                ck.Expires = DateTime.Now.AddDays(-1);
                this.Response.Cookies.Add(ck);
                lblResultado.Text = "";
            }
        }
    }
}