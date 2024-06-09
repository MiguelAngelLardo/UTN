/*12 Hacer un programa para ingresar una lista de 10 números e informar el máximo
de los negativos y el mínimo de los positivos.
Ejemplo: 5, 8, 12, 2, -10, 15, -20, 8, -3, 24. Máximo Negativo -3. Mínimo Positivo 2.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");


	int numero, maximoNeg, minimoPos;
	bool banderaPos=false, banderaNeg=false;

	for (int i=1;i<=10;i++){
		 cout << "Ingrese un número ";
		 cin >> numero;

		 if(numero>0){
			if(!banderaPos){
				minimoPos = numero;
				banderaPos = true;

			}else if (numero < minimoPos){
				minimoPos = numero;
			}

		 } else if (numero < 0){
			if(!banderaNeg){
				maximoNeg = numero;
				banderaNeg = true;

			}else if (numero > maximoNeg){
				maximoNeg = numero;
			}


		 }

	}

	cout << "--------------------------------" << endl;
	cout << " El número máximo negativo ingresado es " << maximoNeg << endl;
	cout << " El número mímimo positivo  ingresado es " << minimoPos << endl;;


return 0;
}
