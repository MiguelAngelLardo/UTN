using Negocio;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarMedicos
{
  public partial class CrearUsuario : System.Web.UI.Page
  {
    NegocioMedico negocioMedico = new NegocioMedico();


    protected void Page_Load(object sender, EventArgs e)
    {
      string legajo = Request.QueryString["legajo"];
      if (!string.IsNullOrEmpty(legajo))
      {
        txtLegajoMedico.Text = legajo;
        txtLegajoMedico.ReadOnly = true;
      }
    }

    protected void btnGuardarUsuario_Click(object sender, EventArgs e)
    {
            if (!Page.IsValid)//valido los required fields
            {
                return;
            }
         
      string legajo = Request.QueryString["legajo"];
      string usuario = txtUsuario.Text.Trim();
      string password = txtContraseña.Text.Trim();
      Entidades.Medico medico = new Entidades.Medico();
      medico.Legajo = legajo;
      medico.Login.NombreUsuario = usuario;
      medico.Login.Contrasenia = password;
      medico.UsuarioHabilitado = true; // es un BIT en la bd

            try
            {
                bool creado = negocioMedico.CrearUsuarioMedico(medico);

                if (creado)
                {
                    lblMensajeError.Visible = false;
                    lblMensajeExito.Visible = true;
                    lblMensajeExito.Text = "Usuario creado exitosamente.";
                    txtUsuario.Text = "";
                    txtContraseña.Text = "";
                    txtRepitaContraseña.Text = "";
                    txtUsuario.Enabled = false;
                    txtContraseña.Enabled = false;
                    txtRepitaContraseña.Enabled = false;
                    btnGuardarUsuario.Visible = false;

                }
                else
                {
                    lblMensajeError.Visible = true;
                    lblMensajeError.Text = "Error al crear el usuario. Verifique los datos e intente nuevamente.";
                }
            }
            catch (Exception exDelNegocio)
            {
                lblMensajeError.Text = exDelNegocio.Message;
                lblMensajeError.Visible = true;
            }
    }
  }
}