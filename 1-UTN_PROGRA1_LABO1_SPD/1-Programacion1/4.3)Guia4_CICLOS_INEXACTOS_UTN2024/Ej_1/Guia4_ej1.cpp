/*1
Hacer un programa para mostrar por pantalla los números del 1 al 10.
Importante: El programa no tiene ningún ingreso de datos.

*/

#include <iostream>
using namespace std;


  int main(){
	setlocale(LC_ALL, "Spanish");
	 int numero = 1;

	 while (numero <=10){
		cout << numero << endl;

		numero ++;
	 }


	return 0;
  }
