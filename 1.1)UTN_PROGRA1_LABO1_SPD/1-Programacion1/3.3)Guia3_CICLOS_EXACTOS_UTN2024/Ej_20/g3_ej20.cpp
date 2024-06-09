/*20 Se define a un número como primo cuando tiene solamente dos divisores.
Ejemplo A: 2, 7, 11, 13 son números primos, ya que todos tienen solamente dos
divisores.
Ejemplo B: 6 no es primo, pues tiene 4 divisores (1, 2, 3 y 6)
Ejemplo C: 9 no es primo, pues tiene 3 divisores (1, 3 y 9)
Hacer un programa para ingresar un número y luego informar con*/

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
	 cout << endl;
	 if(contador == 2){
		cout << " El número " << numero << " es primo." << endl;
	 }else{
		cout << " El número " << numero << " no es primo." << endl;
	 }

return 0;
}
