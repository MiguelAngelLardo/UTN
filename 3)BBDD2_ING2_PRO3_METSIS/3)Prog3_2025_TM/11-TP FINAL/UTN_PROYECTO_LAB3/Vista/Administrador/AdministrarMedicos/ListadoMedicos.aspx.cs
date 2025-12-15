using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarMedicos
{
  public partial class ListadoMedicos : System.Web.UI.Page
  {
    private NegocioMedico _negMedico = new NegocioMedico();
    private NegocioEspecialidad _negEspecialidad = new NegocioEspecialidad();
    private NegocioDiaSemana _negDias = new NegocioDiaSemana();
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        CargarEspecialidadDiasFiltros();//Cargamos los DDLs y Checkboxes
        CargarGridMedicos(); //Cargamos el grid. Como los filtros están vacíos, traerá todo.
      }
    }

    private void CargarEspecialidadDiasFiltros()
    {
      // Cargar Especialidades
      ddlEspecialidades.DataSource = _negEspecialidad.Listar();//retorna System.Data.DataTable
      ddlEspecialidades.DataTextField = "DescripcionEspecialidad"; //Descripcion_E AS DescripcionEspecialidad\r\n 
      ddlEspecialidades.DataValueField = "IdEspecialidad"; //IdEspecialidad_E AS IdEspecialidad,
      ddlEspecialidades.DataBind();
      ddlEspecialidades.Items.Insert(0, new ListItem("-- Seleccione una especialidad --", "0"));

      // Cargar Días 
      checkDias.DataSource = _negDias.Listar();
      checkDias.DataTextField = "NombreDia"; //Nombre_D AS NombreDia
      checkDias.DataValueField = "IdDia"; //IdDia_D AS IdDia
      checkDias.DataBind();
    } 

    private void CargarGridMedicos()
    {
      //filtros de texto nom ape legajo
      string nomApe = txtBuscarPorNombre.Text.Trim();
      string legajo = txtBuscarPorLegajo.Text.Trim();

      // filtro de DropDown especialidad
      int idEspecialidad = Convert.ToInt32(ddlEspecialidades.SelectedValue);

      // filtro Dias DAtaTable => como en el SP de Agregar
      DataTable dtDias = new DataTable();
      dtDias.Columns.Add("IdDia", typeof(int));
      foreach (ListItem item in checkDias.Items)
      {
        if (item.Selected)
        {
          dtDias.Rows.Add(Convert.ToInt32(item.Value));
        }
      }

      DataTable tabla = _negMedico.ListarBuscarTodoMedicos(nomApe, legajo, idEspecialidad, dtDias); //busqueda pro

      tabla.Columns.Add("EstadoUsuario", typeof(string)); //agrego columna invisible  
      foreach (DataRow fila in tabla.Rows)
      {
        bool tieneUsuario = fila["Usuario_M"] != DBNull.Value && !string.IsNullOrEmpty(fila["Usuario_M"].ToString());
        bool habilitado = fila["UsuarioHabilitado_M"] != DBNull.Value && Convert.ToBoolean(fila["UsuarioHabilitado_M"]);

        if (!tieneUsuario) fila["EstadoUsuario"] = "Sin usuario";
        else if (habilitado) fila["EstadoUsuario"] = "Habilitado";
        else fila["EstadoUsuario"] = "Deshabilitado";
      }
      gvMedicos.DataSource = tabla; //paso tabla normal + la invisible
      gvMedicos.DataBind();
    }


    protected void btnAgregarMedico_Click(object sender, EventArgs e)
    {
       Response.Redirect("FormAgregarMedico.aspx");
    }

    protected void gvMedicos_RowDataBound(object sender, GridViewRowEventArgs e)
    {
        if (e.Row.RowType == DataControlRowType.DataRow)
        {
            string estadoUsuario = DataBinder.Eval(e.Row.DataItem, "EstadoUsuario").ToString();
            Button btnCrearUsuario = (Button)e.Row.FindControl("btnCrearUsuario");
            Button btnEliminarUsuario = (Button)e.Row.FindControl("btnEliminarUsuario");
            CheckBox chkHabilitar = (CheckBox)e.Row.FindControl("chkHabilitar");
            Label lblEstado = (Label)e.Row.FindControl("lblEstado");
            HtmlGenericControl divEstado = (HtmlGenericControl)e.Row.FindControl("divEstado");

                btnCrearUsuario.Visible = false;
                btnEliminarUsuario.Visible = false;
                chkHabilitar.Visible = false;
                lblEstado.Visible = false;
                divEstado.Visible = false;
                switch (estadoUsuario)
                {
                    case "Sin usuario":
                    
                        btnCrearUsuario.Visible = true;
                        btnCrearUsuario.Text = "Crear";
                        btnCrearUsuario.CommandName = "CrearUsuario";
                        break;

                    case "Habilitado":
                        btnCrearUsuario.Visible = true;
                        btnCrearUsuario.Text = "Administrar";
                        btnCrearUsuario.CommandName = "AdministrarUsuario";

                        btnEliminarUsuario.Visible = true;

                        chkHabilitar.Visible = true;
                        chkHabilitar.Checked = true;

                        lblEstado.Visible = true;
                        lblEstado.Text = "Habilitado";
                        divEstado.Visible = true;

                        break;

                    case "Deshabilitado":
                        btnCrearUsuario.Visible = true;
                        btnCrearUsuario.Text = "Administrar";
                        btnCrearUsuario.CommandName = "AdministrarUsuario";

                        btnEliminarUsuario.Visible = true;

                        chkHabilitar.Visible = true;
                        chkHabilitar.Checked = false;

                        lblEstado.Visible = true;
                        lblEstado.Text = "Deshabilitado";
                        divEstado.Visible = true;
                        break;
                }
            }
    }

    protected void gvMedicos_RowCommand(object sender, GridViewCommandEventArgs e)
    {
        string legajo = e.CommandArgument.ToString();

        switch (e.CommandName)
        {
            case "Ver": Response.Redirect($"DetalleMedico.aspx?legajo={legajo}"); break;

            case "Editar": Response.Redirect($"FormEditarMedico.aspx?legajo={legajo}"); break;

            case "Eliminar":_negMedico.EliminarMedico(legajo); CargarGridMedicos(); break;

            case "CrearUsuario": Response.Redirect($"CrearUsuario.aspx?legajo={legajo}"); break;

            case "AdministrarUsuario": Response.Redirect($"CambiarUsuarioContrasenia.aspx?legajo={legajo}"); break;
            
            case "EliminarUsuario": _negMedico.EliminarUsuario(legajo); CargarGridMedicos(); break;

            }
    }

        protected void chkHabilitar_CheckedChanged(object sender, EventArgs e)
        {
            CheckBox chk = (CheckBox)sender;
            GridViewRow fila = (GridViewRow)chk.NamingContainer;

            HiddenField hf = (HiddenField)fila.FindControl("hfLegajo");
            Label lbl = (Label)fila.FindControl("lblEstado");

            string legajo = hf.Value;
            bool habilitado = chk.Checked;

            _negMedico.CambiarEstadoUsuarioMedico(legajo, habilitado);

            lbl.Text = habilitado ? "Habilitado" : "Deshabilitado";
        }


        protected void gvMedicos_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
        gvMedicos.PageIndex = e.NewPageIndex;
        CargarGridMedicos();
    }

    protected void btnBuscar_Click(object sender, EventArgs e)
    {
      gvMedicos.PageIndex = 0; // Resetea la paginación
      //ddlEspecialidades.SelectedValue = "0";
      //checkDias.ClearSelection();
      //foreach (ListItem item in checkDias.Items) item.Selected = false; //reseteco cbl
      //los reseteos anteriores no el gustan el view state de CSHARP asi que uso JavaScript con OnClientClick
      CargarGridMedicos(); // Llama al método unificado
    }

    protected void btnAplicarFiltros_Click(object sender, EventArgs e)
    {
      gvMedicos.PageIndex = 0; // Resetea la paginación
      CargarGridMedicos(); // Llama al MISMO método unificado
    }

    }
}