#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{ int numeroVenta, cantidadButaca;
  int CANTIDAD_BUTACAS = 1200;
  const int COSTO = 5000;

  int totalRecaudado = 0;

  cout << "Numero de venta: ";
  cin >> numeroVenta; 
  cout <<"Cantidad de butaca: ";
  cin >> cantidadButaca;

  while(numeroVenta != 0)
  {
    if(cantidadButaca > 0){
      totalRecaudado += COSTO*cantidadButaca; 
      CANTIDAD_BUTACAS -= cantidadButaca;
    }

    cout << "Numero de venta: ";
    cin >> numeroVenta; 
    cout <<"Cantidad de butaca: ";
    cin >> cantidadButaca;
  }

    cout << " Total recaudado: " << totalRecaudado << endl;
    cout << " Butacas sin vender: " << CANTIDAD_BUTACAS << endl;

 return 0;

}