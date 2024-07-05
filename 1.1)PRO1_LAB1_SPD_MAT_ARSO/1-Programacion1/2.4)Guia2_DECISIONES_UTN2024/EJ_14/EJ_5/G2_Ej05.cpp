/*4 Un negocio de perfumería efectúa descuentos según el importe de la venta.
Si el importe es menor a $100 aplicar un descuento del 5%
Si el importe es entre $100 y hasta $500 aplicar un descuento del 10%
Si el importe es mayor a $500 aplicar un descuento del 15%
Hacer un programa donde se ingresa el importe original sin descuento y se
informe por pantalla el importe con el descuento ya aplicado.
Importante: Verifique que el programa emita UN SOLO CARTEL.*/


#include <iostream>
using namespace std;

int main(){
float imVenta, imPagar;
int descuento;

cout << "Ingrese el importe de venta" << endl;
cin >> imVenta;
if(imVenta < 100){
    descuento = imVenta * 0.05;
}else if(imVenta > 500){
      descuento = imVenta * 0.15;
    }else{
      descuento = imVenta * 0.10;
    };
 imPagar = imVenta - descuento;

cout << "---------------------------------" << endl;
cout << "Importe de venta     : $"<< imVenta << endl;
cout << "Importe de descuento : $"<< descuento << endl;
cout << "---------------------------------" << endl;
cout << "Total a pagar        : $"<< imPagar << endl;


return 0;
}
