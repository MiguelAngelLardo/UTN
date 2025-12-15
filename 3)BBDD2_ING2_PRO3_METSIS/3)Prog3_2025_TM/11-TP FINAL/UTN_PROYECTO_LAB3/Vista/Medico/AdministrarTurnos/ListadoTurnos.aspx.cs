using System;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;
using Negocio;

namespace Vista.Medico.AdministrarTurno
{
  public partial class ListadoTurnos : System.Web.UI.Page
  {
    private NegocioTurno _negTurno = new NegocioTurno();
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        CargarGridTurnosMedico();
      }
    }

    private void CargarGridTurnosMedico()
    {
      string usuario = Session["UsuarioLogueado"]?.ToString(); // El ? evita error si es null
      if (usuario != null)
      {
        gvTurnos.DataSource = _negTurno.ListarTablaTurnoMedico(usuario);
        gvTurnos.DataBind();
      }
    }

    private void HabilitarTextBoxPorDdl(DropDownList ddlAsistencia, TextBox txtObservaciones)
    {
      string selectedValue = ddlAsistencia.SelectedValue;

      if (selectedValue == "-1")
      {
        txtObservaciones.Enabled = false;
        txtObservaciones.Text = string.Empty; // Limpiamos el texto al deshabilitar
        txtObservaciones.Attributes["placeholder"] = "Debe seleccionar 'Asistió/No Asistió'";
      }
      else
      {
        txtObservaciones.Enabled = true;

        if (selectedValue == "0" && string.IsNullOrEmpty(txtObservaciones.Text))
        {
          txtObservaciones.ReadOnly = true;
          txtObservaciones.Attributes["placeholder"] = "Presione Enter para confirmar 'No asistió'.";

        }else if(selectedValue == "0" && !string.IsNullOrEmpty(txtObservaciones.Text))
        {
          txtObservaciones.Text = "";//limpio
          txtObservaciones.Attributes["placeholder"] = "Observación cargada (Solo lectura)";
          txtObservaciones.ReadOnly = true;
        }
        else //if(selectedValue == "1")
        {
          txtObservaciones.Text = "";//limpio
          txtObservaciones.Attributes["placeholder"] = "Escriba aquí y presione Enter.";
          txtObservaciones.ReadOnly = false;
        }
      }
    }


    protected void gvTurnos_RowDataBound(object sender, GridViewRowEventArgs e)//se ejecuta una vez al iniciar carga y cada vez que hago SelectedIndexChanged.
    {
      if (e.Row.RowType == DataControlRowType.DataRow)//DataRow es para no ir al Header, footer o Pager y solo al DataTable con informacion real
      {
        TextBox pTextBox = (TextBox)e.Row.FindControl("txtObservaciones");//pTextBox es un puntero de Tipo TxtBox que apunta a 
        DropDownList pDdlAsistencia = (DropDownList)e.Row.FindControl("ddlAsistencia");
        DataRowView drv = (DataRowView)e.Row.DataItem;//ya cargue todo con gvTurnos.DataSource = _negTurno.ListarTablaTurnoMedico(usuario); => ahora el DataItem me guarda lo de todo la fila
                                                      //el DataBind me hace de While
                                                     

        DateTime fechaTurno = (DateTime)drv["Dia"]; //Obtener la Fecha
        bool esTurnoPasado = fechaTurno.Date < DateTime.Today.Date;

        //Cargar Observacion y Estado
        if (drv["Observacion"] != DBNull.Value) { pTextBox.Text = drv["Observacion"].ToString(); } //SELECT Observacion_T AS Observacion
        string selectedValue = "-1";
        if (drv["Atendido"] != DBNull.Value) { selectedValue = Convert.ToBoolean(drv["Atendido"]) ? "1" : "0"; }//T.Atendido_T AS Atendido,
        pDdlAsistencia.SelectedValue = selectedValue;

        if (!esTurnoPasado && string.IsNullOrEmpty(pTextBox.Text))//si esta vacio (por que es actual) modifico solo los txt actuales y los txt pasados quedan igual bbdd
        {
          HabilitarTextBoxPorDdl(pDdlAsistencia, pTextBox);
        }

        if (esTurnoPasado)// Bloquea edición y colorea si el día YA paso
        {
          e.Row.CssClass = "turno-pasado";
          pTextBox.Enabled = false;
          pDdlAsistencia.Enabled = false;
        }
        else//si es hoy o futuro el turno => y aprobado y aca no va HabilitarTextBoxPorDdl(pDdlAsistencia, pTextBox);
        {
          pDdlAsistencia.Enabled = true;
        }
      }
    }


    protected void ddlAsistencia_SelectedIndexChanged(object sender, EventArgs e)//se ejecuta en cada click del ddl
    {
      DropDownList pDdlAsistencia = (DropDownList)sender; //Obtener el DDL que disparó el evento
      
      //Obtener la Fila del DDL
      GridViewRow fila = (GridViewRow)pDdlAsistencia.NamingContainer; //Encontrar la fila(GridViewRow) que contiene este DDL
      TextBox txtObservaciones = (TextBox)fila.FindControl("txtObservaciones"); //Encontrar el TextBox en esa misma fila

      HabilitarTextBoxPorDdl(pDdlAsistencia, txtObservaciones);
    }


    protected void gvTurnos_RowCommand(object sender, GridViewCommandEventArgs e) //RowCommand Se dispara al hacer clic en los botones de la grilla
    {
      // Limpiar mensajes anteriores antes de cualquier acción
      lblEstadoTurno.Visible = false;
      lblErrorTurno.Visible = false;

      if (e.CommandName == "Guardar")
      {
        int idTurno = Convert.ToInt32(e.CommandArgument);
        GridViewRow row = (GridViewRow)((Button)e.CommandSource).NamingContainer;

        TextBox pTextBox = (TextBox)row.FindControl("txtObservaciones");
        DropDownList pDdlAsistencia = (DropDownList)row.FindControl("ddlAsistencia");

        bool asistio = pDdlAsistencia.SelectedValue == "1";
        string observacion = pTextBox.Text;

        if (asistio && string.IsNullOrEmpty(observacion.Trim()))// Usamos .Trim() para validar que no sean solo espacios
        {
          lblErrorTurno.Text = "❌ Debe ingresar una observación si el paciente asistió.";
          lblErrorTurno.Visible = true;
          return;
        }


        bool exito = _negTurno.ActualizarAtencion(idTurno, observacion, asistio);//en regla de negocio si es No asistio completa Observaciones como tal
        if (exito)
        {
          string estado = asistio ? "ASISTIÓ" : "NO ASISTIÓ";
          lblEstadoTurno.Text = $"✅ Turno N° {idTurno} registrado como {estado}.";
          lblEstadoTurno.Visible = true;
          CargarGridTurnosMedico();
        }
        else
        {
          lblErrorTurno.Text = "❌ Error al actualizar el turno.";
          lblErrorTurno.Visible = true;
          CargarGridTurnosMedico();
        }
      }    
    }

    protected void gvTurnos_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvTurnos.PageIndex = e.NewPageIndex;
        CargarGridTurnosMedico();
    }

   protected void btnBuscar_Click(object sender, EventArgs e)
        {
            if (lblEstadoTurno.Visible)
            {
                lblEstadoTurno.Visible = false;
            }
            string nombre = txtBuscarPorPaciente.Text.Trim();
            string usuario = Session["UsuarioLogueado"]?.ToString();
            if (nombre == "")
            {
                CargarGridTurnosMedico();
                lblErrorTurno.Visible = false;
                return;
            }
            else
            {
                DataTable dtTurnos = _negTurno.BuscarTurnoPorPaciente(nombre, usuario);
                if (dtTurnos.Rows.Count == 0)
                {
                    lblErrorTurno.Text = "No se encontraron turnos para el paciente buscado.";
                    lblErrorTurno.Visible = true;
                    return;
                }
                else
                {
                    lblErrorTurno.Visible = false;
                    gvTurnos.DataSource = dtTurnos;
                    gvTurnos.DataBind();
                    return;
                }
            }
        }
        protected void btnAplicarFiltros_Click(object sender, EventArgs e) 
        {
            if (lblEstadoTurno.Visible)
            {
                lblEstadoTurno.Visible = false;
            }
            string usuario = Session["UsuarioLogueado"]?.ToString();
            // reviso si hay opcion de asistencia seleccionada
            int asistenciaSeleccionada = Convert.ToInt32(ddlAsistencia.SelectedValue);
            bool filtroAsistencia = asistenciaSeleccionada != -1;
            // reviso si hay fecha
            string fechaSeleccionada = txtFecha.Text;
            bool filtroFecha = !string.IsNullOrEmpty(txtFecha.Text);

            if (!filtroAsistencia && !filtroFecha)
            {
                CargarGridTurnosMedico();
                lblErrorTurno.Visible = false;
                return;
            }

            DataTable dtTurnos = _negTurno.FiltrarTurnos(
              asistenciaSeleccionada,
            fechaSeleccionada,
            usuario
             );
            if (dtTurnos.Rows.Count == 0)
            {
                lblErrorTurno.Text = "No se encontraron turnos para el/los filtros seleccionados.";
                lblErrorTurno.Visible = true;
                return;
            }
            else
            {
                lblErrorTurno.Visible = false;
                gvTurnos.DataSource = dtTurnos;
                gvTurnos.DataBind();
                return;
            }
        }
    }
}
