/*
22 Hacer un programa que permita ingresar una lista de números positivos,
negativos o cero hasta que se ingrese el 5º número par.
Calcular e informar:
- La cantidad de ternas de números negativos ingresados de manera
consecutiva.
Ejemplo A: 4 -1 -4 -5 10 -3 -5 7 -5 -3 -6 10 → Cantidad de ternas: 2

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contadorPares = 0, cantTernas = 0, cantNegativos = 0;



    while (contadorPares < 5) {
    cout << "Ingrese un número: ";
    cin >> numero;
      if (numero % 2 == 0) { // averiguar si es par
		contadorPares++;
        }

        if (numero < 0) { // averiguar si es negativo
            cantNegativos++;
            if (cantNegativos == 3) { // ver si hay tres números negativos consecutivos
                cantTernas++;
                cantNegativos = 0; // Reiniciar el contador de negativos para la proxima terna
            }
        } else { // Reiniciar el contador de negativos si no es negativo
            cantNegativos = 0;
        }

            }

    cout << "Cantidad de ternas de números negativos ingresados de manera consecutiva: " << cantTernas << endl;

    return 0;
}
