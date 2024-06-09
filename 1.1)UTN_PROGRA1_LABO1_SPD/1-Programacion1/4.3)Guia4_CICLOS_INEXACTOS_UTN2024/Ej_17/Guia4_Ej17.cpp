/*
17 Hacer un programa para ingresar una lista de números que finaliza cuando se
ingresan dos números positivos consecutivos, y luego informar el máximo.
Cuando se ingresa el segundo número positivo consecutivo el mismo debe ser
descartado.
Ejemplo A: 5 -10 20 -8 0 13 -35 -8 15 10. Se listará Máximo 20.
En este caso, el segundo número positivo consecutivo, el 10, no se analiza, sólo
sirve para finalizar el ingreso.
Ejemplo B: 5 -10 20 -20 0 55 -13 45 -8 -5 12 120. Se listará Máximo 55.
En este caso, el segundo número positivo consecutivo, el 120, no se analiza,
sólo sirve para finalizar el ingreso.
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, numeroAnterior, maximo, contador=0;


  cout << "Ingresa un numero: ";
	cin >> numero;
	maximo = numero;
	if(numero > 0){
		contador++;
	}


	do{

    cout << "Ingresa un numero: ";
		cin >> numero;
		if(numero > 0){
			contador++;
		}else{
			contador=0;
		}

		if ( numero > maximo && contador!=2)
			maximo = numero;


	} while(contador!=2);

	cout << "El máximo número ingresado es: " << maximo;

return 0;
}
