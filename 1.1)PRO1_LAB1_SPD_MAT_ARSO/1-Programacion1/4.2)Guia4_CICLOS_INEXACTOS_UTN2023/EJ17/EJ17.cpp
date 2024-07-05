#include <iostream>
using namespace std;

int main() {
	
	int n, primo, contador ;
	
	cout << "Ingrese un numero: ";
	cin >> n;
	
	while (n != 0)
	{
		contador = 0;
		for (int x = 1; x <= n; x ++)
		{
			if (n % x == 0)
				contador ++;
		}
	
		if(contador == 2)
		{
			primo = n;
			cout << "El numero primo es: " << primo << endl;
		}else{
			cout << "No hay numero primo" << endl;
		}
		
		cout << "Ingrese un numero: ";
		cin >> n;
	}
	
	return 0;
}