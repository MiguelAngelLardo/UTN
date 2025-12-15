using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CargarSugerencias
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //TENGO LOS ITEMS CARGADOS EN EL COMBOBOX
            //Le decis que va a brindar sugerencias:
            cmbNombres.AutoCompleteMode = AutoCompleteMode.SuggestAppend;
            //De la siguiente manera le decis que se complete con los mismos items que se encuentra
            //en el listboz
            cmbNombres.AutoCompleteSource = AutoCompleteSource.ListItems;
        }
    }
}
