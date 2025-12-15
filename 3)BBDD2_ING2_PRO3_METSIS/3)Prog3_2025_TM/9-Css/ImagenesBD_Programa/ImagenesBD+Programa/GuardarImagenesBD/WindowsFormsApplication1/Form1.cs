using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void browseButton_Click(object sender, EventArgs e)
        {
            //Este es el código del boton buscador

            // Se crea el OpenFileDialog para que se pueda selecciona un archivo
            OpenFileDialog dialog = new OpenFileDialog();
            // Se muestra al usuario esperando una acción
            DialogResult result = dialog.ShowDialog();
            //showdialog muestra al usuario el openfiledialog
            //result espera que el usuario seleccione un archivo
  
            if (result == DialogResult.OK)
            {
                //aca entra cuando el usuario da aceptar a la imagen del buscador
                //si selecciona una imagen la muestra en el picturebox
                pictureBox.Image = Image.FromFile(dialog.FileName);
            }
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            try
            {
             // Objetos de conexión y comando
              SqlConnection conn = new SqlConnection("Data Source=TAMARACARLOS-PC\\SQLEXPRESS;Initial Catalog=Store;Integrated Security=True");
              SqlCommand cmd = new SqlCommand();

                // Estableciento propiedades
               cmd.Connection = conn;
               cmd.CommandText = "INSERT INTO Products VALUES (@id, @name, @quantity, @price, @image)";

                // Creando los parámetros necesarios
                cmd.Parameters.Add("@id", System.Data.SqlDbType.Int);
                cmd.Parameters.Add("@name", System.Data.SqlDbType.NVarChar);
                cmd.Parameters.Add("@quantity", System.Data.SqlDbType.Int);
                cmd.Parameters.Add("@price", System.Data.SqlDbType.SmallMoney);
                cmd.Parameters.Add("@image", System.Data.SqlDbType.Image);

                // Asignando los valores a los atributos
                cmd.Parameters["@id"].Value = int.Parse(txtClave.Text);
                cmd.Parameters["@name"].Value = txtNombre.Text;
                cmd.Parameters["@quantity"].Value = int.Parse(txtExistencia.Text);
                cmd.Parameters["@price"].Value = float.Parse(txtPrecio.Text);

                // Asignando el valor de la imagen

                // Stream usado como buffer
                System.IO.MemoryStream ms = new System.IO.MemoryStream();
                // Se guarda la imagen en el buffer
                pictureBox.Image.Save(ms, System.Drawing.Imaging.ImageFormat.Jpeg);
                // Se extraen los bytes del buffer para asignarlos como valor para el 
                // parámetro.
                cmd.Parameters["@image"].Value = ms.GetBuffer();

                conn.Open();
                cmd.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("Guardado en la base de datos");
                txtClave.Text = "";
                txtExistencia.Text = "";
                txtId.Text = "";
                txtNombre.Text = "";
                txtPrecio.Text = "";
                pictureBox.Image = null;
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                DataSet ds = new DataSet();
                string conexion;
                string consulta;
                conexion = "Data Source=TAMARACARLOS-PC\\SQLEXPRESS;Initial Catalog=Store;Integrated Security=True";
                consulta = "select productImage from Products where id='" + txtId.Text + "'";
                SqlConnection cn = new SqlConnection(conexion);
                cn.Open();
                SqlDataAdapter adaptador = new SqlDataAdapter(consulta, cn);
                adaptador.Fill(ds, "products");

                byte[] imageBuffer = (byte[])ds.Tables["products"].Rows[0]["productImage"];
                // Se crea un MemoryStream a partir de ese buffer
                System.IO.MemoryStream ms = new System.IO.MemoryStream(imageBuffer);
                // Se utiliza el MemoryStream para extraer la imagen
                pictureBox1.Image = Image.FromStream(ms);
            }
            catch
            {
                MessageBox.Show("ID del producto inexistente");
                pictureBox1.Image = null;
                
            }
        }

        private void txtClave_KeyPress(object sender, KeyPressEventArgs e)
        {
            //validacion para que solo se ingresen numeros
            if (char.IsLetter(e.KeyChar))
            {
                e.Handled = true;
            }
            else
            {
                e.Handled = false;
            }
        }

        private void txtNombre_KeyPress(object sender, KeyPressEventArgs e)
        {
            //validacion solo se ingresen letras
            if (char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
           
        }

        private void txtExistencia_KeyPress(object sender, KeyPressEventArgs e)
        {
            //validacion para que solo se ingresen numeros
            if (char.IsLetter(e.KeyChar))
            {
                e.Handled = true;
            }
            
        }

        private void txtPrecio_KeyPress(object sender, KeyPressEventArgs e)
        {
            //validacion para que solo se ingresen numeros
            if (char.IsLetter(e.KeyChar))
            {
                e.Handled = true;
            }
           
        }

        private void txtId_KeyPress(object sender, KeyPressEventArgs e)
        {
            //validacion para que solo se ingresen numeros
            if (char.IsLetter(e.KeyChar))
            {
                e.Handled = true;
            }
        }
                
        
    }
}
