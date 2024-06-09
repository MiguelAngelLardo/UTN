#include <iostream>
using namespace std;

/*Hacer un programa para ingresar una lista de 10 números y luego informar cuantos de
los números ingresados son primos.
*/

int main (){
int n, contPrimo = 0;

  
  for (int x = 0; x < 10; x++){
    int prePrimo = 0;

    cout << x+1 << ")Ingrese un numero: ";
    cin >> n;

    for(int y = 1; y <= n; y ++){
      
      prePrimo = (n % y == 0) ? prePrimo + 1 : prePrimo + 0;
      //n = n + 1 => n += 1;

     /*if(n % y == 0){
        prePrimo ++;
      }
      */
    }

    contPrimo += (prePrimo == 2) ? 1 : 0;

    /*if(prePrimo == 2){
        contPrimo ++;
      }  
    */  

  }

  printf("La cantidad de numeros primos es: #%d", contPrimo);









  return 0;
}