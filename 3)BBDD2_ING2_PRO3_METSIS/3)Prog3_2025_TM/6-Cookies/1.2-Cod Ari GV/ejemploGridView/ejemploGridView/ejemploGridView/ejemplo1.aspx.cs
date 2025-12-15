using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace ejemploGridView
{
    public partial class ejemplo1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Page.IsPostBack == false)
            {
                CargarGridView();
            }
        }

        // CARGAR GRIDVIEW
        private void CargarGridView()
        {
            GestionLibros gestionLibros = new GestionLibros();
            gvLibros.DataSource = gestionLibros.ObtenerTodosLosLibros(); /// DATA TABLE
            gvLibros.DataBind();
        }

        // SELECCIONAR
        protected void gvLibros_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
        {
            /// BUSCAR LOS DATOS EN FILA DENTRO DEL ITEM TEMPLATE
            string idLibro = ((Label)gvLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_idLibro")).Text;
            string titulo = ((Label)gvLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Titulo")).Text;
            string precio = ((Label)gvLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Precio")).Text;
            string autor = ((Label)gvLibros.Rows[e.NewSelectedIndex].FindControl("lbl_it_Autor")).Text;

            /// MOSTRAR LO SELECCIONADO EN UN LABEL
            lblMensaje.Text = "Usted seleccionó: " + idLibro + " - " + titulo + " - " + precio + " - " + autor;
        }

        /// ELIMINAR
        protected void gvLibros_RowDeleting(object sender, GridViewDeleteEventArgs e)
        {
            // BUSCAR ID DEL ITEM TEMPLATE
            string idLibro = ((Label)gvLibros.Rows[e.RowIndex].FindControl("lbl_it_idLibro")).Text;

            // CREAR LIBRO
            Libro libro = new Libro(Convert.ToInt32(idLibro));

            /// ELIMINAR LIBRO
            GestionLibros gestionLibros = new GestionLibros();
            gestionLibros.EliminarLibro(libro);

            CargarGridView();

        }

        /// EDITAR
        protected void gvLibros_RowEditing(object sender, GridViewEditEventArgs e)
        {
            gvLibros.EditIndex = e.NewEditIndex;
            CargarGridView();
        }

        /// CANCELAR
        protected void gvLibros_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
        {
            gvLibros.EditIndex = -1;
            CargarGridView();
        }

        /// ACTUALIZAR
        protected void gvLibros_RowUpdating(object sender, GridViewUpdateEventArgs e)
        {
            /// BUSCAR FILA DENTRO DEL EDIT ITEM TEMPLATE
            string idLibro = ((Label)gvLibros.Rows[e.RowIndex].FindControl("lbl_eit_idLibro")).Text; 
            string titulo = ((TextBox)gvLibros.Rows[e.RowIndex].FindControl("txt_eit_Titulo")).Text;
            string precio = ((TextBox)gvLibros.Rows[e.RowIndex].FindControl("txt_eit_Precio")).Text;
            string autor = ((TextBox)gvLibros.Rows[e.RowIndex].FindControl("txt_eit_Autor")).Text;


            // CREAR LIBRO
            Libro libro = new Libro(Convert.ToInt32(idLibro),titulo,Convert.ToDecimal(precio),autor);

            // ACTUALIZAR LIBRO
            GestionLibros gestionLibros = new GestionLibros();
            gestionLibros.ActualizarLibro(libro);
            gvLibros.EditIndex = -1;
            CargarGridView();
        }


        // PAGINACION
        protected void gvLibros_PageIndexChanging(object sender, GridViewPageEventArgs e)
        {
            gvLibros.PageIndex = e.NewPageIndex;
            CargarGridView();
        }

        protected void gvLibros_RowCommand(object sender, GridViewCommandEventArgs e)
        {
            if (e.CommandName == "eventoComprar")
            {
                int fila = Convert.ToInt32(e.CommandArgument);
                string idLibro = ((Label)gvLibros.Rows[fila].FindControl("lbl_it_idLibro")).Text;
                string titulo = ((Label)gvLibros.Rows[fila].FindControl("lbl_it_Titulo")).Text;
                string precio = ((Label)gvLibros.Rows[fila].FindControl("lbl_it_Precio")).Text;
                string autor = ((Label)gvLibros.Rows[fila].FindControl("lbl_it_Autor")).Text;

                lblMensaje.Text = "Ud compró: " + titulo + " a $: " + precio;
            }
        }
    }
}