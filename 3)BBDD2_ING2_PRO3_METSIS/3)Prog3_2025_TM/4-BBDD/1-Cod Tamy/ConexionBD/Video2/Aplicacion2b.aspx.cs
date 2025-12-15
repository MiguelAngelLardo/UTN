using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace AplicacionesUnidad2
{
    public partial class Aplicacion2b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True");
                cn.Open();

                SqlDataAdapter adap = new SqlDataAdapter("Select * from productos", cn);
                DataSet ds = new DataSet();
                adap.Fill(ds, "TablaProductos");

                ddlProductos.DataSource = ds.Tables["TablaProductos"];

                ddlProductos.DataTextField = "NombreProducto";
                ddlProductos.DataValueField = "IdProducto";

                ddlProductos.DataBind();


            }
        }
    }
}