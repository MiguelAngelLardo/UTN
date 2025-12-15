using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace tema5
{
    public partial class formulario1 : System.Web.UI.Page
    {
        private const string cadenaConexion = @"Data Source=localhost\SQLEXPRESS;Initial Catalog=Neptuno;Integrated Security=True";
        private string consultaSQL;
        private int filasAfectadas;
        private Conexion conexion = new Conexion();

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnAgregarProducto_Click(object sender, EventArgs e)
        {
            /// ESTABLEZCO CONSULTA SQL QUE SE DESEA EJECUTAR
            consultaSQL = "INSERT INTO Productos (IdProducto, NombreProducto, Suspendido) VALUES (" + txtIdProducto.Text + ",'" + txtNombreProducto.Text + "'," + obtenerEstadoCheckBox() +")";

            /// EJECUTAR CONSULTA
            filasAfectadas = conexion.ejecutarTransaccion(consultaSQL);

            limpiarCampos();
            mostrarMensaje(filasAfectadas);

        }

        private void mostrarMensaje(int filasAfectadas)
        {
            if(filasAfectadas == 1)
            {
                lblMensaje.Text = "Operación realizada exitosamente";
            }
            else
            {
                lblMensaje.Text = "No se pudo realizar la operación";
            }
        }

        private void limpiarCampos()
        {
            txtIdProducto.Text = string.Empty;
            txtNombreProducto.Text = string.Empty;
            chkEstado.Checked = false;
            txtIdEliminarProducto.Text = string.Empty;
        }

        private byte obtenerEstadoCheckBox()
        {
            byte estadoProducto = 0;
            if (chkEstado.Checked)
            {
                estadoProducto = 1;
            }
            return estadoProducto;
        }

        protected void btnEliminarProducto_Click(object sender, EventArgs e)
        {
            /// ESTABLEZCO CONSULTA SQL QUE SE DESEA EJECUTAR
            consultaSQL = "DELETE FROM Productos WHERE IdProducto = " + txtIdEliminarProducto.Text;
            
            /// EJECUTAR CONSULTA
            filasAfectadas = conexion.ejecutarTransaccion(consultaSQL);

            limpiarCampos();
            mostrarMensaje(filasAfectadas);
        }
    }
}