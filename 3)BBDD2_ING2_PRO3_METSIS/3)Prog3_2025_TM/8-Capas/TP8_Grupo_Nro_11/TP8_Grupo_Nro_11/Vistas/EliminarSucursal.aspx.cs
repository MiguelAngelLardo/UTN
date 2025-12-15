using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vistas
{
    public partial class EliminarSucursal : System.Web.UI.Page
    {
        public Sucursal sucursal = new Sucursal();
        protected void Page_Load(object sender, EventArgs e)
        {
            Label1.Text = "Eliminar Surcursal";
        }

        protected void btnFiltrar_Click(object sender, EventArgs e)
        {
            int idSucursal;
            if (int.TryParse(tbBuscarIdSucursal.Text, out idSucursal))
            {
                NegocioSucursal negocioSucursal = new NegocioSucursal();
                sucursal.setIdSucursal(idSucursal);
                bool exito = negocioSucursal.eliminarSucursal(sucursal.getIdSucursal());

                if (!exito)
                {
                    labelError.Text = "No se pudo eliminar la sucursal.";
                }
                else
                {
                    labelError.Text = "La sucursal se ha eliminado con éxito.";
                }
            }
            else
            {
                labelError.Text = "Por favor, ingrese un ID de sucursal válido.";
            }
        }

        protected void lbAgregarSucursal_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Agregar Sucursal")
            {
                Server.Transfer("AgregarSucursal.aspx");
            }
        }

        protected void lbListadodeSucursales_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Listado de sucursales")
            {
                Server.Transfer("ListadoSucursales.aspx");
            }
        }

        protected void lbEliminarsucursal_Click(object sender, EventArgs e)
        {
            if (Label1.Text != "Eliminar Surcursal")
            {
                Server.Transfer("EliminarSucursal.aspx");
            }
        }
    }
}