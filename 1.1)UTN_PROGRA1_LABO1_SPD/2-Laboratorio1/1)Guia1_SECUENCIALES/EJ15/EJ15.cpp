#include <iostream>
using namespace std;

int main()
{
  float maxTemperatura, minTemperatura, rangoTemperatura;

  cout << "Ingrese la maxima temperatura de San Fernando: ";
  cin >> maxTemperatura;

  
  cout << "Ingrese la minima temperatura de San Fernando: ";
  cin >> minTemperatura;

  if(maxTemperatura >= minTemperatura){
    rangoTemperatura = maxTemperatura - minTemperatura;
    cout << "El rango de temperatura en San Fernando fue: " << rangoTemperatura;
  }else{
    cout << "ERROR. La temperatura maxima debe ser mayor a la minima.";
  }

  return 0;
}