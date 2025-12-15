using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Security.Claims;
using System.Web;
using System.Web.Services.Protocols;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using Tp7.Datos_DAL_;
using Tp7.Entidades_Modelos_;

namespace Tp7
{
  public partial class SeleccionarSucursales : System.Web.UI.Page
  {
    private void CargarSucursales(string filtroNombre = "", string filtroProvincia = "")
    {

      // 1. Conexión
      ConexionDB objConex = new ConexionDB();
      SqlConnection cn = objConex.conectarseBD();
      SqlCommand cmd = new SqlCommand();

      // 2. Se declara la consulta base AQUÍ, al principio del método.
      string consulta = "SELECT Id_Sucursal, NombreSucursal, DescripcionSucursal, URL_Imagen_Sucursal FROM Sucursal WHERE 1=1 ";

      // 3. Se le AGREGA el filtro por NOMBRE si es necesario
      if (!string.IsNullOrEmpty(filtroNombre))
      {
        consulta += "AND NombreSucursal LIKE '%' + @nombreBuscado + '%' "; // Se usa += para concatenar
        cmd.Parameters.AddWithValue("@nombreBuscado", filtroNombre);
      }

      // 4. Se le AGREGA el filtro por PROVINCIA si es necesario
      if (!string.IsNullOrEmpty(filtroProvincia))
      {
        consulta += "AND Id_ProvinciaSucursal = @IdProv "; // Se usa += para concatenar
        cmd.Parameters.AddWithValue("@IdProv", filtroProvincia);//no hace falta inner join por que solo quiero filtrar por provincia, no mostrar datos de provincia y sucursal
      }

      // 5. Se ejecuta la consulta final
      cmd.CommandText = consulta;
      cmd.Connection = cn;

      SqlDataAdapter da = new SqlDataAdapter(cmd);//no uso SqlDataReader por que ellistview tiene q saber el total para paginar
      DataTable dt = new DataTable(); // 2. Creamos un DataTable
      da.Fill(dt);

      if (cn.State == ConnectionState.Open) // 4. Cerramos la conexión (el DataAdapter la abre y cierra solo, pero por las dudas)

      {
        cn.Close();
      }


      // 5. Asignamos el DataTable (que sí sabe cuántas filas tiene) al ListView
      lwProductos.DataSource = dt;
      lwProductos.DataBind();
      // cn.Close();

    }
    protected void Page_Load(object sender, EventArgs e)
    {
      if (!IsPostBack)
      {
        CargarSucursales(); // Llama sin filtros, trae todo.

        // --- CÓDIGO QUE TE FALTA: Cargar las provincias en el DataList ---
        ConexionDB objConex = new ConexionDB();
        SqlConnection cn = objConex.conectarseBD();
        SqlCommand cmdProvincias = new SqlCommand("SELECT Id_Provincia, DescripcionProvincia FROM Provincia", cn);
        SqlDataReader drProvincias = cmdProvincias.ExecuteReader();

        dlProvincias.DataSource = drProvincias; // Apuntamos al DataList
        dlProvincias.DataBind();                // Lo llenamos

        cn.Close();


      }
    }

        protected void ImageButton1_Click(object sender, ImageClickEventArgs e)
        {

        }

        protected void lvSucursales_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

