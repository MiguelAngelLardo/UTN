#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
 
  int  ultimoPrimo, ubicacionPrimo, primerPar, ubicacionPar;
  bool banderaPar = false;

  for(int x = 0; x < 7; x++){
    int n, contadorPrimo = 0;

    cout << x+1 << ") Ingrese un numero: "; 
    cin >> n;

    for (int y = 1; y <= n; y ++)
    {
     if (n % y == 0)
      contadorPrimo ++;
    }

    if (contadorPrimo == 2){
      ultimoPrimo = n;
      ubicacionPrimo = x + 1;
    }

    if(n % 2 == 0){
      if(!banderaPar){
        banderaPar = true;
        primerPar = n;
        ubicacionPar = x +1;
      }
    }
  }

  cout << "El primer par es: " << primerPar << " ubicacion " << ubicacionPar << endl;
  cout << "El ultimo primo es: " << ultimoPrimo << " ubicacion " << ubicacionPrimo << endl;

}