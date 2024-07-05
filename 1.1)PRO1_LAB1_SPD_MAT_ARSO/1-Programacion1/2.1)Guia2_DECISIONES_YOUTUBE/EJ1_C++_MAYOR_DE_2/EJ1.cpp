#include <iostream>

using namespace std;
/*Hacer un programa para ingresar un número y luego se emita por pantalla un
cartel aclaratorio si “Es mayor a 10” o “No es mayor a 10”.*/

int main(){

  int numero;
  cout << "Ingrese un numero: ";
  cin >> numero;

  if(numero > 10)
  {
    cout << "Es mayor a 10";
  }
  else
  {
    cout << "No es mayor a 10";  
  }

  return 0;
}