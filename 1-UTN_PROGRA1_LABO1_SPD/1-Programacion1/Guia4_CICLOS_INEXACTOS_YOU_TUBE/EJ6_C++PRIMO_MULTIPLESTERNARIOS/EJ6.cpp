#include <iostream>
#include <string>

using namespace std;

/*Hacer un programa que solicite UN número y luego calcule y emita un cartel
aclaratorio si el mismo es primo o no es primo.
Nota: usando While. Ya lo hicimos con FOR, ahora con While.*/

int main (){

  int n, divisor = 1, contPrePrimo = 0;

  cout << "Ingrese un numero: ";
  cin >> n;

  while(divisor <= n){
    if(n % divisor == 0){
      contPrePrimo ++;
    }

    divisor ++;
  }

  if(contPrePrimo == 2){
    cout << "El numero " << n << " es un numero primo.";
  }else{
    printf("EL numero %d no es primo", n);
  }

  cout << endl;
 (contPrePrimo == 2) ? cout << "El numero " << n << " es un numero primo." : cout << "El numero " << n << " NO ES numero primo";
 cout << endl;
 cout << (contPrePrimo == 2 ? "El numero " + to_string(n) + " es un numero primo." : "El numero " + to_string(n) + " NO ES numero primo.");

  return 0;
}