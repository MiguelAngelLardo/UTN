#include <iostream>
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  const int TAM = 5;
  int n, vector[TAM] = {};
  bool noEncontrado = true;

  for(int x = 0; x < TAM; x ++){
    cout << "Ingrese un numero #" << x+1 << ": ";
    cin >> n;
    vector[x] = n;
  }

  cout << "Ingrese un numero a buscar: ";
  cin >> n;
  for(int x = 0; x < TAM; x ++){
    cout << "Vuelta " << x+1 << ": " << endl;
    if (n == vector[x])   
      noEncontrado = false;
  }

  if(noEncontrado)
    cout << "El numero " << n << " No se encuentra en el vector."; 
  else
    cout << "El numero " << n << " SI se encuentra en el vector."; 

  return 0;

}