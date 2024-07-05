#include <iostream>

using namespace std;
//2. Hacer un programa para solicitar por teclado un número y luego devolver su valor elevado al cubo.

int main(){
  int n, resultado;

  cout << "Ingrese un numero: ";
  cin >> n;

  resultado = n * n * n;

  cout << "El resultado es: " << resultado; 

  return 0;
}