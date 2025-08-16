using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Ej1_Formulario
{
  public partial class WebForm1 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void btnGenerarTabla_Click(object sender, EventArgs e)
    {
      string productoA = txtProductoA.Text;
      string productoB = txtProductoB.Text;

      int cantidadA = int.Parse(txtCantidadA.Text);// el texto que un usuario escribe en un TextBox es siempre de tipo string
      int cantidadB = int.Parse(txtCantidadB.Text);

      string tabla = "<table border='1'>";//table es etiqueta de html que el navegador lo inerpreta y le da formato
      tabla += "<tr> <th>Producto</th> <th>Cantidad</th> </tr>";
      tabla += "<tr> <td>" + productoA + "</td> <td>" + cantidadA + "</td> </tr>";
      tabla += "<tr> <td>" + productoB + "</td> <td>" + cantidadB + "</td> </tr>";
      tabla += "<tr> <td> TOTAL </td> <td>" +  (cantidadA + cantidadB) + "</td> </tr>";
      tabla += "</table>";

      lblTabla.Text = tabla; // la tabla debe ir en label para mostrarla





    }
  }
}