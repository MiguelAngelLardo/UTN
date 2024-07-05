/*
Un comercio solicita hacer un programa que permita ingresar el nombre de un artículo, su precio unitario y la cantidad de unidades vendidas (entero).

Además, el programa debe poder calcular e informar una serie de descuentos y recargos que dependen de la Forma de Pago:

E : Efectivo (Aplica un 15% de descuento al total de la compra)
Q : QR (Aplica un 5% de descuento al total de la compra)
T : Tarjeta (Aplica un 10% de recargo al total de la compra)

La salida por pantalla debe mostrar el nombre del artículo, el subtotal de la compra, la forma
de pago y el total de la compra (incluyendo el descuento o recargo aplicado si corresponde).
Si abonó en efectivo, informar también el vuelto que debe otorgarse al cliente, si es que debe hacerlo.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //DATOS DE ENTRADA
    string nombreArt;
    float precio, pago;
    int cantidad;
    char fp;

    cout << "INGRESAR: " << endl;
    cout << "Nombre del articulo: ";
    cin >> nombreArt;
    cout << "Precio unitario: ";
    cin >> precio;
    cout << "Cantidad de unidades vendidas: ";
    cin >> cantidad;
    cout << "Forma de pago (E-Efectivo, Q-QR, T-Tarjeta): ";
    cin >> fp;

    /*
    if(fp == 'E')
    {
        cout << "Con cuanto abona: $";
        cin >> pago;
    }
    */

    //VARIABLES AUXILIARES
    string formaPago;
    float subtotal, total, vuelto = 0;

    //PROCESO
    subtotal = precio * cantidad;

    switch(fp)
    {
    case 'E':
	case 'e':
        formaPago = "Efectivo";
        total = subtotal * 0.85f;
        //cout << "El total es de: $" << total << endl;
        //cout << "Con cuanto abona? ";
        //cin >> pago;
        //vuelto = pago - total;
        break;
    case 'Q':
	case 'q':
        formaPago = "QR";
        total = subtotal * 0.95f;
        //total = subtotal - (subtotal * 5 / 100);
        break;
    case 'T':
	case 't':
        formaPago = "Tarjeta";
        total = subtotal * 1.1f;
		//total = subtotal + (subtotal * 10 / 100);
        break;
    default:
        cout << "No se ha ingresado una forma de pago valida" << endl;
        break;
    }

    //INFORMACION DE SALIDA
    cout << endl;
    cout << "Nombre del articulo: " << nombreArt << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Forma de pago: " << formaPago << endl;
    cout << "Total: $" << total << endl;
	cout << endl;
	
    if(fp == 'E')
    {
        cout << "Con cuanto abona: $";
        cin >> pago;
        vuelto = pago - total;
    }

    if(vuelto > 0)
    {
        cout << "Su vuelto es: $" << fixed << setprecision(2) << vuelto << endl;
    }
    else if(vuelto < 0)
    {
        cout << "Falta abonar: $" << fixed << setprecision(2) << vuelto * (-1) << endl;
    }

    return 0;
}