using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace appWeb
{
    public partial class ejemplo2 : System.Web.UI.Page
    {
        private const string cadenaConexion = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
        private string consultaSQL = "SELECT * FROM productos";
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                // Establecer la conexión a la base de datos en SQL Server

                SqlConnection sqlConnection = new SqlConnection(cadenaConexion);
                sqlConnection.Open();

                // Consulta SQL que se desea ejecutar

                SqlDataAdapter sqlDataAdapter = new SqlDataAdapter(consultaSQL,sqlConnection);

                DataSet dataSet = new DataSet();
                sqlDataAdapter.Fill(dataSet,"TablaProductos");

                // Asignar la tabla de datos como origen de datos del GridView

                gvProductos.DataSource = dataSet.Tables["TablaProductos"];
                gvProductos.DataBind();

                sqlConnection.Close();
            }
        }
    }
}