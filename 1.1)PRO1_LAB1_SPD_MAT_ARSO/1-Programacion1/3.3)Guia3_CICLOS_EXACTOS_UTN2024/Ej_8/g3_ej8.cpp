/*8 Hacer un programa para ingresar una lista de 10 números, luego informar el
porcentaje de positivos, negativos, y ceros.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");


		int numero, contadorPositivo=0, contadorNegativo=0, contadorCero=0;
		float porcentajePositivo, porcentajeNegativo,porcentajeCero;

	for (int i=0; i<10; i++){

		cout << "Ingrese un numero ";
		cin >> numero;

		if(numero > 0){
			contadorPositivo++;
		}else if (numero < 0){
			contadorNegativo++;
		}else{
			contadorCero++;
		}

	}
	cout << "---------------------------------" << endl;
	porcentajePositivo = (float) (contadorPositivo*100)/10;
	porcentajeNegativo = (float) (contadorNegativo*100)/10;
	porcentajeCero = (float) (contadorCero*100)/10;


	cout << "Porcentaje de positivos " << porcentajePositivo << " %" << endl;
	cout << "Porcentaje de Negativos " << porcentajeNegativo << " %" << endl;
	cout << "Porcentaje de Ceros     " << porcentajeCero << " %" << endl;

return 0;
}
