using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion4a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnIniciarSesion_Click(object sender, EventArgs e)
        {
            //Alternativa 1:

            HttpCookie ck = new HttpCookie("NombreUsuario", txtUsuario.Text);
            ck.Expires = DateTime.Now.AddDays(1);
            this.Response.Cookies.Add(ck);

            //Alternativa 2:

            Response.Cookies["NombreClave"].Value = txtClave.Text;
            Response.Cookies["NombreClave"].Expires = DateTime.Now.AddHours(1);
            Response.Redirect("Aplicacion4b.aspx");

        }
    }
}