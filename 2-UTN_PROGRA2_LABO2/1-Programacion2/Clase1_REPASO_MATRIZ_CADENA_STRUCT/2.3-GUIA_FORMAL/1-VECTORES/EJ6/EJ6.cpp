#include <iostream>

using namespace std;

int funcion (int *vNum, int n);

int main (){
  int vNum[10] = {1, 2, 3, 10, 20, 30, 40, 100, 200, 300};
  int retorno;

  retorno = funcion(vNum, 300);

  cout << "El retorno es: " << retorno;

  return 0;
}

int funcion (int *vNum, int n){
  for(int x = 0; x < 10; x ++){
    if(vNum[x] == n){
      return x + 1;
    }
  }
  return -1;
}