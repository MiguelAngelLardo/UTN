#include <iostream>

using namespace std;

/**
 Busca un elemento dentro del vector que se envia como parámetro. 
 @param vec El vector donde buscar
 @param TAM El tamaño del vector
 @param elementoBuscado El elemento a buscar en el vector
 @return bool
*/
bool existeElementoEnVector(int *vec, const int TAM, int elementoBuscado){
  for(int x = 0; x < TAM; x ++){
    if(vec[x] == elementoBuscado)
      return true;
  }
  return false;
}

/**
 Muestra los elementos que existen en el vector A pero no en el B y visceversa.
*/
void mostrarDiferenciaSimetrica(int *vecA, const int tamA, int *vecB, const int tamB){
  int *vecC = nullptr;//si el S.O me da memoria dinamica hace que el puntero apunte al primer elemento del ARRAY 
  vecC = new int (tamA + tamB);
  int pos = 0;
  if(vecC != nullptr)// si apunta a algo diferente a CERO(nullptr) significa que apunta a un elemento osea q hay memoria usada
  {
    ///RELLENO ELEMENTOS QUE ESTAN EN A PERO NO EN B
    for(int i = 0; i < tamA; i ++){
      if(!existeElementoEnVector(vecB, tamB, vecA[i])){ // si da return == false
        vecC[pos++] = vecA[i];//primero usa la posicion pos y desp lo incrementa
      }
    }

    ///RELLENO ELEMENTOS QUE ESTAN EN B PERO NO EN A
    for(int i = 0; i < tamB; i ++){
      if(!existeElementoEnVector(vecA, tamA, vecB[i])){ // si da return == false
        vecC[pos++] = vecB[i];//primero usa la posicion pos y desp lo incrementa
      }
    }
    
    if(pos > 0){
      for(int x = 0; x < pos; x ++){
        cout << vecC[x] << " ";
      }
    }

    delete []vecC;
  } 

}

int main(){
  int vecA[5] = {1, 2, 3, 4,5};
  int vecB[7] = {1, 2, 3, 10, 20, 30, 40};

  mostrarDiferenciaSimetrica(vecA, 5, vecB, 7);

  return 0;
}