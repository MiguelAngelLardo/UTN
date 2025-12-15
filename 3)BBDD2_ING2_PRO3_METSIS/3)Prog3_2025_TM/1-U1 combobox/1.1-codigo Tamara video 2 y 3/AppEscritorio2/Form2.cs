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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void btnAceptar_Click(object sender, EventArgs e)
        {
            if (txtNombres.Text.Trim().Length != 0)
           //if (txtNombres.Text.Trim() != "" )
            { 
                lbPersonas.Items.Add(txtNombres.Text);
                txtNombres.Text = "";
            }
            else
            {
                MessageBox.Show("Debe ingresar un nombre");
            }
        }

        private void btnMostrarSeleccionado_Click(object sender, EventArgs e)
        { 
          //  MessageBox.Show("El elemento seleccionado fue: " + lbPersonas.SelectedItem);
          //  MessageBox.Show("El indice del elemento seleccionado fue: " + lbPersonas.SelectedIndex);

            foreach(String aux in lbPersonas.SelectedItems)
            {
                MessageBox.Show("Elemento seleccionado " + aux);
            }


            /*    
            //SPLIT:  Sirve para partir cadenas
            
            String varNombre = "Pepito - Jose - Maria";
            String p1 = varNombre.Split('-')[0]; //Obtiene pepito
            String p2 = varNombre.Split('-')[1]; //Obtiene jose
            String p3 = varNombre.Split('-')[2]; //Obtiene pepito
            MessageBox.Show(p1);
            MessageBox.Show(p2);
            MessageBox.Show(p3);
            */



            /*
            //UPPER: Convierte en mayusculas. Me sirve para comparar textos
            String p4 = "Jose";
            String p5 = "josE";

            if(p4.ToUpper()==p5.ToUpper())
            {
                MessageBox.Show("Son iguales");
            }
            else
            {
                MessageBox.Show("Son distintos");
            }
            */

        }

    }
}
