#pragma once


void desplegarMenu();
void implementarOpcion(int op);




///.CPP -> #include "menu.h" - #include "estructuras.h" - #jugar.h
#include "jugar.h"
using namespace std;
void desplegarMenu(){
  int opcion;

  do{
    cout <<endl << "EMBAUCADO" << endl;
    cout << "-------------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADÍSTICAS" << endl;
    cout << "3 - CRÉDITOS" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "Ingrese su opción: ";
    cin >> opcion;

    implementarOpcion(opcion);

  }while(opcion != 0);
}

void implementarOpcion(int op){
  system("cls");

  switch(op)
  {
    case 1://jugar
      jugar();
      break;

    case 2:
      //estadisticas
      break;
    case 3:
      //credigos
      break;
    case 0:
      cout << "-------------------------" << endl;
      cout << "SALIENDO DEL JUEGO. GRACIAS POR JUGAR EMBAUCADO";
      break;

    default:
      cout << "ERROR: " << op << " No es un numero valido." << endl;
      system("pause");system("cls");
      break;

  }

  //system("cls");


}
