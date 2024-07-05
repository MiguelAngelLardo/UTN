#include <iostream>
using namespace std;

int main() {
	
	int n, anterior, maximo;
	bool bandera = false;	
	
  cout << "Ingresa un numero: ";
	cin >> n;
	
	
	if (!bandera){
		maximo = n;
		bandera = true;
	}
	
	do{
		anterior = n;
    cout << "Ingresa un numero: ";
		cin >> n;
		
		if ( n > maximo)
			maximo = n;
		
	
	} while(n != anterior);
	
	cout << "El valor maximo es: " << maximo;
	 
	return 0;
}