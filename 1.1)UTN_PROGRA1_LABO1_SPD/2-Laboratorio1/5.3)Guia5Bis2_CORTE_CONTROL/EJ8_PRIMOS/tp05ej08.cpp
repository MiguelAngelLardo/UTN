//TP         : 05
//EJERCICIO  : 08
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

int main(void){
  const int CANT_GRUPOS = 5;
  int n, i, cantNroGrupo;
  //PUNTO A
  int cantImpPos;
  int maxGrp=0;
  float maxPorc=0.0;
  //PUNTO B
  int uNroPri=0, ord=0;
  //PUNTO C
  int cDiv, nant, cGrpOrd=0;
  bool ordenado=true;

  for(i=1; i <= CANT_GRUPOS; i++){
    cantImpPos = cantNroGrupo = 0;
    ordenado = true;
    uNroPri = ord = 0;
    cout << "Ingresar numero: ";
    cin >> n;

    while(n != 0){
      cDiv=0;
      cantNroGrupo++;
      //PUNTO A
      if(n > 0 && n%2 == 1){
        cantImpPos++;
      }
      //PUNTO B
      for(int j=1; j<=n; j++){
        if(n%j == 0){
          cDiv++;
        }
      }
      if(cDiv==2){
        uNroPri = n;
        ord = cantNroGrupo;
      }
      //PUNTO C
      if(cantNroGrupo == 1){
        nant = n;
      }
      else if(n > nant){
        nant = n;
      }
      else{
        ordenado = false;
      }
      cout << "Ingresar numero: ";
      cin >> n;
    }
    //PUNTO A
    if(((float)cantImpPos/cantNroGrupo * 100) > maxPorc){
      maxPorc = ((float)cantImpPos/cantNroGrupo * 100);
      maxGrp = i;
    }
    //PUNTO B
    cout << endl << "PUNTO B" << endl;
    cout << "-----------------" << endl;
    cout << "GRUPO      : " << i << endl;
    if(uNroPri != 0){
      cout << "ULT. PRIMO : " << uNroPri << endl;
      cout << "POSICION   : " << ord << endl;
    }
    else{
      cout << "SIN NUMEROS PRIMOS" << endl;
    }
    //PUNTO C
    if(ordenado){
      cGrpOrd++;
    }
  }
  cout << endl << "PUNTO A" << endl;
  cout << "-----------------" << endl;
  cout << "GRUPO MAYOR PORCENTAJE DE IMPARES POSITIVOS: " << maxGrp << endl;

  cout << endl << "PUNTO C" << endl;
  cout << "-----------------" << endl;
  cout << "CANTIDAD DE GRUPOS ORDENADOS: " << cGrpOrd;
  return 0;
}