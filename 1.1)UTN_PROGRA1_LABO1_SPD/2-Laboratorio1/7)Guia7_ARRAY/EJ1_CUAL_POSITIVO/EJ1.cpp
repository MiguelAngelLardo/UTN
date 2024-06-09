#include <iostream>
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int n, vector[10] = {};

  for(int x = 0; x < 10; x ++){
    cout << "Ingrese un numero #" << x+1 << ": ";
    cin >> n;
    vector[x] = n;
  }

  cout << "Los numeros positivos son: " << endl;
  for(int x = 0; x < 10; x ++){
    if(vector[x] > 0){
      cout << vector[x] << " - ";
    }
  }

  return 0;
}