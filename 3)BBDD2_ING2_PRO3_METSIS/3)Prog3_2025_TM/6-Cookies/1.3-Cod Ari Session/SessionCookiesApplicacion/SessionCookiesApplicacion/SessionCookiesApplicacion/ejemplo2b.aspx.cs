using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo2b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnClic_Click(object sender, EventArgs e)
        {
            if(Application["contador"] == null)
            {
                /// LA PRIMERA VEZ QUE SE EJECUTA EL CLIC
                /// SINO EXISTE Application["contador"] LA CREA
                Application["contador"] = 1;
            }
            else
            {
                Application["contador"] = Convert.ToInt32(Application["contador"]) + 1;
            }
        }
    }
}