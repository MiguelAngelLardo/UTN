using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Entidades;
using Negocio;


namespace Vistas
{
  public partial class ListadoDeSucursales : System.Web.UI.Page
  {

    public void cargaGridSurucrales()
    {

      NegocioSucursal negSuc = new NegocioSucursal();

      gvListar.DataSource = negSuc.negSucListarSucursales();
      gvListar.DataBind();

    }

    protected void Page_Load(object sender, EventArgs e)
    {
      // usa NegocioSucursal
      if (!IsPostBack)
      {
        cargaGridSurucrales();
      }
    }

    protected void btnFiltrar_Click(object sender, EventArgs e)
    {


      string idSucursal = txtIngreseIdSucu.Text;

      if (idSucursal == "")
      {
        cargaGridSurucrales();
        lblError.Visible = false;
        return;
      }
      else if( !Int32.TryParse(idSucursal, out int idSucInt))//TryParse trata de convertir string a int. "out in" significa "la vbandeja de salida sale con conversion exitosa"
      {
        lblError.Text = "El Id de Sucursal debe ser un número entero.";
        lblError.Visible = true;
        return;
      }
      else
      {
        NegocioSucursal negSuc = new NegocioSucursal();
        gvListar.DataSource = negSuc.negSucListarSucPorIdSuc(idSucursal);
        gvListar.DataBind();
        lblError.Visible = false;


      }


    }

    protected void btnMostrarTodosFiltrar_Click(object sender, EventArgs e)
    {
      cargaGridSurucrales();
      lblError.Visible = false;
      txtIngreseIdSucu.Text = "";
    }
  }
}