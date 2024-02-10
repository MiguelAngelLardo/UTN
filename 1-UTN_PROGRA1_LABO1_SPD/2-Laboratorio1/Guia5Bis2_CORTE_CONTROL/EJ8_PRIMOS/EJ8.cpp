#include <iostream>
using namespace std;

int main (){
  int n;
  int contImpar, contTotal, maxGrupo; // PTOA
  float maxPorcentaje = 0; // PTOA
  int gruposOrdenados = 0;

  for (int i = 0; i < 5; i++){
    contImpar = contTotal = 0; // PTOA
    int ultimoPrimo = 0, ubicacionPrimo; //PTOB
    bool orden = false;
    
    cout << "Ingrese un numero: ";
    cin >> n;    
    while(n != 0){
      int numAnterior = n;

      //PTOA
      contTotal ++;
      contImpar += (n % 2 != 0 && n > 0) ? 1 : 0;

      //PTOB
      int contPrimo = 0;
      for(int x = 1; x <= n; x ++){
        contPrimo += (n % x == 0) ? 1 : 0;
      }
      if(contPrimo == 2){
        ultimoPrimo = n;
        ubicacionPrimo = contTotal;
      }

      cout << "Ingrese un numero: ";
      cin >> n;

      //PTOC
      if(n > numAnterior){
        orden = true;
      }
    }

    float porcentaje = contImpar * 100 / (float)contTotal;
    if(porcentaje > maxPorcentaje){
      maxPorcentaje = porcentaje;
      maxGrupo = i+1;
    }

    if(ultimoPrimo != 0){
      cout << "EL ULTIMO PRIMO DEL GRUPO " << i + 1 << " es: " << ultimoPrimo << " y esta en la posicion #" << ubicacionPrimo << endl << endl;
    }else{
      cout << "El grupo " << i + 1 << " no posee PRIMOS." << endl << endl;
    }
    
    if(!orden){
      gruposOrdenados ++;
    }
  }

  cout << "PUNTO A: GRUPO " << maxGrupo << " - PORCENTAJE " << maxPorcentaje << "%" << endl;
  cout << "PUNTO C: La cantidad de grupos con numero ordenador es: " << gruposOrdenados << endl;

  return 0;
}