#include <iostream>
#include <cstring>

#include "funciones.h"

using namespace std;

int main()
{
  char materias[20][30];
  int horas[20];
  inicializarVector(horas, 20); ///el tercer valor no lo pide por que esta POR DEFECTO
  int matDia[20][31];
  ponerCeroMatriz(matDia, 20, 31);
  int opc;
  while (true){
    system("cls");
    cout << "MENU PRINCIPAL" << endl;
    cout << "------------------------" << endl;
    cout << "1. INGRESO MATERIAS" << endl;
    cout << "2. MOSTRAR MATERIAS" << endl;
    cout << "3. INGRESO DE ACCESOS" << endl;
    cout << "4. MOSTERIAS SIN ACCESO" << endl;
    cout << "5. MATERIA CON MAS ACCESOS" << endl;
    cout << "6. ESTADISTICAS AGOSTO" << endl;
    cout << "0. FIN DEL PROGRAMA" << endl;
    cout << "------------------------" << endl;
    cout << "OPCION: ";
    cin >> opc;
    switch(opc){
    case 1:
      cargarMaterias(materias);
      break;
    case 2:
      mostrarMatrizCaracteres(materias, 10);
      break;
    case 3:
      ingresarDatosAccesos(horas, matDia);
      break;
    case 4:
      puntoA(horas, materias, matDia);
      break;
    case 5:
      puntoB(horas, materias);
      break;
    case 6:
      puntoC(matDia, materias);
      break;
    case 0:
      return 0;
      break;

    }

  }







    return 0;
}
