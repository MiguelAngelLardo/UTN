/*14 Hacer un programa para ingresar el importe de una compra y el descuento a
aplicar. Listar por pantalla, el importe sin descuento, el descuento aplicado y el
importe total a cobrar.
Ejemplo: se ingresa importe 4500, descuento 40; se deberá mostrar
Importe: 4500, Descuento: 1800, total: 2700.*/

#include <iostream>
using namespace std;

int main(){
    int importe, porcentaje, total, descuento;


    cout << "Ingrese el monto de compra y el porcentaje de descuento a aplicar " << endl;
    cin >> importe >> porcentaje;
    descuento = (porcentaje*importe)/100;
    total = importe - descuento;

    cout <<"Importe Original: $" << importe << endl;
    cout <<"Descuento       : $" << descuento << endl;
    cout << "--------------------------------"<< endl;
    cout <<"Total a Pagar   : $" << total << endl;



return 0;
}
