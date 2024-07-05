/*
7-Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
luego informar el máximo.
Ejemplo A: 5, 10, 20, 8, 25, 13, 35, -8, -5, 20, 0. Se listará Máximo 35.
Ejemplo B: 5, 10, 20, 8, 55, 13, 55, -8, -5, 20, 0. Se listará Máximo 55.
Ejemplo C: -15, -10, -20, -8, -55, -13, -55, -8, -5, -20, 0. Se listará Máximo -5.
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	 int numero, maximo;

	 cout << "Ingrese un número " ;
	 cin >> numero;
	 maximo = numero;

	 while (numero!=0){
		if(numero>maximo){
			maximo = numero;

		}

		cout << "Ingrese otro número (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	cout << "El maximo número ingresado es: " << maximo<< endl;



return 0;
}
