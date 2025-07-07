#include <iostream>
using namespace std;
#include "funciones.h"

/*
5. Hacer una función que reciba como parámetros un vector de enteros de 10 elementos y un número entero, 
y que devuelva verdadero si el número recibido existe en el vector, o falso si no existe.
*/

int main(){
  int vec[TAM], n;
  bool bandera;
  ponerEnCero(vec);
  cargarVector(vec);
  
  cout << "Ingrese un numero para validarlo con el vector: ";
  cin >> n;
  bandera = corroborarIgualdad(vec, n);

  (bandera) ? cout << "Verdadero\n" : cout << "Falso\n";
  cout << (bandera ? "Verdadero" : "Falso"); 



 

  return 0;
}