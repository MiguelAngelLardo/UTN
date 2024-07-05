/*
Hacer un programa para ingresar los valores de los pesos de distintas
encomiendas que se deben enviar a distintos clientes y que finaliza cuando se
ingresa un peso negativo. Se deben agrupar las encomiendas en camiones que
pueden transportar hasta 200 kilos en total.
Ejemplo: 10 20 140 70 100 40 10 50 80 90 30 40 50 -10
Camión: 1 2 3 4 5
Se pide determinar e informar:
a) El número de cada camión y peso total de encomiendas. Camión 1: 170 kg,
Camión 2: 170 kg, etc.
b) El número de camión que transporta mayor cantidad de encomiendas. En el
ejemplo anterior sería el Camión 3 con 4 encomiendas.

*/

#include <iostream>
using namespace std;


int main(){
	setlocale(LC_ALL, "Spanish");

	int peso,pesoAnterior;
	int camion=0;
	int camiomMayor;
	int encomiendaMayor=0;
	cout<< "Ingrese el peso de la encomienda ";
	cin >> peso;

	while(peso>0){
		pesoAnterior=peso;
		int pesoTotal=0;
		int encomiendas=0;
		camion++;
		while( (peso+pesoTotal)<= 200 && peso >0){
			encomiendas++;
			pesoTotal+=peso;


			cout<< "Ingrese el peso de la encomienda ";
			cin >> peso;
		}
		//mostrar puntoa
		cout << " Camión: " << camion << endl;
		cout << " Peso total de encomiendas "<< pesoTotal << " kg" << endl;
		//calculo punto b
		if(encomiendas>encomiendaMayor){
			encomiendaMayor=encomiendas;
			camiomMayor=camion;
		}
	}
	//mostrar punto b
	cout << " El camión " << camiomMayor << " transporta la mayor cantidad de encomiendas" << endl;
return 0;
}
