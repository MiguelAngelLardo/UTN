/*
12 Dada una lista de 10 números, cargarlos en un vector. Luego ingresar un
número e informar la cantidad de veces que ese número aparece en el vector.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
int contarApariciones(int vec[], int tamanio, int numero);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

int contarApariciones(int vec[], int tamanio, int numero) {
    int contador = 0;
    for (int i = 0; i < tamanio; i++) {
        if (vec[i] == numero) {
            contador++;
        }
    }
    return contador;
}

int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int numero, apariciones;

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);

    cout << "Ingrese un número para buscar en el vector: ";
    cin >> numero;

    apariciones = contarApariciones(vecNumeros, TAM, numero);

    cout << "El número " << numero << " aparece " << apariciones << " veces en el vector." << endl;

    return 0;
}
