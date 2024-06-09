#include <iostream>
using namespace std;

int main()
{
  int cantDineroRetirar;
  cout << " Ingrese la cantidad de dinero a retirar: ";
  cin >> cantDineroRetirar;

  int retiro1000 = cantDineroRetirar / 1000; 
  cantDineroRetirar = cantDineroRetirar % 1000;

  int retiro500 = cantDineroRetirar / 500;
  cantDineroRetirar = cantDineroRetirar % 500;

  int retiro200 = cantDineroRetirar / 200;
  cantDineroRetirar = cantDineroRetirar % 200;

  int retiro100 = cantDineroRetirar / 100;
  cantDineroRetirar = cantDineroRetirar % 100;

  cout << " Se entregan: " << retiro1000 << " billetes de $1000, " << retiro500 << " billetes de $500, " << retiro200 << " billetes de $200, " << retiro100 << " billetes de $100.";

  return 0;
}