using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MiPrimerSitioWeb
{
    public partial class Aplicacion2 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnMultiplicar_Click(object sender, EventArgs e)
        {
            int numero = int.Parse(txtNumero.Text);
            String tabla = "<table border='1'>";
            tabla += " <tr> <td>Producto</td> <td>Resultado</td> </tr>";
            for(int i=1; i<=10; i++)
            {
                tabla += "<tr>";
                tabla += " <td>"+ i + "X" + numero+"</td>";
                tabla += " <td> "+i*numero+" </td>";
                tabla += "</tr>";
            }
            tabla += "</table>";
            lblTabla.Text = tabla;
            txtNumero.Text = "";
        }
    }
}