using Entidades;
using Negocio;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Vistas
{
    public partial class ListadoSucursales : System.Web.UI.Page
    {
        NegocioSucursal neg = new NegocioSucursal();
        protected void Page_Load(object sender, EventArgs e)
        {
            Label1.Text = "Listado de Sucursales";
        }

        protected void btnFiltrar_Click(object sender, EventArgs e)
        {
            int num;
            if (tbBuscarIdSucursal.Text.Trim() != "")
            {
                if (int.TryParse(tbBuscarIdSucursal.Text, out num))
                {
                    Sucursal sucur = new Sucursal();
                    sucur.setIdSucursal(num);

                    DataTable tablaSucursales = neg.TablaPorId(sucur);
                    if (tablaSucursales.Rows.Count > 0)
                    {
                        gvTabla.DataSource = tablaSucursales;
                        gvTabla.DataBind();
                        labelError.Text = "";
                        tbBuscarIdSucursal.Text = "";
                    }
                    else
                    {
                        labelError.Text = "No se encontraron sucursales con el ID ingresado.";
                    }
                }
                else
                {
                    labelError.Text = "Por favor ingrese un número entero.";
                }
            }
            else
            {
                labelError.Text = "Por favor ingrese un ID.";
            }
        }
    

    protected void btnMostrarTodos_Click(object sender, EventArgs e)
        {
            DataTable tablaSucursales = neg.TablaCompleta();
            gvTabla.DataSource = tablaSucursales;
            gvTabla: DataBind();
            labelError.Text = "";
            tbBuscarIdSucursal.Text = "";
        }
    }
}