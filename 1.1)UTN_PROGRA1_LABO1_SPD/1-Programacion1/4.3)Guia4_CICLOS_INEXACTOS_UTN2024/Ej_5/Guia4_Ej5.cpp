/*
5-Hacer un programa para que el usuario ingrese dos números y luego el programa
muestre por pantalla los números entre el menor y el mayor de ambos.
Ejemplo, si el usuario ingresa 3 y 15, se mostrarán los números entre el 3 y el 15;
y si el usuario ingresa 25 y 8, se mostrarán los números entre el 8 y el 25.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero1, numero2,mayor, menor;
	cout << "Ingrese un número " ;
	cin >> numero1;
	cout << "Ingrese otro número ";
	cin >> numero2;

	if(numero1<numero2){
		menor = numero1;
		mayor = numero2;
	}else{
		menor = numero2;
		mayor = numero1;

	}

	while (menor<=mayor){

		cout << menor << endl;
		menor ++;

	}



return 0;
}
