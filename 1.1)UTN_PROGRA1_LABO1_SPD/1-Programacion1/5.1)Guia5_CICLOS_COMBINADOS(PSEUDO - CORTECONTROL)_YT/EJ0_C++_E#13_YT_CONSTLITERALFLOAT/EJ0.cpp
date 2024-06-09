#include <iostream>
#include <iomanip> //MANIPULAR setPRECISION

using namespace std;

const int TAM = 3;

int main(){
  int n;
  int maxPar, maxImpar; // PTO A
  bool banderaPar, banderaImpar; //PTOA
  int cantidadPositivos, cantidadNegativos; // PTOB
  int contGeneral = 0; // PTO C

  for(int x = 0; x < TAM; x ++)
  {
    cout << "Ingrese un numero: ";
    cin >> n;
    
    maxPar = maxImpar = 0; // PTO A
    banderaPar = banderaImpar = false; //PTOA
    cantidadPositivos = cantidadNegativos = 0;//PTOB
    while(n != 0){ // SUB GRUPO
      contGeneral ++; // PTOC
      
      if(n % 2 == 0) //PTO A
      {
        if(!banderaPar)
        {
          maxPar = n;
          banderaPar = true;
        }else if(n > maxPar){
          maxPar = n;
        }
      }
      else
      {
        if(!banderaImpar)
        {
          maxImpar = n;
          banderaImpar = true;
        }else if(n > maxImpar){
          maxImpar = n;
        }
      }

      (n > 0) ? cantidadPositivos ++ : cantidadNegativos ++;
      
      cout << "Ingrese un numero: ";
      cin >> n;
    }

    cout << "SUB GRUPO(SUB LOTE) #" << x+1 << endl;
    cout << "***PUNTO A***\n";
    cout << "MAX PAR: " << maxPar << " - MAX IMPAR: " << maxImpar << endl << endl; //PTO A 
    cout << "***PUNTO B***\n";
    cout << "PORCENTAJES de POSITIVOS %" << fixed << setprecision(2) << 100.0f * cantidadPositivos / (cantidadNegativos + cantidadPositivos) << endl; 
    cout << "PORCENTAJES de NEGATIVOS %" << fixed << setprecision(2) << 100.0f * cantidadNegativos / (cantidadNegativos + cantidadPositivos) << endl; 
    // - parcial / total * 100 NO DA -> 100.0f * parcial / total
    //CONSTANTE LITERAL DECIMAL FLOTANTE es 100.0F
  }

  printf("LA CANTIDAD TOTAL DE NUMEROS ES: %d", contGeneral);

  return 0;
}