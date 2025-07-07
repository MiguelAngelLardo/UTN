#include <iostream>

using namespace std;
/*
3. Hacer una función que reciba como parámetros una matriz de enteros de 10x10 
y un número entero (entre 0 y 9), y 
devuelva la suma de todos los componentes de la columna indicada por el segundo parámetro.
*/

int funcion(int mNum [][3], int n);

int main (){
  int mNum[3][3] = {1, 200, 3,
                    4, 5, 6, 
                    700, 8, 9};
  int posMaxFila = funcion(mNum, 3);

  cout << "La posiciondel maximo de la fila es: " << posMaxFila;

  return 0;
}

int funcion(int mNum [][3], int n){
  int sumaColumna = 0;
  for(int i = 0; i < 3; i ++){
    for(int j = n-1; j < n; j ++){
        sumaColumna += mNum[i][j];
      }
    }
  return sumaColumna;    
}
