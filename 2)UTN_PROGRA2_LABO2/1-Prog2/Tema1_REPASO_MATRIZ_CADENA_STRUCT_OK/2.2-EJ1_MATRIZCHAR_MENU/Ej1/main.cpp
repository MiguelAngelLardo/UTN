#include <iostream>
#include <cstring>
#include "funciones.h"

using namespace std;

int main()
{
  char materias[20][35];//cargo 20 materias y 35 nombres
  float vHorasMaterias[20] = {};
  int matAccesos[20][31] = {0};
  int opc;
  while(true)
  {
    system("cls");
    cout << "************MENU*****************" << endl;
    cout << " 1. CARGAR MATERIAS " << endl;
    cout << " 2. MOSTRAR MATERIAS " << endl;
    cout << " 3. CARGAR ACCESOS" << endl;
    cout << " 4. MATERIAS SIN ACCESOS" << endl;
    cout << " 5. MATERIAS CON MAS HORAS" << endl;
    cout << " 6. ACCESOS " << endl;
    cout << " 0. FIN DEL PROGRAMA" << endl;
    cout << "**********************************" << endl;
    cout << "INGRESE OPCION" << endl;
    cin >> opc;

    system("cls");
    switch(opc){
    case 1:
      cargarMaterias(materias);
      break;
    case 2:
      mostrarMaterias(materias);
      break;
    case 3:
      cargatAccesos(vHorasMaterias, matAccesos);
      break;
    case 4:
      puntoA(vHorasMaterias, materias);
      break;
    case 5:
      puntoB(vHorasMaterias, materias);
      break;
    case 6:
      puntoC(matAccesos, materias);
      break;
    case 0:
      return 0;
      break;
    default:
      cout << "OPCION INCORRECTA. VUELVA A INGRESAR";
      break;
    }
    cout << endl;
    system("pause");

  }

    return 0;
}
