#include <iostream>
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  const int TAM = 5;
  int n, minNum, contadorMin, vector[TAM] = {};
  contadorMin = 0;

  for(int x = 0; x < TAM; x ++){
    cout << "Ingrese un numero #" << x+1 << ": ";
    cin >> n;
    vector[x] = n;
  }

  minNum = vector[0];
  for(int x = 0; x < TAM; x ++){
    if (vector[x] < minNum)   
      minNum = vector[x];
  }

  for(int x = 0; x < TAM; x ++){
    if (minNum == vector[x])
      contadorMin ++;
  }

  cout << "El menor numero es: " << minNum << ". Se repite: #" << contadorMin << " veces";

  return 0;

}