#include <iostream>
using namespace std;

int main() 
{
  int contadorNumPositivo10Grupos = 0;

  for (int x = 0; x < 10; x ++)
  {
    int n, maxPar = 0, maxImpar = 0, contTotal = 0, contPos = 0, contNeg = 0;
    float porcentajePos, porcentajeNeg;
    bool banderaPar = false, banderaImpar = false;

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

      contTotal ++;
      if (n >= 0){
        contPos++;
        contadorNumPositivo10Grupos ++;
      }else
        contNeg ++; 
      
      cout << "Grupo "<< x+1 << ") Ingrese un numero WHILE: ";
      cin >> n;
    }

    porcentajePos = (float)contPos*100/contTotal;
    porcentajeNeg = (float)contNeg*100/contTotal;

    cout << endl << "Grupo " << x+1 << ": Maximo par => " << maxPar << ". Maximo impar => " << maxImpar << ". Porcentaje positivo %" << porcentajePos << ". Porcentaje negativo %" << porcentajeNeg << endl; 

  }

  cout << "Numeros positivos en total en los 10 grupos: " << contadorNumPositivo10Grupos;

	return 0;
}