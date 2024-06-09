#include <iostream>
using namespace std;

int main() 
{
  int n, numeroPrimo, primoMenorMayor;
  bool banderaPrimoMenorMayor = false, banderaPrimoOrdenado = true;

  cout << "Ingrese un numero: ";
  cin >> n;
  while (n != 0)
  {
    int contPrePrimo = 0;

    for(int x = 1; x <= n; x ++)
      if(n%x == 0)
        contPrePrimo ++;
    
    if(contPrePrimo == 2){
      numeroPrimo = n;
    }
    
    if(!banderaPrimoMenorMayor){
      banderaPrimoMenorMayor = true;
      primoMenorMayor = numeroPrimo;    
    }else if(numeroPrimo > primoMenorMayor && banderaPrimoOrdenado == true){
      primoMenorMayor = numeroPrimo;
    }else if (numeroPrimo < primoMenorMayor){
      banderaPrimoOrdenado = false;
    }

    cout << "Ingrese un numero: ";
    cin >> n;
  }

  cout << (banderaPrimoOrdenado? "Conjunto Ordenado" : "Conjunto no ordenado");

  return 0;
}