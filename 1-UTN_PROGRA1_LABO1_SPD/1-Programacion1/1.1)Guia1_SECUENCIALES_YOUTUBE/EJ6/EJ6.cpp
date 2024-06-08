#include <iostream>

using namespace std;

/*6. Hacer un programa para ingresar por teclado las tres notas de exámenes de un
alumno y luego calcule y emita por pantalla el promedio final*/

int main (){
  int n1, n2, n3;

  cout << "Ingrese la nota 1: ";
  cin >> n1;
  cout << "Ingrese la nota 2: ";
  cin >> n2;
  cout << "Ingrese la nota 3: ";
  cin >> n3;

  int promedio = (n1+n2+n3)/3;

  cout << "El promedio es: " << promedio;

  return 0;
}