/*7
Hacer un programa para ingresar por teclado el importe de una venta y el porcentaje de
descuento aplicada a la misma y luego informar por pantalla el importe a pagar.
Ejemplo A. Si el importe de la venta es $1200 y el descuento es el 15% entonces el total
a pagar será de $1020.
Ejemplo B. Si el importe de la venta es $800 y el descuento es el 0% entonces el total a
pagar será de $800.*/

#include <iostream>

using namespace std;

int main(){
int montoVenta;
float descuento,total;

cout << "Ingrese el monto de venta" << endl;
cin >> montoVenta;

cout << "Ingrese el porcentaje de descuento" << endl;
cin >> descuento;
descuento = descuento/100;
total = montoVenta * (1-descuento);
cout << "El total a pagar es de $" << total << endl;



return 0;
}



