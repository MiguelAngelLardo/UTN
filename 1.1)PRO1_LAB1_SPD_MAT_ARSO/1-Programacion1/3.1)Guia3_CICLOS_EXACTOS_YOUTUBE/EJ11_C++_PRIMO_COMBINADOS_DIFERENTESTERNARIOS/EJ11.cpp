#include <iostream>
#include <string> //Libreria tiene dentro "HERRAMIENTAS"

using namespace std;

/* Hacer un programa para ingresar 10 números y luego calcule y emita el mayor
de los primos de la lista. En caso de no haber ningún número primo, deberá
aclararlo con un cartel.*/

int main (){

  int n, contadorPrePrimo, maxPrimo;
  bool banderaPrimo = false;

  for (int x = 0; x < 5; x++)
  {
    cout << "Ingrese los numeros: ";
    cin >> n;

    //FOR PARA EL PRIMO
    contadorPrePrimo = 0;
    for(int y = 1; y <= n; y ++){
      if(n % y == 0){ //contadorPrePrimo += (n % y == 0) ? 1 : 0;
        contadorPrePrimo ++; // contador += 1 || contador = contador + 1 || contador -=- 1
      }
    }

    if(contadorPrePrimo == 2) // si contadorPrePrimo == 2 => ahora es primo
    {
      if(!banderaPrimo){ // banderaPrimo == false
        maxPrimo = n;
        banderaPrimo = true;
      }else if(n > maxPrimo){
        maxPrimo = n;
      }
    }
  }

  if(banderaPrimo){
    printf("El mayor numero primo es %d: ", maxPrimo);
  }else{
    cout << "No hay primo";
  }
  cout << endl;
  banderaPrimo ? cout << "El maximo primo es: " << maxPrimo : cout << "No hay primo";
  cout << endl;
  cout << (banderaPrimo ? "El maximo primo es " + to_string(maxPrimo) : "No hay primo");

  return 0;
}