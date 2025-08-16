#include <iostream>

using namespace std;

void delta (int *alfa, int *beta, int tamAlfa, int tamBeta, int vGamma[], int tamGamma);

main(){
  int vAlfa[3] = {1, 2, 3};
  int vBeta[5] = {4, 5, 6, 7, 8};
  int tamGamma = 7;
  int *Gamma = new int[tamGamma];

  if(Gamma == nullptr){
    cout << "No se pudo pedir memoria " << endl;
    exit(-200);
  }
  
  delta (vAlfa, vBeta, 3, 5, Gamma, tamGamma);

  for(int x = 0; x < tamGamma; x ++){
    cout << x+1 <<") NUM #" << Gamma[x] << endl; 
  }

  delete []Gamma;

  return 0;
}


void delta (int *alfa, int *beta, int tamAlfa, int tamBeta, int vGamma[], int tamGamma){
  int indice = 0;

  for (int j = 0; j < tamAlfa; j++) {
    vGamma[indice] = alfa[j];
    indice ++; //gamma[indice++] 
  }

  for (int j = 0; j < tamBeta; j++) {
    vGamma[indice ++] = beta[j];
  }
}