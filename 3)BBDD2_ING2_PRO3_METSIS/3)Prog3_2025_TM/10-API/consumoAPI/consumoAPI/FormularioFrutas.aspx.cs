using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Web.UI;
using Entidades;
using Negocio;

namespace Vistas
{
    public partial class FormularioFrutas : System.Web.UI.Page
    {
        NegocioFrutas negocioFrutas;

        protected void Page_Load(object sender, EventArgs e)
        {
        }

        protected void btnBuscar_Click(object sender, EventArgs e)
        {
            // Ejecutar async de forma segura en evento sincrónico
            try
            {
                Task.Run(async () => await BuscarFrutasAsync()).GetAwaiter().GetResult();
            }
            catch (Exception ex)
            {
                lblMensaje.Text = "Error al buscar frutas: " + ex.Message;
                lblMensaje.ForeColor = System.Drawing.Color.Red;
            }
        }

        private async Task BuscarFrutasAsync()
        {
            List<FrutasPlanas> frutas = null;
            negocioFrutas = new NegocioFrutas();

            /// TRAE TODAS LAS FRUTAS, SI TODOS LOS TEXTBOXS ESTAN VACIOS
            if (string.IsNullOrEmpty(txtNombreFamilia.Text) &&
                string.IsNullOrEmpty(txtMinimo.Text) &&
                string.IsNullOrEmpty(txtMinimo.Text))
            {
                frutas = await negocioFrutas.ObtenerTodas();
            }

            else if (!string.IsNullOrEmpty(txtNombreFamilia.Text))
            {
                frutas = await negocioFrutas.ObtenerPorFamilia(txtNombreFamilia.Text.ToString());
            }
            else
            {
                double min, max;
                try {  min = Convert.ToDouble(txtMinimo.Text.Trim()); }
                catch {  min = 0; }

                try {  max = Convert.ToDouble(txtMaximo.Text.Trim()); }
                catch { max = 1000; }

                frutas = await negocioFrutas.ObtenerPorNutricion(txtTipoNutricion.Text.ToString(), min, max);
            }

            gvFrutas.DataSource = frutas;
            gvFrutas.DataBind();
        }

        protected void btnLimpiar_Click(object sender, EventArgs e)
        {
            txtNombreFamilia.Text = string.Empty;
            txtMinimo.Text = string.Empty;
            txtMaximo.Text = string.Empty;
            txtTipoNutricion.Text = string.Empty;
        }
    }
}
