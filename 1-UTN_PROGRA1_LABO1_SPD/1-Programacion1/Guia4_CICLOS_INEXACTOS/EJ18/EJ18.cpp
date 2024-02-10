#include <iostream>
using namespace std;

int main() {
	
	int n, acumulador;
		
	cout << "Ingrese un numero: ";
	cin >> n;
	
	while (n != 0)
	{
		acumulador = 0;
		for (int x = 1; x < n; x ++)
		{
			if (n % x == 0)
				acumulador += x;
		}
	
		if(n == acumulador)
		{
			cout << "El numero " << n << " es perfecto" << endl;
		}else{
			cout << "El numero " << n << " NO es perfecto" << endl;
		}
		
		cout << "Ingrese un numero: ";
		cin >> n;
	}
	
	return 0;
}