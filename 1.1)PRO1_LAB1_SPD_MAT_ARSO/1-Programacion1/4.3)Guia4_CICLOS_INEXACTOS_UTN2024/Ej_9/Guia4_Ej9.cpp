/*
9-Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
luego informar el máximo de los pares.
Ejemplo A: 2, 10, 20, 8, 25, 13, 36, -8, -5, 20, 0. Se listará Máximo 36.
Ejemplo B: 5, -13, 23, 81, -55, -13, 55, 4, 15, -20, 0. Se listará Máximo 4.
Ejemplo C: -5, -13, -20, -8, -55, -13, -55, -14, -15, -20, 0. Se listará Máximo -8.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, maximo;
	bool bandera;

	 cout << "Ingrese un número " ;
	 cin >> numero;
	 bandera = false;


	 while (numero!=0){
		if(numero%2==0){
			if(!bandera || numero>maximo){
				maximo = numero;
				bandera = true;
			}
		}

		cout << "Ingrese otro número (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	cout << "El maximo número par ingresado es: " << maximo<< endl;

return 0;
}
