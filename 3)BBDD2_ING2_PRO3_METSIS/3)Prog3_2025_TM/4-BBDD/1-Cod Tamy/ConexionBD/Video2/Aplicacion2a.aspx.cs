using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace AplicacionesUnidad2
{
    public partial class Aplicacion2a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True");
                //   cn.ConnectionString = "Data Source=localhost\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True";
                cn.Open();

                SqlCommand cmd = new SqlCommand("Select * from productos", cn);
                //  cmd.CommandText = "Select * from productos";
                // cmd.Connection = cn;

                SqlDataReader dr = cmd.ExecuteReader();

                ddlProductos.DataSource = dr;

                ddlProductos.DataTextField = "NombreProducto";
                ddlProductos.DataValueField = "IdProducto";

                ddlProductos.DataBind();

                cn.Close();


            }
        }
    }
}