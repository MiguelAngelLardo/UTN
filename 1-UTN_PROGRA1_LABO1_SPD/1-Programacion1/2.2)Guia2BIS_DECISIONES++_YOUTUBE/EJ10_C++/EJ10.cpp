#include <iostream>

using namespace std;
/*
10. Hacer un programa que solicite cuatro números y emitir un cartel aclaratorio si
son todos iguales entre sí, caso contrario, no emitir nada.
*/

int main(){
  int n1, n2, n3, n4;
  cout << "Ingrese el numero 1: ";
  cin >> n1;
  cout << "Ingrese el numero 2: ";
  cin >> n2;
  cout << "Ingrese el numero 3: ";
  cin >> n3;
  cout << "Ingrese el numero 4: ";
  cin >> n4;

  if(n1 == n2 && n2 == n3 && n3 == n4)
  {
    cout << "Son iguales";
  }

  //(n1 == n2 && n2 == n3 && n3 == n4) ? cout << "Son igueles" : cout << " " ;

  return 0;
}