using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Video7
{
    public partial class Aplicacion4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnMostrar_Click(object sender, EventArgs e)
        {
            String nombre;
            String apellido;

            foreach (ListViewItem item in lvPersonas.Items)
            {
                CheckBox i = (CheckBox)(item.FindControl("chkSeleccion"));
                if (i.Checked)
                {
                    nombre = ((Label)item.FindControl("NombreLabel")).Text;
                    apellido = ((Label)item.FindControl("ApellidoLabel")).Text;
                    lblMensaje.Text += nombre + " " + apellido + " </br>";

                }

            }


        }
    }
}