#include <iostream>

using namespace std;

/*
Actividad

Hacer un programa que permita representar un Incrementador. 
Un incrementador es un número entero que comienza con un valor inicial y pueda incrementarse a partir de un valor de incremento. 
También deberá llevar la cuenta de la cantidad de veces que incrementó.

Por ejemplo, si nuestro incrementador comienza en 0 y el valor de incremento es de 50. En cada incremento, aumentará de 50 en 50. Ejemplo:
0, 50, 100, 150, etc.


Restricciones:
-	El valor del incrementador no puede nunca disminuir.
-	La cantidad de veces que se incrementó siempre debe aumentar de uno en uno. Tampoco puede disminuir.
-	Siempre que el incrementador aumente debe hacerlo por la misma cantidad definida en el valor de incremento.

*/

void incrementar(int &incremento, int &cantidad);

int main(){
  int incrementador = 0;
  bool quieroIncrementar = true;
  int cantidad = 0;

  cout << "Quiere incrementar: ";
  cin >> quieroIncrementar;

  while(quieroIncrementar){
    incrementar(incrementador, cantidad);

    cout << "Valor actual: " << incrementador << endl;


    cout << "Quiere incrementar: ";
    cin >> quieroIncrementar;
  }

  cout << "Valor final: " << incrementador << endl;
  cout << "Cantidad de incrementos: " << cantidad << endl;


  return 0;
}

void incrementar(int &incremento, int &cantidad){
  incremento += 50;
  cantidad ++;
}