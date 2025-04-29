#include <cstring> //#include <string.h>
#include <iostream>
using namespace std;
#include <cstdlib>

const int F = 5;
const int C = 10;

void cargarLista(char mat[F][C], int tam){
  int i;
  for(i=0; i<tam; i++){
    cout << "INGRESAR PALABRA: ";
    cin >> mat[i];
  }
  return;
}
void mostrarLista(char mat[F][C], int tam){
  int i;
  for(i=0; i<tam; i++){
    cout << mat[i] << endl;
  }
}

int main(){
  char nombre[F][C];
  char cadena[C];
  cargarLista(nombre, F);
  mostrarLista(nombre, F);
  strcpy(cadena, nombre[1]);
  cout << endl << "SEGUNDA PALABRA: " << cadena;

  return 0;
}
