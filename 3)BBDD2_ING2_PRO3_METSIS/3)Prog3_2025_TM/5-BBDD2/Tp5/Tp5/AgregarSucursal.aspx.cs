using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data.SqlClient;
using System.Data;
namespace Tp5
{
  public partial class AgregarSucursal : System.Web.UI.Page
  {

    /*
    public void cargarTradicional_ddlProvincias()
    {
      SqlConnection cn = new SqlConnection("Data Source=localhost\\SQLEXPRESS;Initial Catalog=BDSucursales;Integrated Security=True;");
      cn.Open();
      
      SqlCommand cmd = new SqlCommand("SELECT ID_Provincia, DescripcionProvincia FROM Provincia", cn);
      SqlDataReader dr = cmd.ExecuteReader();

      ddlProvincia.DataSource = dr;
      ddlProvincia.DataValueField = "ID_Provincia";
      ddlProvincia.DataTextField = "DescripcionProvincia";
      ddlProvincia.DataBind();

      cn.Close();


      //ddlProvincia.Items.Add(new ListItem("--seleccionar--", "0"));
      // Usamos Insert(0, ...) para agregar el item al PRINCIPIO de la lista, DESPUÉS de cargar los datos.
      ddlProvincia.Items.Insert(0, new ListItem("--seleccionar--", "0"));
    }*/

    public void cargaConClase_ddlProvincias()
    {
      String consultaSeleccionar = "SELECT ID_Provincia, DescripcionProvincia FROM Provincia";
      Conexion objConexion = new Conexion();
      DataTable dt = objConexion.seleccionarDatos(consultaSeleccionar);

      ddlProvincia.DataSource = dt;
      ddlProvincia.DataValueField = "ID_Provincia";
      ddlProvincia.DataTextField = "DescripcionProvincia";
      ddlProvincia.DataBind();

      // 3. Insertamos el item por defecto
      ddlProvincia.Items.Insert(0, new ListItem("--seleccionar--", "0"));
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      if(!IsPostBack)
      {
        //cargarTradicional_ddlProvincias();
        cargaConClase_ddlProvincias();
      }
    }

    protected void btnAceptar_Click(object sender, EventArgs e)
    {
      //Id_Sucursal es int auto incremental PK not null
      //NombreSucursal es varchar 100 not null
      //DescripcionSucursal es Varchar 100 not null
      //Id_ProvinciaSucursal es int not null FK
      //DireccionSucursal varchar 100 null
      //INSERT INTO Sucursal (NombreSucursal, DescripcionSucursal, Id_ProvinciaSucursal) VALUES('Sucursal Caballito', 'Sucursal principal en el barrio de Caballito', 1);
      String consultaInsertar = " INSERT INTO Sucursal(NombreSucursal, DescripcionSucursal, Id_ProvinciaSucursal, DireccionSucursal) VALUES ('"+txtNombreSuc.Text+"', '"+txtDescripcion.Text+"', "+ddlProvincia.SelectedValue+",'"+txtDireccion.Text +"' )";

      Conexion objConexion = new Conexion();
      int filasAfectadas = objConexion.insertarEliminarModificar(consultaInsertar);

      lblConfirmacion.Text = (filasAfectadas > 0) ? "La sucursal se ha agregado con éxito" : "No se pudo agregar la sucursal";

    }
  }
}

