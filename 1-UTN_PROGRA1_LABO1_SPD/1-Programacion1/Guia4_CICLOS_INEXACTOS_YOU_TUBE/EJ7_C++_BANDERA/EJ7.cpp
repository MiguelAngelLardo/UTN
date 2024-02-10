#include <iostream>
using namespace std;

/*Hacer un programa que solicite una lista de números que corta cuando se
ingresa un cero y luego mostrar por pantalla el máximo de ellos y la posición
en la que fue ingresado.*/

int main (){

  int n, posicion = 0, posicionMax, maxNum;
  bool banderaMax = false;

  printf("1) Ingrese un numero: ");
  cin >> n;

  while(n != 0){
    posicion ++;
    if(!banderaMax){ // banderaMax == false
      maxNum = n;
      banderaMax = true;
      posicionMax = posicion;
    }else if(n > maxNum){
      maxNum = n;
      posicionMax = posicion;
    }


    printf("%d) Ingrese un numero: ", posicion + 1);
    cin >> n;
  }

  cout << "El numero maximo es: " << maxNum << endl;
  printf("En la posicion %d", posicionMax);

  
  return 0;
}

