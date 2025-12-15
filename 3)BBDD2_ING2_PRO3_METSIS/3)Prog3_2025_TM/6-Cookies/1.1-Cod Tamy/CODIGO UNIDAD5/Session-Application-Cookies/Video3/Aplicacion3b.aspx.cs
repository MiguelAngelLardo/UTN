using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace Aplicaciones
{
    public partial class Aplicacion3b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if(Session["tabla"]!= null)
            {
                grdPersonas.DataSource = (DataTable)Session["tabla"];
                grdPersonas.DataBind();
            }
        }

        protected void btnEliminar_Click(object sender, EventArgs e)
        {
            Session["tabla"] = null;
            grdPersonas.DataSource = null;
            grdPersonas.DataBind();
        }
    }
}