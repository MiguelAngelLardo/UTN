/*
Problema 4
Igual al Problema 3 pero el dueño del comercio decidió hacer una rifa de una notebook para
quienes hayan comprado en su negocio. Otorgará una serie de números para el sorteo a
partir de la siguientes condiciones:

Importe de la venta 	Cantidad de números para el sorteo
Entre $100 y $1000 		         	1
Mayor a $1000 y hasta $2500 		2
Mayor a $2500 y hasta $7500 		5
Mayor a $7500 				          10

La salida por pantalla debe mostrar el nombre del artículo, el subtotal de la compra y el total
de la compra (incluyendo el descuento o recargo aplicado si corresponde). También debe
mostrar la cantidad de números para el sorteo obtenidos



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
    int numerosSorteo = 0;

    //PROCESO
    subtotal = precio * cantidad;

    switch(fp)
    {
    case 'E':
	  case 'e':
        formaPago = "Efectivo";
        total = subtotal * 0.85f;
        if (subtotal >= 100 && subtotal <= 1000) {
            numerosSorteo = 1;
        } else if (subtotal > 1000 && subtotal <= 2500) {
            numerosSorteo = 2;
        } else if (subtotal > 2500 && subtotal <= 7500) {
            numerosSorteo = 5;
        } else if (subtotal > 7500) {
            numerosSorteo = 10;
        }
        break;
    case 'Q':
	case 'q':
        formaPago = "QR";
        total = subtotal * 0.95f;
        if (subtotal >= 100 && subtotal <= 1000) {
            numerosSorteo = 1;
        } else if (subtotal > 1000 && subtotal <= 2500) {
            numerosSorteo = 2;
        } else if (subtotal > 2500 && subtotal <= 7500) {
            numerosSorteo = 5;
        } else if (subtotal > 7500) {
            numerosSorteo = 10;
        }
        break;
    case 'T':
	  case 't':
        formaPago = "Tarjeta";
        total = subtotal * 1.1f;
		    if (subtotal >= 100 && subtotal <= 1000) {
            numerosSorteo = 1;
        } else if (subtotal > 1000 && subtotal <= 2500) {
            numerosSorteo = 2;
        } else if (subtotal > 2500 && subtotal <= 7500) {
            numerosSorteo = 5;
        } else if (subtotal > 7500) {
            numerosSorteo = 10;
        }
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
    cout << "Numeros para el sorteo: " << numerosSorteo << endl;
    cout << endl;
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