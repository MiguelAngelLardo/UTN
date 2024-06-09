#include <iostream>
using namespace std;

int main() 
{
  int n, primerPar = 0, contPrimo = 0, primerPrimo = 0;

  for (int x = 0; x < 10; x ++)
  {
    cout << x << ") Ingrese un numero: ";
    cin >> n;
    if (n % 2 == 0 && primerPar == 0)
      primerPar = n;
    
    for (int y = 1; y <= n; y ++)    
      if (n % y == 0)
        contPrimo ++;
    
    if (contPrimo == 2 && primerPrimo == 0)
      primerPrimo = n;
  }  

  cout << "Primer numero par: " << primerPar << endl;
  cout << "Primer numero primo: " << primerPrimo;
  
	return 0;
}