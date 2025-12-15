using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                ddlColores.Items.Add("Azul");
                ddlColores.Items.Add("Rojo");
                ddlColores.Items.Add("Verde");
            }
        }

        protected void ddlColores_SelectedIndexChanged(object sender, EventArgs e)
        {
            lblColorSeleccionado.Text = ddlColores.SelectedItem.ToString();
        }
    }
}