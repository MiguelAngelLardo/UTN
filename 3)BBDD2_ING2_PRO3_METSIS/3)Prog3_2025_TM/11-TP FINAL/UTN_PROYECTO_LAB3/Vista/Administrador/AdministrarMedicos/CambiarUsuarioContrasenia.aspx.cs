using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarMedicos
{
    public partial class CambiarUsuarioContrasenia : System.Web.UI.Page
    {
        NegocioMedico negocioMedico = new NegocioMedico();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                obtenerLegajoMedico();
                obtenerNombreUsuario();
                divCambioUsuario.Visible = true;
                divCambioContraseña.Visible = false;
            }
        }
        protected void obtenerLegajoMedico()
        {
            string legajo = Request.QueryString["legajo"];
            if (!string.IsNullOrEmpty(legajo))
            {
                txtLegajoMedicoCambio.Text = legajo;
                txtLegajoMedicoCambio.ReadOnly = true;
            }
        }
        protected void obtenerNombreUsuario()
        {             
            string legajo = Request.QueryString["legajo"];
            if (!string.IsNullOrEmpty(legajo))
            {
                string nombreUsuario = negocioMedico.ObtenerNombreUsuarioPorLegajo(legajo);
                txtUsuarioCambio.Text = nombreUsuario;
            }
        }
        protected void radioOpcionCambio_SelectedIndexChanged(object sender, EventArgs e)
        {
            // Alternar visibilidad según opción seleccionada
            string opcion = radioOpcionCambio.SelectedValue;

            divCambioUsuario.Visible = opcion == "Usuario";
            divCambioContraseña.Visible = opcion == "Contraseña";
            lblMensajeExito.Text = "";
            lblMensajeError.Text = "";
        }
        protected void cambioUsuario()
        {
            string legajo = Request.QueryString["legajo"];
            Entidades.Medico medico = new Entidades.Medico();
            medico.Legajo = legajo;
            string nuevoUsuario = txtUsuarioCambio.Text;
            medico.Login.NombreUsuario = nuevoUsuario;
            try
            {
                bool cambiado = negocioMedico.CambiarUsuario(medico);

                if (cambiado)
                {
                    txtUsuarioCambio.Text = "";
                    lblMensajeError.Visible = false;
                    lblMensajeExito.Visible = true;
                    lblMensajeExito.Text = "Usuario cambiado a: " + nuevoUsuario;

                }
                else
                {
                    txtUsuarioCambio.Text = "";
                    lblMensajeExito.Visible = false;
                    lblMensajeError.Visible = true;
                    lblMensajeError.Text = "Error al cambiar el usuario. Verifique los datos e intente nuevamente.";
                }
            }
            catch (Exception exDelNegocio)
            {
                lblMensajeError.Text = exDelNegocio.Message;
                lblMensajeError.Visible = true;
            }
        }
        protected void cambioContrasenia()
        {
            string legajo = Request.QueryString["legajo"];
            Entidades.Medico medico = new Entidades.Medico();
            medico.Legajo = legajo;
            string nuevaContraseña = txtContraseñaCambio.Text;
            medico.Login.Contrasenia = nuevaContraseña;
            try
            {
                bool cambiado = negocioMedico.CambiarContrasenia(medico);
                if (cambiado)
                {
                    txtContraseñaCambio.Text = "";
                    txtRepitaContraseñaCambio.Text = "";
                    lblMensajeError.Visible = false;
                    lblMensajeExito.Visible = true;
                    lblMensajeExito.Text = "Contraseña cambiada exitosamente.";
                }
                else
                {
                    txtContraseñaCambio.Text = "";
                    txtRepitaContraseñaCambio.Text = "";
                    lblMensajeExito.Visible = false;
                    lblMensajeError.Visible = true;
                    lblMensajeError.Text = "Error al cambiar la contraseña. Verifique los datos e intente nuevamente.";
                }
            }
            catch (Exception exDelNegocio)
            {
                lblMensajeError.Text = exDelNegocio.Message;
                lblMensajeError.Visible = true;
            }

        }
        protected void btnGuardarCambio_Click(object sender, EventArgs e)
        {
            string opcion = radioOpcionCambio.SelectedValue;
          
           
            if (opcion == "Usuario")
            {
               cambioUsuario();
            }
            else if (opcion == "Contraseña")
            {
                cambioContrasenia();
            }
        }

    }
}