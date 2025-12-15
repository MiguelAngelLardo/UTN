using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MiPrimerSitioWeb
{
    public partial class Aplicacion6b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            String Nombre;
            String Apellido;
            Nombre = Request["txtNombre"].ToString();
            Apellido = ((TextBox)PreviousPage.FindControl("txtApellido")).Text;

            lblMensaje.Text = Nombre + " " + Apellido;

        }

      
    }
}