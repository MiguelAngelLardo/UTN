/*17 Hacer un programa para ingresar por teclado cuatro números. Si los valores que
se ingresaran están ordenados en forma creciente, emitir el mensaje “Conjunto
Ordenado”, caso contrario emitir el mensaje: “Conjunto Desordenado”.
Ejemplo A: si los números que se ingresan son 8, 10, 12 y 14, entonces están
ordenados.
Ejemplo B: si los números que se ingresan son 8, 12, 12 y 14, entonces están
ordenados.
Ejemplo C: si los números que se ingresan son 10, 8, 12 y 14, entonces están
desordenados.*/

#include <iostream>
using namespace std;


int main(){
	int num1, num2, num3, num4;

	cout << "Ingrese el primer numero" << endl;
	cin >> num1;
	cout << "Ingrese el segundo numero" << endl;
	cin >> num2;
	cout << "Ingrese el tercer numero" << endl;
	cin >> num3;
	cout << "Ingrese el cuarto numero" << endl;
	cin >> num4;

	if(num1<=num2 && num2<=num3 && num3<= num4){

		cout << "Conjunto Ordenado" << endl;
	}else{
		cout << "Conjunto Desordenado" << endl;

	}

return 0;
}
