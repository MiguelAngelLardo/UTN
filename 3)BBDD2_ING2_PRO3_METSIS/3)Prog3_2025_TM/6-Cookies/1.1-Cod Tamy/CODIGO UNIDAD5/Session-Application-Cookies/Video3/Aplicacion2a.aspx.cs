using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Aplicaciones
{
    public partial class Aplicacion2a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnContar_Click(object sender, EventArgs e)
        {
            if(Application["cant"] == null)
            {
                Application["cant"] = 1; //La 1era vez que se hace click sobre el boton contar
            }
            else
            {
                Application["cant"] = Convert.ToInt32(Application["cant"]) + 1;
            }
        }
    }
}