using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
namespace Tp4
{
  public partial class Ej2 : System.Web.UI.Page
  {

    public void hacerConexion_CargaGrid()
    {
      SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True");
      cn.Open();
      SqlCommand cmNepProd = new SqlCommand("SELECT IdProducto, NombreProducto, IdCategoría, CantidadPorUnidad, PrecioUnidad FROM Productos", cn);
      SqlDataReader drNepProd = cmNepProd.ExecuteReader();

      grdNeptuno.DataSource = drNepProd;
      grdNeptuno.DataBind();

      cn.Close();
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        //cargo ddlProuctos
       ddlProducto.Items.Add(new ListItem("Igual a:", "="));
        ddlProducto.Items.Add(new ListItem("Mayor a:", ">"));
        ddlProducto.Items.Add(new ListItem("Menor a:", "<"));

        //cargo ddlPrecio
        ddlCategoria.Items.Add(new ListItem("Igual a:", "="));
        ddlCategoria.Items.Add(new ListItem("Mayor a:", ">"));
        ddlCategoria.Items.Add(new ListItem("Menor a:", "<"));

       hacerConexion_CargaGrid();

      }
    }


    protected void btnFiltrar_Click(object sender, EventArgs e)
    {
      
      // 1. El "WHERE 1=1" es un truco para poder agregar
      string consulta = "SELECT IdProducto, NombreProducto, IdCategoría, CantidadPorUnidad, PrecioUnidad FROM Productos WHERE 1=1 ";

      SqlCommand cmd = new SqlCommand();

      if (txtProducto.Text.Trim() != "") // Chequeamos si el TextBox de IdProducto NO está vacío
      {
        consulta += " AND IdProducto " + ddlProducto.SelectedValue + "@idSinInyeccion" ;// El ddlProducto.SelectedValue nos dará "=", ">" o "<"
        cmd.Parameters.AddWithValue("@idSinInyeccion", txtProducto.Text);
      }

      // --- FILTRO POR ID DE CATEGORÍA ---
      if (txtCategoria.Text.Trim() != "")
      {
        consulta += " AND IdCategoría " + ddlCategoria.SelectedValue + "@idCat";//le pongo espacio al and para que concatene las consultas y no se rompa
        cmd.Parameters.AddWithValue("@idCat", txtCategoria.Text);
      }

      cmd.CommandText = consulta; // Ahora que la consulta está completa, la asignamos al comando.

      //  Creamos la conexión y la abrimos justo antes de usarla.
      SqlConnection cn = new SqlConnection("Data Source=-sai\\sqlexpress;Initial Catalog=Neptuno;Integrated Security=True");
      cmd.Connection = cn;
      cn.Open();

      SqlDataReader dr = cmd.ExecuteReader();

      grdNeptuno.DataSource = dr;
      grdNeptuno.DataBind();
      cn.Close();

       // Ahora que ya no necesitamos la BD, limpiamos los controles.
      txtProducto.Text = "";
      txtCategoria.Text = "";
      ddlProducto.SelectedIndex = 0; // Vuelve a la primera opción ("Igual a:")
      ddlCategoria.SelectedIndex = 0;
   
    }

    protected void btnQuitarFiltro_Click(object sender, EventArgs e)
    {
      hacerConexion_CargaGrid();
    }
  }
}