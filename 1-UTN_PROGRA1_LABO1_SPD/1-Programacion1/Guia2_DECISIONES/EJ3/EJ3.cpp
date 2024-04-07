#include <iostream>
using namespace std;

/*Hacer un programa para ingresar por teclado un número y luego informar por
 pantalla con un cartel aclaratorio si el mismo es par o impar*/

int main (){

 int n;

 cout << "Ingrese un numero: ";
 cin >> n;

 if (n % 2 == 0){
  cout << "Es par";
 }else{
  cout << "No es par";
 }

  return 0;
}