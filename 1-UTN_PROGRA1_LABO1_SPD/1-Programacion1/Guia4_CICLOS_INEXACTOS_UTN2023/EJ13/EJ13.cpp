#include <iostream>
using namespace std;

int main() {
	
	int n, minimo, primerNumero = 0, contadorCreciente = 0, contadorWhile = 0;
	
  cout << "Ingrese un numero: ";
	cin >> n;
	
	while (n != 0)
	{
		contadorWhile ++;
		
		if (primerNumero == 0)
		{
			minimo = n;
			primerNumero ++;
			contadorCreciente ++;
			
			
		}
		else
		{
			if (n >= minimo)
			{
				contadorCreciente ++;
			}
			
		}

		cout << "Ingrese un numero: ";
		cin >> n;
	}
	
	if (contadorCreciente == contadorWhile)
	{
		cout << "Ordenado";
	}
	else
	{
		cout << "No ordenado"; 
	}

	 
	return 0;
}