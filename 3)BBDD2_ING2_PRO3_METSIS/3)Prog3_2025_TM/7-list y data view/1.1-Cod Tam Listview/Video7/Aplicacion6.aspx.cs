using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace Video7
{
    public partial class Aplicacion6 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (IsPostBack == false)
            {
                DataSet ds = new DataSet();

                SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Empresa;Integrated Security=True");
                cn.Open();
                SqlDataAdapter adaptador = new SqlDataAdapter("SELECT [Dni], [Nombre], [Apellido], [Edad], [Sexo], [ImagenURL] FROM [Personas] ", cn);
                adaptador.Fill(ds, "Empleados");
                lvPersonas.DataSource = ds.Tables["Empleados"];
                lvPersonas.DataBind();
            }
        }
    }
}