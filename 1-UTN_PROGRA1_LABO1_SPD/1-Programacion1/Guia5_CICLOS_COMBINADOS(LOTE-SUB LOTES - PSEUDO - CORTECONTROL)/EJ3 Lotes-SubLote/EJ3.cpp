#include <iostream>
using namespace std;

int main() 
{
  int contGruposOrdenadosMayorMenor = 0, grupoMaxPorcentajeImparPositivo = 0;
  float porcentajeImparPositivo = 0, maxPorcentajeImparPositivo;
  bool banderaPorcentajeImparPositivo = false;

  for(int x = 0; x < 10; x ++)
  {
    int n, contImparPos = 0, ultimoPrimo = 0, ubicacionPrimo = 0, contTotalPorGrupo = 0, contMayorMenor = 0, ordenMayorMenor;
    bool banderaOrden = false;

    cout << "Ingrese un numero: ";
    cin >> n;

    while(n != 0)
    {
      int contPrimo = 0;
      contTotalPorGrupo ++;      

      if(n % 2 != 0 && n > 0) //A) suma al impar positivo 
        contImparPos ++;
      
      //B)********************************************************************************
      for (int i = 1; i <= n; i++) // se inicializa en el while para contar 2 divisores
        if(n % i ==0)
          contPrimo ++;
      
      if (contPrimo ==2){ //guarda el primo y la ubicacion
        ultimoPrimo = n;
        ubicacionPrimo = contTotalPorGrupo;
      }
      //B)****************************************************************************

      if(!banderaOrden){ //C) calcula si esta el grupo ordenado de mayor a menor
        ordenMayorMenor = n;
        contMayorMenor ++;
        banderaOrden = true;
      }else if(n < ordenMayorMenor){
        ordenMayorMenor = n;
        contMayorMenor ++;
      }

      cout << "Ingrese un numero: ";
      cin >> n;
    }

    if (contMayorMenor == contTotalPorGrupo) // C) sale del grupo y compara total numero del grupo con total ordenados
      contGruposOrdenadosMayorMenor ++;    

    porcentajeImparPositivo = contImparPos*100/contTotalPorGrupo; //A)calcula el porcentaje del grupo X + 1

    if(!banderaPorcentajeImparPositivo){ //A) guarda el mayor porcentaje impar positivo y en que grupo se encuenta
      maxPorcentajeImparPositivo = porcentajeImparPositivo;
      grupoMaxPorcentajeImparPositivo = x+1;
      banderaPorcentajeImparPositivo = true; 
    }else if(porcentajeImparPositivo > maxPorcentajeImparPositivo){
      maxPorcentajeImparPositivo = porcentajeImparPositivo;
      grupoMaxPorcentajeImparPositivo =  x+1;
    }

    cout << endl << "Grupo " << x+1 << ") Ultimo numero primo: " << ultimoPrimo << ". En la posicion " << ubicacionPrimo << endl; 

  }

   cout << "La cantidad de grupos ordenados de mayor a menor es: " << contGruposOrdenadosMayorMenor << endl;
   cout << "Grupo " << grupoMaxPorcentajeImparPositivo << ") es el que tiene %" << maxPorcentajeImparPositivo << " (mayor porcentaje de todos los grupos)" << endl << endl;
	
  return 0;
}