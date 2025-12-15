using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppEscritorio4
{
    public partial class Formulario2 : Form
    {
        Formulario1 formulario1;
        public Formulario2(Formulario1 formulario1)
        {
            InitializeComponent();
            this.formulario1 = formulario1;
        }

        private void Formulario2_FormClosed(object sender, FormClosedEventArgs e)
        {
            formulario1.Show();
        }
    }
}
