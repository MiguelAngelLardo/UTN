#include <iostream>

using namespace std;

int funcion (int *vNum, int n);

int main (){
  int vNum[10] = {1, 2, 3, 10, 20, 3, 40, 100, 3, 300};
  int retorno;

  retorno = funcion(vNum, 3);

  cout << "El retorno es: " << retorno;

  return 0;
}

int funcion (int *vNum, int n){
  int cont = 0;
  for(int x = 0; x < 10; x ++){
    if(vNum[x] == n){
      cont ++;
    }
  }
  return cont;
}