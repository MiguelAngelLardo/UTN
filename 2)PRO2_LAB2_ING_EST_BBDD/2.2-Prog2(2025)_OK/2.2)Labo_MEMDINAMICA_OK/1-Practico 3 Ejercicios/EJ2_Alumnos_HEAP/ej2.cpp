#include <iostream>
#include <ctime>//para time

using namespace std;

/*
2- 📚 Actividad: Alumnos por Encima del Promedio
Un profesor desea cargar las notas de los alumnos de su 
curso y quiere saber cuántos de sus estudiantes obtuvieron una califi cación mayor que el promedio general.
El programa debe solicitar al usuario la cantidad de alumnos y debe permitir 
cargar una califi cación por cada uno de ellos.
*/

int main() {
  int cantidad, *vDimCalific = nullptr;

  cout << "Ingrese la cantidad de alumnos: ";
  cin >> cantidad;

  vDimCalific = new int[cantidad];

  if(vDimCalific == nullptr) exit(500);
  
  int acumNotas = 0;
  for(int i = 0; i < cantidad; i ++){
    cout << i+1 << ") Ingrese la nota: ";
    cin >> vDimCalific[i];
    acumNotas += vDimCalific[i];
  }

  float promedio = (float)acumNotas/cantidad;

  cout << "Promedio: " << promedio << endl;

  int contMayorAlPromedio = 0; 
  for(int i = 0; i < cantidad; i ++){
    if(vDimCalific[i] > promedio){
      contMayorAlPromedio ++;
    }
  }

  cout << "La cantidad mayor al primedio es: " << contMayorAlPromedio << endl;

  return 0;
}