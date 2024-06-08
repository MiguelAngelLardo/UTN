#include <iostream>
#include <iomanip>

using namespace std;

/*
Hacer un programa que permita ingresar por teclado dos números y que luego
muestre por pantalla la suma, la resta, la multiplicación y la división de dichos
números. Se deben mostrar cuatro resultados en pantalla. Los números deben
ser solicitados una única vez.
*/

int main (){

  float num1, num2;

  cout << "Ingrese un numero: ";
  cin >> num1;
  cout << "Ingrese otro numero: ";
  cin >> num2;

  float resultado1 = num1 + num2;
  float resultado2 = num1 - num2;
  float resultado3 = num1 * num2;
  float resultado4 = num1 / num2; 
  
  cout << endl;
  cout << "la suma de los numeros es: " << fixed << setprecision(2) << resultado1 << endl;
  cout << "la resta de los numeros es: " << fixed << setprecision(2) << resultado2 << endl;
  cout << "la multiplicacion de los numeros es: " << fixed << setprecision(2) << resultado3 << endl;
  cout << "la division de los numeros es: " << fixed << setprecision(2) << resultado4 << endl;

  return 0;
}