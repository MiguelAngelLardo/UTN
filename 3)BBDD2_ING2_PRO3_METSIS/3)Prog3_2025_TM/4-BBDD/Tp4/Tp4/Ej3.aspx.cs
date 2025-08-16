using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp4
{
  public partial class Ej3 : System.Web.UI.Page
  {

    public void cargarDdl()
    {
      ddlTemas.Items.Add(new ListItem("Tema 1", "1"));
      ddlTemas.Items.Add(new ListItem("Tema 2", "2"));
      ddlTemas.Items.Add(new ListItem("Tema 3", "3"));
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        cargarDdl();
      }
    }

    protected void lbVerLibros_Click(object sender, EventArgs e)
    {
      string idTemaSeleccionado = ddlTemas.SelectedValue;
      Response.Redirect("Ej3b.aspx?IdTema=" + idTemaSeleccionado);
    }
  }
}