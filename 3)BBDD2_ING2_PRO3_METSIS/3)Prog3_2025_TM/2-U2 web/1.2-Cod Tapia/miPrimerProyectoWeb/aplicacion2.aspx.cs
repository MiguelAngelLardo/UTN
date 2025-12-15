using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace miPrimerProyectoWeb
{
    public partial class aplicacion2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnVerTabla_Click(object sender, EventArgs e)
        {
            int numero = int.Parse(txtIngreso.Text);
            string tabla = "<table border='1'";
            tabla += "<tr><td>Producto</td> <td>Resultado</td> </tr>";
            for(int i = 1; i <= 10; i++)
            {
                tabla += "<tr>";
                tabla += "<td>" + i + " x " + numero + "</td>";
                tabla += "<td>" + i * numero + "</td>";
                tabla += "</tr>";
            }
            tabla += "</table>";
            lblTabla.Text = tabla;
            txtIngreso.Text = "";
        }
    }
}