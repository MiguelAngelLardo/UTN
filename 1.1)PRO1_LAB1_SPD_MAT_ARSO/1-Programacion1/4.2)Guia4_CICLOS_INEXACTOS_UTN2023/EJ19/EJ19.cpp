#include <iostream>
using namespace std;

int main() {
	
	int n, primerPar, ubicacion = 0, ubicacionPar, contador, ultimoPrimo, ubicacionPrimo; 
	bool banderaPar = false;
		
	cout << " Ingrese un numero: ";
	cin >> n; 
	ubicacion ++;
	
	while (n != 0)
	{
		contador = 0;
		if (n % 2 == 0 && !banderaPar){
			primerPar = n;
			ubicacionPar = ubicacion;
			banderaPar = true;			
		}
		
		for (int x = 1;x <= n ;x ++)
		{
			if (n % x == 0)
				contador ++;		
		}
		if(contador == 2)
		{	
			ultimoPrimo = n;
			ubicacionPrimo = ubicacion;
		}
		
		cout << "Ingrese un numero: ";
		cin >> n; 
		ubicacion ++;
		
		if(n == 0)
			cout << "La ubicacion del cero es: " << ubicacion <<endl;
	}
	
		   
	cout << "El primer par es : " << primerPar << " y su ubicacion es: " << ubicacionPar << endl;
	cout << "El ultimo primo es : " << ultimoPrimo << " y su ubicacion es: " << ubicacionPrimo << endl;
	

	return 0;
}