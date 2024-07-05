#include <iostream>
using namespace std;
/* Hacerun programa para ingresar por teclado tres números e informar con una
 leyenda aclaratoria si los tres son todos distintos entre sí, caso contrario no
 emitir nada.
 Tener en cuenta: Si A es distinto de B y B es distinto de C, eso no significa que A
 y Cseandistintos. Ejemplo: A=8, B=6 y C=8*/

 int main (){

  int n1, n2, n3;

  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese un numero: ";
  cin >> n2;
  cout << "Ingrese un numero: ";
  cin >> n3;

  if (n1 != n2 && n1 != n3 && n2 != n3){
    cout << "Son diferentes entre si";
  }
  
  return 0;
 }