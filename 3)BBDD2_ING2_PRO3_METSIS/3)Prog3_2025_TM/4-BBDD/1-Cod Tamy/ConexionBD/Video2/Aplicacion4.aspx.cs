using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;

namespace AplicacionesUnidad2
{
    public partial class Aplicacion4 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnGuardar_Click(object sender, EventArgs e)
        {
            try
            {
                SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True");
                cn.Open();

                SqlCommand cmd = new SqlCommand();
                cmd.Connection = cn;

                cmd.CommandText = "spInsertarCategoria";
                cmd.CommandType = CommandType.StoredProcedure;

                SqlParameter SqlParametros = new SqlParameter();
                SqlParametros = cmd.Parameters.Add("@IDCATEGORIA", SqlDbType.Int);
                SqlParametros.Value = Convert.ToInt32(txtIdCat.Text);

                SqlParametros = cmd.Parameters.Add("@NOMBRECATEGORIA", SqlDbType.VarChar);
                SqlParametros.Value = txtNombreCat.Text;

                SqlParametros = cmd.Parameters.Add("@DESCRIPCION", SqlDbType.VarChar);
                SqlParametros.Value = txtDescripcion.Text;

                int i = cmd.ExecuteNonQuery();

                if (i == 1)
                {
                    txtDescripcion.Text = "";
                    txtIdCat.Text = "";
                    txtNombreCat.Text = "";
                    lblMensaje.Text = "Operación realizada con exito";
                }
            }
            catch (Exception E)
            {
                lblMensaje.Text = "La operación no pudo ser realizada, el ID categoría debe ser un numero entero y verificar que no se ingrese un ID categoría existente ";
            }

        }
    }
}