#include <iostream>
using namespace std;

int main()
{
  const int COSTO_ALQUILER = 10000, COSTO_CADA_1000_CARAMELOS = 5000;
  const float COSTO_POR_CARAMELO = 0.5;

  int cantidadCaramelo, costoPorMil;
  float presupuestoInicial, costoProduccionCaramelo;

  cout << "Ingrese su presupuesto inicial: ";
  cin >> presupuestoInicial;

  cout << "Ingrese la cantidad de caramelos: ";
  cin >> cantidadCaramelo;

  costoProduccionCaramelo = cantidadCaramelo * COSTO_POR_CARAMELO;

  if (cantidadCaramelo >= 1000){
    costoPorMil = cantidadCaramelo / 1000;
    costoPorMil = costoPorMil * COSTO_CADA_1000_CARAMELOS;
  }

  if(presupuestoInicial > COSTO_ALQUILER + costoPorMil + costoProduccionCaramelo){
    cout << "El presupuesto es suficiente para cubrir los costos de : " << COSTO_ALQUILER + costoPorMil + costoProduccionCaramelo;
  }else{
    cout << "El presupuesto no es es suficiente, necesita un credito de: " << (COSTO_ALQUILER + costoPorMil + costoProduccionCaramelo) - presupuestoInicial;
  }

  return 0;
}