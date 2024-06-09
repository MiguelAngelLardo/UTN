#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int dado1, dado2, dado3;
  int puntajeTotal = 0; //A)

  cout << "Ingrese el dado 1: ";
  cin >> dado1;
  cout << "Ingrese el dado 2: ";
  cin >> dado2;
  cout << "Ingrese el dado 3: ";
  cin >> dado3;

  if(dado1 %2 == 0)
    puntajeTotal += dado1;

  if(dado2 %2 == 0)
    puntajeTotal += dado2;

  if(dado3 %2 == 0)
    puntajeTotal += dado3;

  puntajeTotal *= dado3;

  cout << "Puntaje total: " << puntajeTotal;  

  return 0;
}