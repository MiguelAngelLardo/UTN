using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarTurnos
{
  public partial class FormEditarTurno : System.Web.UI.Page
 
  {
        private NegocioEspecialidad _negEspecialidad = new NegocioEspecialidad();
        private NegocioMedico _negMedico = new NegocioMedico();
        private NegocioPaciente _negPac = new NegocioPaciente();
        private NegocioTurno _negTurno = new NegocioTurno();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                RecuperarDatosTurno();               
            }
        }
    protected void RecuperarDatosTurno()
    {
            string idTurno = Request.QueryString["id"];

            if (string.IsNullOrEmpty(idTurno))
            {
                lblMensajeError.Text = "Error: No se proporcionó un ID de turno.";
                lblMensajeError.Visible = true;
                return;
            }

            Entidades.Turno turno = _negTurno.GetDatosTurno(idTurno);

            if(turno == null)
            {
                lblMensajeError.Text = "Error: No se encontró el turno con el ID " + idTurno;
                lblMensajeError.Visible = true;
                return;
            }
            else
            {
                CargarEspecialidades();
                CargarPacientesActivos();
                CargaFormulario(turno);
            }
              
        }
        private void CargaFormulario(Turno turno)
        {   
           //Cargo especialidad del turno
            ddlEspecialidad.SelectedValue = turno.Especialidad.IdEspecialidad.ToString();
            CargarMedicosPorEspecialidad(turno.Especialidad.IdEspecialidad);
            // Selecciono el médico del turno 
            if (ddlMedico.Items.FindByValue(turno.Medico.Legajo) != null) { ddlMedico.SelectedValue = turno.Medico.Legajo; }
            //Seleccion al paciente, dato no editable
            ddlPaciente.SelectedValue = turno.Paciente.Dni;
            ddlPaciente.Enabled = false;
            // guardo en viewstate datos originales oara hora t fecha
            ViewState["FechaOriginalTurno"] = turno.Fecha;
            ViewState["HoraOriginalTurno"] = turno.Hora.ToString(@"hh\:mm");

            DiasHorariosMedico infoMedico = _negMedico.ObtenerDiasYHorarioMedico(turno.Medico.Legajo);
            ViewState["InfoMedicoSeleccionado"] = infoMedico;

            ObtenerHorasMedico(turno.Medico.Legajo, turno.Fecha, turno.Hora.ToString(@"hh\:mm"));

            txtDiaTurno.Text = turno.Fecha.ToString("yyyy-MM-dd");
            ddlHorario.SelectedValue = turno.Hora.ToString(@"hh\:mm");
        }
        private void ObtenerHorasMedico(string legajo, DateTime fecha, string horaOriginal)
        {
            ddlHorario.Items.Clear();
            ddlHorario.Enabled = false;
            lblMensajeError.Visible = false;

            // 1) OBTENER INFO DEL VIEWSTATE (NO volver a ir a BD)
            DiasHorariosMedico infoMedico = ViewState["InfoMedicoSeleccionado"] as DiasHorariosMedico;

            if (infoMedico == null)
            {
                // fallback de seguridad, no debería usarse salvo casos límite
                infoMedico = _negMedico.ObtenerDiasYHorarioMedico(legajo);
                ViewState["InfoMedicoSeleccionado"] = infoMedico;
            }

            if (infoMedico == null || string.IsNullOrEmpty(infoMedico.HorarioBase))
            {
                ddlHorario.Items.Insert(0, new ListItem("-- Sin datos de horario --", "0"));
                return;
            }

            // 2) Validar día
            int idDia = (int)fecha.DayOfWeek;
            if (idDia == 0) idDia = 7;
            string idDiaStr = idDia.ToString();

            if (!infoMedico.IdsDiasTrabajo.Split(',').Contains(idDiaStr))
            {
                ddlHorario.Items.Insert(0, new ListItem("-- No atiende ese día --", "0"));
                return;
            }

            // 3) Generar slots
            List<string> slotsPosibles = GenerarSlotsDesdeHorario(infoMedico.HorarioBase);

            // 4) Horas ocupadas sin la original
            List<string> horasOcupadas = _negMedico
                .ObtenerHorasOcupadas(legajo, fecha)
                .Where(h => h != horaOriginal)
                .ToList();

            // 5) Disponibles
            List<string> horasDisponibles = slotsPosibles
                .Where(slot => !horasOcupadas.Contains(slot))
                .ToList();

            ddlHorario.Items.Insert(0, new ListItem("-- Seleccione la hora --", "0"));

            // 6) Insertar la original primero
            if (!string.IsNullOrEmpty(horaOriginal) && slotsPosibles.Contains(horaOriginal))
            {
                ddlHorario.Items.Add(new ListItem(horaOriginal + " (actual)", horaOriginal));
            }

            // 7) Resto
            foreach (string hora in horasDisponibles)
            {
                if (hora != horaOriginal)
                    ddlHorario.Items.Add(new ListItem(hora, hora));
            }

            ddlHorario.Enabled = true;

            // 8) seleccionar por defecto
            ddlHorario.SelectedValue = horaOriginal;
        }


        private void CargarEspecialidades()
      {
            ddlEspecialidad.DataSource = _negEspecialidad.Listar();//retorna System.Data.DataTable
            ddlEspecialidad.DataTextField = "DescripcionEspecialidad"; //Descripcion_E AS DescripcionEspecialidad\r\n 
            ddlEspecialidad.DataValueField = "IdEspecialidad"; //IdEspecialidad_E AS IdEspecialidad,
            ddlEspecialidad.DataBind();
            // que la seleccionada por defecto sea la del turno que estoy editando
      }
        private void CargarMedicosPorEspecialidad(int idEspecialidad)//medicos x especialidad
        {
            ddlMedico.Enabled = true;//ver de sacarlo
            ddlMedico.DataSource = _negMedico.ListarMedicosPorEspecialidad(idEspecialidad);
            ddlMedico.DataTextField = "NombreCompleto"; //Nombre_P AS NombrePersona
            ddlMedico.DataValueField = "Legajo_M"; //IdEspecialidad_E_M IdEspecialidad
            ddlMedico.DataBind();
            ddlMedico.Items.Insert(0, new ListItem("-- Seleccione un Medico (Solo usuarios habilitados) --", "0"));
        }
        private void CargarPacientesActivos()
        {
            DataTable dtPacientes = _negPac.ListarPacientesActivos();
            dtPacientes.Columns.Add("NombreYdNi", typeof(string)); //agrego columna
            foreach (DataRow fila in dtPacientes.Rows)//objFilaTemporal
            {
                string nombreCompleto = fila["NombreCompleto"].ToString();
                string dni = fila["DNI"].ToString();
                fila["NombreYdNi"] = $"{nombreCompleto} (DNI: {dni})";// le agrego a la ultima columna => Nombre Apellido (DNI: 12345678) en cada iteracion
            }
            ddlPaciente.DataSource = dtPacientes;
            ddlPaciente.DataTextField = "NombreYdNi";
            ddlPaciente.DataValueField = "DNI";
            ddlPaciente.DataBind();
        }
        protected void ddlEspecialidad_SelectedIndexChanged(object sender, EventArgs e)//especialidad == 0 desabilita medico y calendario
        {
            int idEsp = int.Parse(ddlEspecialidad.SelectedValue);// o Convert.ToInt32(ddlEspecialidad.SelectedValue);

            if (idEsp == 0)
            {
                CargarMedicosFalse(); // Deshabilita ddlMedico
                CargarHorariosFalse(); // <--- Deshabilita txtDateCalendario y ddlHorarioDisponible
            }
            else
            {
                CargarMedicosPorEspecialidad(idEsp); // Habilita ddlMedico y lo llena
                CargarHorariosFalse(); // <--- Asegura que txtDateCalendario siga deshabilitado
            }
        }
        private void CargarMedicosFalse()
        {
            ddlMedico.Enabled = false; // ddl en sombra
            ddlMedico.Items.Clear();//puedo sacarlo pero lo dejo por claridad visual
            ddlMedico.Items.Insert(0, new ListItem("-- Primero seleccione una Especialidad --", "0"));
        }
        private void CargarHorariosFalse()
        {
            // Resetear Fecha
            txtDiaTurno.Enabled = false;
            txtDiaTurno.Text = string.Empty;

            // Resetear DDL de Horarios
            ddlHorario.Enabled = false;
            ddlHorario.Items.Clear();

            //Mensaje que indica la dependencia de la fecha:
            ddlHorario.Items.Insert(0, new ListItem("-- Primero seleccione una Fecha --", "0"));
        }


        protected void ddlMedico_SelectedIndexChanged(object sender, EventArgs e)//segun el medico muestra los dias + muestra todos los horarios del medico (no filtra)
        {
            string legajo = ddlMedico.SelectedValue;

            if (legajo != "0")
            {
                DiasHorariosMedico objDiasHsMed = _negMedico.ObtenerDiasYHorarioMedico(legajo);

                if (!string.IsNullOrEmpty(objDiasHsMed.NombresDiasTrabajo))
                {
                    /**** Guardamos el objeto completo para usarlo en el evento de fecha ****/
                    ViewState["InfoMedicoSeleccionado"] = objDiasHsMed;//hay q convertir un objeto en cadena de bytes => le pongo [Serializable] a la clase

                    /**** Cambio LBL del DDL Horarios + Mostrar LBL del footer del main ****/
                    lblHorario.Text = "Horario base: " + objDiasHsMed.HorarioBase;//08:00-12:00 del SP
                   
                    // Habilitar la selección de fecha
                    txtDiaTurno.Enabled = true;
                    txtDiaTurno.Text = string.Empty;

                    EstablecerFechaMinima();
                }
                else//legajo SI, Dias de Trabajo no
                {
                    CargarHorariosFalse();//puede pasar que tenga legajo y no dias?? no... a no ser q lo hacke manual desde el SSMS 
                }
            }
            else//legajo NO
            {
                CargarHorariosFalse();
                ViewState["InfoMedicoSeleccionado"] = null; // Limpiar al deseleccionar
            }

        }
         private void EstablecerFechaMinima()
    {
      string hoy = DateTime.Today.ToString("yyyy-MM-dd");// Obtiene la fecha de hoy en formato yyyy-MM-dd
      txtDiaTurno.Attributes.Add("min", hoy);//atributo min para que el calendario no muestre anteriores
    }

        /// <summary>
        /// Genera una lista de strings con los slots de horario (ej: "08:00", "09:00", etc.)
        /// </summary>
        /// <param name="horarioBase">Cadena con el formato HH:MM-HH:MM (ej: "08:00-12:00")</param>
        /// <param name="duracionTurnoMinutos">Duración de cada slot de turno en minutos (ej: 60)</param>
        /// <returns>Lista de strings con los horarios de inicio de los turnos</returns>
        private List<string> GenerarSlotsDesdeHorario(string horarioBase, int duracionTurnoMinutos = 60)
        {
            List<string> colSoltsHoras = new List<string>();//almacenará las horas de inicio de los turnos ("08:00", "09:00", etc.).

            string[] vRangoHorario = horarioBase.Split('-');// Asegura que el formato es el esperado "//08:00-12:00"
                                                            //partes[0] "08:00" La hora de inicio
                                                            //partes[1] "12:00" La hora de fin

            if (vRangoHorario.Length != 2)//medida de seguridad ya que siempre sera un (vector[2]) de 2 elementos
            {
                return colSoltsHoras;
            }

            //resultado=> horaInicio = 08:00:00  horaFin = 12:00:00
            if (TimeSpan.TryParse(vRangoHorario[0], out TimeSpan horaInicio) && TimeSpan.TryParse(vRangoHorario[1], out TimeSpan horaFin))//TimeSpan. Es más seguro que Convert.ToTimeSpan() porque no lanza una excepción si la conversión falla; simplemente devuelve false.
            {
                TimeSpan duracionTurno = TimeSpan.FromMinutes(duracionTurnoMinutos);//le paso el 60 por parametro
                                                                                    //TimeSpan.FromMinutes(22) => duracionTurno es 00:22:00. => hace el rollover automatico 

                TimeSpan horaActual = horaInicio;
                while (horaActual.Add(duracionTurno) <= horaFin)//Ejemplo (Iteración 1): 08:00:00.Add(01:00:00) = 09:00:00.
                {
                    colSoltsHoras.Add(horaActual.ToString(@"hh\:mm"));//guarda  08:00:00 como "08:00", hasta "11:00"
                    horaActual = horaActual.Add(duracionTurno);
                }
            }
            return colSoltsHoras;
        }

        protected void txtDiaTurno_TextChanged(object sender, EventArgs e)
        {
            string legajo = ddlMedico.SelectedValue;

            lblMensajeError.Visible = false;
            ddlHorario.Items.Clear();
            ddlHorario.Enabled = false;

            if (legajo == "0" || ViewState["InfoMedicoSeleccionado"] == null || string.IsNullOrEmpty(txtDiaTurno.Text))
            {
                ddlHorario.Items.Insert(0, new ListItem("-- Error de selección --", "0"));
                return;
            }

            // ★ Recupero info del médico
            DiasHorariosMedico objDiasHsMedYaCargado = (DiasHorariosMedico)ViewState["InfoMedicoSeleccionado"];

            // ★ Fecha nueva seleccionada
            DateTime fechaTurno = Convert.ToDateTime(txtDiaTurno.Text);
            int idDiaSeleccionado = (int)fechaTurno.DayOfWeek;
            if (idDiaSeleccionado == 0) idDiaSeleccionado = 7;
            string idDiaSeleccionadoStr = idDiaSeleccionado.ToString();

            // Recupero info del turno ORIGINAL de forma segura
            DateTime fechaOriginal = DateTime.MinValue;
            string horaOriginal = string.Empty;

            if (ViewState["FechaOriginalTurno"] != null)
            {
                DateTime.TryParse(ViewState["FechaOriginalTurno"].ToString(), out fechaOriginal);
            }

            if (ViewState["HoraOriginalTurno"] != null)
            {
                horaOriginal = ViewState["HoraOriginalTurno"].ToString();
            }
            // 1) Validación de día laboral
            if (!objDiasHsMedYaCargado.IdsDiasTrabajo.Split(',').Contains(idDiaSeleccionadoStr))
            {
                lblMensajeError.Text = $"El Dr. no atiende el día {fechaTurno.ToString("dddd", new System.Globalization.CultureInfo("es-ES"))}. Seleccione otro día.";
                lblMensajeError.Visible = true;
                ddlHorario.Items.Insert(0, new ListItem("-- Día no laborable --", "0"));
                return;
            }

            // 2) Slots del horario base
            List<string> slotsPosibles = GenerarSlotsDesdeHorario(objDiasHsMedYaCargado.HorarioBase);

            // 3) Horas ocupadas
            List<string> horasOcupadas = _negMedico.ObtenerHorasOcupadas(legajo, fechaTurno);

            // ⚠ IMPORTANTE: si la fecha NO cambió y fechaOriginal fue proporcionada, la hora original NO se elimina
            if (fechaOriginal != DateTime.MinValue && fechaTurno == fechaOriginal)
            {
                horasOcupadas = horasOcupadas.Where(h => h != horaOriginal).ToList();
            }


            // 4) Filtrar horas disponibles
            List<string> horasDisponibles = slotsPosibles.Where(slot => !horasOcupadas.Contains(slot)).ToList();

            ddlHorario.Items.Insert(0, new ListItem("-- Seleccione la hora --", "0"));

            //  insertar la hora original:
            if (fechaOriginal != DateTime.MinValue && fechaTurno == fechaOriginal && slotsPosibles.Contains(horaOriginal))
            {
                ddlHorario.Items.Add(new ListItem(horaOriginal + " (actual)", horaOriginal));
            }

            // 5) Agrego el resto de horas disponibles
            foreach (string hora in horasDisponibles)
            {
                if (hora != horaOriginal)
                    ddlHorario.Items.Add(new ListItem(hora, hora));
            }

            // 6) Activar ddl
            if (ddlHorario.Items.Count > 1)
                ddlHorario.Enabled = true;
            else
            {
                lblMensajeError.Text = "No quedan horarios disponibles para este día.";
                lblMensajeError.Visible = true;
                ddlHorario.Items.Insert(1, new ListItem("-- Sin turnos libres --", "-1"));
            }
        }

        protected void btnGuardarCambios_Click(object sender, EventArgs e)
        {
            string idTurno = Request.QueryString["id"];
            int idEspecialidad = int.Parse(ddlEspecialidad.SelectedValue);
            string legajo = ddlMedico.SelectedValue;
            string dniPaciente = ddlPaciente.SelectedValue;
            DateTime dia = Convert.ToDateTime(txtDiaTurno.Text);
            TimeSpan hora = TimeSpan.ParseExact(ddlHorario.SelectedValue, @"hh\:mm", System.Globalization.CultureInfo.InvariantCulture);


            Turno turnoEditado = new Turno();
            turnoEditado.IdTurno = Convert.ToInt32(idTurno);
            turnoEditado.Especialidad.IdEspecialidad = idEspecialidad;
            turnoEditado.Medico.Legajo = legajo;
            turnoEditado.Paciente.Dni = dniPaciente;
            turnoEditado.Hora = hora;
            turnoEditado.Fecha = dia;

            bool exito = _negTurno.EditarTurno(turnoEditado);

            if (exito)
            {
                lblMensajeExito.Text = "✅ ¡Turno editado con éxito!";
                lblMensajeExito.Visible = true;

                btnGuardarCambios.Visible = false;
                hlVolver.Visible = true;
                LimpiarFormulario();

            }
            else
            {
                lblMensajeError.Text = "❌ Error al intentar editar el turno. Consulte con soporte.";
                lblMensajeError.Visible = true;

                btnGuardarCambios.Visible = false;
                hlVolver.Visible = true;
                LimpiarFormulario();
            }

        }
        private void LimpiarFormulario()
        {
            ddlEspecialidad.Enabled = false;
            ddlPaciente.Enabled = false;
            ddlMedico.Enabled = false;
            txtDiaTurno.Enabled = false;
            lblHorario.Text = "Horario base:"; 
            ddlHorario.Enabled = false;
            lblDiaTurno.Text = string.Empty;    
            ViewState["InfoMedicoSeleccionado"] = null;
            ViewState["FechaOriginalTurno"] = null;
            ViewState["HoraOriginalTurno"] = null;
        }

    }
}
