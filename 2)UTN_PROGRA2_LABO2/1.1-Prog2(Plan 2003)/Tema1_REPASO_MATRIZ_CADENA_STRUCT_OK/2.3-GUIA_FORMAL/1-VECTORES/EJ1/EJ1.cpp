#include <iostream>

using namespace std;
/*
1. Hacer una función que reciba como parámetros un vector de enteros y 
un número entero que indica la cantidad de componentes del vector, 
y que devuelva el valor mínimo contenido en ese vector.
*/

void cargarVector(int vec[], int tam);

int devolverMinimo(int vec[], int tam); 
//int vec[10], int *vec, int (&vec)[10]

int main (){

  int vec[5], min;
  
  cargarVector(vec, 5);
  min = devolverMinimo(vec, 5);

  cout << "EL minimo es: " << min;

  return 0;
}

void cargarVector(int vec[], int tam){
  for(int x = 0; x < tam; x ++){
    cout << x+1 << ")Ingrese numero: ";
    cin >> vec[x];
  }
}


int devolverMinimo(int vec[], int tam){  
  int min;
  min = vec[0];
  for(int x = 1; x < tam; x ++){
    if(vec[x] < min){
      min = vec[x];
    }
  }

  return min;
} 
