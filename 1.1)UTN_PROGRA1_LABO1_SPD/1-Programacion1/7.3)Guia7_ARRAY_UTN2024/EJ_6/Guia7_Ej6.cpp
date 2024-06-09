/*
Leer 10 números y guardarlos en un vector. Determinar e informar los dos
últimos números pares en el vector y sus respectivas posiciones en el mismo.
Suponer que habrá al menos dos números pares.
*/


#include <iostream>
using namespace std;
void cargarVector(int vec[], int tamanio);
void informarParesYPosicion(int vec[], int tamanio);


void cargarVector(int vec[], int tamanio){
    for (int i=0; i<tamanio; i++){
        cin >> vec[i];
    }
}
void informarParesYPosicion(int vec[], int tamanio){
    int ultimoPar=0, anteUltimoPar=0;
    int posUltimo, posAnteUltimo;

    for (int i=0; i<tamanio;i++){
        if(vec[i]%2==0){
            if(ultimoPar==0){
                ultimoPar=vec[i];
                posUltimo=i+1;
            }
            else{
                anteUltimoPar=ultimoPar;
                ultimoPar=vec[i];
                posAnteUltimo=posUltimo;
                posUltimo=i+1;
            }

        }

    }
    cout << "Ante último número par " << anteUltimoPar << ", posición # " << posAnteUltimo<< endl,
    cout << "Último número par " << ultimoPar << ", posición # " << posUltimo<< endl;



}

int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int menorImpar,mayorPar;

    cout << "Ingresar " << TAM << " números al vector: " << endl;
    cargarVector(vecNumeros,TAM);
    informarParesYPosicion(vecNumeros,TAM);


return 0;
}
