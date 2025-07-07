#include "funciones.h"
#include <iostream>

using namespace std;

void cargarDatos(int vCandidatos[], int *vMunicipios){
  int candidato, municipio, cantidadVotos;

  cout << "Municipio: ";
  cin >> municipio;
  
  while(municipio >= 0){
    cout << "Candidato: ";
    cin >> candidato;
    cout << "Votos: ";
    cin >> cantidadVotos;

    // A
    vCandidatos[candidato-1] += cantidadVotos;

    // B
    vMunicipios[municipio-1] += cantidadVotos;

    cout << "Municipio: ";
    cin >> municipio;
  }
}

void puntoA(int *vCandidatos, int cantidadCandidato){
  int candidatoMasVotado = buscarIndiceMaximo(vCandidatos, cantidadCandidato);
  cout << "Candidato mas votado: " << candidatoMasVotado + 1 << endl;

}
void puntoB (int vMunicipios[], int candidadMunicipios){
  int cantMunicipios =  contarMayoresAReferencia(vMunicipios, candidadMunicipios, 5000);
  cout << "Cantidad de municipios con mas de 5000 votos: " << cantMunicipios << endl;

}

int contarMayoresAReferencia(int vectorBusqueda[], int cantidad, int valorReferencia){
  int cont = 0;
  for(int i = 0; i < cantidad;  i ++){
    if (vectorBusqueda [i] > valorReferencia){
      cont ++;
    }
  }
  return cont;
}

int buscarIndiceMaximo (int vectorBusqueda[], int cantidad){
  int posicionMaximo = 0;
  for (int i = 1; i < cantidad; i++){
    if (vectorBusqueda[i] > vectorBusqueda[posicionMaximo]){
      posicionMaximo = i;
    }
  }
  return posicionMaximo;
}
