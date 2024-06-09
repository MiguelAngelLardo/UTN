#include <iostream>
using namespace std;

int main()
{
  int horas;
  char lenguaje;
  bool urgente;
  float total;

  cout << "Ingrese las cantidad de horas que va a trabajar: ";
  cin >> horas;

  cout << "Ingrese el lenguaje con el que va a programar ('C' - '#' - 'P' - 'G'): ";
  cin >> lenguaje;

  cout << "Ingrese si el lenguaje es urgente (1 para Si, 0 para No): ";
  cin >> urgente;

  switch (lenguaje)
  {
    case 'c':
    case 'C':
      total = horas * 2500;  
    break;

    case '#':
      total = horas * 2100;  
    break;

    case 'p':
    case 'P':
      total = horas * 1400;  
    break;

    case 'g':
    case 'G':
      total = horas * 2000;    
    break;

    default:
      cout << "Ingresa un valor valido.";
    break;
  }

  if (urgente)
    total = total * 1.2;
  
   cout << "Total a pagar: $" << total << endl;

  return 0;
}