using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Entidades; //no la use hasta ahora
using Negocio;

namespace Vistas
{
  public partial class AgregarSucursal : System.Web.UI.Page
  { 

    public void cargarDdlProvincias1()
    {
      // La Vista le pide los datos a la capa de Negocio.
      NegocioProvincia negProv = new NegocioProvincia();

      ddlProvincia.DataSource = negProv.negProvGetListaProv();

      ddlProvincia.DataValueField = "propIdProvincia"; //si no lo hago property no funciona con get de c++
      ddlProvincia.DataTextField = "propDescripcionProvincia";
      ddlProvincia.DataBind();
      ddlProvincia.Items.Insert(0, new ListItem("--Seleccionar--", "0"));

    }


    public void cargarDdlProvincias2()
    {
      NegocioProvincia negProv = new NegocioProvincia();

      // DataSource ahora recibe el DataTable directamente.
      ddlProvincia.DataSource = negProv.getTablaProvincias();

      // Los nombres deben coincidir con las COLUMNAS del DataTable.
      ddlProvincia.DataValueField = "Id_Provincia";
      ddlProvincia.DataTextField = "DescripcionProvincia";
      ddlProvincia.DataBind();

      ddlProvincia.Items.Insert(0, new ListItem("--Seleccionar--", "0"));
    }






    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        cargarDdlProvincias2();
      }
    }

    protected void btnAceptar_Click(object sender, EventArgs e)
    {
      NegocioSucursal negSuc = new NegocioSucursal();

      Sucursal nuevaSuc = new Sucursal();
      nuevaSuc.setNombreSucursal(txtNombreSuc.Text);
      nuevaSuc.setDescripcionSucursal(txtDescripcionSuc.Text);
      nuevaSuc.setIdProvincia(Convert.ToInt32(ddlProvincia.SelectedValue));
      nuevaSuc.setDireccionSucursal(txtDireccion.Text);

      bool seAgrego = new NegocioSucursal().negSucAgregarSucursal(nuevaSuc);

      lblConfirmacion.Text = seAgrego ? "La sucursal se ha agregado con éxito" : "No se pudo agregar la sucursal";

       
    }
  }
}