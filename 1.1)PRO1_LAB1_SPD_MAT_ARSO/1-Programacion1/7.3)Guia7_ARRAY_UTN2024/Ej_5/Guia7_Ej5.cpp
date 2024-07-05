/*
5 Leer 10 números y guardarlos en un vector. Determinar e informar cuál es el
menor de los impares y el mayor de los pares. Suponer que habrá al menos un
número par y uno impar
*/


#include <iostream>
using namespace std;


void cargarVector(int vec[], int tamanio);
int determinarMenorImpar(int vec[], int tamanio);
int determinarMayorPar(int vec[], int tamanio);

void cargarVector(int vec[], int tamanio){
    for (int i=0; i<tamanio; i++){
        cin >> vec[i];
    }
}
int determinarMenorImpar(int vec[], int tamanio){
    bool hayImpar = false;
    int menorImpar;
    for (int i = 0; i < tamanio; ++i){
        if (vec[i] % 2 != 0)   // Es impar{
            if (!hayImpar || vec[i] < menorImpar){
                menorImpar = vec[i];
                hayImpar = true;
            }
    }
    return menorImpar;
}
int determinarMayorPar(int vec[], int tamanio){
    bool hayPar = false;
    int mayorPar;
    for (int i = 0; i < tamanio; ++i){
        if (vec[i] % 2 == 0){   // Es par
            if (!hayPar || vec[i] > mayorPar){
                mayorPar = vec[i];
                hayPar = true;
            }
        }
    }
    return mayorPar;
}


int main(){
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int menorImpar,mayorPar;

    cout << "Ingresar " << TAM << " números al vector: " << endl;
    cargarVector(vecNumeros,TAM);

    ///Llamado a las funciones
    menorImpar=determinarMenorImpar(vecNumeros,TAM);
    mayorPar=determinarMayorPar(vecNumeros,TAM);



    // Informar

    cout << "El menor impar es: " << menorImpar << endl;
    cout << "El mayor par es: " << mayorPar << endl;




return 0;
}
