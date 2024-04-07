#include <iostream>

using namespace std;
/*
5. Hacer una función que reciba como parámetros una matriz de enteros
de 10x10,
y devuelva la suma de todos los componentes de la matriz.
*/

int funcion(int mNum [][3]);

int main (){
  int mNum[3][3] = {1, 1, 1,
                    2, 2, 2, 
                    3, 3, 3};
  int sumTot = funcion(mNum);

  cout << "La suma total es " << sumTot;

  return 0;
}

int funcion(int mNum [][3]){
  int sumaTotal = 0;
  for(int i = 0; i < 3; i ++){
    for(int j = 0; j < 3; j ++){
      sumaTotal += mNum [i][j];    
    }
  }    
  return sumaTotal;    
}
