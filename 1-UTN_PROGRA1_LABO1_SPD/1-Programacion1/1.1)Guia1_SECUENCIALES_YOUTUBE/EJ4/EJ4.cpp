#include <iostream>

using namespace std;
/* 4. Hacer un programa que permita ingresar los kilómetros existentes entre dos
ciudades y la velocidad promedio de un vehículo. Calcular y emitir por pantalla
el tiempo aproximado que demandará llegar de un punto a otro teniendo en
cuenta los datos ingresados. */

int main (){
  int km, v, t;
  cout << "Ingrese los KM: ";
  cin >> km;
  cout << "Ingrese la velocidad: ";
  cin >> v;

  t = km / v;

  cout << "El tiempo es: " << t;

  return 0;
}