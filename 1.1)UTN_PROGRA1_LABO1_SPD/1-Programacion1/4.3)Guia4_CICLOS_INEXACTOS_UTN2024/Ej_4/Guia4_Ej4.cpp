/*
4-Hacer un programa para que el usuario ingrese un número positivo y que luego
se muestre por pantalla los números entre el 1 y el número ingresado por el usuario.
Ejemplo. Si el usuario ingresa 15, se mostrarán los números entre el 1 y el 15.
*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	 int numero, contador;

	 cout << "Ingrese un número positivo " ;
	 cin >> numero;
	 contador =1;

	 while (contador <=numero){
		cout << contador << endl;

		contador ++;
	 }


return 0;
}
