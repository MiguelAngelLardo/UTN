using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppEscritorio2
{
    public partial class Form1 : Form
    {
        public Form1()  // Constructor
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //  este evento se produce una unica vez al ejecutar el formulario
            cmbColores.Items.Add("Rojo");
            cmbColores.Items.Add("Azul");
            cmbColores.Items.Add("Amarillo");
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            if (cmbColores.SelectedIndex != -1)
            {
                int seleccionado = cmbColores.SelectedIndex + 1;
                MessageBox.Show("El elemento seleccionado es " + cmbColores.SelectedItem + " y está en el orden " +
                    seleccionado);
            }

            else
            {
                MessageBox.Show("Seleccione un item");
            }
        }
    }
}
