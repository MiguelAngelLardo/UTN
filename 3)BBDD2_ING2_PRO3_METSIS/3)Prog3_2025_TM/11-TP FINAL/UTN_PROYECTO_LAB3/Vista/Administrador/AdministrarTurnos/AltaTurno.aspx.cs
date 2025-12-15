using System;
using System.Collections.Generic;
using System.Net.NetworkInformation;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;

using System.Linq;
using Entidades; //para clase medico
using Negocio; //para capa negocio
namespace Vista.Administrador.AdministrarTurnos
{
  public partial class AltaTurno : Page
  {
    private NegocioEspecialidad _negEspecialidad = new NegocioEspecialidad();
    private NegocioMedico _negMedico = new NegocioMedico();
    private NegocioPaciente _negPac = new NegocioPaciente();
    private NegocioTurno _negTurno = new NegocioTurno();



    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        CargarMedicosFalse();
        CargarHorariosFalse();

        CargarEspecialidades();
        CargarPacientesActivos();
        EstablecerFechaMinima();
      }
    }

    private void CargarMedicosFalse()
    {
      ddlMedico.Enabled = false; // ddl en sombra
      ddlMedico.Items.Clear();//puedo sacarlo pero lo dejo por claridad visual
      ddlMedico.Items.Insert(0, new ListItem("-- Primero seleccione una Especialidad --", "0"));
    }

    private void CargarHorariosFalse2()
    {
      txtDateCalendario.Text = string.Empty;//calendario limpio
      txtDateCalendario.Enabled = false;//no deja elejir fechas

      lblHorarioDisponible.Text = "Horario Atención: No asignado"; //lbl arriba del ddl de 08:00 - 12:00
      ddlHorarioDisponible.Enabled = false; // ddl en sombra
      ddlHorarioDisponible.Items.Clear();//puedo sacarlo pero lo dejo por claridad visual
      ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Primero seleccione un Medico --", "0"));

      lblDiasMedico.Text = string.Empty;//si dice lunes, miercoles lo 
    }

    private void CargarHorariosFalse()
    {
      // Resetear Fecha
      txtDateCalendario.Enabled = false;
      txtDateCalendario.Text = string.Empty;

      // Resetear DDL de Horarios
      ddlHorarioDisponible.Enabled = false;
      ddlHorarioDisponible.Items.Clear();
      
      //Mensaje que indica la dependencia de la fecha:
      ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Primero seleccione una Fecha --", "0"));
    }

    private void CargarEspecialidades()
    {
      ddlEspecialidad.DataSource = _negEspecialidad.Listar();//retorna System.Data.DataTable
      ddlEspecialidad.DataTextField = "DescripcionEspecialidad"; //Descripcion_E AS DescripcionEspecialidad\r\n 
      ddlEspecialidad.DataValueField = "IdEspecialidad"; //IdEspecialidad_E AS IdEspecialidad,
      ddlEspecialidad.DataBind();
      ddlEspecialidad.Items.Insert(0, new ListItem("-- Seleccione una especialidad --", "0"));
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
      ddlPaciente.Items.Insert(0, new ListItem("-- Seleccione un Paciente --", "0"));

      //ddlPaciente.DataSource = _negPac.ListarPacientesActivos();
      //ddlPaciente.DataTextField = "NombreCompleto"; // P.Apellido_P + ', ' + P.Nombre_P AS NombreCompleto 
      //ddlPaciente.DataValueField = "DNI";//P.Dni_P AS DNI, -- Será el DataValueField 
      //ddlPaciente.DataBind();//como el databind destruye todo lo q habia antes de cargar debo poner desp el Inser 0 "seleccione un paciente"
      //ddlPaciente.Items.Insert(0, new ListItem("-- Seleccione un Paciente --", "0"));
    }

    private void EstablecerFechaMinima()
    {
      string hoy = DateTime.Today.ToString("yyyy-MM-dd");// Obtiene la fecha de hoy en formato yyyy-MM-dd
      txtDateCalendario.Attributes.Add("min", hoy);//atributo min para que el calendario no muestre anteriores
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
          lblHorarioDisponible.Text = "Horario base: " + objDiasHsMed.HorarioBase;//08:00-12:00 del SP
          lblDiasMedico.Text = objDiasHsMed.NombresDiasTrabajo; //nombres del MapeoDias

          /*  lo dejo comentado por que sino siempre veia los 4 horarios asi cambiase de fecha        
          // Generacion de 4 slots de horarios en ddlHorariosDisponibles
          List<string> slots = GenerarSlotsDesdeHorario(objDiasHsMed.HorarioBase);//08:00+09:00+10:00+11:00
          ddlHorarioDisponible.Items.Clear();//sin esto queda --Seleccione la hora -- y abajo -- Primero seleccione un Medico -- y abajo los slots
          ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Seleccione la hora --", "0")); //quito el msj primero seleccione un medico

          if (slots.Count > 0)
          {
            foreach (string slot in slots) ddlHorarioDisponible.Items.Add(new ListItem(slot, slot));//ListItem.Text y ListItem.Value siempre guardan string por el HTML asi q no puedo guardar TimeSpan en Value
            ddlHorarioDisponible.Enabled = true; // Habilitar el DDL de horarios
          }
          else
          {
            ddlHorarioDisponible.Items.Insert(1, new ListItem("Horario no configurado o inválido", "-1"));
          }*/

          // Habilitar la selección de fecha
          txtDateCalendario.Enabled = true;
          txtDateCalendario.Text = string.Empty;
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


    /*ddlMedico_SelectedIndexChanged y txtDateCalendario_TextChanged ocurren independientemente y acumulan los cambios si no se limpian.*/
    protected void txtDateCalendario_TextChanged(object sender, EventArgs e)//este filtra los slots segun fecha y disponibilidad
    {
      string legajo = ddlMedico.SelectedValue;
      
      //aca hagol impieza inicial => sin esto me aparece en el ddl los horarios del medico anterior 
      lblMensajeError.Visible = false;
      ddlHorarioDisponible.Items.Clear();
      ddlHorarioDisponible.Enabled = false;

      //ViewState["InfoMedicoSeleccionado"] = null; //para pruebas
      //aca verifico
      if (legajo == "0" || ViewState["InfoMedicoSeleccionado"] == null || string.IsNullOrEmpty(txtDateCalendario.Text))
      {
        ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Error de selección --", "0"));
        return;
      }

      //aca teletransporto al  objDiasHsMed del ddlMedico ya cargado desde el public DiasHorariosMedico ObtenerDiasYHorarioMedico(string Legajo)
      DiasHorariosMedico objDiasHsMedYaCargado = (DiasHorariosMedico)ViewState["InfoMedicoSeleccionado"];

      /*RELACIONADO AL CALENDARIO*/
      //el usuario ve su configucacion regional por ejemplo, dd/mm/aaaa o mm/dd/aaaa pero el valor interno q envio al servidor es el estandar ISO 8601 (YYYY-MM-DD)
      //HTML5 garantiza que la transferencia de datos sin ambigüedades culturales (como saber si "01/02/2025" es 1 de febrero o 2 de enero).
      DateTime fechaTurno = Convert.ToDateTime(txtDateCalendario.Text);//como us TextMode="Date" en un TextBox de ASP.NET traigo al servidor un formato estándar ISO 8601 (YYYY-MM-DD)
      int idDiaSeleccionado = (int)fechaTurno.DayOfWeek;//en C# day of week es Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6
      if (idDiaSeleccionado == 0) idDiaSeleccionado = 7;//para c # 0 es domingo
      string idDiaSeleccionadoStr = idDiaSeleccionado.ToString();// infoMedico.IdsDiasTrabajo es la cadena "1,3,5"


      /*lo que muestra en el lbl y ddl cuando es una fecha no laboral*/
      if (!objDiasHsMedYaCargado.IdsDiasTrabajo.Split(',').Contains(idDiaSeleccionadoStr))//objDiasHsMedYaCargado tiene "1,3,5" y lo pasa a {"1", "3", "5"} => .Contains(idDiaSeleccionadoStr) verifica si el Friday = 5 esta en el array del split 
      {
        // Muestra un mensaje de error => fechaTurno.ToString("dddd", new System.Globalization.CultureInfo("es-ES")) devuelve el nombre del dia de la semana en español
        lblMensajeError.Text = $"El Dr. no atiende el día {fechaTurno.ToString("dddd", new System.Globalization.CultureInfo("es-ES"))}. Seleccione otro día.";
        lblMensajeError.Visible = true;
        ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Día no laborable --", "0"));
        return;
      }

      /*ddlMedico uso el ObtenerDiasYHorarioMedico para que el SP me de 08:00-12:00 (ademas del IdsDiasTrabajo y NombresDiasTrabajo) devolviendo un objeto DiasHorariosMedico*/
      List<string> slotsPosibles = GenerarSlotsDesdeHorario(objDiasHsMedYaCargado.HorarioBase);//uso (@"hh\:mm")) => "08:00","09:00","10:00","11:00"
      List<string> horasOcupadas = _negMedico.ObtenerHorasOcupadas(legajo, fechaTurno);//uso (@"hh\:mm")) => trabaja el 21/11/2025 de "08:00" a "09:00"

      //guardo horarios del medico NO OCUPADOS )> USO LINQ
      //¿horasOcupadas contiene "08:00"? Si, no lo agrego a horasDisponibles
      List<string> horasDisponibles = slotsPosibles.Where((string slot) => !horasOcupadas.Contains(slot)).ToList();//muestra "10:00","11:00"

      /*
      List<string> horasDisponibles = new List<string>();
      foreach (string slot in slotsPosibles) if (!horasOcupadas.Contains(slot)) horasDisponibles.Add(slot);
       */

      //si la fecha es laboral muestra
      ddlHorarioDisponible.Items.Insert(0, new ListItem("-- Seleccione la hora --", "0"));


      if (horasDisponibles.Count > 0)
      {
        foreach (string hora in horasDisponibles)
        {
          ddlHorarioDisponible.Items.Add(new ListItem(hora, hora));
        }
        ddlHorarioDisponible.Enabled = true;
      }
      else
      {
        lblMensajeError.Text = "No quedan horarios disponibles para este día.";
        lblMensajeError.Visible = true;
        ddlHorarioDisponible.Items.Insert(1, new ListItem("-- Sin turnos libres --", "-1"));
      }
    }

    protected void btnGuardarTurno_Click(object sender, EventArgs e)
    {
      int idEspecialidad = int.Parse(ddlEspecialidad.SelectedValue);

      // Estos son strings (Legajo, DNI, Hora) => no necesitan conversión numérica.
      string legajoMedico = ddlMedico.SelectedValue;
      string dniPaciente = ddlPaciente.SelectedValue;

      DateTime diaAtencionFuturo = Convert.ToDateTime(txtDateCalendario.Text);//paso el string ISO 8601 ("YYYY-MM-DD") a un objeto DateTime.


      //System.Globalization => es para formatos de números, las monedas, fecha y hora.
      //CultureInfo => cómo se deben formatear y analizar los datos según una región geográfica específica
      //InvariantCulture => Es una cultura que es neutra, usa el estandar internacional => ejemplo el "." como separador decimal.
      //3 tipos de casteos ParseExact() o Convert.ToTimeSpan() o TimeSpan.Parse()
      //ParseExact() es mucho más seguro => La conversión solo tiene éxito si el valor es exactamente 08:00 o 11:30 => si es "8:00 AM" o "08:00:00" dara error
      TimeSpan horarioUnitario = TimeSpan.ParseExact(ddlHorarioDisponible.SelectedValue,@"hh\:mm",System.Globalization.CultureInfo.InvariantCulture);


      Turno nuevoTurno = new Turno();
      nuevoTurno.Medico.Legajo = legajoMedico;
      nuevoTurno.Paciente.Dni = dniPaciente;
      nuevoTurno.Especialidad.IdEspecialidad = idEspecialidad;
      nuevoTurno.Hora = horarioUnitario;
      nuevoTurno.Fecha = diaAtencionFuturo;

      bool exito = _negTurno.AgregarTurno(nuevoTurno);

      if (exito)
      {
        lblMensajeExito.Text = "✅ ¡Turno registrado con éxito!";
        lblMensajeExito.Visible = true;

        btnGuardarTurno.Visible = false;
        hlVolver.Visible = true;
        LimpiarFormulario();

      }
      else
      {
        lblMensajeError.Text = "❌ Error al intentar guardar el turno. Consulte con soporte.";
        lblMensajeError.Visible = true;

        btnGuardarTurno.Visible = false;
        hlVolver.Visible = true;
        LimpiarFormulario();
      }


    }


    private void LimpiarFormulario()
    {
      ddlEspecialidad.Enabled = false;
      ddlPaciente.Enabled = false;
      ddlMedico.Enabled = false;
      txtDateCalendario.Enabled = false;
      lblHorarioDisponible.Text = "Horario base:"; // Resetear el texto base
      ddlHorarioDisponible.Enabled = false;
      lblDiasMedico.Text = string.Empty; // Limpiar los días de atención mostrados     
      ViewState["InfoMedicoSeleccionado"] = null;

     
      //txtDateCalendario.Text = string.Empty; // 5. Resetear la fecha (ya cubierto por CargarHoariosFalse, pero lo aseguramos)
    }


  }
}
