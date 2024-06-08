/*30 Dada una lista de 7 números todos distintos entre sí determinar e informar con
un cartel aclaratorio si los números primos ingresados en la misma están
ordenados de menor a mayor. Los números primos pueden no ser consecutivos,
pero sí estar ordenados.
Ejemplo A: 4, 5, 7, 12, 13, 19, 20. Se emite un cartel que diga “Ordenados” ya que
los números primos están ordenados: 5, 7, 13, 19.
Ejemplo B: 4, 10, 3, 5, 11, 7, 14. Se emite un cartel que diga “Desordenados” ya
que los números primos no están ordenados: 3, 5, 11, 7.*/

#include <iostream>
using namespace std;


int main(){
	 int numero, primoMenor, contadorDivisores=0, contadorPrimo=0, contadorOrdenado=0;
	 bool primerPrimo=false;

	 for (int i=1; i<=7; i++){
		cout << "Ingrese un número ";
		cin >> numero;
		contadorDivisores=0;
		for(int j=1;j<=numero;j++){
			if(numero%j==0){
				contadorDivisores++;
			}
		};

		if(contadorDivisores == 2){
			contadorPrimo ++;
			if(!primerPrimo){
				primoMenor = numero;
				primerPrimo = true;
				contadorOrdenado++;
			}else if(numero>primoMenor){
				primoMenor = numero;
				contadorOrdenado++;
			}else{
				contadorOrdenado = 0;
			}
		}

	 };

	 if(contadorPrimo == contadorOrdenado){
			cout << "Los números primos ingresados están ordenado de menor a mayor. " << endl;
		}else{
			cout << "Los números primos ingresados  NO están ordenado de menor a mayor. " << endl;

		}


return 0;
}
