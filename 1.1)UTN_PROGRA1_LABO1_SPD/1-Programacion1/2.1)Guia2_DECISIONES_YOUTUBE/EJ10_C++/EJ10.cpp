#include <iostream>

using namespace std;

/*Hacer un programa para ingresar cuatro números y luego mostrar por pantalla
cuáles son mayores a 100.*/

int main(){
  int n1, n2, n3, n4;

  cout << "Ingrese el numero 1: ";
  cin >> n1;
  cout << "Ingrese el numero 2: ";
  cin >> n2;
  cout << "Ingrese el numero 3: ";
  cin >> n3;
  cout << "Ingrese el numero 4 ";
  cin >> n4;

  if(n1 > 100){
    cout << n1 << endl;
  }

  if(n2 > 100){
    cout << n2 << endl;
  }

  if(n3 > 100){
    cout << n3 << endl;
  }

  if(n4 > 100){
    cout << n4 << endl;
  }

  return 0;
}