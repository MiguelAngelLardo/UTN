using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;
using Entidades;
using Negocio;

namespace Vistas
{
    public partial class FormularioCategorias : System.Web.UI.Page
    {
        NegocioCategoria neg = new NegocioCategoria();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                DataTable tablaCategorias = neg.getTabla();
                grdCategorias.DataSource = tablaCategorias;
                grdCategorias.DataBind();

                ListViewCategoria.DataSource = neg.getTabla();
                ListViewCategoria.DataBind();
            }
        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            Boolean estado = false;
            estado = neg.agregarCategoria(txtNombreCategoria.Text);
            if (estado == true)
            {
                lblMensaje.Text = "Categoria agregada con exito";
            }
            else
            {
                lblMensaje.Text = "No se puedo agregar categoría";
            }

            //Refresco la información de la tabla
            DataTable tablaCategorias = neg.getTabla();
            grdCategorias.DataSource = tablaCategorias;
            grdCategorias.DataBind();
            txtNombreCategoria.Text = "";
        }
    }
}