using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace TP4
{
    public partial class Ejercicio1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                cargar_ddlProvinciaInicio();
            }
           
        }

        protected void ddlProvinciaInicio_SelectedIndexChanged(object sender, EventArgs e)
        {
            cargar_ddlLocalidadInicio();
            cargar_ddlProvinciaFinal();
        }



        // Método para cargar el DropDownList de provincias de inicio
        public void cargar_ddlProvinciaInicio()
        {
            SqlConnection cn = new SqlConnection(@"Data Source=localhost\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cn.Open();

            SqlCommand cmd = new SqlCommand("SELECT IdProvincia, NombreProvincia FROM Provincias", cn);
            SqlDataReader dr = cmd.ExecuteReader();

            ddlProvinciaInicio.DataSource = dr;
            ddlProvinciaInicio.DataTextField = "NombreProvincia";
            ddlProvinciaInicio.DataValueField = "IdProvincia";
            ddlProvinciaInicio.DataBind();

            cn.Close();
            ddlProvinciaInicio.Items.Insert(0, new ListItem("--Seleccionar--", "0"));

            
            
        }

        public void cargar_ddlLocalidadInicio()
        {
            SqlConnection cn = new SqlConnection(@"Data Source=localhost\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cn.Open();
            SqlCommand cmd = new SqlCommand("SELECT IdLocalidad, NombreLocalidad FROM Localidades WHERE IdProvincia = @IdProvincia", cn);
            cmd.Parameters.AddWithValue("@IdProvincia", ddlProvinciaInicio.SelectedValue);
            SqlDataReader dr = cmd.ExecuteReader();
            ddlLocalidadInicio.DataSource = dr;
            ddlLocalidadInicio.DataTextField = "NombreLocalidad";
            ddlLocalidadInicio.DataValueField = "IdLocalidad";
            ddlLocalidadInicio.DataBind();
            cn.Close();
            ddlLocalidadInicio.Items.Insert(0, new ListItem("--Seleccionar--", "0"));
        }

        //mira si yo pongo en la ProvinciaInicio la opcion 1, no puede aparecer en la provincia final la opcion 1
        public void cargar_ddlProvinciaFinal()
        {
            SqlConnection cn = new SqlConnection(@"Data Source=localhost\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cn.Open();
            SqlCommand cmd = new SqlCommand("SELECT IdProvincia, NombreProvincia FROM Provincias WHERE IdProvincia != @IdProvincia", cn);
            cmd.Parameters.AddWithValue("@IdProvincia", ddlProvinciaInicio.SelectedValue);
            SqlDataReader dr = cmd.ExecuteReader();
            ddlProvinciaFinal.DataSource = dr;
            ddlProvinciaFinal.DataTextField = "NombreProvincia";
            ddlProvinciaFinal.DataValueField = "IdProvincia";
            ddlProvinciaFinal.DataBind();
            cn.Close();
            ddlProvinciaFinal.Items.Insert(0, new ListItem("--Seleccionar--", "0"));
        }

        protected void ddlProvinciaFinal_SelectedIndexChanged(object sender, EventArgs e)
        {
            cargar_ddlLocalidadFinal();
        }

        public void cargar_ddlLocalidadFinal()
        {
            SqlConnection cn = new SqlConnection(@"Data Source=localhost\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
            cn.Open();
            SqlCommand cmd = new SqlCommand("SELECT IdLocalidad, NombreLocalidad FROM Localidades WHERE IdProvincia = @IdProvincia", cn);
            cmd.Parameters.AddWithValue("@IdProvincia", ddlProvinciaFinal.SelectedValue);
            SqlDataReader dr = cmd.ExecuteReader();
            ddlLocalidadFinal.DataSource = dr;
            ddlLocalidadFinal.DataTextField = "NombreLocalidad";
            ddlLocalidadFinal.DataValueField = "IdLocalidad";
            ddlLocalidadFinal.DataBind();
            cn.Close();
            ddlLocalidadFinal.Items.Insert(0, new ListItem("--Seleccionar--", "0"));
        }

    
    }

}