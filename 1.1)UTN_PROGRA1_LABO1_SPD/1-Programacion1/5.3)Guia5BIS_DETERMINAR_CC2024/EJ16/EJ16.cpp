#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{ 
  int n;
  int maxPar, maxImpar; //A)
  int cantidadPositivos, cantidadNegativos; // B)
  int contadorTotal = 0;


  for(int x = 0; x < 3; x ++)
  { 
    maxPar = 0, maxImpar = 0;
    cantidadNegativos = 0, cantidadPositivos = 0;

    cout << "Ingrese un numero: ";
    cin >> n;
    while(n != 0)
    { 
      contadorTotal ++;
      if(n%2 == 0)
      {
        if(maxPar == 0)
        {
          maxPar = n;
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
        if(maxImpar == 0)
        {
          maxImpar = n;
        }
        else
        {
          if(n > maxImpar)
          {
            maxImpar = n;
          }
        }
      }

      if(n > 0){
        cantidadPositivos ++ ;
      }else{
        cantidadNegativos ++;
      }
      

      cout << "Ingrese un numero: ";
      cin >> n;
    }

    cout << endl << "Maximo par: " << maxPar << endl;
    cout << "Maximo impar: " << maxImpar << endl;
    cout << "Porcentaje numeros negativos: %" << (float)cantidadNegativos*100/(cantidadNegativos+cantidadPositivos) << endl;
    cout << "Porcentaje numeros positivos: %" << (float)cantidadPositivos*100/(cantidadNegativos+cantidadPositivos) << endl << endl;
  }

  cout << "El total de numeros ingresados es: " << contadorTotal;


 return 0;

}