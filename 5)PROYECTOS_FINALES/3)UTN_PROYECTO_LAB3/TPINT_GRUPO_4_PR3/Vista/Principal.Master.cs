using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista
{
  public partial class Principal : System.Web.UI.MasterPage
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (Session["UsuarioLogueado"] == null)
      {
        Response.Redirect("~/Inicio.aspx");
        return;
      }

      lblUsuarioLogueado.Text = Session["UsuarioLogueado"].ToString();

      if (Session["TipoUsuario"] != null)
      {
        string tipoUsuario = Session["TipoUsuario"].ToString();
        switch (tipoUsuario)
        {
          case "Admin": hlLogo.NavigateUrl = "~/Administrador/MenuAdmin.aspx"; break;
          case "Medico":
            hlLogo.NavigateUrl = "~/Medico/MenuMedico.aspx";

            // Aqui ocultamos las secciones que no corresponden a Médico
            lnkPacientes.Visible = false;
            lnkMedicos.Visible = false;
            lnkReportes.Visible = false;

            // Aqui cambiamos el destino del link "Turnos"
            lnkTurnos.NavigateUrl = "~/Medico/AdministrarTurnos/ListadoTurnos.aspx";
            break;

           default: hlLogo.NavigateUrl = "~/Inicio.aspx"; break;
        }
      }
    }

    protected void btnCerrarSesion_Click(object sender, EventArgs e)
    {
      Session.Abandon();//destruye lo que tengo en session
      Response.Redirect("~/Inicio.aspx");
    }
  }
}
