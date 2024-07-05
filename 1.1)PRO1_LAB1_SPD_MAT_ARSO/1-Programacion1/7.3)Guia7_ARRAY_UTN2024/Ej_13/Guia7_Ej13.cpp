/*
13 Dada una lista de 10 números, cargarlos en un vector. Luego contar y listar la
cantidad de números pares que aparecen en el vector.
*/

#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
int contarPares(int vec[], int tamanio);
void cargarVectorPares(int vec[], int vecPares[], int tamanio);
void mostrarVector(int vecPares[], int tam);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

int contarPares(int vec[], int tamanio) {
    int contador = 0;
    for (int i = 0; i < tamanio; i++) {
        if (vec[i]%2==0) {
            contador++;
        }
    }
    return contador;
}
void cargarVectorPares(int vec[], int vecPares[], int tamanio){
    int j = 0; // Índice para el vector de pares
    for (int i = 0; i < tamanio; i++) { // Recorro el vector principal
        if (vec[i] % 2 == 0) { // Verifico si el valor en la posición i es par
            vecPares[j] = vec[i]; // Ese valor lo asigno al vector de pares
            j++; // Incremento el índice del vector de pares
        }
    }
}
void mostrarVector(int vecPares[], int tam){
    for(int i=0;i<tam;i++){
        cout << vecPares[i] << " ";
    }
}
int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int cantidadPares;

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);


    cantidadPares = contarPares(vecNumeros, TAM);//cuento los pares para saber el tamanio del vector de pares
    int vecPares[cantidadPares];
    cargarVectorPares(vecNumeros,vecPares,TAM);//cargo el vector de numeros pares

    cout << " Los números pares son : " << endl;
    mostrarVector(vecPares,cantidadPares);



    return 0;
}
