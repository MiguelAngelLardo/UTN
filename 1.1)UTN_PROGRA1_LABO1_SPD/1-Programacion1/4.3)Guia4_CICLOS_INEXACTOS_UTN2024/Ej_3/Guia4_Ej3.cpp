/*
3
Hacer un programa para mostrar por pantalla los números del 20 al 1 en orden decreciente.
Importante: El programa no tiene ningún ingreso de datos.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	 int numero = 20;

	 while (numero >=1){
		cout << numero << endl;

		numero --;
	 }

return 0;
}
