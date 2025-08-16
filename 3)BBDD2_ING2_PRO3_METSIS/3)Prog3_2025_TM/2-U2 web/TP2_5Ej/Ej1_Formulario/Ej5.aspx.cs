using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp2Ej1_Formulario
{
  public partial class Ej5 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        ddlCantMem.Items.Add(new ListItem("2 GB", "200"));
        ddlCantMem.Items.Add(new ListItem("4 GB", "375"));
        ddlCantMem.Items.Add(new ListItem("8GB", "500"));

        cblAccesorios.Items.Add(new ListItem("Monitor LCD", "2000,50"));//con pc en español va  ","
        cblAccesorios.Items.Add(new ListItem("HD 500GB", "550,50"));
        cblAccesorios.Items.Add(new ListItem("Grabador DVD", "1200"));
      }
    }

    protected void btnCalculoPrecio_Click(object sender, EventArgs e)
    {
      string precioMemStr = ddlCantMem.SelectedValue;
      int precioMemoria = int.Parse(precioMemStr);

      float precioAccesorios = 0;//es igual a float precioAccesorios = 0.0f;

      foreach(ListItem item in cblAccesorios.Items)
      {
        if (item.Selected)
        {
          precioAccesorios += float.Parse(item.Value);
        }
      }

      float precioFinal = precioMemoria + precioAccesorios;
    
      //C es de currency moneda para ver ,50 y no ,5
      lblPrecioFinal.Text = "El precio final es de " + precioFinal.ToString("C") + "$";

    }
  }
}