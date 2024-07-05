/*6 Hacer un programa para ingresar un N valor que indica la cantidad de números
que componen una lista y luego solicitar se ingresen esos N números. Se pide
informar cuantos son positivos
Ejemplo A: Se ingresa como N el valor 5, y luego se ingresa: 10, -3, 2, 5, 4. Se
listará: Cantidad de Positivos: 4
Ejemplo B: Se ingresa como N el valor 6, y luego se ingresa: -10, -3, -2, 0, -5, -4.
Se listará: Cantidad de Positivos: 0*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int tamanio, numero, contadorPositivo=0;

	cout << " Ingrese el tamanio de la lista " ;
	cin >> tamanio;

	for (int i=0; i<tamanio; i++){

		cout << "Ingrese un numero ";
		cin >> numero;

		if(numero > 0){
			contadorPositivo++;
		}

	}
	cout << "---------------------------------" << endl;

	cout << "Cantidad de positivos " << contadorPositivo << endl;


return 0;
}
