#include <iostream>

using namespace std;
/*
14 Hacer un programa para ingresar una lista de números que finaliza cuando se
ingresa un cero, informar si todos están ordenados en forma creciente.
 En caso de haber dos números “empatados” considerarlos como crecientes.
Por ejemplo si la lista fuera:
Ejemplo 1: -10, 1, 5, 7, 15, 18, 20, 23, 0 se emitirá un cartel: “Conjunto Ordenado”
Ejemplo 2: 10, 10, 15, 20, 25, 25, 28, 33, 0 se emitirá un cartel: “Conjunto Ordenado”
Ejemplo 3: 10, 1, 15, 7, -15, 18, 20, 23, 0 se emitirá un cartel: “Conjunto No Ordenado”

*/

int main(){
  int contCreciente = 0, contVueltas = 0;
  int numMinimoIngresado;
  int n;
  bool bandera = false;

  cout << "Ingrese un numero: ";
  cin >> n;


  while (n != 0){
    contVueltas ++; //10 -> contador centinela

    if (!bandera){ // -> (!bandera) -> bandera == false
      numMinimoIngresado = n;
      contCreciente++;
      bandera = true;
    }else if (n >= numMinimoIngresado){
      numMinimoIngresado = n;
      contCreciente ++;//5
    }
    
    cout << "Ingrese un numero: ";
    cin >> n;
  }

  if (contCreciente == contVueltas){
    cout << "Conjunto ordenado"<< endl;
  }else{
    cout << "Conjunto desordenado";
  }

  return 0;
}