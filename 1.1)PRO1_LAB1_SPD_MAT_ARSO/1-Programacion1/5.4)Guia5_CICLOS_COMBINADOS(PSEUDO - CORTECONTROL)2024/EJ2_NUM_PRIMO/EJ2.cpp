#include <iostream>
using namespace std;
/* Hacer un programa para ingresar una lista de 10 números y luego informar
cuántos de los números ingresados son primos. Se informa 1 resultado al final.*/

int main(){

  int n; 
  int contadorPrimos = 0;
  int contadorPrePrimos;

  for (int x=0; x < 10; x++){
    cout << "Ingrese los numeros: ";
    cin >> n;
   
    contadorPrePrimos = 0;
    
    for (int i=1; i <= n; i++){
      if (n % i == 0)
      contadorPrePrimos++;//sera primo si acumulo 2 veces
    }

    if (contadorPrePrimos == 2){
      contadorPrimos ++;
    } 
  }

  cout << "La cantidad de numeros primos es: " << contadorPrimos;



  return 0;
}