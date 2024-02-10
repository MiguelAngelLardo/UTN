#include <iostream>
using namespace std;

/*10. Hacer un programa que solicite una lista de números que corta cuando se
ingresa un cero y luego emitir por pantalla el máximo de los números
negativos y el mínimo de los números positivos.*/

int main (){

  int n, minPos, maxNeg;
  bool banderaMinPos = false, banderaMaxNeg = false;

  cout << "Ingrese un numero: ";
  cin >> n;

  while (n != 0){

    if (n > 0){
      if (!banderaMinPos){
        minPos = n;
        banderaMinPos = true;
      }else if (n < minPos){
        minPos = n;
      }
    }else{ //(n < 0)
      if (!banderaMaxNeg){
        maxNeg = n;
        banderaMaxNeg = true;
      }else if (n > maxNeg)
        maxNeg = n;
    }

    cout << "Ingrese un numero: ";
    cin >> n;
  }

  //cout << "El minimo positivo es: " << minPos <<  " y el maximo negativo es: " << maxNeg << endl;
  printf ("El minimo positivo es: %d y el maximo negativo es: %d", minPos, maxNeg);
  
  return 0;
}