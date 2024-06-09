#include <iostream>
using namespace std;

/*Hacer un programa que solicite 10 números y luego mostrar por pantalla el
máximo de ellos y la posición en la que fue ingresado.*/

int main (){
  int n, max, posicion;

  for(int x = 0; x < 10; x++)
  {
    cout << x+1 << ") Ingrese un numero: ";
    cin >> n;

    if(x == 0){
      max = n;
      posicion = 1;
    }else if(n > max){
      max = n;
      posicion = x + 1;
    }
  }

  cout << "El numero maximo es: " << max << " - POSICION: " << posicion;

  return 0;
}