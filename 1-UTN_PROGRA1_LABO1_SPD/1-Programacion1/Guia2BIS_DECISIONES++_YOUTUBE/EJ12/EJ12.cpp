#include <iostream>
using namespace std;

/*Hacer un programa para ingresar tres números y emitir un cartel aclaratorio si
la suma de los dos primeros es mayor al producto del segundo con el tercero.*/

int main (){

  int n1, n2, n3, suma, producto;

  cout << "ingrese el numero 1: ";
  cin >> n1;
  cout << "ingrese el numero 2: ";
  cin >> n2;
  cout << "ingrese el numero 3: ";
  cin >> n3;

  suma = n1 + n2;
  producto = n2*n3;  


  if (suma > producto){
    cout << "SUMA ES MAYOR QUE PRODUCTO.";
  }

  return 0;
}