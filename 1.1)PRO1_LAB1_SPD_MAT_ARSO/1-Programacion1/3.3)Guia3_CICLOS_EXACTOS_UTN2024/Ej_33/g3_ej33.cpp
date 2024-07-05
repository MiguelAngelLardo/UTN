/*33 Hacer un programa para ingresar una lista de 13 números. Se pide luego
determinar e informar:
A) La cantidad de ternas de valores positivos consecutivos.
B) La cantidad de ternas de valores negativos consecutivos y ordenados en
forma creciente.
Ejemplo si la lista fuera: 10, 5, 4, 3, -8, -3, -1, 0, 3, 8, -5, -8, -10 entonces el
programa detectará una terna de positivos consecutivos (10, 5, 4) y una terna de
negativos consecutivos ordenados (-8, -3, -1)
Nota: Si el número ingresado es cero, no se lo considera ni negativo ni positivo.
Nota: La terna (-5, -8, -10) no es contabilizada ya que no se encuentra ordenada
crecientemente.*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");
	int numero, contadorPositivo = 0, contadorNegOrd=0, numAnterior, ternaPositiva=0, ternaNegativa=0;
	bool banderaPositivo=false, banderaNegativo=false;

	for (int i=0;i<13;i++){
		 cout << "Ingrese un número ";
		 cin >> numero;

		 if (numero>0){
			if(!banderaPositivo){
				contadorPositivo++;
				banderaPositivo=true;
				numAnterior = numero;
			} else if (numAnterior>0 && numero>0){
				contadorPositivo++;
			}
			contadorNegOrd =0; // si se ingresa un positivo se reinicia el contador de negtivos
			banderaNegativo=false;

		 } else if (numero < 0){
		 	if(!banderaNegativo){
				contadorNegOrd++;
				banderaNegativo=true;
				numAnterior = numero;
			} else if (numAnterior<0 && numero<0 && numero>numAnterior){
				contadorNegOrd++;
			}
			contadorPositivo=0; // si se ingresa un negativo se reinicia el contador de positivos
			banderaPositivo = false;
		 }else{
			contadorPositivo=0; // si se ingresa cero, se reinicia todo
			contadorNegOrd=0;
			banderaPositivo = false;
            banderaNegativo = false;
		 };


		 if(contadorPositivo==3){
			ternaPositiva++;
			contadorPositivo=0;
			banderaPositivo = false;

		 };
		  if(contadorNegOrd==3){
			ternaNegativa++;
			contadorNegOrd=0;
			banderaNegativo = false;
		 };
	}

	cout << "Cantidad de ternas positivas: " << ternaPositiva << endl;
	cout << "Cantidad de ternas negativas y ordenadas " << ternaNegativa << endl;


return 0;
}
