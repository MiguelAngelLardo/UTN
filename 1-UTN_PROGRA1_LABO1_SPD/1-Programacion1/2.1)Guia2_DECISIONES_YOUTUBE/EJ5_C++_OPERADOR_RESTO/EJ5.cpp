#include <iostream>

using namespace std;

/*Hacer un programa para ingresar un número y mostrar por pantalla un cartel
aclaratorio si el mismo es PAR o IMPAR.
Nota: leé sobre el operador “Resto”. En el próximo video lo explicaremos!*/

int main(){
  int n1;

  cout << "Ingrese un numero: ";
  cin >> n1;

  if(n1 % 2 == 0)
  {
    cout << "Es PAR";
  }
  else
  {
    cout << "IMPAR";
  }

  return 0;
}