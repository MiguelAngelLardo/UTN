#include <iostream>

using namespace std;

/*
9. Realizar el nuevamente el ejercicio 8 pero ahora debe devolver además la
posición en la que fue encontrado cada uno de los mínimos.
*/

int main(){
  int n, minimo1, minimo2;
  int posicion, posPrimerMin, posSegundoMin;;
  bool bandera = false;
  
  cout << "1) Ingrese un numero: ";
  cin >> n;
  minimo1 = n;
  posicion = 1; //POSICION GENERAL
  posPrimerMin = posicion;
 
  while(n != 0){
    if(n < minimo1){
      minimo2 = minimo1;
      posSegundoMin = posPrimerMin;
      minimo1 = n;
      posPrimerMin = posicion;
    }else if(!bandera){
      minimo2 = n;
      posSegundoMin = posicion;
      bandera = true;
    }else if(n < minimo2){
      minimo2 = n;
      posSegundoMin = posicion;
    }

    
    cout << posicion + 1 << ")Ingrese un numero: ";
    cin >> n;
    posicion ++;//POSICION GENERAL
  }

  cout << "El primer numero minimo es: " << minimo1 << " y esta en la posicion: "<< posPrimerMin << endl;
  printf ("El segundo numero minimo es: %d y se encuentra en la posicion: %d", minimo2, posSegundoMin);

  return 0;
}