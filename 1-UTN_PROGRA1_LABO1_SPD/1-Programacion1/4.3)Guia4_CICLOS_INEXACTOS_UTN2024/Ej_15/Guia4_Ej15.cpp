/*
15-Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
informar los 2 mayores valores ingresados, aclarando cual es el máximo y cuál el que le sigue.
Ejemplo: 10, 8, 12, 14, 3, 0 el resultado será 14 y 12.
Ejemplo: 14, 8, 12, 14, 3, 0 el resultado será 14 y 14.
Ejemplo: -4, -8, -12, -20, -2, 0 el resultado será -2 y -4

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero,primerMaximo, segundoMaximo, contador;

	 cout << "Ingrese un número " ;
	 cin >> numero;
	 primerMaximo = numero;
	 segundoMaximo = numero;

	 while (numero!=0){
		if(numero>primerMaximo){
			segundoMaximo=primerMaximo;
			primerMaximo=numero;
		}else if(numero > segundoMaximo){
			segundoMaximo=numero;
		}

		cout << "Ingrese otro número (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	cout << "El maximo número ingresado  es: " << primerMaximo << endl;
	cout << "El segundo máximo ingresado es: " << segundoMaximo<< endl;

return 0;
}
