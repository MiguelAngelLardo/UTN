using Ejercicio6.Conexion;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Ejercicio6
{
  public partial class Ej11 : System.Web.UI.Page
  {

    public void cargarGrid()
    {
      GestionProducto objGestProd = new GestionProducto();
      grdProductos.DataSource = objGestProd.seleccionar4ColumnasFromProductos();
      grdProductos.DataBind();
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)//si es la primer vez que cargo la pagina
      {
        cargarGrid();
      }
    }

    protected void grdProductos_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
    { 
      //SE BUSCAN DATOS en itemtemplate
      string idLibroDeFila = ((Label)grdProductos.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdProd")).Text;
      string nombreLibroDeFila = ((Label)grdProductos.Rows[e.NewSelectedIndex].FindControl("lbl_it_NomProd")).Text;
      string cantPorUnidadDeFila = ((Label)grdProductos.Rows[e.NewSelectedIndex].FindControl("lbl_it_CantUnid")).Text;
      string precioUnidadDeFila = ((Label)grdProductos.Rows[e.NewSelectedIndex].FindControl("lbl_it_PrecUnit")).Text;

      lblSeleccionar.Text = "Selecciono el producto: " + idLibroDeFila + " - " + nombreLibroDeFila + " - " + cantPorUnidadDeFila + " - " + precioUnidadDeFila;

    }

    //RowIndex es fila actual
    //NewEditIndex o NewSelectedIndex es la fila previa a cambiarla de estado
    protected void grdProductos_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
      string idLibroDeFila = ((Label)grdProductos.Rows[e.RowIndex].FindControl("lbl_it_IdProd")).Text; //fila actual

      Producto objProd = new Producto();
      objProd.idProducto = Convert.ToInt32(idLibroDeFila);

      GestionProducto objGestProd = new GestionProducto();
      objGestProd.eliminarProducto(objProd);

      cargarGrid();

    }

    protected void grdProductos_RowEditing(object sender, GridViewEditEventArgs e)
    {

      grdProductos.EditIndex = e.NewEditIndex;//quieren editarte en esa posicion
      cargarGrid();
    }

    protected void grdProductos_RowCancelingEdit(object sender, GridViewCancelEditEventArgs e)
    {
      grdProductos.EditIndex = -1;//vuelvo a modo lectura
      cargarGrid();
    }

    protected void grdProductos_RowUpdating(object sender, GridViewUpdateEventArgs e)
    {
      //Buscar los datos del edit item template
      string idLibroDeFila = ((Label)grdProductos.Rows[e.RowIndex].FindControl("lbl_eit_IdProducto")).Text;
      string nombreLibroDeFila = ((TextBox)grdProductos.Rows[e.RowIndex].FindControl("txt_eit_NomProd")).Text;
      string cantPorUnidadDeFila = ((TextBox)grdProductos.Rows[e.RowIndex].FindControl("txt_eit_CantXUnid")).Text;
      string precioUnidadDeFila = ((TextBox)grdProductos.Rows[e.RowIndex].FindControl("txt_eit_PrecUnid")).Text;

      Producto objProd = new Producto();
      objProd.idProducto = Convert.ToInt32(idLibroDeFila);
      objProd.nombreProducto = nombreLibroDeFila;
      objProd.cantidadPorUnidad = cantPorUnidadDeFila;
      objProd.precioUnitario = Convert.ToDecimal(precioUnidadDeFila);

      GestionProducto objGestionProd = new GestionProducto();
      objGestionProd.actualizarProducto(objProd);//le paso el producto con los nuevos datos

      grdProductos.EditIndex = -1;//vuelvo a modo lectura
      cargarGrid();


    }

    protected void grdProductos_PageIndexChanging(object sender, GridViewPageEventArgs e)
    {
      grdProductos.PageIndex = e.NewPageIndex;
      cargarGrid();
    }
  }
}