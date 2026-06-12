using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vista.Administrador.AdministrarPacientes
{
    public partial class DetallePaciente : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)

            {
                string dni = Request.QueryString["dni"];
                if (!string.IsNullOrEmpty(dni))
                {
                    CargarPaciente(dni);
                }

            }
        }
        private void CargarPaciente(string dni)
        {

            NegocioPaciente negocioPaciente = new NegocioPaciente();
            DataTable dt = negocioPaciente.ObtenerPaciente(dni);

            if (dt.Rows.Count > 0)
            {
                DataRow fila = dt.Rows[0];

                lblNombre.Text = $"{fila["Nombre"]} {fila["Apellido"]}";
                lblDNI.Text = fila["DNI"].ToString();
                lblSexo.Text = fila["Sexo"].ToString();
                lblNacionalidad.Text = fila["Nacionalidad"].ToString();
                lblFechaNacimiento.Text = Convert.ToDateTime(fila["FechaNacimiento"]).ToString("dd/MM/yyyy");
                lblDireccion.Text = fila["Direccion"].ToString();
                lblLocalidad.Text = fila["Localidad"].ToString();
                lblProvincia.Text = fila["Provincia"].ToString();
                lblCorreo.Text = fila["Correo"].ToString();
                lblTelefono.Text = fila["Telefono"].ToString();

            }
        }

        protected void btnVolver_Click(object sender, EventArgs e)
        {
            Response.Redirect("ListadoPacientes.aspx");
        }
    }
}

