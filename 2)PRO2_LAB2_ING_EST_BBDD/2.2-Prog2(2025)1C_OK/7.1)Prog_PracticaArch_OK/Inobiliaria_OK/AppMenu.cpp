#include <iostream>
#include "AppMenu.h"

using namespace std;

using namespace std;
void AppMenu::appMenu(){
  int opcion;
  do
  {
    cout << "1. MENU PROPIETARIO" << endl;
    cout << "2. MENU INMUEBLE" << endl;
    cout << "0. SALIR" << endl;
    cout << "*************************" << endl;
    cin >> opcion;
    system("cls");
    switch (opcion)
    {
     case 1:{
      _propietarioMenu.menuPropietario();
     }break;
     case 2:{
      _inmuebleMenu.menuInmueble();
     }break;
     case 0:{
       cout << "Gracias por usar el programa" << endl;
     }break;
    } 
   
  }while (opcion != 0);
  
}
