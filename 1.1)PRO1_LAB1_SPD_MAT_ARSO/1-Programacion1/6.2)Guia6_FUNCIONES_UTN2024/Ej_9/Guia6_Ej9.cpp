/*
9 Escribir una función que reciba un número y retorne 1 si el número recibido es
perfecto y 0 si no es perfecto.
Hacer un programa para que, dada una lista de números que finaliza con cero,
informe cuántos de ellos eran perfectos. Utilizar la función solicitada.
*/

#include <iostream>
using namespace std;

int EsPerfecto (int numero);

int main(){
setlocale(LC_ALL, "Spanish");

	int numero, contadorPerfecto=0;
	cout << "Ingrese un número ";
	cin >> numero;

	while(numero!=0){
		if (EsPerfecto(numero)==1){
			contadorPerfecto++;
		}
		cout << "Ingrese un número ";
		cin >> numero;
	}
	cout << "Se ingresaron " << contadorPerfecto << " números perfectos";

return 0;
}


int EsPerfecto(int numero){
	int sumaDivisores=0;

	for(int i=1; i<numero; i++){

		if(numero%i==0){
			sumaDivisores += i;
		}
	}
	if(sumaDivisores==numero){
		return 1;
	}
	else{
		return 0;
	}

}
