/*
16 Dada una lista de 10 números, cargarlos en un vector. Luego detectar si en el
vector hay algún elemento repetido y, en caso de haberlo, indicarlo con un
cartel “Hay Repetidos”.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
bool hayRepetidos(int vec[], int tamanio);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

/*
Esta función usa dos bucles anidados para comparar cada elemento del vector con todos los demás elementos que vienen después de él.
Si encuentra un par de elementos iguales, retorna true, indicando que hay elementos repetidos.
Si termina de comparar todos los elementos sin encontrar repeticiones, retorna false.
*/
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

int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);

    if (hayRepetidos(vecNumeros, TAM)) {
        cout << "Hay Repetidos" << endl;
    } else {
        cout << "No hay Repetidos" << endl;
    }

    return 0;
}
