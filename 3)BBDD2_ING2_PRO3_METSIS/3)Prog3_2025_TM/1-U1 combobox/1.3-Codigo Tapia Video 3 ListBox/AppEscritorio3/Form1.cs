using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppEscritorio3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnAgregar_Click(object sender, EventArgs e)
        {
            if(txtNombreApellido.Text.Trim().Length > 0  )
            //if (txtNombreApellido.Text.Trim() != "")
            {
                lbPersonas.Items.Add(txtNombreApellido.Text.Trim());
                txtNombreApellido.Text = "";
            }
            else
            {
                MessageBox.Show("Debe ingresar nombre y apellido");
            }
        }

        private void btnSeleccionado_Click(object sender, EventArgs e)
        {
            //MessageBox.Show("El elemento seleccionado fue " + lbPersonas.SelectedItems);
            //MessageBox.Show("En el posición " + lbPersonas.SelectedIndex);

            foreach (String persona in lbPersonas.SelectedItems)
            {
                MessageBox.Show("El elemento seleccionado fue " + persona);
            }

            // SIRVE PARA SEPARAR CADENA DE CARACTERES
            //String ejemplo1 = "Joel - Maria - Sofia";
            //String p1 = ejemplo1.Split('-')[0]; // Devuelve Joel
            //String p2 = ejemplo1.Split('-')[1]; // Devuelve Maria
            //String p3 = ejemplo1.Split('-')[2]; // Devuelve Sofia

            //MessageBox.Show(p1);
            //MessageBox.Show(p2);
            //MessageBox.Show(p3);


            //  SIRVE PARA COMPARAR TEXTO
            //String p4 = "ARIEL";
            //String p5 = "aRiEl";

            //if(p4.ToUpper()  == p5.ToUpper())
            //{
            //    MessageBox.Show("Es el mismo nombre");
            //}

            //else
            //{
            //    MessageBox.Show("Son nombre diferentes");
            //}

            String p6 = "ARIEL".Replace('A', 'Y');
            MessageBox.Show(p6);


        }
    }
}
