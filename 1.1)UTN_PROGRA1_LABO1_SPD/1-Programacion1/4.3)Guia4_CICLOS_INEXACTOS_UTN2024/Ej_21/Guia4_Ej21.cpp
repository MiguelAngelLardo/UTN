/*
Hacer un programa que permita ingresar una lista de números positivos,
negativos o cero hasta que la diferencia entre el máximo y el mínimo sea mayor
a 10. Calcular e informar:
- La cantidad de números que componen la lista.
Ejemplo A: 1 4 6 -10 → Cantidad de números: 4
Ejemplo B: 100, 104, 106, 100, 100, 105, 200 → Cantidad de números: 7
*/

#include <iostream>
using namespace std;


int main() {
    setlocale(LC_ALL, "Spanish");

    int numero, maximo, minimo, cantidad = 0, diferencia;

    cout << "Ingrese un número: ";
    cin >> numero;
    maximo = minimo = numero;
    diferencia = maximo - minimo;
    cantidad++;

    while (diferencia < 10) {
        cout << "Ingrese un número: ";
        cin >> numero;
        cantidad++;
        if (numero > maximo) {
            maximo = numero;
        } else if (numero < minimo) {
            minimo = numero;
        }
        diferencia = maximo - minimo;
    }

    cout << "Cantidad de números ingresados: " << cantidad << endl;

    return 0;
}
