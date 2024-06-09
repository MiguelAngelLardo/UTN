#include <iostream>
using namespace std;

int main()
{
  int cantHuevos;
  cout << " Ingrese los huevos vendidos:";
  cin >> cantHuevos;
  
  int caja = cantHuevos / 12;
  int suelto = cantHuevos % 12;

  int pagarCajas = caja * 100;
  int pagarSuelto = suelto * 12;

  int totalaPagar = pagarCajas + pagarSuelto;

  cout << totalaPagar;

  return 0;
}