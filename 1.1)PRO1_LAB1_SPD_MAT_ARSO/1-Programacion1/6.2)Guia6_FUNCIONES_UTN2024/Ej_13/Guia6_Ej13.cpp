/*
13 Escribir una función llamada calcularPotencia para que, dados dos números
enteros, calcule y devuelva la potencia del primero a la del segundo. Tener en
cuenta las siguientes posibilidades:
calcularPotencia(2, 3) → 8
calcularPotencia(2, 0) → 1
calcularPotencia(2, -3) → 0,125*/

#include <iostream>
using namespace std;

float CalcularPotencia(int n1, int n2);

int main(){
setlocale(LC_ALL, "Spanish");

	int n1, n2;

	cout << "Ingrese un número ";
	cin >> n1;
	cout << "Ingrese otro número ";
	cin >> n2;

	cout << endl << n1 << " elevado a " << n2 << " es igual a = " << CalcularPotencia(n1,n2) << endl;

return 0;
}

float CalcularPotencia (int n1, int n2){
	float resultado= 1.0;

	 if(n2==0){
		resultado == 1.0;
	 }
	 else if(n2>0)
		{
		for(int i=0; i<n2;i++){
			resultado *= n1;
		}
	 }
	 else{
		n2 = n2 *(-1);
		for(int i=0; i<n2;i++){
			resultado *= (1.0/n1);
		}
	 }
	return resultado;
}
