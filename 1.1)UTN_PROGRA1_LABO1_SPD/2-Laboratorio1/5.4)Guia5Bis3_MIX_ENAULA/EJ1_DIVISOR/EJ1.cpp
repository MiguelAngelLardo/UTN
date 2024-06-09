#include <iostream>
using namespace std;

int main() 
{

 int n, menorDivisor, mayorDivisor;
 bool banderaMinimo = false, banderaMaximo = false;

 cout << "Ingrese un numero: ";
 cin >> n;

 for(int x = 2; x < n; x++ )
 {
  if(n % x == 0)
  { 
    if (!banderaMinimo){
      menorDivisor = x;
      banderaMinimo = true;
    }

    if(!banderaMaximo){
      mayorDivisor = x;
      banderaMaximo = true;
    }else if (n > mayorDivisor){
      mayorDivisor = x;
    }
  }

 }
} 