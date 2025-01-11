#include <iostream>

using namespace std;

/*
3. Hacer una función que reciba como parámetros un vector de enteros y un número entero que indica la cantidad de componentes del vector, 
y que devuelva la posición que cupa el valor mínimo contenido en ese vector.
*/

void cargarVector(int vec[], int tam);

int devolverPosMinimo(int vec[], int tam); 
//int vec[10], int *vec, int (&vec)[10]

int main (){

  int vec[5], posMin;
  
  cargarVector(vec, 5);
  posMin = devolverPosMinimo(vec, 5);

  cout << "EL la posicion del minimo es: " << posMin+1;

  return 0;
}

void cargarVector(int vec[], int tam){
  for(int x = 0; x < tam; x ++){
    cout << x+1 << ")Ingrese numero: ";
    cin >> vec[x];
  }
}


int devolverPosMinimo(int vec[], int tam){  
  int min, posMin;
  min = vec[0];
  posMin = 0;
  for(int x = 1; x < tam; x ++){
    if(vec[x] < min){
      min = vec[x];
      posMin = x;
    }
  }

  return posMin;
} 
