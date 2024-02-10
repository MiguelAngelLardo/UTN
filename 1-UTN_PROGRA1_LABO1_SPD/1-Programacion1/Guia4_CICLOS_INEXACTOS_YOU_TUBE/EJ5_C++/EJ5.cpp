#include <iostream>
using namespace std;

/* Hacer un programa que muestre los números del 1 al 100 de 5 en 5. Ejemplo:
0, 5, 10, 15, 20…. 100. Usando While.*/

int main (){

  int n1 = 0;

  while (n1 <= 100)
  {
    cout << n1 << endl;
    n1 += 5;
  }

  return 0;
}