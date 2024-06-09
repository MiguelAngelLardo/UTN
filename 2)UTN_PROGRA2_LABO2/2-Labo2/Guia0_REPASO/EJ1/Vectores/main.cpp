#include <iostream>

using namespace std;
#include "funciones.h"

int main()
{
  int opc, pos;
  int vec[10];
  bool cargado = false;
  while (true){
    system("cls");
    cout << "****MENU VECTORES****" << endl;
    cout << "**************************" << endl;
    cout << "1. Cargar vector" << endl;
    if(cargado){
    cout << "2. Mostrar vector" << endl;
    cout << "3. Mostrar maximo" << endl;
    cout << "4. mostrar minimo" << endl;
    }
    cout << "0. salir" << endl;
    cout << "**************************" << endl;
    cout << "ELIJA UNA OPCION: ";
    cin >> opc;
    system("cls");
    switch(opc){
      case 1:
        cargado = cargarVector(vec, 10);
        break;
      case 2:
        if (cargado) mostrarVector(vec, 10);
        else cout << "CARGAR VECTOR PRIMERO" << endl;
        break;
      case 3:
        if (cargado){
          pos=maximoVector(vec, 10);
          cout << "VALOR MAXIMO " << vec[pos];
        }
        else {
          cout << "CARGAR VECTOR PRIMERO" << endl;
        }
        break;
      case 4:
        if (cargado){
          pos=minimoVector(vec, 10);
          cout << "VALOR MINMO " << vec[pos];
        } else{
        cout << "CARGAR VECTOR PRIMERO" << endl;
        }
        break;
      case 0:
        return 0;
        break;
      default: cout << "OPCION INCORRECTA";
        break;
    }
    cout << endl;
    system("pause");
  }

  return 0;
}
