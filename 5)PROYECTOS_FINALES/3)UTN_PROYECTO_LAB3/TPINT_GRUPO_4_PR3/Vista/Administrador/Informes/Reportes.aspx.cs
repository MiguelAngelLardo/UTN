using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.Informes
{
    public partial class Reportes : System.Web.UI.Page
    {
        NegocioTurno negocio = new NegocioTurno();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string hoy = DateTime.Now.ToString("yyyy-MM-dd");

                txtFechaDesde.Attributes["max"] = hoy;
                txtFechaHasta.Attributes["max"] = hoy;
            }
        }
       
        protected void btnGenerarReporteAusentismo_Click(object sender, EventArgs e)
        {
            if (!Page.IsValid)//valido los required fields
            {
                return;
            }

            lblMensaje.Text = "";

            DateTime fechaDesde = DateTime.Parse(txtFechaDesde.Text);
            DateTime fechaHasta = DateTime.Parse(txtFechaHasta.Text);

            if (fechaHasta > DateTime.Now.Date)
            {
                lblMensaje.Text = "❌ Error: No se pueden consultar fechas futuras.";
                lblMensaje.ForeColor = System.Drawing.Color.Red;
                return;
            }

            InformePresentismo resultado = negocio.ReportePresentismo(fechaDesde, fechaHasta);


            lblTotal.Text = resultado.Total.ToString();
            lblPresentes.Text = resultado.Presentes + "(" + resultado.PorcentajePresentes.ToString("0.0") + "%)"; 
            lblAusentes.Text = resultado.Ausentes + "(" + resultado.PorcentajeAusentes.ToString("0.0") + "%)";

            GridView1.DataSource = negocio.ReportePresentismoDetalle(fechaDesde, fechaHasta);
            GridView1.DataBind();
        }

        protected void btnGenerarReporte2_Click(object sender, EventArgs e)
        {
            if(!Page.IsValid)//valido los required fields
            {
                return;
            }

            DateTime fechaDesde = DateTime.Parse(TextBox1.Text);
            DateTime fechaHasta = DateTime.Parse(TextBox2.Text);

            InformeRanking resultado = negocio.ObtenerReporteRanking(fechaDesde, fechaHasta);

            lblTotalTurnos.Text = resultado.turnosTotal.ToString();
            lblTurnoPorMedico.Text = resultado.cantidadMaxima.ToString();
            lblPromedio.Text = resultado.promedioTurnos.ToString();

            gvReporteMedicos.DataSource = resultado.detalleRanking;
            gvReporteMedicos.DataBind();
        }

        protected void GridView1_RowDataBound(object sender, GridViewRowEventArgs e)
        {
            if (e.Row.RowType == DataControlRowType.DataRow)
            {
                Label lblEstado = (Label)e.Row.FindControl("lblEstado");
                DataRowView filaDatos = (DataRowView)e.Row.DataItem;

                bool asistio = Convert.ToBoolean(filaDatos["Atendido_T"]);

                if (asistio)
                {
                    lblEstado.Text = "PRESENTE";
                    lblEstado.ForeColor = System.Drawing.Color.Green;
                    lblEstado.Font.Bold = true;
                }
                else
                {
                    lblEstado.Text = "AUSENTE";
                    lblEstado.ForeColor = System.Drawing.Color.Red;
                    lblEstado.Font.Bold = true;
                }
            }
        }

    }
}