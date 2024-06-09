#include <iostream>
#include <iomanip>
using namespace std;
/*3-Hacer un programa para ingresar una lista de números que finaliza cuando se
ingresa un cero y luego informar el porcentaje de números primos y el
porcentaje de números no primos. Se informan 2 resultados al final*/
int main(){
  
  int n;
  int contadorPrePrimos;//lowerCamelCase
  int contadorPrimos = 0, contadorNoPrimos = 0;
  float porcPrimos = 0, porcNoPrimos = 0;
  int cantTotal;
  cout << "Ingrese los numeros: ";
  
  cin >> n;

  while (n != 0){

    contadorPrePrimos = 0;    
    for (int x = 1; x <= n; x++){
      (n % x == 0) ? contadorPrePrimos++ : contadorPrePrimos += 0;
    }
      
    (contadorPrePrimos == 2) ? contadorPrimos++ : contadorNoPrimos++;
    
    cout << "Ingrese los numeros: ";
    cin >> n;
  }

  cantTotal = contadorNoPrimos + contadorPrimos;
  porcPrimos = (contadorPrimos * 100) / cantTotal;
  porcNoPrimos = (contadorNoPrimos *100) / cantTotal;

  cout << "El porcentaje total de numeros primos es: "  << fixed << setprecision(2) << porcPrimos << "%" << endl;
  cout << "El porcentaje total de numeros NO primos es: "  << fixed << setprecision(2) << porcNoPrimos << "%" << endl;


  return 0;
}