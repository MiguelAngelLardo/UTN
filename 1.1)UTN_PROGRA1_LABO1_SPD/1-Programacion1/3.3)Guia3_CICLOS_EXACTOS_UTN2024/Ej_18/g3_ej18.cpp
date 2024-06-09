/*18 Hacer un programa para ingresar un número y luego informar todos los
divisores pares de ese número.
Ejemplo A. Si se ingresa 6 se listará: 2 y 6. Ejemplo B. Si se ingresa 8 se listará:
2, 4 y 8. Ejemplo C. Si se ingresa 11 no se listará nada.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contador=0;
	 cout << "Ingrese un número ";
	 cin >> numero;

	 cout << "Los divisores pares de " << numero << " son: " << endl;

	 for (int i=1; i<=numero;i++){
		if (numero%i==0){
			if(i%2==0){
				contador++;
				if(i==numero){
					cout << i << endl;
				}else{
					cout << i << ", ";
				}
			}
		}
	 }
	 if(contador==0){
		cout << "El número " << numero << " no tiene divisores pares." << endl;
	 }
return 0;
}
