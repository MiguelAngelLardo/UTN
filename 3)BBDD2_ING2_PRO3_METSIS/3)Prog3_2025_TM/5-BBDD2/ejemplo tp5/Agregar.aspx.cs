using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Data;


namespace TrabajandoConClases
{
    public partial class Agregar : System.Web.UI.Page
    {
        Negocio negocio = new Negocio();
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!Page.IsPostBack)
            {
                CargarProvincias();
            }
        }

        private void CargarProvincias()
        {
            ddl_Provincias.DataSource = negocio.ObtenerProvincias();
            ddl_Provincias.DataTextField = "DescripcionProvincia";
            ddl_Provincias.DataValueField = "Id_Provincia";
            ddl_Provincias.DataBind();
        }

        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            //lbl_Mensaje.Text = "SI COMPLETO TODOS LOS CAMPOS, DEBERIA AGREGAR A LA BD Y DECIR LA SUCURSAL SE HA AGREGADO CON ÉXITO";
        }
    }
}