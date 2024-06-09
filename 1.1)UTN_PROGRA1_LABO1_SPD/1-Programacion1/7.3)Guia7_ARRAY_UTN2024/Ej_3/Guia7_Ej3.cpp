/*
3 Leer 10 números y guardarlos en un vector. Determinar e informar cuál es el
valor máximo y su posición dentro del vector.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
void mostrarMaximoPosicion(int vec[], int tamanio);

void cargarVector(int vec[], int tamanio){
    for (int i=0; i<tamanio; i++){
        cin >> vec[i];
    }

}
void mostrarMaximoPosicion(int vec[], int tamanio){
    int maximo,posicion;

    maximo=vec[0];///determinar el primer valor como maximo
    posicion = 1;

     for (int i=0; i<tamanio;i++){ /// vector para comparar maximos
         if(vec[i]>=maximo){
            maximo=vec[i];///
            posicion = i+1;
         }
     }

     cout << "Valor máximo: " << maximo<< endl;
     cout << "Posición #" << posicion << endl;
}


int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];

    cout << "Ingresar " << TAM << " números al vector: " << endl;
    cargarVector(vecNumeros,TAM),
    mostrarMaximoPosicion(vecNumeros,TAM);





return 0;
}
