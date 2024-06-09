#include <iostream>
using namespace std;

int main() {
  int legajo, sueldo, mayorSueldo = 0, legajoMayorSueldo;

  for (int i = 0; i < 10; i ++)
  { 
    cout << "Ingrese numero de legajo: ";
    cin >> legajo;
    cout << "Ingrese el sueldo: ";
    cin >> sueldo;

    if(sueldo > mayorSueldo)
    {
      mayorSueldo = sueldo;
      legajoMayorSueldo = legajo;
    }
  }
  
  cout << "Mayor sueldo: $" << mayorSueldo << ". Numero de legajo: " << legajoMayorSueldo;

	return 0;
}