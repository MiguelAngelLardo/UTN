#include <iostream>
#include "PropietarioMenu.h"

using namespace std;
void PropietarioMenu::menuPropietario(){
  int opcion;
  do
  { 
    cout << "1. ALTA" << endl;
    cout << "2. BAJA" << endl;
    cout << "3. MODIFICAR DATOS" << endl;
    cout << "4. LISTADO" << endl;
    cout << "5. BUSCAR CLIENTE POR DNI" << endl;
    cout << "6. BUSCAR TODAS LAS PROPIEDADES DEL CLIENTE" << endl;
    cout << "7. LISTAR INACTIVOS" << endl;
    cout << "0. REGRESAR AL MENU PRINCIPAL" << endl;
    cout << "*************************" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
     case 1:{
      _propietarioManager.cargarPropietario();
     }break;
     case 2:{
      _propietarioManager.bajaLogicaPorDNI();
     }break;
     case 3:{
      _propietarioManager.modificarTodoElRegistro();
     }break;
     case 4:{
      _propietarioManager.listarTodosLeyendoDeAUno();
     }break;
     case 5:{
      _propietarioManager.buscarPorDNI();
     }break;
     case 6:{
      _propietarioManager.listarPropiedadesDelCliente();
     }break;
     case 7:{
      _propietarioManager.listarInactivos();
     }break;
     case 0:{
      system("cls");
    }break;
    } 
   
  }while (opcion != 0);
  
}

