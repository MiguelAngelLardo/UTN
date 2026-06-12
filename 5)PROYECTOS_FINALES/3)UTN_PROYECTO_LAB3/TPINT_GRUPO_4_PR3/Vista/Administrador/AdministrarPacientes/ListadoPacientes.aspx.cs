using Negocio;
using System;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarPacientes
{
  public partial class ListadoPacientes : System.Web.UI.Page
  {
    NegocioPaciente negocioPaciente = new NegocioPaciente();

    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        CargarGridPacientes();
      }
    }

    private void CargarGridPacientes(string nomApe = null, string dni = null)
    {
      DataTable tabla = negocioPaciente.BuscarPacientes(nomApe, dni);

      gvPacientes.DataSource = tabla;
      gvPacientes.DataBind();
    }

    protected void btnAgregarPaciente_Click(object sender, EventArgs e)
    {
      Response.Redirect("FormAgregarPaciente.aspx");
    }


    protected void btnBuscar_Click(object sender, EventArgs e)
    {
      string nombre = txtBuscarPorNombre.Text.Trim();
      string dni = txtBuscarPorDNI.Text.Trim();

      DataTable tabla = negocioPaciente.BuscarPacientes(nombre, dni);

      gvPacientes.DataSource = tabla;
      gvPacientes.DataBind();
    }

        protected void gvPacientes_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            string dni = e.CommandArgument.ToString();

            switch (e.CommandName)
            {
                case "Editar":
                    dni = e.CommandArgument.ToString();
                    Response.Redirect("FormEditarPaciente.aspx?dni=" + dni);
                    break;
                case "Ver":
                    dni = e.CommandArgument.ToString();
                    Response.Redirect("DetallePaciente.aspx?dni=" + dni);
                    break;
                case "Eliminar":
                    negocioPaciente.EliminarPaciente(dni);
                    CargarGridPacientes();
                    break;
            }
        }

        protected void gvPacientes_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            gvPacientes.PageIndex = e.NewPageIndex;
            CargarGridPacientes();
        }
    }
}