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
    public partial class Ejercicio3 : Form
    {
        public Ejercicio3()
        {
            InitializeComponent();
        }

    private void btnMostrar_Click(object sender, EventArgs e)
    {
      string resultado = "Usted seleccionó los siguientes elementos:\n";

      resultado += "Sexo: ";
      resultado += (rbFemenino.Checked) ? "Femenino\n" : "Masculino\n";
      resultado += "Estado Civil: ";
      resultado += (rbSoltero.Checked) ? "Soltero\n" : "Casado\n";
      resultado += "Oficio:\n";

      if (clbOficios.CheckedItems.Count > 0)
      {
        foreach (string item in clbOficios.CheckedItems)
        {
          resultado += "- " + item + "\n";
        }
      }
      else
      {
          resultado += "Ninguno seleccionado\n";
      }

      lblResultado.Text = resultado;
    }

    






    //marcar por defecto femenino y casado 0> propiedad -> checked -> true
    //clbOficio voy a items y en coleccion pongo los check ue quieri


  }
}
