
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int lecturaActual, lecturaAnterior;
  char codigoTarifa;

  cout << "Ingrese la lectura de kWh del medidor del mes actual: ";
  cin >> lecturaActual;
  cout << "Ingrese la lectura de kWh del medidor del mes anterior: ";
  cin >> lecturaAnterior;
  cout << "Ingrese el codigo de tarifa (A/a, B/b, C/c, D/d, E/e, F/f): ";
  cin >> codigoTarifa;

  // Variables para almacenar la información
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
      cout << "Código de tarifa no válido." << endl;
      return 1;
    }

    // Calcular el consumo de kWh
    int consumoKWh = lecturaActual - lecturaAnterior;

    // Calcular el importe a abonar
    double importe = cargoFijo + (consumoKWh * precioPorKWh);

    // Mostrar la información
    cout << "Tipo de servicio: " << tipoServicio << endl;
    cout << "Categoria: " << categoria << endl;
    cout << "Consumo de kWh: " << consumoKWh << " kWh" << endl;
    cout << "Importe a abonar: $" << fixed << setprecision(2) << importe << endl;

    return 0;
}


