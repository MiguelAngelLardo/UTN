using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Video7
{
    public partial class Aplicacion5 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnOrdenar_Click(object sender, EventArgs e)
        {
            SqlDataSource1.SelectCommand = "SELECT [Dni], [Nombre], [Apellido], [Edad], [Sexo], [ImagenURL] FROM [Personas] ORDER BY [Nombre]";
        }
    }
}