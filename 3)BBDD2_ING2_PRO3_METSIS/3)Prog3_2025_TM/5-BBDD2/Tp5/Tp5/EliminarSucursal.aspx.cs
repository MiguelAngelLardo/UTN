using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Tp5
{
  public partial class EliminarSucursal : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnEliminar_Click(object sender, EventArgs e)
    {

      if (string.IsNullOrWhiteSpace(txtIdSucursal.Text))
      {
        lblEliminar.Text = "Debe ingresar un valor numerico";
        txtIdSucursal.Focus();
        return;
      }  

      String consulta = "DELETE FROM Sucursal Where Id_Sucursal = @id"; //sin inyeccion 
      String consulta2 = "DELETE FROM Sucursal Where Id_Sucursal =" + txtIdSucursal.Text;//sucede inyeccion -> asi lo explico tamara y no uso la sobre carga de insertarEliminarModificar

      SqlParameter parametro = new SqlParameter();//SqlParameter parametroSimple = new SqlParameter("@id", txtIdSucursal.Text);
      parametro.ParameterName = "@id";
      parametro.Value = txtIdSucursal.Text;

      Conexion conexion = new Conexion();


      int filasAfectadas = conexion.insertarEliminarModificar(consulta, parametro);

      lblEliminar.Text = (filasAfectadas > 0) ? "La sucursal se ha eliminado con éxito": "ID inexistente";
      txtIdSucursal.Text = "";//limpio text box
    }
  }
}