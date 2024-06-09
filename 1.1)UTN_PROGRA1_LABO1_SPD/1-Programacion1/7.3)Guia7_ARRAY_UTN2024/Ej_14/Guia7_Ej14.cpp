/*
14 Dada una lista de 10 números, cargarlos en un vector. Luego contar y listar la
cantidad de números primos que aparecen en el vector.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
bool esPrimo(int numero);
int contarPrimos(int vec[], int tamanio);
void cargarVectorPrimos(int vec[], int vecPrimos[], int tamanio);
void mostrarVector(int vec[], int tam);

void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

bool esPrimo(int numero) {
    int divisores=0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisores++;
        }
    }
    if(divisores==2){
         return true;
    }
    else{
        return false;
    }

}

int contarPrimos(int vec[], int tamanio) {
    int contador = 0;
    for (int i = 0; i < tamanio; i++) {
        if (esPrimo(vec[i])) {//llamo a la funcion y verifico cada uno de los valores del vector
            contador++;// determina el tamanio del vector de numeros primos.
        }
    }
    return contador;
}

void cargarVectorPrimos(int vec[], int vecPrimos[], int tamanio) {
    int j = 0; // Índice para el vector de primos
    for (int i = 0; i < tamanio; i++) {//recorro el vector pincipal
        if (esPrimo(vec[i])) {//determino cuales de los valores son primos
            vecPrimos[j] = vec[i];//cargo los numeros primos en un nuevo vector
            j++;//determina las posiciones del vector de numeros primos
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
    int cantidadPrimos;

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);

    cantidadPrimos = contarPrimos(vecNumeros, TAM); // Cuento los primos para saber el tamaño del vector de primos
    int vecPrimos[cantidadPrimos];
    cargarVectorPrimos(vecNumeros, vecPrimos, TAM); // Cargo el vector de números primos

    cout << "Los números primos son: " << endl;
    mostrarVector(vecPrimos, cantidadPrimos);


    return 0;
}
