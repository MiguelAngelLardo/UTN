#include <iostream>
using namespace std;

/* Hacer un programa que solicite dos números y luego muestre los números
entre el menor y el mayor de ellos. Acordate, usando While.*/

int main (){

  int n1, n2;
  cout << "Ingrese un numero: ";
  cin >> n1;
  cout << "Ingrese otro numero: ";
  cin >> n2;

  while (n1 < n2 - 1)
  {
    n1++;
    
    cout << n1 << endl;
  }
    
  return 0;
}