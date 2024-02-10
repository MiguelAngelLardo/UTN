#include <iostream>

using namespace std;
/*
1. Hacer un programa para mostrar los números del 1 al 10. No se debe realizar
ningún pedido de datos. USANDO WHILE.
*/

int main(){
  int n1 = 1;


  while(n1 <= 10){ //VERDADERO va a dar veultas sin parar
    cout << n1 << endl;
    n1 ++; //n1 = n1 +1 || n1 += 1 || n1 -=- 1;
  }

  return 0;
}