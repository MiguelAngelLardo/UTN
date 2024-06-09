#include <iostream>
#include <iomanip>
using namespace std;
/* Dar una lista de números compuesta por 10grupos y cada grupo separado del
 siguiente por un cero, se pide determinar e informar:
 a) Para cada uno de los grupos el máximo de los números pares y el máximo de
 los números impares. Se informan 2 resultados por cada grupo.
 b) Para cada uno de los grupos el porcentaje de números negativos y números
 positivos. Se informan 2 resultados por cada grupo.
 c) Cuántos números positivos había en total entre los 10 grupos. Se informa 1
 resultado al final*/
 int main(){

  int n, totalNumeros; 
  int maxPar, maxImpar;
  int positivos, negativos;
  int positivosTotalesGrupos = 0;
  float porcentajePos, porcentajeNeg;
  bool banderaPar, banderaImpar;

  for (int x = 0; x < 10; x++)
  {
    printf ("\n%d)Ingrese el numero: ", x+1);
    cin >> n;

    positivos =  negativos = maxPar = maxImpar = 0;
    banderaPar = banderaImpar = false;
    while(n != 0)
    {

      if (n % 2 == 0){ //PTOA
        if(!banderaPar){
          maxPar = n;
          banderaPar = true;
        }else if (n > maxPar){
          maxPar = n;
        }
      }else if(!banderaImpar){
        maxImpar = n;
        banderaImpar = true;
        }else if (n > maxImpar){
        maxImpar = n;
      }

      (n > 0) ? positivos++ : (n < 0) ? negativos++ : 0;//PTOB


      (n > 0) ? positivosTotalesGrupos++ : 0;//PTOC


      totalNumeros = positivos + negativos;
      porcentajePos = (positivos * 100) / totalNumeros;
      porcentajeNeg = (negativos * 100) / totalNumeros;


      printf ("%d)Ingrese el numero: ", x+1);
      cin >> n;

    }
  
  
    cout << "El maximo par es: " << maxPar << endl;
    cout << "El maximo impar es: " << maxImpar<< endl;

    cout << "El porcentaje de numeros positivos es " << fixed << setprecision(2) <<porcentajePos << "%\n";
    cout << "El porcentaje de numeros negativos es  "<< fixed << setprecision(2) <<  porcentajeNeg << "%\n";

  }

  cout << "La cantidad de numeros positivos en total es: " << positivosTotalesGrupos << endl;

 

  return 0;

 }