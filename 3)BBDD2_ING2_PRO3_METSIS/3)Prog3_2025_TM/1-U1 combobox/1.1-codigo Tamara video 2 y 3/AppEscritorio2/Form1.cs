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
        public Form1() //Constructor de la clase
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Evento que se produce al ejecutar el formulario por primera vez
            //Solo pasa por este evento una vez

            cbColores.Items.Add("Azul");
            cbColores.Items.Add("Amarillo");
            cbColores.Items.Add("Verde");
            cbColores.Items.Add("Rojo");

        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            if(cbColores.SelectedIndex == -1)
            {
                //El usuario no selecciono ningun elemento de la lista
                MessageBox.Show("Debe seleccionar algun elemento del combobox");
            }
            else
            {
                MessageBox.Show("El elemento seleccionado por el usuario es: " + cbColores.SelectedItem +
                " y su posicion dentro del combobox es: " + cbColores.SelectedIndex);
            }
        }
    }
}
