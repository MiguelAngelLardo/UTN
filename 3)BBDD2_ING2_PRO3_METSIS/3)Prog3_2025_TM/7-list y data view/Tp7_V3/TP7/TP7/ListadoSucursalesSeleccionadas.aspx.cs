using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using TP7.Modelo_Entidades_; // <-- Asi reconoce la clase Sucursal.Cs. El _ es para decirle Descarta este valor
namespace TP7
{
  public partial class ListadoSucursalesSeleccionadas : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      
      if (!IsPostBack)
      {
        if (Session["SucursalesSeleccionadas"] != null)// 1. Verificamos que la variable de sesión exista y no esté vacía.

        {
          List<Sucursal> lista = (List<Sucursal>)Session["SucursalesSeleccionadas"];//casteo el Objet a List<Sucursal> y creo puntero local lista
          gvSucursales.DataSource = lista;
          gvSucursales.DataBind();
        }
      }
      

    }
  }
}