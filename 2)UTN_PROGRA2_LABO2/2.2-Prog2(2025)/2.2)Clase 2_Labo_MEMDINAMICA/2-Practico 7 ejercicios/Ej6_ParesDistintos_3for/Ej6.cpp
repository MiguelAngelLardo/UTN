#include <iostream>

using namespace std;
/*
Escribe un programa que solicite al usuario ingresar una lista de 10 números
enteros. Luego, el programa debe mostrar los números pares distintos que se
ingresaron. Para resolver este ejercicio, deberás implementar una función que
reciba un vector de enteros y su tamaño, y que devuelva un puntero a un vector
dinámico que contenga solo los números pares distintos del vector recibido.
*/

int* paresDistintos(int v[], int &tam) {
  int *vDinParesDis = nullptr, cont = 0;
  bool repetido;

  for(int i = 0; i < tam; i++){
    repetido = false;
    if(v[i] % 2 == 0){
      if(i > 0){
        for(int k = 0; k < i; k++) {
          if(v[i] == v[k]){
            repetido = true;
            break;
          }
        }
      }
      if(!repetido){
        for(int j = i+1; j < tam; j++){
          if(v[i] == v[j]){
            cont ++;
            break;
          }  
        }
      } 
    }  
  }  

  vDinParesDis = new int[cont];
  if(vDinParesDis == nullptr)exit(500);

  int id = 0;
  for(int i = 0; i < tam; i++){
    repetido = false;
    if(v[i] % 2 == 0){
      if(i > 0){
        for(int k = 0; k < i; k++) {
          if(v[i] == v[k]){
            repetido = true;
            break;
          }
        }
      }
      if(!repetido){
        for(int j = i+1; j < tam; j++){
          if(v[i] == v[j]){
            vDinParesDis[id] = v[i];
            id++;
            break;
          }  
        }
      } 
    }  
  } 

  tam = cont;
  return vDinParesDis;
}  



int main() {
  int vNum[10] = {2, 6, 2, 1, 2, 6, 6, 8, 8, 10};
  int tam = 10;
  system("cls");

  int *vDin = paresDistintos(vNum, tam);

  cout << "Tam vale " << tam << endl;

  for(int i = 0; i < tam; i++){
    cout << "Numeros " << vDin[i] << " "<< endl;
  }  
}