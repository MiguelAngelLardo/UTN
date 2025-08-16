using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_5
{
    public partial class fDatosPersonales : Form
    {
        private List<string> datos = new List<string>();

        public fDatosPersonales()
        {
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            if ((tbApelido.Text.Length == 0) ||
                (tbNombre.Text.Length == 0) ||
                (tbEdad.Text.Length == 0) ||
                (tbDireccion.Text.Length == 0))
            {
                MessageBox.Show("Debe rellenar todos los campos", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                //poner rojo a cada tb
                tbApelido.BackColor = Color.Red;
                tbNombre.BackColor = Color.Red;
                tbEdad.BackColor = Color.Red;
                tbDireccion.BackColor = Color.Red;
            }
            else
            {
                //poner blanco a cada tb
                tbApelido.BackColor = Color.White;
                tbNombre.BackColor = Color.White;
                tbEdad.BackColor = Color.White;
                tbDireccion.BackColor = Color.White;
            

            // quiero cargar el tbApellido tbNombre tbEdad tbDireccion en tbResultado
            string resultado = $"Apellido: {tbApelido.Text}\r\n" +
                               $"Nombre: {tbNombre.Text}\r\n" +
                               $"Edad: {tbEdad.Text}\r\n" +
                               $"Dirección: {tbDireccion.Text}\r\n \r\n";

            //crea una coleccion de string y guarda resultado

            datos.Add(resultado);

            // Concatenar todos los resultados acumulados y mostrarlos en tbResultado
            tbResultado.Text = string.Join("", datos);

                // Limpiar los campos de entrada
                tbApelido.Text = "";
                tbNombre.Text = "";
                tbEdad.Text = "";
                tbDireccion.Text = "";

            }
        }
        private void btnCancelar_Click(object sender, EventArgs e)
        {
            //cerrar el formulario
            this.Close();
        }

        private void tbEdad_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar) && !char.IsDigit(e.KeyChar))
            {
                // Si no es un dígito ni una tecla de control, cancelar el evento
                e.Handled = true;
            }
        }
    }
}
