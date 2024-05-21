#include <iostream>

using namespace std; // cin y el cout mas facil de escribir
 
/*
2) Hacer un programa que solicite por teclado que se ingresen dos números y luego
guardarlos en dos variables distintas. A continuación se deben intercambiar mutuamente
los valores en ambas variables y mostrarlos por pantalla.
Ejemplo: Suponiendo que se ingresan 3 y 8 como valores y que la variables usadas son A y B,
entonces A=3 y B=8, pero luego debe quedar A=8 y B=3. 
*/

int main () { // es la funcion principal
//que solicite por teclado que se ingresen dos números
  int n1, n2, aux; //lowerCamelCase

  cout << "Ingrese el primer numero COCA: ";
  cin >> n1;//5
  
  cout << "Ingrese el segundo numero AGUA: ";
  cin >> n2;//30
   // <-------  
  aux = n1;
  //<-------
  n1 = n2;
  n2 = aux;
                      //juntar un texto con lo que tiene la variable
  cout << "Hola, soy n1 COCA => " << n1 << endl;//30
  cout << "Hola, soy n2 AGUA => " << n2 << endl;//5

  return 0; // con el numero entero
}