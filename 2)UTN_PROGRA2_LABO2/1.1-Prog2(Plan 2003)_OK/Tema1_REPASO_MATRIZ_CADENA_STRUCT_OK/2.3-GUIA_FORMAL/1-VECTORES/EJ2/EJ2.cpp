#include <iostream>

using namespace std;
/*
2. Hacer una función que reciba como parámetros un vector de enteros y un 
número entero que indica la cantidad de componentes del vector, 
y que devuelva el valor máximo contenido en ese vector.
*/

void cargarVector(int vec[], int tam);

int devolverMaximo(int (&vec)[5], int tam); 
//int vec[10], int *vec, int (&vec)[10]

int main (){

  int vec[5], max;
  
  cargarVector(vec, 5);
  max = devolverMaximo(vec, 5);

  cout << "EL maximo es: " << max;

  return 0;
}

void cargarVector(int vec[], int tam){
  for(int x = 0; x < tam; x ++){
    cout << x+1 << ")Ingrese numero: ";
    cin >> vec[x];
  }
}


int devolverMaximo(int (&vec)[5], int tam){  
  int max;
  max = vec[0];
  for(int x = 1; x < tam; x ++){
    if(vec[x] > max){
      max = vec[x];
    }
  }

  return max;
} 


