/*
4 Leer 10 números y guardarlos en un vector. Determinar e informar cuál es el
valor máximo absoluto del vector. Por ejemplo 20, -43 y 5, el máximo absoluto
es -43.

*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
int determinarMaximoAbsoltuto(int vec[], int tamanio);

void cargarVector(int vec[], int tamanio){
    for (int i=0; i<tamanio; i++){
        cin >> vec[i];
    }
}

int determinarMaximoAbsoltuto(int vec[], int tamanio){
    int maxAbsoluto, valorActual;
    maxAbsoluto = vec[0];
    for (int i = 1; i <tamanio; i++) {
        valorActual = vec[i];
        // Calcular el valor absoluto del elemento actual
        if (valorActual < 0) {
            valorActual = -valorActual;
        }

        // Comparar y actualizar el valor máximo absoluto
        if (valorActual> maxAbsoluto) {
            maxAbsoluto = valorActual;
        }

    }
    return maxAbsoluto;
}

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int maximoAbsoluto;

    cout << "Ingresar " << TAM << " números al vector: " << endl;
    cargarVector(vecNumeros,TAM);

    maximoAbsoluto = determinarMaximoAbsoltuto(vecNumeros,TAM);
    // Informar el valor máximo absoluto
    cout << "El valor máximo absoluto del vector es: " << maximoAbsoluto << endl;

    return 0;
}
