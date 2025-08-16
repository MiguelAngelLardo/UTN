using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data.SqlClient;
namespace Tp4
{
  public partial class Ej3b : System.Web.UI.Page
  {

    
    
    protected void Page_Load(object sender, EventArgs e)
    {
      string idTema = Request.QueryString["IdTema"];
      string consulta = "SELECT IdLibro, IdTema, Titulo, Precio, Autor FROM Libros WHERE IdTema = @IdTema";

      //Abrimos la conexión, ejecutamos y cerramos.
      SqlConnection cn = new SqlConnection("Data Source=localhost\\sqlexpress;Initial Catalog=Libreria;Integrated Security=True");
      SqlCommand cmd = new SqlCommand(consulta, cn);
      cmd.Parameters.AddWithValue("@IdTema", idTema);
      cn.Open();

      SqlDataReader dr = cmd.ExecuteReader();
      gvLibros.DataSource = dr; 
      gvLibros.DataBind();

      cn.Close();
    }

    protected void lbConsultarOtroTema_Click(object sender, EventArgs e)
    {
      Response.Redirect("Ej3.aspx");
    }
  }
}