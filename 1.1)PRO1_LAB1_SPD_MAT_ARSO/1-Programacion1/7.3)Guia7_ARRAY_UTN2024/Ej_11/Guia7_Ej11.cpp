/*
11 Dada una lista de 10 números, cargarlos en un vector. Luego ingresar un
número e informar el primer índice donde ese número aparece en el vector. En
caso de no aparecer se mostrará el valor índice igual a -1.

*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
int buscarNumero(int vec[], int tamanio, int numero);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

int buscarNumero(int vec[], int tamanio, int numero) {
    for (int i = 0; i < tamanio; i++) {
        if (numero == vec[i]) {
            return i;  // Retornar la posición encontrada
        }
    }
    return -1;  // Si no se encuentra el número, retornar -1
}

int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int numero, posicion;

    cout << "Ingrese " << TAM << " números en el vector: " << endl;
    cargarVector(vecNumeros, TAM);

    cout << "Ingrese un número para buscar en el vector: " << endl;
    cin >> numero;
    posicion = buscarNumero(vecNumeros, TAM, numero);

    if (posicion != -1) {
        cout << "El número " << numero << " se encuentra en el índice " << posicion << endl;
    } else {
        cout << "El número " << numero << " no se encuentra en el vector." << endl;
    }

    return 0;
}
