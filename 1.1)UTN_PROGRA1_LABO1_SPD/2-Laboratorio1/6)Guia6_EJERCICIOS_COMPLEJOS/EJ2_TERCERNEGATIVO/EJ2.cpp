#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{

  int n, contadorNegativo=0, tercerNegativo, ultimo, primerDivisible;
  bool band = true;
    
  cout << "Ingrese una lista de numeros. Finaliza con 2 numeros consecutivos: ";
  cin >> n;
  while(n != ultimo)
  {
    if(n < 0 ){
      contadorNegativo++;
    }
    
    if(contadorNegativo == 3){
      tercerNegativo = n;
    }

    if (band == true)
    {
      if(n % 3 == 0)
      {
        if(n % 4 != 0){
          primerDivisible = n;
          band = false;
        }
      }
    }
  ultimo = n;
  cout << "Ingrese otro numero: ";
  cin >> n;
  }

  if (contadorNegativo >=3){
    cout << "El tercer numero negativo es: " << tercerNegativo << endl;
  }
  else{
    cout << "No se encontraron numeros negativos" << endl;
  }
  if (band == false){
    cout << "El primer numero divisible por 3 y no por 4 es " << primerDivisible << endl;
  }

 return 0;

}