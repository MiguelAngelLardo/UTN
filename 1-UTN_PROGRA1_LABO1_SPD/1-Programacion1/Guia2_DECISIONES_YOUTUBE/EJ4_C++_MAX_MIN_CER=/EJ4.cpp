#include <iostream>

using namespace std;
/*
Hacer un programa para ingresar un número y luego se emita un cartel por
pantalla “Positivo” si el número es mayor a cero, “Negativo” si el número es
menor a cero o “Cero” si el número es igual a cero.
*/
int main (){

 int n1;

 cout << "ingrese un numero: ";
 cin >> n1;

 if (n1 > 0)
 {
   cout << "Es positivo";
 }
 else 
 {
   if (n1 < 0)
   {
     cout << "Es negativo";
   }
   else 
   {
     cout << "CERO";
   }
  }

  return 0;
}