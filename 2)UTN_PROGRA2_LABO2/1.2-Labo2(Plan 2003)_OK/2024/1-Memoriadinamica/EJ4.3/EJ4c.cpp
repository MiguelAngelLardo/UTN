#include <iostream>

using namespace std;

int* delta (int *alfa, int *beta, int tamAlfa, int tamBeta);


main(){
  int vAlfa[3] = {1, 2, 3};
  int vBeta[5] = {4, 5, 6, 7, 8};
  int tamGamma = 7;
  int *Gamma;
  
  Gamma = delta (vAlfa, vBeta, 3, 5);
  for(int x = 0; x < tamGamma; x ++){
    cout << x+1 <<") NUM #" << Gamma[x] << endl; 
  }

  delete []Gamma;

  return 0;
}


int* delta (int *alfa, int *beta, int tamAlfa, int tamBeta) {
  int *vGamma = nullptr;
  int tamGamma = tamAlfa+tamBeta;
  vGamma = new int [tamGamma];
 
  if(vGamma != nullptr){
    int indice = 0;
    // Asignar valores de alfa a gamma
    for (int j = 0; j < tamAlfa; j++) {
      vGamma[indice] = alfa[j];
      indice ++; //gamma[indice++] 
    }
 
    // Asignar valores de beta a gamma
    for (int j = 0; j < tamBeta; j++) {
      vGamma[indice ++] = beta[j];
    }

    return vGamma;

  }else{
    std::cout << "No hay suficiente espacio de memoria";
  }
}