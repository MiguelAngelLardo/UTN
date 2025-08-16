using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _9_TryCatch
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnConvertir_Click(object sender, EventArgs e)
        {
            /*try
            {
                int num = Convert.ToInt32(txtNumero.Text);
            }
            catch
            {
                MessageBox.Show("Se ha producido una Excepción.");
            }*/

            try
            {
                int num = Convert.ToInt32(txtNumero.Text);
            }
            //Los identificadores de objetos que se utilizan
            //como fe son arbitrarios y solo existen en el ambito
            //del bloque Catch.
            catch (FormatException fe)
            {
                MessageBox.Show(fe.Message);
            }

        }
    }
}
