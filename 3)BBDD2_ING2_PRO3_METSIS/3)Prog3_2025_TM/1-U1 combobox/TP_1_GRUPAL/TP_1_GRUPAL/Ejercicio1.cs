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
public partial class Ejercicio1 : Form
{
  public Ejercicio1()
  {
    InitializeComponent();
  }

    private void btnAgrgegar_Click(object sender, EventArgs e)
    {
      string nombreIngresado = tbCin.Text;// 1. Obtener el nombre del TextBox

      if (string.IsNullOrEmpty(nombreIngresado)) { //valido q no este vacio
        MessageBox.Show("Debe ingresar un Nombre");
        tbCin.Focus(); // Devolvemos el cursor al TextBox 
        return;
      }

      foreach (string nombreEnLista in lbxIzquierda.Items)//valido nombres repetidos
      {
        // Comparamos ambos nombres en minúsculas.
        if (nombreEnLista.ToLower() == nombreIngresado.ToLower())
        {
          MessageBox.Show("El nombre '" + nombreIngresado + "' ya existe en la lista.");
          tbCin.Clear();
          tbCin.Focus();
          return; // Detiene la ejecución si encuentra un duplicado.
        }
      }

      lbxIzquierda.Items.Add(nombreIngresado);

      tbCin.Clear();
      tbCin.Focus();
    }

    private void btnPasarUno_Click(object sender, EventArgs e)
    {
      if (lbxIzquierda.Items.Count == 0)
      {
        MessageBox.Show("La lista de origen está vacía. No hay nada para pasar.");
        return; // Detiene la ejecución.
      }

      //uso System.Object por que es el dato mas generico asi puede captar int,string o clases mias
      //object itemSeleccionado = lbxIzquierda.SelectedItem;

      string itemSeleccionado = (string)lbxIzquierda.SelectedItem;//como devuelve u nobject lo casteo a string
      if (itemSeleccionado == null)//si no selecciono nada
      {
        MessageBox.Show("No seleccionaste nada....");
        return;
      }
      lbxDerecha.Items.Add(itemSeleccionado);
      lbxIzquierda.Items.Remove(itemSeleccionado);

    }

    private void btnPasarTodos_Click(object sender, EventArgs e)
    {
      if (lbxIzquierda.Items.Count == 0)
      {
        MessageBox.Show("La lista de origen está vacía. No hay nada para pasar.");
        return; // Detiene la ejecución.
      }

      foreach (string nombreLista in lbxIzquierda.Items)//me hace el casteo dle objetc a string automatico
      {
        lbxDerecha.Items.Add(nombreLista);
      }

      lbxIzquierda.Items.Clear(); // Limpia la lista de origen después de pasar todos los elementos.
    }
  }

}
