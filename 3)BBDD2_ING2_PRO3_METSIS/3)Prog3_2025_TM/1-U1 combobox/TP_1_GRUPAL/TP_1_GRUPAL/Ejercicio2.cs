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
    public partial class Ejercicio2 : Form
    {
        public Ejercicio2()
        {
            InitializeComponent();
        }

    private void btnAgregar_Click(object sender, EventArgs e)
    {
      string nombre = tbNombre.Text;
      string apellido = tbApellido.Text;
      if(string.IsNullOrEmpty(nombre) || string.IsNullOrEmpty(apellido))
      {
        MessageBox.Show("Debe ingresar un Nombre y un Apellido");
        tbNombre.Focus();
        return;
      }

      string nombreApellido = nombre + " " + apellido; // Concatenamos nombre y apellido
      foreach (string nombreEnLista in lbxElementos.Items)//valido nombres repetidos
      { 

        // Comparamos ambos nombres en minúsculas.
        if (nombreEnLista.ToLower() == nombreApellido.ToLower())
        {
          MessageBox.Show("El nombre " + nombreApellido + " ya existe en la lista.");
          tbNombre.Clear();
          tbApellido.Clear();
          tbNombre.Focus();
          return; // Detiene la ejecución si encuentra un duplicado.
        }
      }

      lbxElementos.Items.Add(nombreApellido);
      tbNombre.Clear();
      tbApellido.Clear();
      tbNombre.Focus();
    }

    private void btnBorrar_Click(object sender, EventArgs e)
    {
      if(lbxElementos.SelectedItem == null)
      {
        MessageBox.Show("Debe seleccionar un elemento para borrar.");
        return; 
      }

      lbxElementos.Items.Remove(lbxElementos.SelectedItem);//elimina lo selecccionado
    }

    //ordena los elementos de la lista => en ListBox voy a la propiedad Started => pongo true


  }//calss Ejercicio2
}//namespace TP_1_GRUPAL

