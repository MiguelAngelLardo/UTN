using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Entidades;

namespace Vista.Administrador.AdministrarPacientes
{
    public partial class FormEditarPaciente : System.Web.UI.Page
    {
        private NegocioProvincia _negProvincia = new NegocioProvincia();
        private NegocioLocalidad _negLocalidad = new NegocioLocalidad();
        private NegocioPaciente _negocioPaciente = new NegocioPaciente();
      
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblMensajeExito.Visible = false;
                lblMensajeError.Visible = false;

                string dniQuery = Request.QueryString["dni"];

                if (string.IsNullOrEmpty(dniQuery))
                {
                    lblMensajeError.Text = "Error: No se proporcionó un DNI de paciente.";
                    lblMensajeError.Visible = true;
                    btnGuardarCambios.Visible = false;
                    return;
                }
                CargarProvincias();
                CargarDatosPaciente(dniQuery);
            }
        }

        private void CargarDatosPaciente(string dni)
        {
            try
            {
                int idProvincia;

                Entidades.Paciente paciente = _negocioPaciente.GetPacientePorDni(dni, out idProvincia);

                if (paciente == null)
                {
                    lblMensajeError.Text = "Error: No se encontró el paciente con DNI " + dni;
                    lblMensajeError.Visible = true;
                    btnGuardarCambios.Visible = false;
                    return;
                }

                txtDNI.Text = paciente.Dni;
                txtNombre.Text = paciente.Nombre;
                txtApellido.Text = paciente.Apellido;
                txtDireccion.Text = paciente.Direccion;
                txtCorreoElectronico.Text = paciente.CorreoElectronico;
                txtTelefono.Text = paciente.Telefono;
                txtNacionalidad.Text = paciente.Nacionalidad;
                txtDiagnostico.Text = paciente.Diagnostico;
                txtFechaNacimiento.Text = paciente.FechaNacimiento.ToString("yyyy-MM-dd");
                ddlSexo.SelectedValue = paciente.Sexo.ToString();
                ddlProvincias.SelectedValue = idProvincia.ToString();
                cargarLocalidades(idProvincia);
                ddlLocalidades.SelectedValue = paciente.Localidad.IdLocalidad.ToString();
            }
            catch (Exception ex)
            {
                lblMensajeError.Text = "Error al cargar datos del paciente: " + ex.Message;
                lblMensajeError.Visible = true;
            }
        }


        private void CargarProvincias()
        {
            ddlProvincias.DataSource = _negProvincia.Listar();

            ddlProvincias.DataTextField = "NombreProvincia";
            ddlProvincias.DataValueField = "IdProvincia";

            ddlProvincias.DataBind();
            ddlProvincias.Items.Insert(0, new ListItem("-- Seleccione una provincia --", "0"));
        }

        private void cargarLocalidades(int idProvincia)
        {
            string provinciaStr = ddlProvincias.SelectedValue;
            ddlLocalidades.DataSource = _negLocalidad.ListarLocalidadesPorProvincia(idProvincia);
            ddlLocalidades.DataTextField = "NombreLocalidad";
            ddlLocalidades.DataValueField = "IdLocalidad";
            ddlLocalidades.DataBind();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Seleccione una localidad --", "0"));
        }
        private void cargarLocalidadesFalse()
        {
            ddlLocalidades.Enabled = false;
            ddlLocalidades.Items.Clear();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Primero seleccione una provincia --", "0"));
        }

        protected void ddlProvincias_SelectedIndexChanged(object sender, EventArgs e)
        {
            int idProvinciaSeleccionada = Convert.ToInt32(ddlProvincias.SelectedValue);
            if (idProvinciaSeleccionada == 0)
            {
                cargarLocalidadesFalse();
            }
            else
            {
                cargarLocalidades(idProvinciaSeleccionada);
                ddlLocalidades.Enabled = true;
            }
        }

        protected void btnGuardarCambios_Click(object sender, EventArgs e)
        {
            lblMensajeExito.Visible = false;
            lblMensajeError.Visible = false;

            if (!Page.IsValid)
            {
                return;
            }

            try
            {
                Entidades.Paciente paciente = new Entidades.Paciente();
                paciente.Localidad = new Entidades.Localidad();

                paciente.Dni = txtDNI.Text.Trim();

                paciente.Nombre = txtNombre.Text.Trim();
                paciente.Apellido = txtApellido.Text.Trim();
                paciente.Nacionalidad = txtNacionalidad.Text.Trim();
                paciente.Direccion = txtDireccion.Text.Trim();
                paciente.CorreoElectronico = txtCorreoElectronico.Text.Trim();
                paciente.Telefono = txtTelefono.Text.Trim();
                paciente.Sexo = Convert.ToChar(ddlSexo.SelectedValue);
                paciente.FechaNacimiento = Convert.ToDateTime(txtFechaNacimiento.Text);
                paciente.Localidad.IdLocalidad = Convert.ToInt32(ddlLocalidades.SelectedValue);
                paciente.Diagnostico = txtDiagnostico.Text.Trim();

                int filasAfectadas = _negocioPaciente.EditarPaciente(paciente);

                if (filasAfectadas > 0)
                {
                    lblMensajeExito.Text = $"Paciente {paciente.Nombre} {paciente.Apellido} (DNI: {paciente.Dni}) actualizado con éxito!";
                    lblMensajeExito.Visible = true;
                    btnGuardarCambios.Visible = false;
                    hlVolver.Visible = true;
                }
                else
                {
                    lblMensajeError.Text = "Error: No se realizaron cambios o el paciente no existe.";
                    lblMensajeError.Visible = true;
                }

            }
            catch (Exception ex)
            {
                lblMensajeError.Text = "Error al guardar paciente: " + ex.Message;
                lblMensajeError.Visible = true;
                System.Diagnostics.Debug.WriteLine("Error al guardar paciente: " + ex.Message);
            }
        }
    }
}
