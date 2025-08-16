using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PRACTICA_7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void AplicarTamanioText(string textSize)
        {
            //Declaro una Var. y le asigno el valor pasado, previa Conversion.
            float nuevoTam = Convert.ToSingle(textSize);
            //Declaro un Objeto FontFamily para el tipo de Fuente actual.
            FontFamily actualFuenteFamily;

            //Declaro un Objeto Font para la nueva Fuente.
            Font nuevaFuente;

            //De la selección actual del RichTextBox obtengo
            //el tipo de familia de la fuente.
            actualFuenteFamily = rtxtEditor.SelectionFont.FontFamily;

            //New Font Instancio el objeto nuevaFuente segun
            //tipo de FFuente y tamaño.
            nuevaFuente = new Font(actualFuenteFamily, nuevoTam);

            rtxtEditor.SelectionFont = nuevaFuente;
        }

        private void rtxtEditor_LinkClicked(object sender, LinkClickedEventArgs e)
        {
            //La calse Process brinda acceso a procesos locales y remotos.
            //El metodo Start inicia un proceso y asocia el recurso a un nuevo componentes.
            System.Diagnostics.Process.Start(e.LinkText);
        }

        private void btnNegrita_Click(object sender, EventArgs e)
        {
            Font viejaFuente; //Declaro una variable Class Font para la Fuente Vieja.
            Font nuevaFuente; //Declaro una variable Class Font para la Fuente Nueva.
                              //Asigno a viejaFuente el tipo de fuente seleccionado.
                              //Obtengo el tipo de Fuente atravez de la Propiedad SelectionFont
                              //del Control RichTextBox.
            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Bold) //Pregunto si ya es Negrita.
                                  //Si ya Tenia Negrita, establece nuevaFuente sin Negrita.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style & ~FontStyle.Bold);
            else
                //Si no Tenia Negrita, establece nuevaFuente con Negrita.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Bold);

            //Establesco la nuevaFuente a la Selección.
            rtxtEditor.SelectionFont = nuevaFuente;
            //Realizo un foco para posicionarme en el Control.
            rtxtEditor.Focus();
        }

        private void btnSubrayado_Click(object sender, EventArgs e)
        {
            Font viejaFuente; //Declaro una variable Class Font para la Fuente Vieja.
            Font nuevaFuente; //Declaro una variable Class Font para la Fuente Nueva.
                              //Asigno a viejaFuente el tipo de fuente seleccionado.
                              //Obtengo el tipo de Fuente atravez de la Propiedad SelectionFont
                              //del Control RichTextBox.
            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Underline) //Pregunto si ya es Subrayado.
                                       //Si ya Tenia Subrayado, establece nuevaFuente sin Subrayado.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style &
               ~FontStyle.Underline);
            else
                //Si no Tenia Subrayado, establece nuevaFuente con Subrayado.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Underline);
            //Establesco la nuevaFuente a la Selección.
            rtxtEditor.SelectionFont = nuevaFuente;
            //Realizo un foco para posicionarme en el Control.
            rtxtEditor.Focus();
        }

        private void btnCursiva_Click(object sender, EventArgs e)
        {
            Font viejaFuente; //Declaro una variable Class Font para la Fuente Vieja.
            Font nuevaFuente; //Declaro una variable Class Font para la Fuente Nueva.
                              //Asigno a viejaFuente el tipo de fuente seleccionado.
                              //Obtengo el tipo de Fuente atravez de la Propiedad SelectionFont
                              //del Control RichTextBox.
            viejaFuente = rtxtEditor.SelectionFont;
            if (viejaFuente.Italic) //Pregunto si ya es Cursiva.
                                    //Si ya Tenia Cursiva, establece nuevaFuente sin Cursiva.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style & ~FontStyle.Italic);
            else
                //Si no Tenia Cursiva, establece nuevaFuente con Cursiva.
                nuevaFuente = new Font(viejaFuente, viejaFuente.Style | FontStyle.Italic);
            //Establesco la nuevaFuente a la Selección.
            rtxtEditor.SelectionFont = nuevaFuente;
            //Realizo un foco para posicionarme en el Control.
            rtxtEditor.Focus();
        }

        private void btnCentrado_Click(object sender, EventArgs e)
        {
            //Atravez de la propiedad SelectionAlignment, obtiene la alineación
            //del texto que se selecciono.
            //Pregunto si es en centrado.
            if (rtxtEditor.SelectionAlignment == HorizontalAlignment.Center)
                //Si estaba Centrado lo alinea a la Izq.
                rtxtEditor.SelectionAlignment = HorizontalAlignment.Left;
            else
                //Si no estaba centrado lo centra.
                rtxtEditor.SelectionAlignment = HorizontalAlignment.Center;

            rtxtEditor.Focus();
        }

        private void txtTamanio_KeyPress(object sender, KeyPressEventArgs e)
        {
            //Valido que si se presiono una tecla que no se un numero,
            //Backspace o enter, se controle el evento.
            if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8 && e.KeyChar != 13)
                e.Handled = true;

            //Pregunto si es Enter.
            else if (e.KeyChar == 13)
            {
                //Si es Enter, pregunto si la cantidad de caracteres es mayor a 0.
                if (txtTamanio.Text.Length > 0)
                    //Llamo al metodo Aplicar Tamaño al Texto.
                    AplicarTamanioText(txtTamanio.Text);

                //Si es Enter y no se ingresaron caracteres, controlo el evento.
                e.Handled = true;

                rtxtEditor.Focus();
            }
        }

        private void txtTamanio_Validated(object sender, EventArgs e)
        {
                //El Evento Validated ocurre despues de la validación(Evento Validating).
                //Llama al Metodo AplicarTamanioText y como parametro pasa,
                //La propiedad Text del objeto sender(Objeto que disparo el evento)
                //Del cual se hace un Cast del tipo TextBox.
                //Es lo mismo que pasarle txtTamanio.text.
                AplicarTamanioText(((TextBox)sender).Text);
                rtxtEditor.Focus();
        }

        private void btnAbrir_Click(object sender, EventArgs e)
        {
            try
            {
                rtxtEditor.LoadFile("Test.rtf");
            }
            catch (System.IO.FileNotFoundException)
            {
                MessageBox.Show("No se pudo cargar el archivo");
            }

        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            try
            {
                rtxtEditor.SaveFile("Test.rtf");
            }
            catch (System.Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }
    }
}
