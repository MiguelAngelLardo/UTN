/*
12
Dada una lista de n�meros que finaliza cuando se ingresa un cero,
informar cual es el primer y segundo n�mero impar ingresado.
Ejemplo 8 4 5 6 -9 5 7 0 se informa 5 y -9

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contador=0, primerImpar, segundoImpar;

	 cout << "Ingrese un n�mero ";
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

				cout << "Ingrese otro n�mero (para finalizar ingrese 0) " ;
				cin >> numero;
	 }

	cout << "---------------------------------"<< endl;
	if (contador >= 2) {
        cout << "El primer n�mero impar ingresado  es: " << primerImpar<< endl;
		cout << "El segundo n�mero impar ingresado es: " << segundoImpar<< endl;

    } else {
        cout << "No se ingresaron suficientes n�meros impares." << endl;
    }





return 0;
}