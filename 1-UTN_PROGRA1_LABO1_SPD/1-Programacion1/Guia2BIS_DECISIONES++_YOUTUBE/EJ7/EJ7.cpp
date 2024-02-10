#include <iostream>

using namespace std;

/*
7. Hacer un programa para ingresar 4 números. Luego analizar e informar por
pantalla si los mismos se encuentran ordenados de forma decreciente.

11,9,8,6
*/


int main (){
  int n1, n2, n3, n4;

  cout << "1) Ingrese un numero: ";
  cin >> n1;
  cout << "2) Ingrese otro numero: ";
  cin >> n2;
  cout << "3) Ingrese otro numero: ";
  cin >> n3;
  cout << "4) Ingrese otro numero: ";
  cin >> n4;

  if(n1 > n2 && n2 > n3 && n3 > n4){
    cout << "Decreciente"; 
  }else{
    cout << "Desordenados";
  }

  return 0;
}
