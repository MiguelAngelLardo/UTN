#include <iostream>

using namespace std;

/*
Una importante cadena de delivery cuenta con una promoción por tiempo
limitado en la que otorga un 15% de descuento sobre el total del valor de la
compra realizada. Hacer un programa para solicitar el monto total y el mismo
calcule y emita por pantalla el total a cobrar con el descuento aplicado.
*/

int main (){
  float montoTotal, descuento;

  cout << "ingrese el monto total: ";
  cin >> montoTotal;

  descuento = montoTotal * 0.85;

  cout << "El total a pagar con el descuento es: " << descuento;

  return 0;
}