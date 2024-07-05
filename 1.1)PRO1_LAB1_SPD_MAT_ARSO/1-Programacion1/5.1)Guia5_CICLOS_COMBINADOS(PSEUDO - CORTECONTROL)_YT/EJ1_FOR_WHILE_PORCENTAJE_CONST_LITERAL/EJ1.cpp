#include <iostream>
#include <iomanip> //MANIPULAR setPRECISION

/*
1. Se dispone de una lista de 10 grupos de números enteros separados entre ellos
por ceros. Se pide determinar e informar:

a. El número de grupo con mayor porcentaje de números impares
positivos respecto al total de números que forman el grupo.

b. Para cada grupo, el último número primo y en qué orden apareció en
ese grupo. Si en un grupo no hubiera números primos, informarlo con
un cartel aclaratorio.

c. Informar cuántos grupos están formados por todos números ordenados
de mayor a menor.

*/
using namespace std;

const int TAM = 3;

int main(){
  int n;

  int contadorNumero, contadorImparesPositivos, grupoMaxPorcentaje;//PTOA
  float porcentajeActual, porcentajeMax = 0; // PTOA

  int contOrdenPrimo, prePrimo, ultimoPrimo, posPrimo;//PTOB

  int mayor, contadorOrdenados = 0;//PTOC
  bool banderaOrdenado; //PTOC

  for(int x = 0; x < TAM; x++)
  { 
    contadorNumero = contadorImparesPositivos = 0; // PTOA    
    contOrdenPrimo = 0, ultimoPrimo = 0; //PTOB
    banderaOrdenado = true;//PTOC

    cout << x+1 << ")Ingrese un numero: ";
    cin >> n; 
    mayor = n; //PTOC

    while(n != 0)
    {
      prePrimo = 0; //PTOB

      contadorNumero ++; //PTOA
      contadorImparesPositivos += (n % 2 != 0 && n > 0) ? 1 : 0; // PTOA

      contOrdenPrimo ++; //ordenPrimo = ordenPrimo + 1 || ordenPrimo += 1 || ordenPrimo -=- 1

      for(int y = 1; y <= n; y ++){ //PTOB
        prePrimo += (n % y == 0) ?  1 : 0;
      }

      if(prePrimo == 2){ //PTOB
        ultimoPrimo = n;
        posPrimo = contOrdenPrimo;
      }

      //PTOC
      (n <= mayor) ? mayor = n : banderaOrdenado = false;     
   
      cout << x+1 << ")Ingrese un numero: ";
      cin >> n;
    }
    
    //PTOA 
    porcentajeActual =  100.0f * contadorImparesPositivos / contadorNumero;
    //  parcial / total * 100 NO DA -> 100.0f * parcial / total
    //CONSTANTE LITERAL DECIMAL FLOTANTE es 100.0F
    if(porcentajeActual > porcentajeMax){
      porcentajeMax = porcentajeActual;
      grupoMaxPorcentaje = x + 1;
    }

    //PTOB
    cout << "PUNTO B" << endl;
    if(ultimoPrimo == 0){
      cout << "Grupo: #" << x +1 <<" => No hay primos" << endl;
    }else{
      cout << "Grupo: #" << x +1 << " => Ultimo primo: " << ultimoPrimo << " Posicion: " << posPrimo << endl;
    }

    if(banderaOrdenado){
      contadorOrdenados ++;
    }
  }

  cout << endl << "PUNTO A" << endl;
  cout << "GRUPO MAYOR PORCENTAJE: " << grupoMaxPorcentaje << endl;
  cout << "MAYOR PORCENTAJE IMPAR POSITIVO: " << fixed << setprecision(2) << porcentajeMax << "%" << endl;
    
  cout << endl << "PUNTO C" << endl;
  printf("La cantidad de grupos ordenados es: %d", contadorOrdenados);

  return 0;
}