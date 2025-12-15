using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;

namespace SessionCookiesApplicacion
{
    public partial class ejemplo3b : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void TextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        protected void btnAgregar_Click(object sender, EventArgs e)
        {
            if (Session["tabla"] == null)
            {
                Session["tabla"] = CrearTabla();
            }

            agregarFila((DataTable)Session["tabla"], txtNombre.Text, txtApellido.Text);

            txtApellido.Text = string.Empty;
            txtNombre.Text = string.Empty;
        }
        private DataTable CrearTabla()
        {
            DataTable dataTable = new DataTable();
            
            DataColumn dataColumn = new DataColumn("Nombre", System.Type.GetType("System.String"));
            dataTable.Columns.Add(dataColumn);
            
            dataColumn = new DataColumn("Apellido", System.Type.GetType("System.String"));
            dataTable.Columns.Add(dataColumn);

            return dataTable;
        }

        private DataTable agregarFila(DataTable dataTable, string nombre, string apellido)
        {
            DataRow dataRow = dataTable.NewRow();

            dataRow["Nombre"] = nombre;
            dataRow["Apellido"] = apellido;
            dataTable.Rows.Add(dataRow);

            return dataTable;
        }
    }
}<