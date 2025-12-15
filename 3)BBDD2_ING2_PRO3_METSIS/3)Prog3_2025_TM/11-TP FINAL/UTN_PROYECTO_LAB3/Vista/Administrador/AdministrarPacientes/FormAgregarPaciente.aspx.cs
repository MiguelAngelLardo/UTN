using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Entidades; 
using Negocio; 

namespace Vista.Administrador.AdministrarPacientes
{
    public partial class FormAgregarPaciente : System.Web.UI.Page
    {
        private NegocioProvincia _negProvincia = new NegocioProvincia();
        private NegocioLocalidad _negLocalidad = new NegocioLocalidad();
        private NegocioPaciente _negPaciente = new NegocioPaciente();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblMensajeExito.Visible = false;
                lblMensajeError.Visible = false;

                CargarProvincias();
                cargarLocalidadesFalse();
            }
        }

        #region "Carga de DropDownLists"

        private void cargarLocalidadesFalse() //localidades deshabilitadas hasta que se seleccione una provincia
        {
            ddlLocalidades.Enabled = false;
            ddlLocalidades.Items.Clear();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Primero seleccione una provincia --", "0"));
        }

        private void CargarProvincias()
        {
            ddlProvincias.DataSource = _negProvincia.Listar();
            ddlProvincias.DataTextField = "NombreProvincia";
            ddlProvincias.DataValueField = "IdProvincia";
            ddlProvincias.DataBind();
            ddlProvincias.Items.Insert(0, new ListItem("-- Seleccione una provincia --", "0"));
        }

        private void CargarLocalidades(int idProvincia)
        {
            ddlLocalidades.DataSource = _negLocalidad.ListarLocalidadesPorProvincia(idProvincia);  //carga basado en provincia seleccionada
            ddlLocalidades.DataTextField = "NombreLocalidad";
            ddlLocalidades.DataValueField = "IdLocalidad";
            ddlLocalidades.DataBind();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Seleccione una localidad --", "0"));
        }

        #endregion

        #region "Eventos"

        protected void ddlProvincias_SelectedIndexChanged(object sender, EventArgs e)
        {
            int idProvinciaSeleccionada = Convert.ToInt32(ddlProvincias.SelectedValue);

            if (idProvinciaSeleccionada == 0)
            {
                cargarLocalidadesFalse();
            }
            else
            {
                CargarLocalidades(idProvinciaSeleccionada);
                ddlLocalidades.Enabled = true;
            }
        }

        protected void btnGuardar_Click(object sender, EventArgs e)
        { 
            lblMensajeExito.Visible = false;
            lblMensajeError.Visible = false;

            if (!Page.IsValid)
            {
                return;
            }

            Entidades.Paciente objPaciente = new Entidades.Paciente();

            objPaciente.Dni = txtDNI.Text.Trim();
            objPaciente.Nombre = txtNombre.Text.Trim();
            objPaciente.Apellido = txtApellido.Text.Trim();
            objPaciente.Nacionalidad = txtNacionalidad.Text.Trim();
            objPaciente.Direccion = txtDireccion.Text.Trim();
            objPaciente.CorreoElectronico = txtCorreoElectronico.Text.Trim();
            objPaciente.Telefono = txtTelefono.Text.Trim();
            objPaciente.Diagnostico = txtDiagnostico.Text.Trim(); 

            objPaciente.Sexo = Convert.ToChar(ddlSexo.SelectedValue);
            objPaciente.FechaNacimiento = DateTime.Parse(txtFechaNacimiento.Text);
           
            objPaciente.Localidad.IdLocalidad = Convert.ToInt32(ddlLocalidades.SelectedValue);
            objPaciente.Estado = true;

            // try-catch para llamar a la capa de Negocio
            try
            {
                bool cargaExitosa = _negPaciente.AgregarPaciente(objPaciente);

                if (cargaExitosa)
                {
                    lblMensajeExito.Text = $"¡Paciente {objPaciente.Nombre} {objPaciente.Apellido} (DNI: {objPaciente.Dni}) guardado con éxito!";
                    lblMensajeExito.Visible = true;
 
                    btnGuardar.Visible = false;
                    hlVolver.Visible = true;    

                    LimpiarFormulario();
                }
                else
                {
                    lblMensajeError.Text = "Error desconocido al guardar en la base de datos.";
                    lblMensajeError.Visible = true;
                }
            }
            catch (Exception exDelNegocio) // Aquí atrapamos el error de DNI duplicado
            {
                lblMensajeError.Text = exDelNegocio.Message;
                lblMensajeError.Visible = true;
            }
        }

        #endregion

        #region "Limpieza de Formulario"

   
        private void LimpiarFormulario() // Resetea todos los campos del formulario
        {
            txtDNI.Text = string.Empty;
            txtNombre.Text = string.Empty;
            txtApellido.Text = string.Empty;
            txtNacionalidad.Text = string.Empty;
            txtDireccion.Text = string.Empty;
            txtCorreoElectronico.Text = string.Empty;
            txtTelefono.Text = string.Empty;
            txtFechaNacimiento.Text = string.Empty;
            txtDiagnostico.Text = string.Empty;

            ddlSexo.SelectedIndex = 0;
            ddlProvincias.SelectedIndex = 0;

            ddlLocalidades.Items.Clear();
            ddlLocalidades.Enabled = false;
        }

        #endregion
    }
}

