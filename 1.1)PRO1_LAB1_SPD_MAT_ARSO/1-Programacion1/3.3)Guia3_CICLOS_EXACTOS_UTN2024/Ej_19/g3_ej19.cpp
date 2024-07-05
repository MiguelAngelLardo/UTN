/* 19 Hacer un programa para ingresar un número y luego informar la cantidad de
divisores de ese número.
Ejemplo A. Si se ingresa 6 se listará: 4 divisores.
Ejemplo B. Si se ingresa 9 se listará: 3 divisores.
Ejemplo C. Si se ingresa 11 se listará: 2 divisores..*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contador=0;
	 cout << "Ingrese un número ";
	 cin >> numero;


	 for (int i=1; i<=numero;i++){
		if (numero%i==0){
			contador ++;
		}
	 }
	 cout << "El número " << numero << " tiene " << contador << " divisores." << endl;

return 0;
}
