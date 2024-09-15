/*
7 Hacer un programa para llenar un vector de 10 elementos con el formato: 1, 0,
1, 0, 1, 0, 1, 0, 1, 0. Luego mostrar los numeros por pantalla. EL USUARIO NO
INGRESA NINGUN VALOR EN ESTE PROGRAMA.
*/


#include <iostream>
using namespace std;

const int TAM = 10;

void cargarVector(int vec[]);
void mostrarVector(int vec[]);

int main(){
    setlocale(LC_ALL, "Spanish");
    int vecNumeros[TAM];

    cargarVector(vecNumeros);

    cout << endl << "Contenido del vector" << endl;
    mostrarVector(vecNumeros);
    cout << endl;

return 0;
}

void cargarVector(int vec[]){
  for (int i = 1; i <= TAM;i++){
    if(i % 2 == 0){
      vec[i-1]=0;
    }
    else{
      vec[i-1]=1;
    }
  }
}


void mostrarVector(int vec[]){
    for (int i = 0 ;i < TAM; i++){
      if(i < 9){// 0 1 2 3 4 5 6 7 8 9 
        cout << vec[i] << ", ";
      }
      else{
        cout << vec[i] << ".";
      }
    }
}