using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_8
{
    public partial class frmListBoxCheckedListBox : Form
    {
        public frmListBoxCheckedListBox()
        {
            InitializeComponent();

            clbValores.Items.Add("Diez");
        }

        private void btnMover_Click(object sender, EventArgs e)
        {
            //Pregunta si la cantidad (Count) de elementos chequeados
            //en la coleccion de items chequeados(CheckedItems) es mayor a cero.
            if (clbValores.CheckedItems.Count >= 0)
            {
                 //Si es mayor a cero. Limpia los Item en el ListBox.
                 lbSeleccionados.Items.Clear();

                //La sentencia foreach recorre la coleccion de Items Seleccionados
                //Y los asigna de a uno a la variable item del tipo String.
                foreach (string item in clbValores.CheckedItems)
                {
                    //Agrego los items seleccionados en la colección
                    //Al Listbox con el Metodo Add.
                    lbSeleccionados.Items.Add(item.ToString());
                }
                //Recorro todos los Items del CheckedListBox.
                for (int i = 0; i < clbValores.Items.Count; i++)
                    //Con el Metodo SetItemChecked, establesco en falso la
                    //casilla de verificación (No esta seleccionado).
                    //Como parametros i-El Indice y el valor de estado en este caso
                   // false.
                     clbValores.SetItemChecked(i, false);
            }
        }
}
}
