using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services.Description;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP3
{
  public partial class WebForm1 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    
  
    protected void btnLocalidad_Click(object sender, EventArgs e)
    {
      string localidadIngresada = txtLocalidad.Text.Trim();

      rfvLocalidad.IsValid = true;//le digo al rfv que funcione
      rfvLocalidad.Text = "Debe ingresar una localidad"; //if (string.IsNullOrEmpty(localidadIngresada))


      //uso ListItem por que el ddl usa clave y value
      foreach(ListItem localidadGuardada in ddlLocalidades.Items)
      {
        if(localidadIngresada.ToLower() == localidadGuardada.Text.ToLower())
        {
          rfvLocalidad.IsValid = false;//lo fuerzo a que se comporte coo si hubiera un error
          rfvLocalidad.Text = "Ya existe esa localidad";
          txtLocalidad.Text = "";
          txtLocalidad.Focus();
          return; 
        }
      }

      ddlLocalidades.Items.Add(localidadIngresada);
      txtLocalidad.Text = "";
      txtLocalidad.Focus();
    }




      protected void cvCodigoPostal_ServerValidate(object source, ServerValidateEventArgs args)
    {
      if(args.Value.Length != 4)
      {
        args.IsValid = false;
      }
      else
      {
        args.IsValid = true;
      }
    }

    protected void btnGuardarUsuario_Click(object sender, EventArgs e)
    {

      //si todos los validadores son validos uso al Page.IsValid(supervisor)
      if (Page.IsValid)
      {
        lblBienvenido.Text = "Bienvenido " + txtNombreUsuario.Text;
      }
    }

    protected void btnInicio_Click(object sender, EventArgs e)
    {
      Response.Redirect("Ej1b.aspx");
    }
  }
}