#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int n, ultimo = 0, anteUltimo = 0;
  bool flagImpar = false;

  cout << "Numero: ";
  cin >> n;

  while (n % 7 != 0)
  {
    if (n % 2 != 0)
    {
      if (ultimo == 0)
      {
        ultimo = n;
        anteUltimo = n;
        flagImpar = true;
      }
      else
      {
        anteUltimo = ultimo;
        ultimo = n;
      }
    }

    cout << "Numero: ";
    cin >> n;

  }

  if(!flagImpar)
    cout << "No hay impar.";
  else  
    cout << "Ante ultimo: " << anteUltimo << ". Ultimo: " << ultimo;

}