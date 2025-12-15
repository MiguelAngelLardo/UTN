using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion6b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string nombre;
            string apellido;
            nombre = Request["txtNombre"].ToString();
            apellido = ((TextBox)PreviousPage.FindControl("txtApellido")).Text;
            lblMensaje.Text = "Bienvenido/a " + nombre + " " + apellido;
        }
    }
}