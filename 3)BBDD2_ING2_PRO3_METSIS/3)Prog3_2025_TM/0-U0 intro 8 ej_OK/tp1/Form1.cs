using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MiPrimerAplicacion
{
    public partial class Name : Form
    {
        public Name()
        {
            InitializeComponent();
        }

        private void Name_Load(object sender, EventArgs e)
        {
            MessageBox.Show("Bienvenidos a C#");
        }

        private void Name_FormClosed(object sender, FormClosedEventArgs e) //este metodo se ejecuta cuando se cierra la ventana
        {
            MessageBox.Show("Chau Chau ...");
        }


    }
}
