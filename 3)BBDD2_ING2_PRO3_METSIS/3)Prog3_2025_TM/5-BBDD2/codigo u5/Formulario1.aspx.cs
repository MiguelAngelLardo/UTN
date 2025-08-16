using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace AccesoDatos2
{
    public partial class Formulario1 : System.Web.UI.Page
    {

        private Conexion conexion = new Conexion();

        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        protected void btnAgregar_Click(object sender, EventArgs e)
        {
            String consulta = "insert into Productos(IdProducto,NombreProducto,Suspendido) values (" + txtIdProducto.Text + ",'" + txtNombreProdcuto.Text + "'," + devuelveEstadoCheck() + ")";
            int filas=conexion.ejecutaTransaccion(consulta);
            if (filas == 0)
            { 
            //No se agregaba a a base de datos
            }
            else
            {
            //Se agrego con exito
            }
            limpiarCampos();

        }

        public void limpiarCampos()
        {
            txtIdProducto.Text = "";
            txtNombreProdcuto.Text = "";
            chkSuspendido.Checked = false;
        }

        public String devuelveEstadoCheck()
        {
            String valor = "";
            if (chkSuspendido.Checked)
            {
                valor = "1";
                //Esta checkeado
            }
            else
            {
                valor = "0";
            }
            return valor;
        }

        protected void btnEliminar_Click(object sender, EventArgs e)
        {
            String consulta = "delete from Productos where IdProducto=" + txtIdEliminar.Text;
            conexion.ejecutaTransaccion(consulta);
            txtIdEliminar.Text = "";

        }
    }
}






