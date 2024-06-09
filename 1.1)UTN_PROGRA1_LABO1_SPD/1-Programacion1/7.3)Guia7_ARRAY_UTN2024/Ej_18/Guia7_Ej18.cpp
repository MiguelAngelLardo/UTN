/*
18 Dada una lista de 10 números, cargarlos en un vector. Luego ingresar dos
números a y b menores a 10. Determinar e informar cuál es el valor máximo en
el vector considerando los elementos que están entre las posiciones a y b.
*/


#include <iostream>
using namespace std;

void cargarVector(int vec[], int tamanio);
int maxEntrePosiciones(int vec[], int a, int b);


void cargarVector(int vec[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cin >> vec[i];
    }
}

int maxEntrePosiciones(int vec[], int a, int b) {
    int maximo = vec[a]; // Inicializamos el máximo con el primer valor en la posición a
    for (int i = a + 1; i <= b; i++) { // bucle for que tiene como inicio y fin los valores pedidos
        if (vec[i] > maximo) {
            maximo = vec[i]; // Actualizamos el máximo si encontramos un valor mayor
        }
    }
    return maximo;
}


int main() {
    setlocale(LC_ALL, "Spanish");
    const int TAM = 10;
    int vecNumeros[TAM];
    int a, b;

    cout << "Ingrese " << TAM << " números en el vector:" << endl;
    cargarVector(vecNumeros, TAM);

    cout << "Ingrese dos índices a y b menores a 10 (a debe ser menor o igual a b):" << endl;
    cin >> a >> b;


        int maximo = maxEntrePosiciones(vecNumeros, a, b);
        cout << "El valor máximo entre las posiciones dadas es: " << maximo << endl;
    return 0;
}
