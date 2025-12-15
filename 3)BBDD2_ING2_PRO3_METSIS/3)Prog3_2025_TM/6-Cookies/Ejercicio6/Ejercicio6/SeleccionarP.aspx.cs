using Ejercicio6.Conexion;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data;//tiene dataTable
namespace Ejercicio6
{
  public partial class SeleccionarPagina : System.Web.UI.Page
  {


    public void cargarGrid()
    {
      GestionProducto objGestProd = new GestionProducto();
      grdSeleccionar.DataSource = objGestProd.seleccionar4ConIdProveedor();
      grdSeleccionar.DataBind();
    }

    public DataTable crearTablaSession()
    {

      //creo 4 columnas
      DataColumn colIdProd = new DataColumn("idProducto", System.Type.GetType("System.Int32"));
      DataColumn colNomProd = new DataColumn("nombreProducto", System.Type.GetType("System.String"));
      DataColumn colIdProv = new DataColumn("idProveedor", System.Type.GetType("System.Int32"));
      DataColumn colPrecio = new DataColumn("precioUnidad", System.Type.GetType("System.Decimal"));

      //creo tabla inicializada con 4 columnas
      DataTable dtSession = new DataTable();
      dtSession.Columns.Add(colIdProd);
      dtSession.Columns.Add(colNomProd);
      dtSession.Columns.Add(colIdProv);
      dtSession.Columns.Add(colPrecio);

      return dtSession;
    }

    public void agregarFilaSession(DataTable dt, int idPro, string nomPro, int idProv, decimal pu)
    {
      DataRow dr = dt.NewRow();// Crea una fila con la estructura de la tabla dt.
      dr["idProducto"] = idPro; // en columna idProducto le asigno idPro
      dr["nombreProducto"] = nomPro;
      dr["idProveedor"] = idProv;
      dr["precioUnidad"] = pu;

      dt.Rows.Add(dr); //agrego la fila a la tabla
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      cargarGrid();
    }

   



    protected void grdSeleccionar_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
    {
      string idSeleccionado = ((Label)grdSeleccionar.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdProd")).Text;
      string nombreSeleccionado = ((Label)grdSeleccionar.Rows[e.NewSelectedIndex].FindControl("lbl_it_NomProd")).Text;
      string idProveedorSeleccionado = ((Label)grdSeleccionar.Rows[e.NewSelectedIndex].FindControl("lbl_it_IdProv")).Text;
      string precioSeleccionado = ((Label)grdSeleccionar.Rows[e.NewSelectedIndex].FindControl("lbl_it_PrecUnit")).Text;

      lblProdSeleccionado.Text = "Productos agregados: " + nombreSeleccionado;

      /// 2. Conviertes los strings a los tipos de datos correctos
      int idConvertido = Convert.ToInt32(idSeleccionado);
      int idProvConvertido = Convert.ToInt32(idProveedorSeleccionado);
      decimal precioConvertido = Convert.ToDecimal(precioSeleccionado);

      if (Session["tablaSessionSeleccionados"] == null)//si no existe la crea
      {
        Session["tablaSessionSeleccionados"] = crearTablaSession();
      }

      DataTable dt = (DataTable)Session["tablaSessionSeleccionados"];
      bool yaExiste = false;
      foreach(DataRow dr in dt.Rows)
      {
        if((int)dr["idProducto"] == idConvertido)//DataRow siempre devuelve object generico
        {
          yaExiste = true;
          break;//si lo encuentra salgo del for 
        }

      }

      if (!yaExiste)
      {
        // 3. Llamas al método con las variables ya convertidas
        agregarFilaSession((DataTable)Session["tablaSessionSeleccionados"], idConvertido, nombreSeleccionado, idProvConvertido, precioConvertido);
      }
      else
      {
        lblProdSeleccionado.Text = "El producto " + nombreSeleccionado + " ya fue seleccionado.";
      }
     

     



      

    }
  }
}