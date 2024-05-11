#include <iostream>
using namespace std;

/* Hacer un programa para ingresar por teclado tres números y luego determinar e
 informar con una leyenda aclaratoria si los tres son iguales entre sí, caso
 contrario no emitir nada.
 Tener en cuenta: Si A es igual a B y B es igual a C, entonces A y C son iguales.*/
 int main (){

  int n1, n2, n3;

  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese otro numero: ";
  cin >> n2;
  cout << "Ingrese otro numero: ";
  cin >> n3;

  if (n1 == n2 && n2 == n3){
    cout << "Son iguales";
  }

 return 0;
}