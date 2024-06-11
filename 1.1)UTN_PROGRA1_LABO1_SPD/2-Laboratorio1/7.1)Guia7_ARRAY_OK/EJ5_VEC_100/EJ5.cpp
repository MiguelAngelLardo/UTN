#include <iostream>
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  const int TAM = 10;  
  int n, vPos[TAM] = {}, vNeg[TAM] = {}, contPos, contNeg;

  contPos = contNeg = 0;
  for (int x = 0; x < TAM; x ++){
    cout << "Ingrese un numero #" << x+1 << " :";
    cin >> n;

    if(n >= 0){
      vPos[contPos] = n;
      contPos ++;  
    }else{
      vNeg[contNeg] = n;
      contNeg ++;
    }  
  }

  cout << "La cantidad de elementos del vector POS es: " << contPos << endl;
  cout << "La cantidad de elementos del vector POS es: " << contNeg << endl;
  
    cout << "Elementos del vector POS: " << endl;
  for (int x = 0; x < contPos; x ++){
      cout << vPos[x];
      if (x < contPos -1)
        cout << " - ";
  }

  cout << endl << "Elementos del vector PNEG: " << endl;
  for (int x = 0; x < TAM; x ++){
    if(vNeg[x] != 0)
      cout << vNeg[x];
      if(x < contNeg -1)
        cout << " - ";
  }

  return 0;

}