    protected void btnSeleccionar_Command(object sender, CommandEventArgs e)
    {
      if (e.CommandName == "eventSeleccionarMigue")//llamo al evento que puse en el aspx
      {
        string argumentoCompleto = e.CommandArgument.ToString();//recibo string completo "1;Sucursal Centro;Calle Falsa 123"

        // 2. Lo separamos en un array usando el punto y coma como separador
        string[] datos = argumentoCompleto.Split(';');//este esun array de memoria heap de c++, por que desp de cortar ysaber las posiciones no se puede cambiar el tamaño
        //Equivalente en C++: new int[tamano];
        /* 
         datos[0] contendrá "1"
         datos[1] contendrá "Sucursal Centro"
         datos[2] contendrá "Calle Falsa 123"
         */

        // 3. Creamos un nuevo objeto Sucursal con los datos del array
        Sucursal objSucursal = new Sucursal();
        objSucursal.Id = Convert.ToInt32(datos[0]);//objSucursal.setId(Convert.ToInt32(datos[0]));
        objSucursal.Nombre = datos[1];//objSucursal.setNombre(datos[1]);
        objSucursal.Descripcion = datos[2];//objSucursal.setDescripcion(datos[2]);

        if (Session["SucursalesSeleccionadas"] == null) // 4. Verificamos si la lista en la Session ya existe

        {
          // Si no existe, la creamos como una Lista de objetos Sucursal
          Session["SucursalesSeleccionadas"] = new List<Sucursal>();//el () es por q llamo al constructor
          //casa nueva (new List<Sucursal>()) en algún lugar de la memoria del servidor.
          //la Session no guarda la casa, guarda la dirección de memoria donde está la casa, la direccion del objeto ya que Session es genrico (Object)
        }
        //# include <vector> 
        //std::vector<Sucursal> listaSucursales;// Creas una nueva lista (vector) de objetos Sucursal




        // 5. Agregamos la nueva sucursal a la lista en la Session
        List<Sucursal> listaSucursales = (List<Sucursal>)Session["SucursalesSeleccionadas"];
        //al tipo Objet de Session lo casteo a List<Sucursal> por que yo se que tiene eso
        //El compilador sabe que cada objeto tiene Id, Nombre y Descripcion
        //A-Session["SucursalesSeleccionadas"]: Va a la Session y toma el papelito con la dirección.
        //B-(List<Sucursal>) => miro el papel y yo programadero le diro esta es la direccion de una casa de tipo List<Sucursal>
        //C-List<Sucursal> listaSucursales = esto no es una casa nueva, creo un papelnuevo(variable) y le pongo la direccion de la casa que ya existe en Session
        //Ahora tenés dos papelitos (Session["SucursalesSeleccionadas"] y listaSucursales) que tienen escrita la misma dirección y apuntan a la única casa (List<Sucursal>) que existe en la memoria.




        // (Opcional pero recomendado) Chequeamos que no esté repetida antes de agregarla
        if (!listaSucursales.Any(s => s.Id == objSucursal.Id))// Esto se llama expresión lambda. Es una forma súper compacta de escribir una función.
        {
          listaSucursales.Add(objSucursal);
        }

        //.Any devuelve true o false si encuentra o no un elemento que cumpla la condición
        //s es variable temporal que representa cada elemento de la lista en cada iteració (cada sucursal de la lista)
        //=> significa "tal que"
       

        // --- LA VERSIÓN LARGA Y EXPLÍCITA ---
        bool yaExiste = false; //Creamos una variable "bandera" para saber si encontramos un duplicado.

        foreach (Sucursal sucursalEnLaLista in listaSucursales)  // 2. Recorremos cada sucursal que ya está en la lista.
        {
          if (sucursalEnLaLista.Id == objSucursal.Id)
          {
            yaExiste = true;// ¡Encontramos un duplicado!
            break;
          }
        }

        if (yaExiste == false) //Si la bandera nunca se levantó, significa que no había duplicados
        {
          listaSucursales.Add(objSucursal);
        }


      }


    }
   
    protected void btnBuscarPorNom_Click(object sender, EventArgs e)
    {
      // Llama al método pasándole solo el filtro de nombre.
      CargarSucursales(txtBusquedaPorNomb.Text.Trim());


    }

        protected void btnProvincias_Command(object sender, CommandEventArgs e)
        {
          if (e.CommandName == "eventBuscarPorProvincia")
          {
            // Llama al método pasándole solo el filtro de provincia.
            CargarSucursales("", e.CommandArgument.ToString());
          }
        }
    }
}