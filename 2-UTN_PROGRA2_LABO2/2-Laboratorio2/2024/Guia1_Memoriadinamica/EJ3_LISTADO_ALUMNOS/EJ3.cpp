#include <iostream>
#include <string>
using namespace std;
#include "Funciones.h"

main (){
  int *notas = nullptr, cantAlum;
  string *nombreApellido = nullptr;

  cout << "Ingrese la cantidad de alumnos que tiene en su materia: ";
  cin >> cantAlum;
  notas = new int [cantAlum];
  nombreApellido = new string [cantAlum];

  int ptoA; 
  if(notas != nullptr && nombreApellido != nullptr){
    cargarDatos(notas, nombreApellido, cantAlum);
    ptoA = ptoACantidadMayorPromedio(notas, cantAlum);

    cout << endl << "PTOA" << endl;
    cout << "La cantidad de alumnos con nota mayor al promedio es: #" << ptoA << endl;

    cout << endl << "PTOB" << endl;
    ptoBListadoMayorPromedio(notas, nombreApellido, cantAlum);

    delete []notas;
    delete []nombreApellido;
  }else{
    cout << "No hay memoria dinamica";
  }

  return 0;
}