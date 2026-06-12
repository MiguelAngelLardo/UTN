using Negocio;
using System;
using System.Data;
using System.Web.UI;

namespace Vista.Administrador.AdministrarMedicos
{
    public partial class DetalleMedico : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                string legajo = Request.QueryString["legajo"];
                if (!string.IsNullOrEmpty(legajo))
                {
                    CargarDatosMedico(legajo);
                }
            }
        }

        private void CargarDatosMedico(string legajo)
        {
            NegocioMedico negocio = new NegocioMedico();
            DataTable dt = negocio.ObtenerDatosMedicoParaDetalle(legajo);
            DataRow row = dt.Rows[0];

            lblLegajo.Text = row["Legajo"].ToString();
            lblNombre.Text = $"{row["Nombre"]} {row["Apellido"]}";
            lblDNI.Text = row["DNI"].ToString();
            lblCorreo.Text = row["Correo"].ToString();
            lblSexo.Text = row["Sexo"].ToString();
            lblNacionalidad.Text = row["Nacionalidad"].ToString();
            lblFechaNacimiento.Text = Convert.ToDateTime(row["FechaNacimiento"]).ToShortDateString();
            lblDireccion.Text = row["Direccion"].ToString();
            lblTelefono.Text = row["Telefono"].ToString();
            lblProvincia.Text = row["Provincia"].ToString();
            lblLocalidad.Text = row["Localidad"].ToString();
            lblEspecialidad.Text = row["Especialidad"].ToString();
            //Lo dejo concatenado por si llega a ser mas de un solo dia
            string dias = row["Dias"].ToString();
            string horario = row["Horario"].ToString();
            lblDiasHorario.Text = $"{dias} - {horario}";
        }

        protected void btnVolver_Click(object sender, EventArgs e)
        {
            Response.Redirect("ListadoMedicos.aspx");
        }
    }
}