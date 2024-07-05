#include <iostream>
using namespace std;

/*
2) Dada una lista de números compuesta por 10 grupos y cada grupo separado del
siguiente por un cero, se pide determinar e informar:

a) Para cada uno de los grupos el máximo de los números pares y el máximo de los
números impares.
b) Para cada uno de los grupos el porcentaje de números negativos y números positivos.
c) Cuantos números positivos había en total entre los 10 grupos.
*/

const int TAM = 3;

int main() 
{ 
  int n;

  bool banderaPar, banderaImpar; //PTOA
  int maxPar, maxImpar;//PTOA
  int contTotal, contPos, contNeg;//PTOB
  float porcentajePos, porcentajeNeg;//PTOB
  int contadorNumPositivo10Grupos = 0;//PTOC 

  for (int x = 0; x < TAM; x ++)
  {
    banderaPar = banderaImpar = false; //PTOA
    maxPar = maxImpar = 0;//PTOA
    contTotal =  contPos =  contNeg = 0; //PTOB
    
    cout << "Grupo "<< x+1 << ") Ingrese un numero: ";
    cin >> n;
    while (n != 0)
    {
      if(!banderaPar && n%2 == 0)
      {
        banderaPar = true;
        maxPar = n;
      }
      else
      {
        if(n%2 == 0 && n > maxPar)
        {
          maxPar = n;
        }
      }

      if(!banderaImpar && n%2 != 0){
        banderaImpar = true;
        maxImpar = n;
      }else if(n%2 != 0 && n > maxImpar)
        maxImpar = n;

      //PTO B
      contTotal ++;
      if (n >= 0){
        contPos ++;
        contadorNumPositivo10Grupos ++;
      }else
        contNeg ++; 
      
      cout << "Grupo "<< x+1 << ") Ingrese un numero WHILE: ";
      cin >> n;
    }

    porcentajePos = (float)contPos*100/contTotal; // 100.0f * contPos / contTotal => const literal flotante decimal
    porcentajeNeg = (float)contNeg*100/contTotal;

    cout << endl << "Grupo #" << x+1 << " PUNTO A:  Maximo par => " << maxPar << ". Maximo impar => " << maxImpar << endl; 
    cout << "PUNTO B: Porcentaje positivo %" << porcentajePos << ". Porcentaje negativo %" << porcentajeNeg << endl; 

  }

  cout << "Numeros positivos en total en los 10 grupos: " << contadorNumPositivo10Grupos;

	return 0;
}