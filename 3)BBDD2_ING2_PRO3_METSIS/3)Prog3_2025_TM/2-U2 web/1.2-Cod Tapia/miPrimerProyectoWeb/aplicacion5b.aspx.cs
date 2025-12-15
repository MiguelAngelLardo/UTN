using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion5b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string nombre;
            string apellido;
            nombre = Request.QueryString["Nom"];
            apellido = Request.QueryString["Ape"];
            lblMensaje.Text = "Bienvenido/a " + nombre + " " + apellido;
        }
    }
}