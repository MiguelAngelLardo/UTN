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
    public partial class Formulario1 : Form
    {
        public Formulario1()
        {
            InitializeComponent();
        }

        private void btnIrFormulario2_Click(object sender, EventArgs e)
        {
            Formulario2 formulario2 = new Formulario2(this);
            formulario2.Show();
            this.Hide();
        }
    }
}
