using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                cargarGridView();
            }
        }

        public void cargarGridView()
        {
            GestionLibros glibros = new GestionLibros();
            grdLibros.DataSource = glibros.ObtenerTodosLosLibrosConTemas();
            grdLibros.DataBind();
        }
        
        protected void grdLibros_RowEditing(object sender, GridViewEditEventArgs e)
        {
            grdLibros.EditIndex = e.NewEditIndex;
            cargarGridView();

        }

        protected void grdLibros_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            grdLibros.EditIndex = -1;
            cargarGridView();
        }

        protected void grdLibros_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            //Buscar los datos del edititemplate
            String s_IdLibro = ((Label)grdLibros.Rows[e.RowIndex].FindControl("lbl_eit_IdLibro")).Text;
            String s_Titulo = ((TextBox)grdLibros.Rows[e.RowIndex].FindControl("txt_eit_Titulo")).Text;
            String s_Precio = ((TextBox)grdLibros.Rows[e.RowIndex].FindControl("txt_eit_Precio")).Text;
            String s_Autor = ((TextBox)grdLibros.Rows[e.RowIndex].FindControl("txt_eit_Autor")).Text;
            String s_IdTema = ((DropDownList)grdLibros.Rows[e.RowIndex].FindControl("ddl_eit_Temas")).SelectedValue;


            Libro lib = new Libro();
            lib.IdLibro = Convert.ToInt32(s_IdLibro);
            lib.Titulo = s_Titulo;
            lib.Precio = Convert.ToDecimal(s_Precio);
            lib.Autor = s_Autor;
            lib.IdTema = Convert.ToInt32(s_IdTema);

            GestionLibros glibros = new GestionLibros();
             glibros.ActualizarLibro(lib);

            grdLibros.EditIndex = -1;
            cargarGridView();

        }

        protected void grdLibros_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow)
            {
                DropDownList ddl = (DropDownList) e.Row.FindControl("ddl_eit_Temas");
                if (ddl != null)
                {
                    GestionTema gt = new GestionTema();
                    ddl.DataSource = gt.ObtenerTodosLosTemas();
                    ddl.DataTextField = "Tema";
                    ddl.DataValueField = "IdTema";
                    //Configurar cual de los elementos va a estar seleccionado
                    ddl.DataBind();
                }
            }
        }
    }
}