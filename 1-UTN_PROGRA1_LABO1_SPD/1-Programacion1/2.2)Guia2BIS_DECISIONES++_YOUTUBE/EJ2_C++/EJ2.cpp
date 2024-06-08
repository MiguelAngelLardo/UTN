#include <iostream>
using namespace std;

/*Hacer un programa que solicite el ingreso de dos números y luego calcular:
a. La resta si el primero es mayor que el segundo.
b. La suma si son iguales.
c. El producto si el primero es menor.
Se deberá emitir un cartel por pantalla con el resultado correspondiente.*/

int main (){
  int n1, n2;
  int resultado;

  cout << " Ingrese un numero: ";
  cin >> n1;
  cout << " Ingrese otro numero: ";
  cin >> n2;

  if (n1 > n2){
    resultado = n1 - n2;
  }else if (n1 == n2){
      resultado = n1 + n2;
    }else if (n1 < n2){
      resultado = n1 * n2;
    }

    cout << "El resultado es: " << resultado;
    
  return 0;
}