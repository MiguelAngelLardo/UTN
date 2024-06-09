#include <iostream>
using namespace std;

/* Hacer un programa que solicite 20 números y calcule y emita por pantalla
cuántos son positivos (mayores a cero). Se debe mostrar un solo valor: el
conteo final.*/

int main (){

  int n1, contador = 0;

  for(int x = 0; x < 20; x++)
  {
    cout << x + 1 << ") Ingrese un numero: ";
    cin >> n1;

    if(n1 > 0)
    {
      contador ++;
    }

  }

  cout << "Los numeros mayores a cero son: " << contador;




  return 0;
}