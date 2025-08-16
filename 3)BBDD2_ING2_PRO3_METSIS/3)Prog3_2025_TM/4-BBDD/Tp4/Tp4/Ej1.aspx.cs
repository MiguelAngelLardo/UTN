using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

using System.Data.SqlClient;
/*
SqlConnection: La manguera para conectar.
SqlCommand: La herramienta para escribir los comandos SQL.
SqlDataReader: La herramienta para leer los resultados.
 */
namespace Tp4
{
  public partial class WebForm1 : System.Web.UI.Page
  {
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)//es la primera vez que se carga la pagina
      {  //llamo al edificio Data Source, en la seccion especifica Initial Catalog

        SqlConnection cn = new SqlConnection("Data Source=-SAI\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
        //cn.ConnectionString = "Data Source=-SAI\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True;Trust Server Certificate=True"
        cn.Open();

        SqlCommand cmd = new SqlCommand("SELECT IdProvincia, NombreProvincia FROM Provincias", cn);
        //cmd.CommandText = "SELECT * FROM Localidades"; -> trae todas las columnas de Localidades
        //cmd.Connection = cn;

        SqlDataReader dr = cmd.ExecuteReader();//lee los resultados uno por uno 

        ddlProvInicio.DataSource = dr;// Es como el "enchufe" que tiene el DropDownList para que le conectes una fuente de datos.

        
        ddlProvInicio.DataTextField = "NombreProvincia";       //que columna quiero que muestre
        ddlProvInicio.DataValueField = "IdProvincia";          //que columna quiero que guarde como valor

        ddlProvInicio.DataBind();//. Es como el "botón de encendido"

        cn.Close();
        ddlProvInicio.Items.Insert(0, new ListItem("--Seleccionar--", "0"));//sin eso se inicializ con bs as pero sin localidada
        ddlProvFinal.Items.Insert(0, new ListItem("--Seleccionar--", "0"));//sin eso se inicializ con bs as pero sin localidada

      }

        ddlProvInicio.AutoPostBack = true;//por defecto autopostback es false, por lo que no se actualiza la pagina al cambiar el valor del dropdownlist
        EventHandler miManejadorDeEvento = new EventHandler(ddlProvInicio_SelectedIndexChanged);
        ddlProvInicio.SelectedIndexChanged += miManejadorDeEvento;

        //miManejadorDeEvento  guarda la dirección de memoria donde se encuentra el método ddlProvInicio_SelectedIndexChanged.

        //cuando sucede el evento SelectedIndexChanged en el ddlProvInicio, se crean y se asan ds parametros
        //1-sender es una referencia al objeto que disparó el evento, en este caso ddlProvInicio.
        //2-e es un objeto de tipo EventArgs que contiene información adicional sobre el evento, en este caso no se usa.

      // Configuración para el SEGUNDO DropDownList de Provincias
       ddlProvFinal.AutoPostBack = true;
       ddlProvFinal.SelectedIndexChanged += new EventHandler(ddlProvFinal_SelectedIndexChanged);

         
    }


    protected void ddlProvInicio_SelectedIndexChanged(object sender, EventArgs e)
    {
      string idProvinciaSeleccionada = ddlProvInicio.SelectedValue;

      SqlConnection cn = new SqlConnection("Data Source=-SAI\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
      cn.Open();

      string consultaLocalidad = "SELECT IdLocalidad, NombreLocalidad FROM Localidades WHERE IdProvincia = " + idProvinciaSeleccionada;
      SqlCommand cmdLocalidad = new SqlCommand(consultaLocalidad, cn);
      //cmdLocalidad.Parameters.AddWithValue("@IdProv", idProvinciaSeleccionada);

      SqlDataReader drLocalidad = cmdLocalidad.ExecuteReader();
      
      ddlLocInicio.DataSource = drLocalidad; // Conecto el DropDownList a la fuente de datos de localidades
      ddlLocInicio.DataTextField = "NombreLocalidad"; // Columna que se mostrará en el DropDownList
      ddlLocInicio.DataValueField = "IdLocalidad"; // Columna que se usará como valor del DropDownList
      ddlLocInicio.DataBind(); // Enciendo el DropDownList con los datos de localidades

      drLocalidad.Close();  // --- Cerramos el primer lector para liberar la conexión, ya que es como una llamada telefonica ---

      //cargar profincias final
      string consultaProvFinal = "SELECT IdProvincia, NombreProvincia FROM Provincias WHERE IdProvincia <> " + idProvinciaSeleccionada;
      SqlCommand cmdProvFinal = new SqlCommand(consultaProvFinal, cn);
      //cmdProvincias.Parameters.AddWithValue("@IdProvExcluida", idProvinciaSeleccionada);

      SqlDataReader drProvFinal = cmdProvFinal.ExecuteReader();

      // Llenamos el DropDownList de la provincia FINAL.
      ddlProvFinal.DataSource = drProvFinal;
      ddlProvFinal.DataTextField = "NombreProvincia";
      ddlProvFinal.DataValueField = "IdProvincia";
      ddlProvFinal.DataBind();

      // Cerramos la conexión al final de todo.
      cn.Close();

    }

     protected void ddlProvFinal_SelectedIndexChanged(object sender, EventArgs e)
     {
      
       string idProvFinalSelec = ddlProvFinal.SelectedValue;
       SqlConnection cn = new SqlConnection("Data Source=-SAI\\SQLEXPRESS;Initial Catalog=Viajes;Integrated Security=True");
       cn.Open();
       
       string consultaLocFinal = "SELECT IdLocalidad, NombreLocalidad FROM Localidades WHERE IdProvincia = " + idProvFinalSelec;
       SqlCommand cmdLocFinal = new SqlCommand(consultaLocFinal, cn);

       SqlDataReader drLocFinal = cmdLocFinal.ExecuteReader();
       
       ddlLocFinal.DataSource = drLocFinal; // Conecto el DropDownList a la fuente de datos de localidades
       ddlLocFinal.DataTextField = "NombreLocalidad"; // Columna que se mostrará en el DropDownList
       ddlLocFinal.DataValueField = "IdLocalidad"; // Columna que se usará como valor del DropDownList
       ddlLocFinal.DataBind(); // Enciendo el DropDownList con los datos de localidades
      // drLocFinal.Close();  // --- Cerramos el lector para liberar la conexión ---
       cn.Close();


  

    }


    protected void ddlLocInicio_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

   
  }
} 