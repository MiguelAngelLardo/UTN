/*
12
Dada una lista de números que finaliza cuando se ingresa un cero,
informar cual es el primer y segundo número impar ingresado.
Ejemplo 8 4 5 6 -9 5 7 0 se informa 5 y -9

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contador=0, primerImpar, segundoImpar;

	 cout << "Ingrese un número ";
	 cin >> numero;


	 while (numero!=0){
			if(numero%2 !=0){/// averiguar si el numero es impar
				contador++;
				if(contador==1){ /// averiguamos si es el primer impar
				primerImpar = numero;

				} else if (contador == 2){/// averiguamos si es el segundo impar
				segundoImpar = numero;

				}
			}

				cout << "Ingrese otro número (para finalizar ingrese 0) " ;
				cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	if (contador >= 2) {
        cout << "El primer número impar ingresado  es: " << primerImpar<< endl;
		cout << "El segundo número impar ingresado es: " << segundoImpar<< endl;

    } else {
        cout << "No se ingresaron suficientes números impares." << endl;
    }





return 0;
}
