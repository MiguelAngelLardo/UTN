/*16 Hacer un programa para ingresar 5 números, luego informar los 2 mayores
valores ingresados, aclarando cual es el máximo y cuál el que le sigue.
Ejemplo A: 10, 8, 12, 14, 3 el resultado será 14 y 12.
Ejemplo B: 14, 8, 12, 14 ,3 el resultado será 14 y 14.
Ejemplo C: -4, -8, -12, -20, -2 el resultado será -2 y -4
Ejemplo D: 100, 20, 5, - 15, 70, el resultado será 100 y 70.
Se recomienda probar el diagrama que vaya a desarrollar con todos los ejemplos, en
particular el Ejemplo D, en el cual el máximo de la lista aparece en el primer lugar y
que si no se tiene precaución puede llevar a resultados como 100 como máximo y
100 como segundo máximo. ¡ESO ES INCORRECTO! El resultado debe ser 100 y 70.*/

#include <iostream>
using namespace std;


int main(){
	bool bandera2=false;
	int numero, primerMaximo, segundoMaximo;

	for(int i=0; i<5;i++){

		cout << "Ingrese un numero ";
		cin >> numero;
		if (i==0){
			primerMaximo = numero;
		}else if (numero >= primerMaximo){
			segundoMaximo = primerMaximo;
			primerMaximo = numero;
		}else if (!bandera2){
			segundoMaximo = numero;
			bandera2 = true;
		}else if(numero >= segundoMaximo){
			segundoMaximo = numero;

		}
	}

	cout << endl << " El mayor numero ingresado es: " << primerMaximo << endl;
	cout << " El segundo mayor numero ingresado es: " << segundoMaximo << endl;

return 0;
}
