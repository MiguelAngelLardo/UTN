using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo3a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["tabla"] != null)
            {
                gvUsuarios.DataSource = (DataTable)Session["tabla"];
                gvUsuarios.DataBind();
            }
        }

        protected void btnEliminar_Click(object sender, EventArgs e)
        {
            Session["tabla"] = null;
            gvUsuarios.DataSource = null;
            gvUsuarios.DataBind();
        }
    }
}