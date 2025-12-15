using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo4a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnIniciarSession_Click(object sender, EventArgs e)
        {
            /// ALTERNATIVA 1
            HttpCookie ck = new HttpCookie("NombreUsuario", txtNombre.Text);
            ck.Expires = DateTime.Now.AddDays(1);
            this.Response.Cookies.Add(ck);

            /// ALTERNATIVA 2
            Response.Cookies["ContraseniaUsuario"].Value = txtContrasenia.Text;
            Response.Cookies["ContraseniaUsuario"].Expires = DateTime.Now.AddHours(1);

            /// REDIRIGIR AL FORMULARIO 4B
            Response.Redirect("ejemplo4b.aspx");
        }
    }
}