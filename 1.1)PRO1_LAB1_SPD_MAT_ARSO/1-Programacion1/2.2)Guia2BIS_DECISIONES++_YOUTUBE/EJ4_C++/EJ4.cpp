#include <iostream>

using namespace std;

/*4. Un importante negocio de desinfectante líquido realiza descuentos
dependiendo de la cantidad de litros vendidos según la siguiente escala:
a. Si vende menos de 100 litros, no hay descuento.
b. Si vende entre 101 y 300 litros, el descuento es del 10%.
c. Si vende entre 301 y 500 litros, el descuento es del 15%.
d. Finalmente, si la venta es de más de 500 litros, el descuento es del 25%.
Hacer un programa que solicite el ingreso del importe total de la venta y la
cantidad de litros vendidos y calcule y emita el importe con el descuento
aplicado.*/

int main(){
  float importeTotal, litrosVendidos;

  cout << "Ingrese el Importe Total de la venta: ";
  cin >> importeTotal;

  cout << "Ingrese los litros vendidos: ";
  cin >> litrosVendidos;

  if(litrosVendidos > 500){
    importeTotal = importeTotal * 0.75;
  }else if(litrosVendidos >= 301){
    importeTotal = importeTotal * 0.85;
  }else if(litrosVendidos >= 101){
    importeTotal = importeTotal * 0.90;
  }

  cout << "El total a pagar es: $" << importeTotal; 

  return 0;
}