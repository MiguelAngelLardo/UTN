#include <iostream>
using namespace std;

int main()
{
  int descuentoAAplicar;
  float importeCompra;

  cout << "Ingrese el importe de la compra: ";
  cin >> importeCompra;

  cout << "Ingrese el descuento a aplicar: ";
  cin >> descuentoAAplicar;

  cout << "Importe: $" << importeCompra << endl;
  cout << "Descuento: $" << importeCompra * descuentoAAplicar/100 << endl;
  cout << "Total: $" << importeCompra - (importeCompra * descuentoAAplicar/100);

  return 0;
}