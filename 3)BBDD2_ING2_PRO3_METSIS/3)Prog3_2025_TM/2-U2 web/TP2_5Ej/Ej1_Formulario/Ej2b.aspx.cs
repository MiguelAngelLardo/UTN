using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace Ej1_Formulario
{
  public partial class Ej2b : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      string nombre, apellido, ciudad, temasSeleccionados;
      nombre = Request.QueryString["varNom"];
      apellido = Request.QueryString["varApe"];
      ciudad = Request.QueryString["varCiudad"];

      temasSeleccionados = Request.QueryString["varTemas"];
      string[] temasArray = temasSeleccionados.Split(',');//separa indices segun encuentre ","
      string temasFormateados = "";//inicializamos la variable para que no de error
      foreach (string item in temasArray)
      {
        temasFormateados += "&nbsp;&nbsp;&nbsp;" + item + "<br />";//el + "<br />" es para q no ponga una palabra al lado de otra
      } 


      lblMensaje.Text = "<h1>RESUMEN</h1><br />" +
       "Nombre: <b>" + nombre + "</b><br />" +
       "Apellido: <b>" + apellido + "</b><br />" +
       "Zona: <b>" + ciudad + "</b><br />" +
       "Los temas elegidos son: <br />" +
       " <b>" + temasFormateados + "</b>";
    }
  }
}