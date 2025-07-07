#include <iostream>

using namespace std;
/*
2. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 y un 
número entero (entre 0 y 9), y devuelva la 
posición que ocupa el máximo en la fila indicada por el segundo parámetro.
*/

int funcion(int mNum [][3], int n);

int main (){
  int mNum[3][3] = {1, 200, 3,
                    4, 5, 6, 
                    700, 8, 9};
  int posMaxFila = funcion(mNum, 1);

  cout << "La posiciondel maximo de la fila es: " << posMaxFila;

  return 0;
}

int funcion(int mNum [][3], int n){
  int maxDeLaFila, posDelmax;
  bool bandera = false;
  for(int i = n-1; i < n; i ++){
    for(int j = 0; j < 3; j ++){
      if(!bandera){
        maxDeLaFila = mNum[i][j];
        posDelmax = j + 1;
        bandera = true;
      }else if(mNum[i][j] > maxDeLaFila){
        maxDeLaFila = mNum[i][j];
        posDelmax = j + 1;
      }
    }
  }
  return posDelmax;    
}
