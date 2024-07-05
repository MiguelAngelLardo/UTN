#include <iostream>
using namespace std;
/*Hacer un programa para ingresar 10 números y guardarlos en un vector.
 Determinar e informar cuál es la suma de los valores del vector.*/

 int main (){
  int vNum[10];//usas la logica de toda la vida 1 es 1
  int acumuladorVector = 0;
   
  for(int x = 0; x < 10; x ++){
    cout << x+1 << ") Ingrese un numero: ";
    cin >> vNum[x];
  }
  
  //vuelta 1 => indice 0 del vector = 15
  //vuelta 2 = indice 1 del vector = 24

  //suma => un for y una variable int acumuladorDelvector +=
  for (int i = 0; i < 10; i ++){
    acumuladorVector += vNum[i];
  }

  cout << "La acumulacion es: " << acumuladorVector;

  return 0;
 }