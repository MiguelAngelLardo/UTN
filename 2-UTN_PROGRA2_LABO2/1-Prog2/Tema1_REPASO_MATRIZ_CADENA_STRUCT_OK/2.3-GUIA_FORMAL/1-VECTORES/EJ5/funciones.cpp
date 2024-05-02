#include "funciones.h"
#include <iostream>

void ponerEnCero(int *vec){
  for(int x = 0; x < TAM; x ++){
    vec[x] = 0;
  }
}

void cargarVector(int *vec){
  for (int i = 0; i < TAM; i++)
  {
    std::cout << i+1 << ") Ingrese un numero: ";
    std::cin >> vec[i]; 
  }
}

bool corroborarIgualdad(int *vec, int n){
  for (int x = 0; x < TAM; x ++){    
    if (vec[x] == n)
      return true;
  }
  return false; 
}