#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int n, diferencia = 0, max = 0, min = 0, contNum = 0;
  
  while(diferencia <= 10){
    cout << "Ingrese un numero: "; 
    cin >> n;

    contNum ++;
    if(max == 0){
      max = n;
      min = n;
    }

    if(n > max)
      max = n;
    
    if(n < min)
      min = n;

    diferencia = max - min;
    if(diferencia < 0)
      diferencia *= -1;    
  }
  
  cout << endl << "Cantidad de numeros : " << contNum;

}