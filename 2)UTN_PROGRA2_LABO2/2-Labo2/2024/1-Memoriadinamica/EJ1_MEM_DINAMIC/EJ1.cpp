#include <iostream>

using namespace std;
/*
Problema 1
Hacer un programa que le pida al usuario un número N y que genere dinámicamente un vector de N elementos 
y los complete con números al azar entre 1 y N. Mostrar el vector resultante.
*/
int main (){
  int n;
  float *vNumeros = nullptr; //NULL / 0 
  cout << "Ingrese el numero de CASILLEROS para el vector: ";
  cin >> n;
  vNumeros = new float[n];

  if(vNumeros != nullptr){
    for(int x = 0;x < n; x ++){
      vNumeros[x] = 1 + (rand() % n); // rand() % n => va desde 0 hasta n50
    }
    
    for(int x = 0;x < n; x ++){
      cout << x+1 << ") #" <<  vNumeros[x] << endl;
    }  
  }

  delete []vNumeros;

  return 0;
}