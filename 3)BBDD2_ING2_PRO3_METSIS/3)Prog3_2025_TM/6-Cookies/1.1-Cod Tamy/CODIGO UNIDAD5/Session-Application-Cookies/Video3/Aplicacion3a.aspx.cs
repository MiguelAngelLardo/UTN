using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace Aplicaciones
{
    public partial class Aplicacion3a : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnAgregar_Click(object sender, EventArgs e)
        {
            if(Session["tabla"] == null)
            {
                Session["tabla"] = crearTabla();
            }
            agregarFila((DataTable)Session["tabla"], txtNombre.Text, txtApellido.Text);
            txtNombre.Text = "";
            txtApellido.Text = "";
        }

        public DataTable crearTabla()
        {
            DataTable dt = new DataTable();
            DataColumn columna = new DataColumn("Nombre", System.Type.GetType("System.String"));
            dt.Columns.Add(columna);

            columna = new DataColumn("Apellido", System.Type.GetType("System.String"));
            dt.Columns.Add(columna);

            return dt;
        }

        public void agregarFila(DataTable tabla, String nombre, String apellido)
        {
            DataRow dr = tabla.NewRow();
            dr["Nombre"] = nombre;
            dr["Apellido"] = apellido;
            tabla.Rows.Add(dr);
        }

    }
}