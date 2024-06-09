/*
17 Dada una lista de 10 números, cargarlos en un vector. Luego detectar si en el
vector hay elementos repetidos y generar otro vector con los elementos
repetidos reemplazados por ceros.
Ejemplo Vector 1: [8, 20, 20, -7, 15, 12, 15, -5, 11, 18]
Ejemplo Vector 2: [8, 0, 0, -7, 0, 12, 0, -5, 11, 18]
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
bool hayRepetidos(int vec[], int tamanio);
void remplazarRepetidos (int vec[], int tamanio);
void mostrarVector(int vec[], int tam);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

bool hayRepetidos(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {//recorro el vector elemento por elemento
        for (int j = i + 1; j < tamanio; j++) {//vuelvo a recorrer el vector, comparando
            if (vec[i] == vec[j]) {
                return true;
            }
        }
    }
    return false;
}
void remplazarRepetidos (int vec[], int tamanio){
    for (int i = 0; i < tamanio; i++) {//recorro el vector elemento por elemento
        for (int j = i + 1; j < tamanio; j++) {//vuelvo a recorrer el vector, comparando
            if (vec[i] == vec[j]) { //si hay repetidos los cargo en el vector
                vec[j]=0;
                vec[i]=0;
            }
        }
    }
}
void mostrarVector(int vec[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];


    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);


    if (hayRepetidos(vecNumeros, TAM)) {
        remplazarRepetidos(vecNumeros, TAM);
        mostrarVector(vecNumeros,TAM);
    } else {
        cout << "No hay Repetidos" << endl;
    }

    return 0;
}
