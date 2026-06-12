using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Entidades; 
using Negocio; 

namespace Vista.Administrador.AdministrarMedicos
{
    public partial class FormEditarMedico : System.Web.UI.Page
    {
        private NegocioProvincia _negProvincia = new NegocioProvincia();
        private NegocioLocalidad _negLocalidad = new NegocioLocalidad();
        private NegocioEspecialidad _negEspecialidad = new NegocioEspecialidad();
        private NegocioDiaSemana _negDias = new NegocioDiaSemana();
        private NegocioMedico _negMedico = new NegocioMedico();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                lblMensajeExito.Visible = false;
                lblMensajeError.Visible = false;
                hlVolver.Text = "Volver al Listado";

                string legajo = Request.QueryString["legajo"];

                if (string.IsNullOrEmpty(legajo))
                {
                    lblMensajeError.Text = "Error: No se proporcionó un legajo de médico.";
                    lblMensajeError.Visible = true;
                    btnEditarMedico.Visible = false; 
                    return;
                }

                CargarProvincias();
                CargarEspecialidades();
                cargarDiasSemana();

                CargarDatosDelMedico(legajo);
            }
        }

        private void CargarDatosDelMedico(string legajo)
        {
            try
            {
                int idProvincia; // Desde el DAO
                Entidades.Medico medico = _negMedico.GetMedicoPorLegajo(legajo, out idProvincia);

                if (medico == null)
                {
                    lblMensajeError.Text = "Error: No se encontró el médico con el legajo " + legajo;
                    lblMensajeError.Visible = true;
                    btnEditarMedico.Visible = false;
                    return;
                }

                // llenar datos (DNI y Legajo son ReadOnly)
                txtLegajo.Text = medico.Legajo;
                txtDNI.Text = medico.Dni;
                txtNombre.Text = medico.Nombre;
                txtApellido.Text = medico.Apellido;
                txtNacionalidad.Text = medico.Nacionalidad;
                txtDireccion.Text = medico.Direccion;
                txtCorreoElectronico.Text = medico.CorreoElectronico;
                txtTelefono.Text = medico.Telefono;
                txtFechaNacimiento.Text = medico.FechaNacimiento.ToString("yyyy-MM-dd");
                ddlSexo.SelectedValue = medico.Sexo.ToString();
                ddlEspecialidad.SelectedValue = medico.Especialidad.IdEspecialidad.ToString();
                ddlTurnoHorario.SelectedValue = medico.HoraAtencion;
                ddlProvincias.SelectedValue = idProvincia.ToString();
                CargarLocalidades(idProvincia);
                ddlLocalidades.Enabled = true; 
                ddlLocalidades.SelectedValue = medico.Localidad.IdLocalidad.ToString();

                foreach (ListItem item in cblDias.Items)
                {
                    bool trabajaEseDia = medico.DiasSemanaMedico //chequea que dias ya trabaja
                                            .Any(dia => dia.IdDia.ToString() == item.Value);

                    if (trabajaEseDia)
                    {
                        item.Selected = true;
                    }
                }
            }
            catch (Exception ex)
            {
                lblMensajeError.Text = "Error al cargar los datos del médico: " + ex.Message;
                lblMensajeError.Visible = true;
                btnEditarMedico.Visible = false;
            }
        }

        protected void btnEditarMedico_Click(object sender, EventArgs e)
        {
            lblMensajeExito.Visible = false;
            lblMensajeError.Visible = false;

            if (!Page.IsValid)
            {
                return;
            }
            Entidades.Medico objMedico = new Entidades.Medico();

            try
            {
                // Llena el objeto con los datos del form
                // Incluye DNI y Legajo (ReadOnly) porque el SP los necesita para el WHERE
                objMedico.Legajo = txtLegajo.Text.Trim();
                objMedico.Dni = txtDNI.Text.Trim();

                // Datos editables
                objMedico.Nombre = txtNombre.Text.Trim();
                objMedico.Apellido = txtApellido.Text.Trim();
                objMedico.Nacionalidad = txtNacionalidad.Text.Trim();
                objMedico.Direccion = txtDireccion.Text.Trim();
                objMedico.CorreoElectronico = txtCorreoElectronico.Text.Trim();
                objMedico.Telefono = txtTelefono.Text.Trim();
                objMedico.HoraAtencion = ddlTurnoHorario.SelectedValue;
                objMedico.Sexo = Convert.ToChar(ddlSexo.SelectedValue);
                objMedico.FechaNacimiento = DateTime.Parse(txtFechaNacimiento.Text);
                objMedico.Especialidad.IdEspecialidad = Convert.ToInt32(ddlEspecialidad.SelectedValue);
                objMedico.Localidad.IdLocalidad = Convert.ToInt32(ddlLocalidades.SelectedValue);
                objMedico.DiasSemanaMedico.Clear();
                foreach (ListItem item in cblDias.Items)
                {
                    if (item.Selected)
                    {
                        DiasSemana dia = new DiasSemana();
                        dia.IdDia = Convert.ToInt32(item.Value);
                        objMedico.DiasSemanaMedico.Add(dia);
                    }
                }

                // Llamamos a la capa de Negocio para ACTUALIZAR
                bool actualizacionExitosa = _negMedico.ActualizarMedico(objMedico);

                if (actualizacionExitosa)
                {
                    lblMensajeExito.Text = $"¡Médico {objMedico.Nombre} {objMedico.Apellido} (Legajo: {objMedico.Legajo}) actualizado con éxito!";
                    lblMensajeExito.Visible = true;

                    btnEditarMedico.Visible = false; 
                    hlVolver.Visible = true;   
                }
                else
                {
                    lblMensajeError.Text = "Error desconocido al actualizar en la base de datos (SP devolvió 0).";
                    lblMensajeError.Visible = true;
                }
            }
            catch (Exception exDelNegocio)
            {
                lblMensajeError.Text = exDelNegocio.Message;
                lblMensajeError.Visible = true;
            }
        }


        // Estos métodos son idénticos a los de FormAgregarMedico.aspx.cs
      
        private void cargarLocalidadesFalse()
        {
            ddlLocalidades.Enabled = false;
            ddlLocalidades.Items.Clear();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Primero seleccione una provincia --", "0"));
        }

        private void CargarEspecialidades()
        {
            ddlEspecialidad.DataSource = _negEspecialidad.Listar();
            ddlEspecialidad.DataTextField = "DescripcionEspecialidad";
            ddlEspecialidad.DataValueField = "IdEspecialidad";
            ddlEspecialidad.DataBind();
            ddlEspecialidad.Items.Insert(0, new ListItem("-- Seleccione una especialidad --", "0"));
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
            ddlLocalidades.DataSource = _negLocalidad.ListarLocalidadesPorProvincia(idProvincia);
            ddlLocalidades.DataTextField = "NombreLocalidad";
            ddlLocalidades.DataValueField = "IdLocalidad";
            ddlLocalidades.DataBind();
            ddlLocalidades.Items.Insert(0, new ListItem("-- Seleccione una localidad --", "0"));
        }

        private void cargarDiasSemana()
        {
            cblDias.DataSource = _negDias.Listar();
            cblDias.DataTextField = "NombreDia";
            cblDias.DataValueField = "IdDia";
            cblDias.DataBind();
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
                CargarLocalidades(idProvinciaSeleccionada);
                ddlLocalidades.Enabled = true;
            }
        }

    }
}