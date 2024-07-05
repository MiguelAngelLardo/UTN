#include <iostream>

using namespace std;
/*
1) Hacer un programa para ingresar por teclado la cantidad de horas trabajadas por un
operario y el valor que se le paga por hora trabajada y listar por pantalla el sueldo que le
corresponda. 
*/
int main(){
  int horas, sueldo, valor;

  cout << "Ingrese las horas trabajadas: ";
  cin >> horas;
  cout << "Ingrese el valor por hora: ";
  cin >> valor;

  sueldo = horas * valor;

  cout << "Su sueldo es de: " << sueldo << endl;

  return 0;
}