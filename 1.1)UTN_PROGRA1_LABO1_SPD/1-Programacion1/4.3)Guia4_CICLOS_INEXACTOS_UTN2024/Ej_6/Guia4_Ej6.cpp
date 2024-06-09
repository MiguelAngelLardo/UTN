/*
6 Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero, luego informar cuántos son positivos y cuántos son negativos.
Ejemplo: 4, -3, 8, -5, 18, 20, 0. Se listará Positivos: 4 Negativos: 2.
Para resolver este ejercicio sugerimos resolver antes el TP3 EJ 7.
*/

#include <iostream>
using namespace std;


int main(){

	setlocale(LC_ALL, "Spanish");

	 int numero, contadorPositivo = 0, contadorNegativo=0;

	 cout << "Ingrese un número " ;
	 cin >> numero;

	 while (numero!=0){
		if(numero>0){
			contadorPositivo ++;

		}else{
			contadorNegativo++;
		}
		cout << "Ingrese otro número (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	cout << "La cantidad de números poisitivos ingresados es: " << contadorPositivo << endl;
	cout << "La cantidad de números poisitivos negativos  es: " << contadorNegativo << endl;


return 0;
}
