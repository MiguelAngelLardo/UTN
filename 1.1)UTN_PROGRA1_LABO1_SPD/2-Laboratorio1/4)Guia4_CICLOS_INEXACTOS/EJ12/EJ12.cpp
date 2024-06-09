#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int numero = 1, contador = 0, quini;
 
    while (contador < 1000)
    {
     if (numero % 15 == 0 && numero % 3 == 0 && numero % 6 != 0){
      contador++;
      cout << numero << endl;
        if (contador == 520){            
            quini = numero;
          }
        }
      numero++;
    }
    cout << "520 = " << quini << endl;
 
    system("pause");

 return 0;

}