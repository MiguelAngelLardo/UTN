#include <iostream>

using namespace std;
#include "funciones.h"

int main (){
  int *vCandidatos = nullptr; //nullpointer es que el puntero no apunta a nada, asi no hay basura
  int *vMunicipios = nullptr;
  int n1,n2;

  cout << "Ingres los candidatos a presidente: ";
  cin >> n1;
  vCandidatos = new int [n1]; //pido memoria para el vector de entero
  for (int i = 0; i < n1; ++i) {
    vCandidatos[i] = 0;
  }

  cout << "Ingres los municipios: ";
  cin >> n2;
  vMunicipios = new int [n2]; //pido memoria para el vector de entero
  for (int i = 0; i < n2; i ++){
    vMunicipios[i] = 0;
  }
  
  cargarDatos(vCandidatos, vMunicipios);
  puntoA(vCandidatos, n1);
  puntoB(vMunicipios, n2);

  delete []vCandidatos;
  delete []vMunicipios;
  

  return 0;
}