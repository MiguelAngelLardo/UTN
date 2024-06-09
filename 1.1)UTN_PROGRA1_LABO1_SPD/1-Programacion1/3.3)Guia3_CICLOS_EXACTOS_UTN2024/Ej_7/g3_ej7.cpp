/*7 Hacer un programa para ingresar una lista de 10 números, luego informar
cuántos son positivos, cuántos son negativos, y cuántos iguales a cero.
Para resolver este ejercicio sugerimos resolver antes el TP2 EJ 11.*/

#include <iostream>
using namespace std;


int main(){

	setlocale(LC_ALL, "Spanish");

	int numero, contadorPositivo=0, contadorNegativo=0, contadorCero=0;

	for (int i=0; i<10; i++){

		cout << "Ingrese un numero ";
		cin >> numero;

		if(numero > 0){
			contadorPositivo++;
		}else if (numero < 0){
			contadorNegativo++;
		}else{
			contadorCero++;

		}

	}
	cout << "---------------------------------" << endl;

	cout << "Cantidad de positivos " << contadorPositivo << endl;
	cout << "Cantidad de Negativos " << contadorNegativo << endl;
	cout << "Cantidad de Ceros     " << contadorCero << endl;

return 0;
}
