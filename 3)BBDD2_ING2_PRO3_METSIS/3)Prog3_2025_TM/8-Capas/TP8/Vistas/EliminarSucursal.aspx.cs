using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using Negocio;
namespace Vistas
{
  public partial class EliminarSucursal : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnEliminar_Click(object sender, EventArgs e)
    {
      string idEliminar = txtIdSucursal.Text.Trim();

      if(idEliminar.Length == 0)
      {
        lblEliminar.Visible = false;
      }
      
      NegocioSucursal negSuc = new NegocioSucursal();
      bool eliminadoCorrectamente = negSuc.negSucEliminarSucursal(idEliminar);
      lblEliminar.Text = eliminadoCorrectamente ? "Sucursal eliminada correctamente." : "Error al eliminar la sucursal.";
    }
  }
}