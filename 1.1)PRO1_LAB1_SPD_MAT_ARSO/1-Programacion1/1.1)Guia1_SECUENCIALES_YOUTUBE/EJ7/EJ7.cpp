#include <iostream>

using namespace std;

/*Hacer un programa para ingresar por teclado los metros cuadrados totales de
un predio y los metros cuadrados cubiertos; luego calcular y mostrar por
pantalla el porcentaje de metros cuadrados cubiertos y el porcentaje de
metros cuadrados descubiertos*/

int main (){
  int metrosTotales, metrosCubiertos;
  float porcentajeCubierto, porcentajeDescubierto;

  cout << "Ingrese los metros totales: ";
  cin >> metrosTotales;
  cout << "Ingrese los metros cubiertos: ";
  cin >> metrosCubiertos;

  int metrosDescubiertos = metrosTotales - metrosCubiertos;

  porcentajeCubierto = metrosCubiertos * 100 / metrosTotales;
  porcentajeDescubierto = metrosDescubiertos * 100 / metrosTotales;

  cout << endl << "Porcentaje cubierto es: " << porcentajeCubierto << "%" << endl;
  cout << "Porcentaje descubierto es: " << porcentajeDescubierto << "%";

  return 0;
}