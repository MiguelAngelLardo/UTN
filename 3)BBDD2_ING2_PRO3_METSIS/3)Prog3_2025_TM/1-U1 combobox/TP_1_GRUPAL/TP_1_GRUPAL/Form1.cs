using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TP_1_GRUPAL
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
           
        }

        private void btnEjercicio1_Click(object sender, EventArgs e)
        {
            Ejercicio1 ej1 = new Ejercicio1();//creo un objeto de tipo Form2
            
            foreach(var item in Application.OpenForms)
            {
                if (item.GetType() == ej1.GetType()) //verifico si el form2 ya esta abierto
                {
                    MessageBox.Show("El formulario ya se encuentra abierto");
                    return; //salgo del metodo si el ej1 ya esta abierto
                }
            }

            ej1.Show(); //muestro el form2

        }

        private void btnEjercicio2_Click(object sender, EventArgs e)
        {
            Ejercicio2 ej2 = new Ejercicio2();//creo un objeto de tipo Form2
            ej2.Show(); //muestro el form2
        }

        private void btnEjercicio3_Click(object sender, EventArgs e)
        {
            Ejercicio3 ej3 = new Ejercicio3();//creo un objeto de tipo Form2
            ej3.Show(); //muestro el form2
        }
    }
}
