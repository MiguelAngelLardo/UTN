using Negocio;
using System;
using System.Data;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarTurnos
{
    public partial class ListadoTurnos : Page
    {
        private NegocioTurno _negTurnos = new NegocioTurno();
        private NegocioEspecialidad _negEspecialidad = new NegocioEspecialidad();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                CargarEspecialidades();
                CargarGridTurnos();
            }
        }

        private void CargarEspecialidades()
        {
            try
            {
                DataTable dtEspecialidades = _negEspecialidad.Listar();

                ddlEspecialidad.DataSource = dtEspecialidades;
                ddlEspecialidad.DataTextField = "DescripcionEspecialidad";
                ddlEspecialidad.DataValueField = "IdEspecialidad";
                ddlEspecialidad.DataBind();

                ddlEspecialidad.Items.Insert(0, new ListItem("-- Todas las especialidades --", ""));
            }
            catch (Exception ex)
            {
                // Si hay error el dropdown quedap vacio
            }
        }

        private void CargarGridTurnos()
        {
            DataTable tabla = _negTurnos.ListarTablaTurno();
            gvTurnos.DataSource = tabla;
            gvTurnos.DataBind();
        }

        protected void btnNuevoTurno_Click(object sender, EventArgs e)
        {
            Response.Redirect("AltaTurno.aspx");
        }

        protected void gvTurnos_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            if (e.CommandName == "Editar")
            {
             string idTurno = e.CommandArgument.ToString();//CommandArgument='<%# Eval("IdTurno")
            //int index = Convert.ToInt32(e.CommandArgument); //da error por que el CommandArgument no es el index de la fila
            //GridViewRow row = gvTurnos.Rows[index]; //gvTurnos.Rows[1010] se rompe todo por que no hay 1010 filas sino  que el id es ese

             GridViewRow row = ((Control)e.CommandSource).NamingContainer as GridViewRow;
            //e.CommandSource es el btnEditar
            //NamingContainer accede al boton dentro de un ItemTemplate y me trae el contenedor, que en este caso es la fila

            //GridViewRow contiene TableCell -> el TableCell contiene el btnEditar (columna acciones indice [6] -> e.CommandSource es el objeto btnEditar

            string fechaStr = row.Cells[3].Text;
            string horaStr = row.Cells[4].Text;

            DateTime fechaTurno = DateTime.Parse(fechaStr);
            TimeSpan horaTurno = TimeSpan.Parse(horaStr);

            DateTime ahora = DateTime.Now;
            if (fechaTurno.Date < ahora.Date)
            {
              ScriptManager.RegisterStartupScript(this, GetType(),
                  "alerta1",
                  "alert('⚠️ No se puede editar un turno con fecha pasada.');",
                  true);
              return;
            }
            if (fechaTurno.Date == ahora.Date && horaTurno < ahora.TimeOfDay)
            {
              ScriptManager.RegisterStartupScript(this, GetType(),
                  "alerta2",
                  "alert('⚠️ No se puede editar un turno cuya hora ya pasó.');",
                  true);
              return;
            }

            Response.Redirect($"FormEditarTurno.aspx?id={idTurno}");
                }
                if (e.CommandName == "Eliminar")
                {
                    string idTurno = e.CommandArgument.ToString();
                    _negTurnos.EliminarTurno(idTurno);
                    CargarGridTurnos();
                }
            }

        protected void btnBuscar_Click(object sender, EventArgs e)
        {
            string nombreMedico = txtBuscarPorMedico.Text.Trim();
            string nombrePaciente = txtBuscarPorPaciente.Text.Trim();

            // Validación: si no ponen ninguno de los dos, recargo la tabla completa
            bool hayBusqueda = !string.IsNullOrEmpty(nombreMedico) || !string.IsNullOrEmpty(nombrePaciente);

            if (!hayBusqueda)
            {
                CargarGridTurnos();
                return;
            }

            // Llamada al mismo método, pero enviando solo estos filtros.
            // El resto lo mandamos vacío para que no afecte.
            DataTable tabla = _negTurnos.BuscarTurnosAdministrador(
                nombreMedico,
                nombrePaciente,
                null, // especialidad NO se usa acá
                false, false, false, false, false, false // días
            );

            gvTurnos.DataSource = tabla;
            gvTurnos.DataBind();
        }

        protected void gvTurnos_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            gvTurnos.PageIndex = e.NewPageIndex;
            CargarGridTurnos();
        }
        protected void btnAplicarFiltros_Click(object sender, EventArgs e)
        {
            // Especialidad
            int? idEspecialidad = null;
            if (!string.IsNullOrEmpty(ddlEspecialidad.SelectedValue))
            {
                idEspecialidad = int.Parse(ddlEspecialidad.SelectedValue);
            }

            // Días
            bool lunes = chkLunes.Checked;
            bool martes = chkMartes.Checked;
            bool miercoles = chkMiercoles.Checked;
            bool jueves = chkJueves.Checked;
            bool viernes = chkViernes.Checked;
            bool sabado = chkSabado.Checked;

            // Validación: si no ponen ningún filtro, recargar todo
            bool hayFiltros = idEspecialidad.HasValue || lunes || martes || miercoles || jueves || viernes || sabado;

            if (!hayFiltros)
            {
                CargarGridTurnos();
                return;
            }

            // Llamada al método
            DataTable tabla = _negTurnos.BuscarTurnosAdministrador(
                "",     // nombre médico NO se usa acá
                "",     // nombre paciente NO se usa acá
                idEspecialidad,
                lunes,
                martes,
                miercoles,
                jueves,
                viernes,
                sabado
            );

            gvTurnos.DataSource = tabla;
            gvTurnos.DataBind();
        }

    }
}
