#include <iostream>

using namespace std;

/*
4. Hacer una función que reciba como parámetros un vector de enteros y un número entero que indica la cantidad de componentes del vector, 
y que devuelva la posición que ocupa el valor máximo contenido en ese vector
*/

void cargarVector(int vec[], int tam);

int devolverPosMax(int vec[], int tam); 
//int vec[10], int *vec, int (&vec)[10]

int main (){

  int vec[5], posMax;
  
  cargarVector(vec, 5);
  posMax = devolverPosMax(vec, 5);

  cout << "La posicion del maximo es " << posMax + 1;

  return 0;
}

void cargarVector(int vec[], int tam){
  for(int x = 0; x < tam; x ++){
    cout << x+1 << ")Ingrese numero: ";
    cin >> vec[x];
  }
}


int devolverPosMax(int vec[], int tam){  
  int max, posMax;
  max = vec[0];
  posMax = 0;
  for(int x = 1; x < tam; x ++){
    if(vec[x] > max){
      max = vec[x];
      posMax = x;
    }
  }

  return posMax;
} 
