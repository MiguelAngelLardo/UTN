using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_6
{
    public partial class fmrRbtnCb : Form
    {
        public fmrRbtnCb()
        {
            InitializeComponent();

            cbProgramador.Checked = true;
            rbHombre.Checked = true;
        }

        private void ValidarOk()
        {
            //Habilita el Boton, siempre y cuando txtNombre tenga datos.
            btnOk.Enabled = (txtNombre.BackColor != Color.Red);
        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            String salida; //Declaro una variable para armar la salida.
            salida = "Nombe: " + txtNombre.Text + "\r\n";
            salida += "Ocupacion: " + (string)(cbProgramador.Checked ?
            "Programador" : "No es Programador") + "\r\n";
            salida += "Sexo: " + (string)(rbHombre.Checked ? "Hombre" :
            "Mujer") + "\r\n";

            //Vuelco la salida al TextBox Salida.
            tbSalida.Text = salida;
        }

        private void fmrRbtnCb_Load(object sender, EventArgs e)
        {
            btnOk.Enabled = false;
        }

        private void txtNombre_Validating(object sender, CancelEventArgs e)
        {
            TextBox tb = (TextBox)sender;
            if (tb.Text.Length == 0)
                tb.BackColor = Color.Red;
            else
                tb.BackColor = System.Drawing.SystemColors.Window;
            ValidarOk();
        }
    }
}
