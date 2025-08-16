using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;


namespace TrabajandoConClases
{
    public partial class Listar : System.Web.UI.Page
    {
        Negocio negocio = new Negocio();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                CargarSucursales();
            }
        }
        private void CargarSucursales()
        {
            gv_Sucursales.DataSource = negocio.ObtenerSucursales();
            gv_Sucursales.DataBind();
        }
    }
}

