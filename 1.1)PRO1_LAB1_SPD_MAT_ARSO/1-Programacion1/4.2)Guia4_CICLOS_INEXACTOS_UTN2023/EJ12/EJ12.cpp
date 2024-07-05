#include <iostream>
using namespace std;

int main() {
	
	int n, contadorImpar = 0, primerImpar, ultimoImpar;
	
	cout << "Ingrese un numero corta con cero: ";
	cin >> n;
	
	while (n != 0){
		if (n % 2 != 9)
		{
			contadorImpar ++;
			if(contadorImpar == 1)
			{
				primerImpar = n;
			}else
			{
				ultimoImpar = n;
			}
		}
		
		cout << "Ingrese un numero corta con cero: ";
		cin >> n;		
	}
	
	cout << "El primer impar es: " << primerImpar << endl;
	cout << "El ultimo impar es: " << ultimoImpar << endl;
	 
	return 0;
}