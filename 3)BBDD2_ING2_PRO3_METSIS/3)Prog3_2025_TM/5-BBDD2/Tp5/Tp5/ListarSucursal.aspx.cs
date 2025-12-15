using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Reflection;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp5
{
  public partial class ListarSucursal : System.Web.UI.Page
  {

    //A-sqlDataAdapter para solo select
    //B-sqlCommand => es para select delete update insert

    public void cargarConClase_gvListar()
    {
      // Agregamos @ al principio de la cadena de texto
      String consultaSelect = @"SELECT
                                  Sucursal.Id_Sucursal,
                                  Sucursal.NombreSucursal as Nombre,
                                  Sucursal.DescripcionSucursal as Descripcion,
                                  Provincia.DescripcionProvincia as Provincia,
                                  Sucursal.DireccionSucursal as Direccion
                                FROM
                                    Sucursal
                                INNER JOIN
                                    Provincia ON Provincia.Id_Provincia = Sucursal.Id_ProvinciaSucursal";

      Conexion conexion = new Conexion();
      DataTable dt = conexion.seleccionarDatos(consultaSelect);
      gvListar.DataSource = dt;
      gvListar.DataBind();
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        cargarConClase_gvListar();
      }

    }

    protected void btnFiltrar_Click(object sender, EventArgs e)
    {
      //valido q el txt no este vacio
      if (string.IsNullOrEmpty(txtIngreseIdSucu.Text))
      {
        cargarConClase_gvListar();
        return;
      }

      // 2. Construimos la consulta con un parámetro @Id para el filtro
      string consulta = @"SELECT
                            Sucursal.Id_Sucursal,
                            Sucursal.NombreSucursal as Nombre,
                            Sucursal.DescripcionSucursal as Descripcion,
                            Provincia.DescripcionProvincia as Provincia,
                            Sucursal.DireccionSucursal as Direccion
                          FROM
                            Sucursal
                          INNER JOIN
                            Provincia ON Provincia.Id_Provincia = Sucursal.Id_ProvinciaSucursal
                          WHERE
                            Sucursal.Id_Sucursal = @Id";

      SqlParameter[] parametroKeyValue = new SqlParameter[]
      {
        new SqlParameter("@Id", txtIngreseIdSucu.Text) //Creamos el único parámetro que necesitamos y lo ponemos dentro del array.
      };

      /*Metodo largo
       * SqlParameter[] parametros = new SqlParameter[1];
         parametros[0] = new SqlParameter("@Id", txtIngreseIdSucu.Text);
       */

      Conexion conexion = new Conexion();

       DataTable dt = conexion.seleccionarDatosConPlaceHoldder(consulta, parametroKeyValue);
       gvListar.DataSource = dt; 
       gvListar.DataBind();
    }

   
    protected void btnMostrarTodosFiltrar0_Click(object sender, EventArgs e)
    {
      cargarConClase_gvListar();
      txtIngreseIdSucu.Text = ""; // Opcional: limpiar el TextBox del filtro
    }
  }
}