/*4 Hacer un programa para que el usuario ingrese un número positivo y luego se
muestren por pantalla los números entre el 1 y el número ingresado por el
usuario.
Ejemplo. Si el usuario ingresa 15, se mostrarán los números entre el 1 y el 15.*/

#include <iostream>
using namespace std;


int main(){

	setlocale(LC_ALL, "Spanish");

	int numero;

	cout << "Ingrese un número ";
	cin >> numero;

	for(int i=1; i<=numero; i++){
		 cout << i << endl;

	}

return 0;
}
