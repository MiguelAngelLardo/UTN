using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ej9_Listview
{
    public partial class frmListView : Form
    {
        private System.Collections.Specialized.StringCollection colListCarpeta;
        // ESTE ES EL ÚNICO CONSTRUCTOR QUE DEBE QUEDAR
        public frmListView()
        {
            InitializeComponent();
            colListCarpeta = new System.Collections.Specialized.StringCollection();
            CrearCabecerayLlenarListView();
            DibujarListView(@"C:\");
            colListCarpeta.Add(@"C:\");
        }

        private void CrearCabecerayLlenarListView()
        {
            ColumnHeader colCab; //Declaro un objeto ColumnHeader.
            colCab = new ColumnHeader(); //Instancio el objeto ColumnHeader.
            colCab.Text = "Nombre Archivo";
            lvCarpetas.Columns.Add(colCab); // Inserto la Cabecera Nombre Archivo.
            colCab = new ColumnHeader();
            colCab.Text = "Tamaño";
            lvCarpetas.Columns.Add(colCab); // Inserto la Cabecera Tamaño.
            colCab = new ColumnHeader(); colCab.Text = "Ultima Modificacion";
            lvCarpetas.Columns.Add(colCab); // Inserto la Cabecera Ultima Modificacion.
        }



        private void DibujarListView(string root)
        {
            try
            {
                ListViewItem lvi;
                ListViewItem.ListViewSubItem lvsi;

                if (string.IsNullOrEmpty(root)) return;

                DirectoryInfo dir = new DirectoryInfo(root);
                DirectoryInfo[] dirs = dir.GetDirectories();
                FileInfo[] files = dir.GetFiles();

                lvCarpetas.Items.Clear();
                lblActualdir.Text = root;

                lvCarpetas.BeginUpdate();

                foreach (DirectoryInfo di in dirs)
                {
                    lvi = new ListViewItem();
                    lvi.Text = di.Name;
                    lvi.ImageIndex = 0;
                    lvi.Tag = di.FullName;

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = "";
                    lvi.SubItems.Add(lvsi);

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = di.LastAccessTime.ToString();
                    lvi.SubItems.Add(lvsi);

                    lvCarpetas.Items.Add(lvi);
                }

                foreach (FileInfo fi in files)
                {
                    lvi = new ListViewItem();
                    lvi.Text = fi.Name;
                    lvi.ImageIndex = 1;
                    lvi.Tag = fi.FullName;

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = fi.Length.ToString();
                    lvi.SubItems.Add(lvsi);

                    lvsi = new ListViewItem.ListViewSubItem();
                    lvsi.Text = fi.LastAccessTime.ToString();
                    lvi.SubItems.Add(lvsi);

                    lvCarpetas.Items.Add(lvi);
                }

                lvCarpetas.EndUpdate();
            }
            catch (System.Exception err)
            {
                MessageBox.Show("Error: " + err.Message);
            }
        }

        private void lvCarpetas_ItemActivate(object sender, EventArgs e)
        {
            System.Windows.Forms.ListView lw = (System.Windows.Forms.ListView)sender;
            string filename = lw.SelectedItems[0].Tag.ToString();

            // Si el ImageIndex es diferente de 0, es un archivo. Si es 0, es una carpeta.
            if (lw.SelectedItems[0].ImageIndex != 0)
            {
                try
                {
                    // Intenta abrir el archivo con el programa predeterminado del sistema.
                    System.Diagnostics.Process.Start(filename);
                }
                catch
                {
                    return;
                }
            }
            else
            {
                // Si es una carpeta, vuelve a dibujar el contenido del ListView con la nueva ruta.
                DibujarListView(filename);
                // Agrega la nueva carpeta al historial para poder usar el botón "Atrás".
                colListCarpeta.Add(filename);
            }
        }


        private void btnAtras_Click(object sender, EventArgs e) { 
            if (colListCarpeta.Count > 1) { 
                DibujarListView(colListCarpeta[colListCarpeta.Count - 2].ToString());
                colListCarpeta.RemoveAt(colListCarpeta.Count - 1); 
            } else 
                DibujarListView(colListCarpeta[0].ToString()); 
        }

        private void rbLarge_CheckedChanged(object sender, EventArgs e) { RadioButton rdb = (RadioButton)sender; if (rdb.Checked) this.lvCarpetas.View = View.LargeIcon; }
        private void rbSmall_CheckedChanged(object sender, EventArgs e) { RadioButton rdb = (RadioButton)sender; if (rdb.Checked) lvCarpetas.View = View.SmallIcon; }
        private void rbLista_CheckedChanged(object sender, EventArgs e) { RadioButton rdb = (RadioButton)sender; if (rdb.Checked) lvCarpetas.View = View.List; }
        private void rbDetalle_CheckedChanged(object sender, EventArgs e) { RadioButton rdb = (RadioButton)sender; if (rdb.Checked) lvCarpetas.View = View.Details; }
        private void rbTitulo_CheckedChanged(object sender, EventArgs e) { RadioButton rdb = (RadioButton)sender; if (rdb.Checked) lvCarpetas.View = View.Tile; }

    }
}
