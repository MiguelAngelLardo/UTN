#include <iostream>
using namespace std;
/*Hacer un programa que muestre los números del 1 al 100 de 5 en 5. Ejemplo:
0, 5, 10, 15, 20…. 100.*/

int main (){

  for (int x = 0; x <= 100; x += 5) // x = x + 5
  {
    cout << x << endl;
  }

  return 0;
}