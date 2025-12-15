using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;

namespace appWeb
{
    public partial class ejemplo7 : System.Web.UI.Page
    {
        private const string cadenaConexion = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnGuardar_Click(object sender, EventArgs e)
        {
            try
            {
                /// Establecer la conexión a la base de datos en SQL Server
                SqlConnection sqlConnection = new SqlConnection(cadenaConexion);
                sqlConnection.Open();

                /// Consulta SQL que se desea ejecutar
                SqlCommand sqlCommand = new SqlCommand();
                sqlCommand.Connection = sqlConnection;

                sqlCommand.CommandType = CommandType.StoredProcedure;
                sqlCommand.CommandText = "spInsertarCategoria";

                SqlParameter sqlParameter = new SqlParameter();

                // CATEGORIA
                sqlParameter = sqlCommand.Parameters.Add("@IDCATEGORIA", SqlDbType.Int);
                sqlParameter.Value = Convert.ToInt32(txtCategoria.Text);

                // NOMBRE
                sqlParameter = sqlCommand.Parameters.Add("@NOMBRECATEGORIA", SqlDbType.VarChar);
                sqlParameter.Value = txtNombre.Text;

                // DESCRIPCION
                sqlParameter = sqlCommand.Parameters.Add("@DESCRIPCION", SqlDbType.VarChar);
                sqlParameter.Value = txtDescripcion.Text;

                // EJECUTAR SENTENCIA
                int filasAfectadas = sqlCommand.ExecuteNonQuery();

                if (filasAfectadas == 1)
                {
                    limpiarTextBox();
                    lblMensaje.Text = "Operación Exitosa";
                }

                sqlConnection.Close();
            }
            catch(Exception E)
            {
                lblMensaje.Text = "Verifique sus ingresos";
            }
        }

        private void limpiarTextBox()
        {
            txtCategoria.Text = string.Empty;
            txtDescripcion.Text = string.Empty;
            txtNombre.Text = string.Empty;
        }
    }
}


//CREATE PROCEDURE spInsertarCategoria(
//	@IDCATEGORIA INT,
//	@NOMBRECATEGORIA NVARCHAR (15),
//	@DESCRIPCION NVARCHAR(40)
//)
//AS
//INSERT INTO Categorías (
//	IDCATEGORÍA,
//	NOMBRECATEGORÍA,
//	DESCRIPCIÓN
//)
//VALUES(
//	@IDCATEGORIA
//	@NOMBRECATEGORIA
//	@DESCRIPCION
//)
