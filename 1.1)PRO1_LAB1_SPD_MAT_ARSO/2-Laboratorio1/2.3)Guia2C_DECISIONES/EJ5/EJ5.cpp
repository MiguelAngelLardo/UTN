
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  char codigoTarifa;
    
  cout << "Ingrese el codigo de tarifa (A/a, B/b, C/c, D/d, E/e, F/f): ";
  cin >> codigoTarifa;

  string tipoServicio, categoria;
  float cargoFijo, precioPorKWh;

  switch (codigoTarifa) {
    case 'A':
    case 'a':
      tipoServicio = "Residencial";
      categoria = "1";
      cargoFijo = 500;
      precioPorKWh = 1.0;
      break;
    case 'B':
    case 'b':
      tipoServicio = "Residencial";
      categoria = "2";
      cargoFijo = 750;
      precioPorKWh = 1.25;
      break;
    case 'C':
    case 'c':
      tipoServicio = "Residencial";
      categoria = "3";
      cargoFijo = 600;
      precioPorKWh = 3.75;
      break;
    case 'D':
    case 'd':
      tipoServicio = "Comercial";
      categoria = "1";
      cargoFijo = 1100;
      precioPorKWh = 6.0;
      break;
    case 'E':
    case 'e':
      tipoServicio = "Comercial";
      categoria = "2";
      cargoFijo = 1500;
      precioPorKWh = 12.5;
      break;
    case 'F':
    case 'f':
      tipoServicio = "Comercial";
      categoria = "3";
      cargoFijo = 1800;
      precioPorKWh = 20.0;
      break;
    default:
      cout << "Codigo de tarifa no valido." << endl;
      return 1;
  }

  // Mostrar la información
  cout << "Tipo de servicio: " << tipoServicio << endl;
  cout << "Categoria: " << categoria << endl;
  cout << "Cargo fijo: $" << fixed << setprecision(2) << cargoFijo << endl;
  cout << "Precio por kWh: $" << fixed << setprecision(2) << precioPorKWh << endl;


  return 0;
}