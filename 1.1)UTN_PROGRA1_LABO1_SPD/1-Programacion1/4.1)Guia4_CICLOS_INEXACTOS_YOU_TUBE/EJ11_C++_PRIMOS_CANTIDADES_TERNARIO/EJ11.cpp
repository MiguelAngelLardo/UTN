#include <iostream>

using namespace std;

/*11. Hacer un programa para ingresar una lista de números que corta cuando se
ingresa un cero y luego mostrar: la cantidad de números primos, la cantidad de
números pares, la cantidad de positivos y la cantidad de negativos.*/

int main (){
  int n, contPos = 0, contNeg = 0, contPares = 0, contPrimo = 0;

  cout << "Ingrese un numero: ";
  cin >> n;
 
  int x, prePrimo; //PUNTO C
  while (n != 0){
 
    (n > 0) ? contPos ++ : contNeg ++; //PUNTO A
    (n % 2 == 0) ? contPares ++ : contPares += 0;//PUNTO B

    ///////////////////////////////////////////////////
    x = 1, prePrimo = 0;
    while(x <= n){      
      (n % x == 0) ? prePrimo += 1 : prePrimo += 0;
      x ++;
    }
    (prePrimo == 2) ? contPrimo -=- 1 : contPrimo -=- 0;
    ////////////////////////////////////////////////////
    /*prePrimo =0;
    for(int x = 1; x <= n; x ++){
      if(n % x == 0){
        prePrimo ++;
      }
      if(prePrimo == 2){
        contPrimo ++;
      }
    }*/
    ////////////////////////////////////////////////////

    cout << "Ingrese un numero: ";
    cin >> n;
  }

  cout << "NUMEROS POSITIVOS #" << contPos << endl;
  cout << "NUMEROS NEGATIVOS #" << contNeg << "\n";
  printf("NUMEROS PARES #%d\n", contPares);
  printf("NUMEROS PRIMOS #%d", contPrimo);

  return 0;
}