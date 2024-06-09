#include <iostream>

using namespace std;
/*3. Hacer un programa que permita ingresar el año actual y el año de la fecha de
nacimiento de una persona y luego calcule y emita por pantalla su edad.*/

int main (){
  int anioActual, anioNacimiento, edad;

  cout << "Ingrese el anio actual: "; 
  cin >> anioActual;
  cout << "Ingrese el anio de nacimiento: ";
  cin >> anioNacimiento;

  edad = anioActual - anioNacimiento;

  cout << "La edad es: " << edad;

  return 0;
}