using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppEscritorio1
{
    public partial class AppEscritorio1 : Form
    {
        public AppEscritorio1()
        {
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("Bienvenido/a " + txtNombre.Text, "Atención");
            MessageBox.Show("Bienvenido/a " + txtNombre.Text);
            //txtNombre.Text = "";
            txtNombre.Text = string.Empty;
        }
    }
}
