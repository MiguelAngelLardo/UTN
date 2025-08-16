using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_2
{
    public partial class Form1 : Form
    {
        // Constructor del formulario principal. Inicializa los componentes de la interfaz.
        public Form1()
        {
            InitializeComponent();
        }

        // Evento Click del botón btnRun1. Cambia el color de fondo del formulario a azul.
        private void btnRun1_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Se disparo 1 el evento Click", "Atención");
            this.BackColor = Color.Blue;
        }

        // Evento Click del formulario. Muestra un mensaje según el botón del mouse presionado.
        private void Form1_Click(object sender, EventArgs e)
        {
            MouseEventArgs click = (MouseEventArgs)e;


            if (click.Button == MouseButtons.Left)
                MessageBox.Show("Presiono el botón Izquierdo", "Atención");
            else if (click.Button == MouseButtons.Right)
                MessageBox.Show("Presiono el Botón Derecho", "Atención");
            else if (click.Button == MouseButtons.Middle)
                MessageBox.Show("Presiono el botón del Medio", "Atención");
        }
    }
}
