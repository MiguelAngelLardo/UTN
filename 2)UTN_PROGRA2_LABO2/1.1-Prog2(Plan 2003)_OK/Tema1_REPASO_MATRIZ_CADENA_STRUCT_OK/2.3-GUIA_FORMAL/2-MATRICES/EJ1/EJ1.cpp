#include <iostream>

using namespace std;
/*
1. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un 
número entero (entre 0 y 9), y 
devuelva el máximo de la fila indicada por el segundo parámetro.
*/

int funcion(int mNum [][3], int n);

int main (){
  int mNum[3][3] = {1, 200, 3,
                    4, 5, 6, 
                    700, 8, 9};
  int maxFila = funcion(mNum, 2);

  cout << "El maximo de la fila es: " << maxFila;

  return 0;
}

int funcion(int mNum [][3], int n){
  int maxDeLaFila;
  bool bandera = false;
  for(int i = n-1; i < n; i ++){
    for(int j = 0; j < 3; j ++){
      if(!bandera){
        maxDeLaFila = mNum[i][j];
        bandera = true;
      }else if(mNum[i][j] > maxDeLaFila){
        maxDeLaFila = mNum[i][j];
      }
    }
  }
  return maxDeLaFila;    
}
