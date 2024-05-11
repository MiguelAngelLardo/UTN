#include <iostream>
using namespace std;

int main() {
	
	int n, maximo;
	bool bandera = false, positivo1 = false, consecutivoPositivo = false;	
	
	cout << "Ingrese un numero: " ;
	cin >> n;
	
	if (!bandera)
	{
		maximo = n;
		bandera = true;
		
		if (n > 0)
		{
			positivo1 = true;
		}
	}
	
	do{
		if ( n > maximo)
			maximo = n;
		cout << "Ingrese un numero: " ;
		cin >> n;
		
		
		if (n <= 0)
		{	
			positivo1 = false;
		}
		else
		{
			if (n > 0 && positivo1)
			{
				consecutivoPositivo = true;
			}
			else
			{
				if (n > 0 && !consecutivoPositivo)
				{
					positivo1 = true;
				}
			}
		}

		
	} while(!consecutivoPositivo);
	
	cout << "El valor maximo es: " << maximo;
	
	return 0;
}