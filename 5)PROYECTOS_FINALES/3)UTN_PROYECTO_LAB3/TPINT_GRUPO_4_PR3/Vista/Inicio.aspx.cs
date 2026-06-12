using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Negocio;
namespace Vista
{
  public partial class Inicio : System.Web.UI.Page
  {

    private NegocioAdmin _negAdmin = new NegocioAdmin();
    private NegocioMedico _negMedico = new NegocioMedico();


    protected void Page_Load(object sender, EventArgs e)
    {

    }
    private bool ValidarLogin()
    {
      if (string.IsNullOrWhiteSpace(tbUsuario.Text) || string.IsNullOrWhiteSpace(tbContraseña.Text))//si tiene mas de 1 ascii 32(' ') o si es ""
      {
        lblError.Text = "Debe rellenar todos los campos";
        return false;
      }
      lblError.Text = "";
      return true; 
    }

    private void EntrarAlPrograma(string usuario, string tipoUsuario, string urlDestino)
    {
      Session["UsuarioLogueado"] = usuario;// no mantiene la info en otros navegadores si en otras pestañas
      Session["TipoUsuario"] = tipoUsuario; // Usamos la variable, como sugeriste
      Response.Redirect(urlDestino);
    }

    protected void btnAcceder_Click(object sender, EventArgs e)
    {
      if (!ValidarLogin()) return;

      string usuario = tbUsuario.Text;
      string contrasenia = tbContraseña.Text;
      string tipoUsuario = ddlUsuario.SelectedValue;// Value="Admin" o "Medico">

      switch (tipoUsuario)
      {

        case "Admin":
          if (_negAdmin.LoginAdmin(usuario, contrasenia)) EntrarAlPrograma(usuario, tipoUsuario, "~/Administrador/MenuAdmin.aspx");
          else lblError.Text = "Usuario Administrador o Contraseña Incorrectos";
          break;
        case "Medico":
          if (_negMedico.LoginMedico(usuario, contrasenia)) EntrarAlPrograma(usuario, tipoUsuario, "~/Medico/MenuMedico.aspx");
          else lblError.Text = "Usuario Medico o Contraseña Incorrectos";
          break;

        case "0": lblError.Text = "Seleccione el tipo de usuario";  break;
      }
    }
  }
}