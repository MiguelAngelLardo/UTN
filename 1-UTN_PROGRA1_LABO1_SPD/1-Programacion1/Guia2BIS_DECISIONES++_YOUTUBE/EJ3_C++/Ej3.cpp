#include <iostream>
using namespace std;

/*Hacer un programa para ingresar dos números. Si el segundo es distinto de
cero, calcular la división del primero por el segundo y mostrar el resultado por
pantalla; caso contrario, emitir un cartel aclarando que no se puede dividir por
cero.*/

int main (){

  int n1, n2;
  float resultado;

  cout << " Ingrese un numero: ";
  cin >> n1;
  cout << " Ingrese otro numero: ";
  cin >> n2;

  if (n2 != 0){
    resultado = n1 / n2;
    cout << " El resultado de dividir " << n1 << "  y " << n2 << " es: " << resultado;
  }else{
    cout << " No se puede dividir por 0";
  } 

    return 0;
  }