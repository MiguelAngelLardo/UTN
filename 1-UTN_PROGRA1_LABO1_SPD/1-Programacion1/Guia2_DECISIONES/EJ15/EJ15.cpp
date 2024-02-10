#include <iostream>
using namespace std;

int main()
{

  int anio;

  cout << "Ingrese el año: "; 
  cin >> anio;

  if((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
    cout << "Es bisiesto.";
  }else{
    cout << "No bisiesto";
  }

  return 0;
}