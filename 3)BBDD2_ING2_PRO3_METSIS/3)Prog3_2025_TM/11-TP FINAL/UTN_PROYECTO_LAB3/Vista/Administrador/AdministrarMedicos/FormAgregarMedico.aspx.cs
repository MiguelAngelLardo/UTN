using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Web;
using System.Web.Services.Description;
using System.Web.UI;
using System.Web.UI.WebControls;

using Entidades; //para clase medico
using Negocio; //para capa negocio
namespace Vista.Administrador.AdministrarMedicos
{
  public partial class FormAgregarMedico : System.Web.UI.Page
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
        cargarLocalidadesFalse(); //localidades deshabilitadas hasta que se seleccione una provincia
        CargarProvincias();
        CargarEspecialidades();
        CargarDiasSemana();
      }
    }

    private void cargarLocalidadesFalse()
    {
      ddlLocalidades.Enabled = false;//ddl en "sombra"
      ddlLocalidades.Items.Clear();//puedo sacarlo pero lo deja por claridad visual
      ddlLocalidades.Items.Insert(0, new ListItem("-- Primero seleccione una provincia --", "0"));
    }

    private void CargarEspecialidades()
    {
      ddlEspecialidad.DataSource = _negEspecialidad.Listar();//retorna System.Data.DataTable
      ddlEspecialidad.DataTextField = "DescripcionEspecialidad"; //Descripcion_E AS DescripcionEspecialidad\r\n 
      ddlEspecialidad.DataValueField = "IdEspecialidad"; //IdEspecialidad_E AS IdEspecialidad,
      ddlEspecialidad.DataBind();
      ddlEspecialidad.Items.Insert(0, new ListItem("-- Seleccione una especialidad --", "0"));
    }

    private void CargarProvincias()
    {

      ddlProvincias.DataSource = _negProvincia.Listar();
      ddlProvincias.DataTextField = "NombreProvincia"; //Nombre_Pr AS NombreProvincia
      ddlProvincias.DataValueField = "IdProvincia"; // IdProvincia_Pr AS IdProvincia
      ddlProvincias.DataBind();
      ddlProvincias.Items.Insert(0, new ListItem("-- Seleccione una provincia --", "0")); // el data bind borra lo anterior por eso no va antes
    }

    private void CargarLocalidadesPorProvincia(int idProvincia)
    {
      ddlLocalidades.Enabled = true;//ddl en "sombra"
      ddlLocalidades.DataSource = _negLocalidad.ListarLocalidadesPorProvincia(idProvincia);
      ddlLocalidades.DataTextField = "NombreLocalidad"; //Nombre_L AS NombreLocalidad
      ddlLocalidades.DataValueField = "IdLocalidad"; //IdLocalidad_L AS IdLocalidad
      ddlLocalidades.DataBind();
      ddlLocalidades.Items.Insert(0, new ListItem("-- Seleccione una localidad --", "0"));
    }

    private void CargarDiasSemana()
    {
      cblDias.DataSource = _negDias.Listar();
      cblDias.DataTextField = "NombreDia"; //Nombre_D AS NombreDia
      cblDias.DataValueField = "IdDia"; //IdDia_D AS IdDia
      cblDias.DataBind();
    }

    private void LimpiarFormulario()
    {
      txtLegajo.Text = string.Empty;
      txtDNI.Text = string.Empty;
      txtNombre.Text = string.Empty;
      txtApellido.Text = string.Empty;
      txtNacionalidad.Text = string.Empty;
      txtDireccion.Text = string.Empty;
      txtCorreoElectronico.Text = string.Empty;
      txtTelefono.Text = string.Empty;
      txtFechaNacimiento.Text = string.Empty;

      ddlTurnoHorario.SelectedIndex = 0;
      ddlSexo.SelectedIndex = 0;
      ddlEspecialidad.SelectedIndex = 0;
      ddlProvincias.SelectedIndex = 0;
      ddlLocalidades.Items.Clear(); // Limpiamos y deshabilitamos
      ddlLocalidades.Enabled = false;

      foreach (ListItem item in cblDias.Items)
      {
        item.Selected = false;
      }
    }

    protected void ddlProvincias_SelectedIndexChanged(object sender, EventArgs e)
    {
      int idProvinciaSeleccionada = Convert.ToInt32(ddlProvincias.SelectedValue);

      if (idProvinciaSeleccionada == 0) cargarLocalidadesFalse();
      else CargarLocalidadesPorProvincia(idProvinciaSeleccionada);//Si eligió una provincia real, cargamos las localidades
    }



    protected void btnGuardarMedico_Click(object sender, EventArgs e)
    {
      lblMensajeExito.Visible = false;//si  dio error por que estaba cargado y desp lo carga se borra el msj de error
      lblMensajeError.Visible = false;

      if (!Page.IsValid)//valido los required fields
      {
        return;
      }

      
      Entidades.Medico objMedico = new Entidades.Medico(); //pongo la ruta completa por que se confunde con la carpeta

      objMedico.Legajo = txtLegajo.Text.Trim();
      objMedico.Dni = txtDNI.Text.Trim();
      objMedico.Nombre = txtNombre.Text.Trim();
      objMedico.Apellido = txtApellido.Text.Trim();
      objMedico.Nacionalidad = txtNacionalidad.Text.Trim();
      objMedico.Direccion = txtDireccion.Text.Trim();
      objMedico.CorreoElectronico = txtCorreoElectronico.Text.Trim();
      objMedico.Telefono = txtTelefono.Text.Trim();

      objMedico.HoraAtencion = ddlTurnoHorario.SelectedValue;
      objMedico.Sexo = Convert.ToChar(ddlSexo.SelectedValue); //casteo a char
      objMedico.FechaNacimiento = DateTime.Parse(txtFechaNacimiento.Text);//persona usa DateTime

      objMedico.Especialidad.IdEspecialidad = Convert.ToInt32(ddlEspecialidad.SelectedValue);//composicion
      objMedico.Localidad.IdLocalidad = Convert.ToInt32(ddlLocalidades.SelectedValue); //composicion

      objMedico.DiasSemanaMedico.Clear(); // limpiamos la lista 
      foreach (ListItem item in cblDias.Items)
      {
        if (item.Selected)//si el check esta seleccionado
        {
          DiasSemana dia = new DiasSemana();
          dia.IdDia = Convert.ToInt32(item.Value);
          dia.NombreDia = item.Text; //no es necesario por que no se usa en la bbdd...igual lo voy a guardar
          objMedico.DiasSemanaMedico.Add(dia); //composicion y List
        }
      }

      try
      {
        bool cargaExitosa = _negMedico.AgregarMedico(objMedico);

        if (cargaExitosa)
        {
          lblMensajeExito.Text = $"Médico {objMedico.Nombre} {objMedico.Apellido} (Legajo: {objMedico.Legajo}) guardado con éxito!";
          lblMensajeExito.Visible = true;

          btnGuardarMedico.Visible = false;
          hlVolver.Visible = true;
          LimpiarFormulario();
        }
        else
        {
          lblMensajeError.Text = "Error desconocido al guardar en la base de datos.";// solo pasa si el SP falla pero no por DNI/Legajo => casi imposible
          lblMensajeError.Visible = true;
        }
      }
      catch (Exception exDelNegocio)//atrapo el error de mas "abajo"
      {
        lblMensajeError.Text = exDelNegocio.Message;// 'ex.Message' contendrá el texto exacto que lanzaste desde la capa de negocio
        lblMensajeError.Visible = true;
      }


            //bool cargaExitosa = _negMedico.AgregarMedico(objMedico);
            //if (cargaExitosa)
            //{
            //  lblMensajeExito.Text = $"Médico {objMedico.Nombre} {objMedico.Apellido} (Legajo: {objMedico.Legajo}) guardado con éxito!";
            //  lblMensajeExito.Visible = true;
        
            //  // Ocultamos el botón de guardar y mostramos el de "Volver"
            //  btnGuardarMedico.Visible = false;
            //  hlVolver.Visible = true;

            //  LimpiarFormulario();
            //}
            //else
            //{
            //  lblMensajeError.Text = "Medico existente";
            //  lblMensajeError.Visible = true;
            //}
    }

  }
}

