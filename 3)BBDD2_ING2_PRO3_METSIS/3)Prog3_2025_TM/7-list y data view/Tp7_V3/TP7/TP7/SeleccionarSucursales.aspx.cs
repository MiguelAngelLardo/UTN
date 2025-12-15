using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;


using TP7.Modelo_Entidades_; // <-- Asi reconoce la clase Sucursal.Cs. El _ es para decirle Descarta este valor

namespace TP7
{
  public partial class SeleccionarSucursales : System.Web.UI.Page
  {

    private void AplicarFiltroPersistente()//me traer el IdProvincia(en el ViewEstate) para usar en el SqlCommand
    {
      if (ViewState["ProvinciaID_Filtro"] != null)//si el ViewState tiene algo entro y obtengo su valo
      {
        string provinciaId = ViewState["ProvinciaID_Filtro"].ToString();//obtengo su valor que es el IdProvincia

        // Si existe, aplicamos el filtro a la consulta.
        sqsSucursales.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal] FROM [Sucursal] WHERE [Id_ProvinciaSucursal] = @IdProvincia";
        sqsSucursales.SelectParameters.Clear();
        sqsSucursales.SelectParameters.Add("IdProvincia", provinciaId);
      }
      
    }

    protected void Page_Load(object sender, EventArgs e)
    {
      AplicarFiltroPersistente();//se ejecuta cada vez que hago click ya que no hay (!IsPostBack)

      //1-hago click en buenos aires -> se inicia postback
      //2-se ejecuta PageLoad -> pero ViewState es nulo
      //3- Se ejecuta el ItemCommand, se guarda IdProvincia = 1 en el ViewState -> entro al metodo AplicarFiltroPersistente para el SqlCommand
      //4-hago click en paginidador 2 de bs as => se inicia post back
      //5-se ejecuta page load primero y llama a AplicarFiltroPersistente -> revisa viewState y encuentra IdProvincia = 1 y hace la consulta SqlCommand
      //6-la pagina sabe que esta en las sucursales d ebuenos aires y el paginador actua en este momento
      //7-el DataPager le pide al ListView los datos de la pagina 2
      //8-claramebnte el ItemCommand no se ejecuta por q no se hizo click en DataList
    }

    //En el archivo .aspx: Agregará el atributo OnItemCommand="dlProvincias_ItemCommand"
    //En el archivo .cs (code-behind) => este es el code behind
    protected void dlProvincias_ItemCommand(object source, DataListCommandEventArgs e)
    { 
      if (e.CommandName == "Filtrar")//puedo tener dos valores en la misma fila un "filtrar" y un "eliminar"
      {
        string provinciaId = e.CommandArgument.ToString();// command Argument traer el Eval("Id_Provincia")
        //la mejor practica es usar un valor en Eval("Id_Provincia").. se podria con el truco de concatenar  Eval("Id_Provincia") + ";" + Eval("DescripcionProvincia") pero no esta bueno

        /*
         DataList ID="dlProvincias"  DataKeyField="Id_Provincia" DataSourceID="sqsProvincias" OnItemCommand="dlProvincias_ItemCommand">
         Button ID="btnDataListProv" CommandArgument='<%# Eval("Id_Provincia") %>' CommandName="Filtrar" 
         Text='<%# Eval("DescripcionProvincia")*/



        ViewState["ProvinciaID_Filtro"] = provinciaId;// Guardamos el ID en ViewState para recordarlo en futuros PostBacks.
        //ViewState guarda información en la propia página del usuario, por lo que solo "vive" en esa página.
        //Session guarda información en el servidor y está disponible en todas las páginas que ese usuario visite durante su sesión.

        //DataPager e sobjeto que controla la paginación en controles como ListView o GridView.
        DataPager pager = (DataPager)lvSucursal.FindControl("paginadorLvSucursal");//busco el control "paginadorLvSucursal" dentro del ListView "lvSucursal"
        //findcontrol devuelve object, asi que casteo
        if (pager != null)//si esta mal escrito "paginadorLvSucursal" o no lo encuentra devuelve nulo
        {
          pager.SetPageProperties(0, 6, true);
          //0 (startRowIndex): Indica el índice de la primera fila que se mostrará en la página actual. En este caso, 0 significa que comenzamos desde la primera fila.
          //pagina 1
            //0-Ticketek
            //1-fravega
            //2-lantec
            //3-daytona
            //4-reebok
            //5-burguer
          //pagina 2
              //0-burger


          //6 (maximumRows): Especifica el número máximo de filas que se mostrarán en la página actual. Aquí, 6 significa que queremos mostrar hasta 6 filas por página.
          //true (databind): Si se establece en true, le digo que el listview se acualice al instante 
        }


        // --- INICIO DE LA CORRECCIÓN ---

        AplicarFiltroPersistente();

        // 5. Forzamos al ListView a que se vuelva a enlazar a los datos AHORA.
        lvSucursal.DataBind();



      }





    }

    protected void btnBuscar_Click(object sender, EventArgs e)
    {
      if (string.IsNullOrWhiteSpace(txtBusquedaSucu.Text))
      {
        // Si el textbox está vacío, borramos el filtro de provincia de la memoria.
        ViewState["ProvinciaID_Filtro"] = null;

        // Y reseteamos la consulta a la original.
        sqsSucursales.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal] FROM [Sucursal]";
        sqsSucursales.SelectParameters.Clear();
      }
      else
      {
        sqsSucursales.SelectCommand = "SELECT [Id_Sucursal], [NombreSucursal], [DescripcionSucursal], [Id_ProvinciaSucursal], [URL_Imagen_Sucursal] FROM [Sucursal] WHERE [NombreSucursal] LIKE '%' + @NombreSucursal + '%'";
        sqsSucursales.SelectParameters.Clear();
        sqsSucursales.SelectParameters.Add("NombreSucursal", txtBusquedaSucu.Text);
      }

      // Reiniciamos el paginador y enlazamos los datos.
      DataPager pager = (DataPager)lvSucursal.FindControl("DataPager1");
      if (pager != null)
      {
        pager.SetPageProperties(0, 6, true);
      }
      lvSucursal.DataBind();
    }

    protected void btnSeleccionar_Command(object sender, CommandEventArgs e)
    { 
      
      if (e.CommandName == "eventSeleccionarSucu")//llamo al evento que puse en el aspx
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
  }
  
}