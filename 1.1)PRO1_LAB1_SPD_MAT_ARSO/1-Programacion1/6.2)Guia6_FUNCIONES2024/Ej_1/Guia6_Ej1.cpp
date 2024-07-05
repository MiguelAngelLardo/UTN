/*
1 Hacer una función llamada EsPar que determine si un número es par o no. La
función debe recibir un número entero por valor y devolver true si es par o false
si no lo es. La función no debe mostrar nada por pantalla.
Hacer un programa para ingresar un número y, utilizando EsPar, emita luego un
cartel indicando si el número ingresado es par o no es par.*/

#include <iostream>
using namespace std;

bool EsPar(int n);

int main(){
	setlocale(LC_ALL, "Spanish");
	 int numero;
	 cout << "Ingrese un número ";
	 cin >> numero;

	 if (EsPar(numero)){
		cout << "El número ingresado es par " << endl;

	 }
	 else{
		cout << "El número ingresado es impar " << endl;
	 }


return 0;
}

bool EsPar(int n){

		if(n%2==0){
			return true;
		}
		else{
			return false;
		}
	}
