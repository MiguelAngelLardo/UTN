#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int n = 1, maxPar = 0;
  
  while (n != 0){
    cout << "Numero: ";
    cin >> n;

    if(n % 2 == 0){
      if(maxPar == 0){
        maxPar = n;
      }
      if(n > maxPar){
        maxPar = n;
      }
    }   
  }

  cout << "Maximo: " << maxPar; 

}