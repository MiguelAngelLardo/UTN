#include <iostream>

using namespace std;

/*

Hacer una función que reciba un vector de enteros y su tamaño y devuelva la
cantidad de números distintos que se repiten en el vector.*/

int funcionEnteros(int vector[], int tam) {
  int cont = 0;
  bool repetido;

  for(int i = 0; i < tam; i++) {
    repetido = false;
    for(int k = 0; k < i; k++) {
      if(vector[i] == vector[k]){
        repetido = true;
      }   
    }
    if(!repetido){
      for(int j = i + 1; j < tam; j++) {
        if(vector[i] == vector[j]){
          cont++;
          break;
        }
      }  
    }           
  }

  return cont;

}

int main() {
  int vector[12] = {1, 2, 1, 4, 2, 7, 1, 7, 1, 8, 8, 8};
  int cont = funcionEnteros(vector, 12);
  system ("cls");
  cout << cont << endl;
  return 0;
}