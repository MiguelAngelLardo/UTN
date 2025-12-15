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
            grdLibros.DataSource = glibros.ObtenerTodosLosLibros();
            grdLibros.DataBind();
        }

        protected void grdLibros_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
        {
            //Se busca los datos en el itemtemplate

            String s_IdLibro = ((Label)grdLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdLibro")).Text;
            String s_Titulo = ((Label)grdLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Titulo")).Text;
            String s_Precio = ((Label)grdLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Precio")).Text;
            String s_Autor = ((Label)grdLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Autor")).Text;

            lblMensaje.Text = "Usted selecciono: " + s_IdLibro + " " + s_Titulo + " " + s_Precio + " " + s_Autor;

        }

        protected void grdLibros_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            //Busco en el itemtemplate el IDLIBRO

            String s_IdLibro = ((Label)grdLibros.Rows[e.RowIndex].FindControl("lbl_it_IdLibro")).Text;

            Libro lib = new Libro();
            lib.IdLibro = Convert.ToInt32(s_IdLibro);

            GestionLibros glibros = new GestionLibros();
            glibros.EliminarLibro(lib);

            cargarGridView();

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

            Libro lib = new Libro();
            lib.IdLibro = Convert.ToInt32(s_IdLibro);
            lib.Titulo = s_Titulo;
            lib.Precio = Convert.ToDecimal(s_Precio);
            lib.Autor = s_Autor;

            GestionLibros glibros = new GestionLibros();
            glibros.ActualizarLibro(lib);

            grdLibros.EditIndex = -1;
            cargarGridView();

        }

        protected void grdLibros_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            grdLibros.PageIndex = e.NewPageIndex;
            cargarGridView();
        }

        protected void grdLibros_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            if (e.CommandName == "eventoComprar")
            {
                //Se hizo click sobre el botón comprar
                int fila = Convert.ToInt32(e.CommandArgument);

                String s_IdLibro = ((Label)grdLibros.Rows[fila].FindControl("lbl_it_IdLibro")).Text;
                String s_Titulo = ((Label)grdLibros.Rows[fila].FindControl("lbl_it_Titulo")).Text;
                String s_Precio = ((Label)grdLibros.Rows[fila].FindControl("lbl_it_Precio")).Text;
                String s_Autor = ((Label)grdLibros.Rows[fila].FindControl("lbl_it_Autor")).Text;

                lblMensaje.Text = "Usted compro el siguiente libro: " + s_IdLibro + " " + s_Titulo + " " + s_Precio + " " + s_Autor;
            }
        }
    }
}