/*
7 Hacer un programa para llenar un vector de 10 elementos con el formato: 1, 0,
1, 0, 1, 0, 1, 0, 1, 0. Luego mostrar los números por pantalla. EL USUARIO NO
INGRESA NINGÚN VALOR EN ESTE PROGRAMA.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
void mostrarVector(int vec[], int tamanio);

void cargarVector(int vec[], int tamanio){
  for (int i=1; i<=tamanio;i++){
    if(i%2==0){
      vec[i-1]=0;
    }
    else{
      vec[i-1]=1;
    }
  }
}


void mostrarVector(int vec[], int tamanio){
    for (int i=0;i<tamanio;i++){
      if(i<9){
        cout << vec[i] << ", ";
      }
      else{
        cout << vec[i] << ".";
      }
    }
}
int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];

    cargarVector(vecNumeros, TAM);

    cout << endl << "Contenido del vector" << endl;
    mostrarVector(vecNumeros, TAM);
    cout << endl;


return 0;
}
