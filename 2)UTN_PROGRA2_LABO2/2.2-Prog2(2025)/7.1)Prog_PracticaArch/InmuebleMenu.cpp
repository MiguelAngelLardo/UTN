#include <iostream>
#include "InmuebleMenu.h"
using namespace std;  
void InmuebleMenu::menuInmueble(){
  int opcion;

  do
  { 
    cout << "1. ALTA" << endl;
    cout << "2. BAJA" << endl;
    cout << "3. MODIFICAR PRECIO" << endl;
    cout << "4. LISTADO" << endl;
    cout << "5. BUSCAR POR CALLE" << endl;
    cout << "6. BUSCAR POR RANGO DE PRECIO" << endl;
    cout << "7. REACTIVAR PROPIEADAD" << endl;
    cout << "0. SALIR" << endl;
    cout << "*************************" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
     case 1:{
      _InmuebleManager.cargarInmueble();
     }break;
     case 2:{
       _InmuebleManager.eliminarLogico();
     }break;
     case 3:{
       _InmuebleManager.modificarPrecioInmueble();
     }break;
     case 4:{
      _InmuebleManager.listarTodosLeyendoDeAUno();
     }break;
     case 7:{
      _InmuebleManager.reactivarInmueble();
     }break;

     case 0:{
       cout << "Gracias por usar el programa" << endl;
     }break;
    } 
   
  }while (opcion != 0);
  


}