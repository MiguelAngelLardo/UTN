#include <iostream>
using namespace std;

/*Hacer un programa que solicite 20 números y luego emitir por pantalla el
máximo de los números pares y el mínimo de los números impares.*/

int main (){
  int n;
  int maxPar, minImpar;

  bool banderaPar = false, banderaImpar = false;

  for (int x = 0; x < 4; x++)
  {
    printf ("%d) Ingrese los numeros: ", x+1);
    cin >> n;

    if(n % 2 == 0)
    {
      if(!banderaPar) // banderaPar == false
      {
        maxPar = n;
        banderaPar =  true;
      }
      else 
      {
        if(n > maxPar)
        {
          maxPar = n;
        }
      }   
    }
    else 
    {
      if (!banderaImpar)
      {
        minImpar = n;
        banderaImpar = true;
      }
      else 
      {
        if (n < minImpar)
        {
          minImpar = n;
        }
      }
    }
  }

  cout << "EL maximo par es: " << maxPar << endl;
  printf ("El minimo par es %d", minImpar);
 
  return 0;
}