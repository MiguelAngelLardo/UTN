/*
11
Hacer un programa para ingresar una lista de números que finaliza cuando se ingresa un cero,
informar el máximo de los negativos y el mínimo de los positivos.
Ejemplo: 5 8 12 2 -10 15 -20 8 -3 24 0.
Máximo Negativo: -3.
Mínimo Positivo: 2.
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
		int numero, maximoNegativo, minimoPositivo;
		bool negativo=false, positivo=false;

	 cout << "Ingrese un número " ;
	 cin >> numero;


	 while (numero!=0){
		if(numero>0){
			if(!positivo || numero < minimoPositivo){
			minimoPositivo = numero;
			positivo = true;
			}
		}else if(numero <0){
			if(!negativo || numero > maximoNegativo){
			maximoNegativo = numero;
			negativo = true;
			}
		}

		cout << "Ingrese otro número (para finalizar ingrese 0) " ;
		cin >> numero;
	 }

	cout << "---------------------------------"<< endl;

    if (positivo)
        cout << "El mínimo número positivo ingresado es: " << minimoPositivo << endl;
    else
        cout << "No se ingresaron números positivos." << endl;

    if (negativo)
        cout << "El máximo número negativo ingresado es: " << maximoNegativo << endl;
    else
        cout << "No se ingresaron números negativos." << endl;



return 0;
}
