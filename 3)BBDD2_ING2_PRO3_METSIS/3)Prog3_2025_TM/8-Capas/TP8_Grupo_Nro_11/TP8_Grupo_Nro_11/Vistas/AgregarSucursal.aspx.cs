using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vistas
{
    public partial class AgregarSucursal : System.Web.UI.Page
    {
        public Sucursal sucursal = new Sucursal();

        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                NegocioProvincia negocioProvincia = new NegocioProvincia();
                DataTable dtProvincias = negocioProvincia.ObtenerProvincias();

                ddlProvincia.DataSource = dtProvincias;
                ddlProvincia.DataTextField = "DescripcionProvincia";
                ddlProvincia.DataValueField = "Id_Provincia";
                ddlProvincia.DataBind();
                ddlProvincia.Items.Insert(0, new ListItem("--Seleccionar--", "0"));

                Label1.Text = "Agregar Sucursal";
            }
        }
        protected void btnAceptar_Click(object sender, EventArgs e)
        {
            if (DectectarSiEstaTodoCargado() == true)
            {

                if (Label1.Text == "Agregar Sucursal")
                {

                    sucursal.setNombreSucursal(tbNombreSucursal.Text);
                    sucursal.setDescripcionSucursal(tbDescripcion.Text);
                    sucursal.setIdProvinciaSucursal(Convert.ToInt32(ddlProvincia.SelectedValue));
                    sucursal.setDireccionSucursal(tbDireccion.Text);

                    Agregar_Sucursal();
                }
                else
                {
                    labelError.Text = "seleccione una opcion como : 'agregar Sucursal' ; 'Listado De Surcursales' ; 'Eliminar Surcursal'";
                }

            }
        }

        public bool DectectarSiEstaTodoCargado()
        {
            

            bool NomSur;
            if (tbNombreSucursal.Text != "") { NomSur = true; } else { NomSur = false; }
            bool Desc;
            if (tbDescripcion.Text != "") { Desc = true; } else { Desc = false; }
            bool Prov;
            if (ddlProvincia.SelectedIndex != 0) { Prov = true; } else { Prov = false; }
            bool direc;
            if (tbDireccion.Text != "") { direc = true; } else { direc = false; }
            bool label;
            if (Label1.Text != "") { label = true; } else { label = false; labelError.Text = "seleccione una opcion como : 'agregar Sucursal' ; 'Listado De Surcursales' ; 'Eliminar Surcursal'"; }

            if ((NomSur == true) && (Desc == true) && (Prov == true) && (direc == true) && (label == true))
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        private void Agregar_Sucursal()
        {
            NegocioSucursal negocioSucursal = new NegocioSucursal(); //La capa vista buscará comunicarse con la capa Negocio.

            bool agregado = negocioSucursal.AgregarSucursal(sucursal); //La capa de vista envía los datos cargados de Sucursal cargado a capa de negocio
                                                                       //Y la capa de negocio se comunicará con la capa de datos para agregar la sucursal.

            if (agregado) //El valor del bool dependerá de lo aplicado en las demas capas asignadas. Si es true es porque se pudo agregar, de lo contrario el valor es false.
            {
                labelError.Text = "Sucursal agregada.";
                limpiarCampos();
            }
            else
            {
                labelError.Text = "No se ha podido agregar la sucursal.";
                limpiarCampos();
            }
        }

        private void limpiarCampos()
        {
            tbNombreSucursal.Text = "";
            tbDescripcion.Text = "";
            tbDireccion.Text = "";
            ddlProvincia.SelectedIndex = 0;
        }


        protected void lbAgregarSucursal_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Agregar Sucursal")
            {
                Server.Transfer("AgregarSucursal.aspx");
            }
        }


        protected void lbListadoDeSurcursales_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Listado De Surcursales")
            {
                Server.Transfer("ListadoSucursales.aspx");
            }
        }

        protected void lbEliminarSurcursal_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Eliminar Surcursal")
            {
                Server.Transfer("EliminarSucursal.aspx");
            }
        }
    }
}