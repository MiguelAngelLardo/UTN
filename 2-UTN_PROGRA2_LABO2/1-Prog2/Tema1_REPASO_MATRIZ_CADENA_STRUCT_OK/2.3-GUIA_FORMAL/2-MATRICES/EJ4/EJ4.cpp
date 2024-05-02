#include <iostream>

using namespace std;
/*
4. Hacer una función que reciba como parámetros una matriz de enteros de 10x10
y un número entero (entre 0 y 9), y devuelva la cantidad de componentes
positivos de la columna indicada por el segundo parámetro.
*/

int funcion(int mNum [][3], int n);

int main (){
  int mNum[3][3] = {1, -200, -3,
                    4, 5, 6, 
                    700, 8, -9};
  int contPos = funcion(mNum, 1);

  cout << "La cantidad de positivos es: " << contPos;

  return 0;
}

int funcion(int mNum [][3], int n){
  int contPos = 0;
  for(int i = 0; i < 3; i ++){
    for(int j = n-1; j < n; j ++){
        if(mNum[i][j] > 0){
          contPos ++;
        }
      }
    }
  return contPos;    
}
