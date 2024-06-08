/* 2-Hacer un programa que solicite por teclado que se ingresen dos números y
luego guardarlos en dos variables distintas. A continuación se deben
intercambiar mutuamente los valores en ambas variables y mostrarlos por
pantalla.
Ejemplo: Suponiendo que se ingresan 3 y 8 como valores y que la variables
usadas son A y B, entonces A=3 y B=8, pero luego debe quedar A=8 y B=3. */

#include <iostream>
using namespace std;

 int main(){
 int A,B,AUX;
 cout << "Ingrese dos numeros" << endl;
 cin >> A >> B;
cout << "Los valores originales son: A = " << A <<" B= " << B << endl;

AUX = A;
A = B;
B = AUX;

cout << "Los valores invetidos son: A = " << A << " B= " << B;
return 0;

 }
