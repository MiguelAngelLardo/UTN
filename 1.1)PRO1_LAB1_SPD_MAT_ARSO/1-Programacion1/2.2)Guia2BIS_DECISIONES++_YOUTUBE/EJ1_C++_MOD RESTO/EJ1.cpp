#include <iostream>
using namespace std;

/*Hacer un programa que solicite el ingreso de un número y que luego emita un
cartel por pantalla aclarando si el mismo es múltiplo de 5.*/

int main (){

  int numero;

  cout << "ingrese un numero: ";
  cin >> numero;

  if (numero % 5 == 0){ 
    cout << "El numero #"<< numero << " es multiplo de 5";
  }else{
    cout << "El numero #" << numero << " no es multiplo de 5";
   }
  
  return 0;
}