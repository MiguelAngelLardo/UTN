/*8 Hacer un programa para ingresar por teclado el importe de una venta sin el
descuento y el importe de esa misma venta con el descuento aplicado y luego
informar por pantalla el porcentaje de descuento aplicada a la misma.
Ejemplo A. Si el importe de la venta sin descuento es $1500 y el importe de la
venta con descuento es $1200 entonces el porcentaje de descuento aplicado
fue el 20%.*/


#include <iostream>
using namespace std;

int main(){

float venta, ventaDcto, descuento;

cout << "Ingrese el importe de venta" << endl;
cin >> venta;

cout <<"Ingrese el importe de venta con descuento" << endl;
cin >> ventaDcto;

descuento = (1-(ventaDcto/venta))*100;

cout << "El porcentaje de descuento es : " << descuento << "%";



return 0;
}
