#include <iostream>

using namespace  std;
/*
Hacer un programa para ingresar por teclado la longitud de los tres lados de un
triángulo y que luego determine e informe con un cartel aclaratorio a qué tipo
de triángulo corresponde:
a. Equilátero: cuando los tres lados sean iguales.
b. Isósceles: cuando dos de los tres lados sean iguales.
c. Escaleno: cuando todos los lados sean distintos.
*/


int main (){
  int lado1, lado2, lado3;

  cout << "Ingrese la longitud del lado UNO del triangulo: ";
  cin >> lado1;
  cout << "Ingrese la longitud del lado DOS del triangulo: ";
  cin >> lado2;
  cout << "Ingrese la longitud del lado TRES del triangulo: ";
  cin >> lado3;

  if(lado1 == lado2 && lado2 == lado3) 
  {
    cout << "Equilatero";
  }  
  else
  {
    if(lado1 != lado2 && lado1 != lado3 && lado2 != lado3){
      cout << "Escaleno";
    }else{
      cout << "Isosceles";
    }
  }
  return 0;
}