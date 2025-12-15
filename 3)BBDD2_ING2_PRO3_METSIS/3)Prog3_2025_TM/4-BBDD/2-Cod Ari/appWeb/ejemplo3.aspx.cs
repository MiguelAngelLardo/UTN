using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace appWeb
{
    public partial class ejemplo3 : System.Web.UI.Page
    {
        private const string cadenaConexion = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
        private string consultaSQL = "SELECT * FROM productos";
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                ///Establecer la conexión a la base de datos en SQL Server

                SqlConnection connection = new SqlConnection(cadenaConexion);
                connection.Open();

                /// Consulta SQL que se desea ejecutar

                SqlCommand sqlCommand = new SqlCommand(consultaSQL, connection);
                SqlDataReader sqlDataReader = sqlCommand.ExecuteReader();

                /// Asignar la tabla de datos como origen de datos del DropDownList

                ddlProductos.DataSource = sqlDataReader;
                ddlProductos.DataTextField = "NombreProducto";
                ddlProductos.DataValueField = "IdProducto";
                ddlProductos.DataBind();

                connection.Close();
            }
        }
    }
}