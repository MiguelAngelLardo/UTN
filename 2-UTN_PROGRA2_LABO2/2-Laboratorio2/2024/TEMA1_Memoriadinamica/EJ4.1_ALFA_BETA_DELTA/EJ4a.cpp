#include <iostream>

using namespace std;

void delta (int *alfa, int *beta, int tamAlfa, int tamBeta);int 


main(){
  int vAlfa[3] = {1, 2, 3};
  int vBeta[5] = {4, 5, 6, 7, 8};
  delta (vAlfa, vBeta, 3, 5);
 
  return 0;
}


void delta (int *alfa, int *beta, int tamAlfa, int tamBeta){
  int *gamma = nullptr, alfaBeta = tamAlfa+tamBeta;
  gamma = new int [alfaBeta];
 
  if(gamma != nullptr){
    int indice = 0;
    // Asignar valores de alfa a gamma
    for (int j = 0; j < tamAlfa; j++) {
        gamma[indice] = alfa[j];
        indice ++; //gamma[indice++] 
    }
 
    // Asignar valores de beta a gamma
    for (int j = 0; j < tamBeta; j++) {
        gamma[indice ++] = beta[j];
    }
 
    for(int x = 0; x < alfaBeta; x ++){
      std::cout << x+1 <<") NUM #" << gamma[x] << std::endl; 
    }
 
    delete []gamma;
 
  }else{
    std::cout << "No hay suficiente espacio de memoria";
  }
}