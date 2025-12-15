using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion3 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            //// CARGAR DROPDOWNLIST FORMA 1
            if (IsPostBack == false)
            {
                ddlColores.Items.Add("Azul");
                ddlColores.Items.Add("Rojo");
                ddlColores.Items.Add("Verde");
            }

            // CARGAR DROPDOWNLIST FORMA 2
            //if (!IsPostBack)
            //{
            //    ListItem itemAzul = new ListItem();
            //    itemAzul.Text = "Azul";
            //    itemAzul.Value = "1";

            //    ListItem itemRojo = new ListItem();
            //    itemRojo.Text = "Rojo";
            //    itemRojo.Value = "2";

            //    ListItem itemVerde = new ListItem();
            //    itemVerde.Text = "Verde";
            //    itemVerde.Value = "3";

            //    ddlColores.Items.Add(itemAzul);
            //    ddlColores.Items.Add(itemRojo);
            //    ddlColores.Items.Add(itemVerde);
            //}

            // CARGAR DROPDOWNLIST FORMA 3
            //if (!IsPostBack)
            //{
            //    ListItemCollection coleccion = new ListItemCollection();
            //    coleccion.Add(new ListItem("Azul","1"));
            //    coleccion.Add(new ListItem("Rojo", "2"));
            //    coleccion.Add(new ListItem("Verde", "3"));

            //    ddlColores.DataSource = coleccion;
            //    ddlColores.DataTextField = "Text";
            //    ddlColores.DataValueField = "Value";
            //    ddlColores.DataBind();
            //}
        }

        protected void btnElegir_Click(object sender, EventArgs e)
        {
            txtColorSeleccionado.Text = ddlColores.SelectedItem.ToString();
        }
    }
}