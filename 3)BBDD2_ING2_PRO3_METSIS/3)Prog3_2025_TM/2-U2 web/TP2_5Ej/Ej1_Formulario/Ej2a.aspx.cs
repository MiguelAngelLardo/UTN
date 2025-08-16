using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Ej1_Formulario
{
  public partial class WebForm2 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if(!IsPostBack) // para que no se vuelva a cargar la lista cada vez que se hace un postback
      {
        //new ListItem tiene dos parámetros: el texto que se muestra y el valor que se envía al servidor
        ddlCiudades.Items.Add(new ListItem("Gral. Pacheco", "zona norte"));
        ddlCiudades.Items.Add(new ListItem("San Miguel", "zona oeste"));
        ddlCiudades.Items.Add(new ListItem("Boedo", "zona sur"));

        cblTemas.Items.Add("Ciencia");
        cblTemas.Items.Add("Literatura");
        cblTemas.Items.Add("Historia");

      }

     



    }
         
        // Para separar los distintos parámetros en una URL, tenés que usar el símbolo &.
        protected void btnResumen_Click(object sender, EventArgs e)
        {
          string nombre = txtNombre.Text, apellido = txtApellido.Text; //TextBox
          string ciudad = ddlCiudades.SelectedValue; //DropDownList
          string temasSeleccionados = "";// CheckboxList
          foreach(ListItem varItem in cblTemas.Items)//en foreach de checkboxlist se usan ListItem a que guarda el string y si es true o false
          {
            if(varItem.Selected == true)
            {
            temasSeleccionados += varItem.Text + ","; 
            }
          }

          // Quitamos la última coma que sobra.
          if (temasSeleccionados.Length > 0)
          {
            temasSeleccionados = temasSeleccionados.TrimEnd(',');
          }

          // Construimos la URL => lo q esta antes de ? es ña direccion de la pagina, lo que esta luego es los datos q envio
          Response.Redirect("Ej2b.aspx?" +
                      "varNom=" + nombre +
                      "&varApe=" + apellido +
                      "&varCiudad=" + ciudad +
                      "&varTemas=" + temasSeleccionados
                     );
        }
    }
}