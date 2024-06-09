/*
20 Dada una lista de números que finaliza cuando se ingresa un cero, informar el
primer número par ingresado y su ubicación en la lista y el último de los
números primos y su ubicación en la lista.
Ejemplo A: 7 4 5 6 9 13 10 0 se informa Primer número par: 4 ubicación 2.
Último primo: 13 ubicación 6.
Ejemplo B: 9 5 21 9 13 15 6 se informa Primer número par: 6 ubicación 7.
Último primo: 13 ubicación 5.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int numero, primerPar, ultimoPrimo, posicion=0, posicionPar=0, posicionPrimo=0;

	cout << "Ingrese un número ";
	cin >> numero;


	while(numero !=0){
		posicion++;
		if (numero%2==0  && posicionPar==0){ /// averiguar el primer par
			primerPar = numero;
			posicionPar = posicion;
		}

		int divisor=1, contador=0; /// averiguar el ultimo primo
		while( divisor <= numero){
		if(numero%divisor ==0){
			contador++;
		}

		divisor++;
		}

		if(contador ==2){
			ultimoPrimo=numero;
			posicionPrimo=posicion;
		}
		cout << "Ingrese un número ";
		cin >> numero;
	}

	if(posicionPar!=0){
		cout << "El primer número par ingresado es " << primerPar << endl;
		cout << " Su posicion es # " << posicionPar << endl;
	}
	else{
		cout << "No se ingresaron números pares" << endl;
	}

	if (posicionPrimo!=0){
		cout << "El útimo número primo ingresado es " << ultimoPrimo << endl;
		cout << " Su posicion es # " << posicionPrimo << endl;

	}
	else{
		cout << "No se ingresaron números primos" << endl;

	}



return 0;
}
