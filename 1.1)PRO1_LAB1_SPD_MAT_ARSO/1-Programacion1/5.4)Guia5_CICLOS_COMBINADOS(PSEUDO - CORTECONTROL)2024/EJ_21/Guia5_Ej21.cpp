/*
21 Una casa de ventas de libros con varias sucursales registró las ventas durante
el mes anterior en un lote de registros. Para cada venta se registraron los
siguientes datos:
● Sucursal de la venta (1 a 20)
● Número del vendedor que efectuó la venta (1 a 150)
● Día de la venta (1 a 31)
● Importe de la venta
● Tipo de Cliente ("U"= Universitario, "N"= No Universitario )
El lote finaliza con un registro con importe igual a cero. Los datos se ingresan
agrupados por sucursal.
A partir de esta información se pide determinar e informar:
a) La comisión total pagada a todos los vendedores en el mes para cada
sucursal.
Considerar que la comisión es un 10% cuando el tipo de cliente es
universitario y un 20% cuando no lo es.
b) La cantidad total vendida de libros por cada sucursal.
c) El número de vendedor que haya efectuado la venta individual de mayor
importe, informando en qué sucursal trabaja y el día en que se realizó esa
venta. Se esperan los datos de un único vendedor.
d) El promedio de recaudación por sucursal para la segunda quincena para los
clientes No Universitarios.
e) El porcentaje de ventas total discriminado por clientes Universitarios y No
Universitarios
*/


#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Spanish");

    int sucursal, importe, vendedor, dia, sucAnterior;
    char tipoCliente;

    // Variables Pto A
    float comisionTotal;

    // Variable Pto B
    int cantidadTotal;

    // Variables Pto C
    int ventaMayor = 0, vendedorMayor = 0, diaMayor, sucMayor;

    // Variables Pto D
    int totalVentas2QuincenaNoU, totalImporte2QuincenaNoU;

    // Variables Pto E
    int totalVentasU = 0, totalVentasN = 0;

    cout << "Ingrese la sucursal (1 a 20): ";
    cin >> sucursal;
    cout << "Ingrese el importe de la venta (0 para terminar): $";
    cin >> importe;

    while (importe != 0) {
        sucAnterior = sucursal;

        // Reinicio Variables de grupo
        comisionTotal = 0.0;
        cantidadTotal = 0;
        totalVentas2QuincenaNoU = totalImporte2QuincenaNoU=0;

        while (sucAnterior == sucursal && importe != 0) {
            cout << "Ingrese el Número del vendedor que efectuó la venta (1 a 150): ";
            cin >> vendedor;
            cout << "Ingrese el Día de la venta (1 a 31): ";
            cin >> dia;
            cout << "Ingrese el Tipo de Cliente (U= Universitario, N= No Universitario): ";
            cin >> tipoCliente;

            // Punto A
            switch (tipoCliente) {
                case 'U':
                    comisionTotal += importe * 0.10;
                    totalVentasU += importe;
                    break;
                case 'N':
                    comisionTotal += importe * 0.20;
                    totalVentasN += importe;
                    break;
                default:
                    cout << "Tipo de cliente no válido." << endl;
                    break;
            }

            // Punto B
            cantidadTotal += importe;

            // Punto C
            if (importe > ventaMayor) {
                ventaMayor = importe;
                vendedorMayor = vendedor;
                diaMayor = dia;
                sucMayor = sucAnterior;
            }

            // Punto D
            if (dia > 15 && tipoCliente == 'N') {
                totalVentas2QuincenaNoU++;
                totalImporte2QuincenaNoU += importe;
            }

            cout << "Ingrese la sucursal (1 a 20): ";
            cin >> sucursal;
            cout << "Ingrese el importe de la venta (0 para terminar): $";
            cin >> importe;
        }

        // Mostrar punto A
        cout << "--------------------------------------------------------" << endl;
        cout << "Sucursal " << sucAnterior << endl;
        cout << "Comisión total pagada a todos los vendedores: $" << comisionTotal << endl;

        // Mostrar punto B
        cout << "Cantidad total vendida de libros: $" << cantidadTotal << endl;
    }

    // Mostrar punto C
    cout << "El vendedor N° " << vendedorMayor << " de la sucursal " << sucMayor << endl;
    cout << "realizó la venta de mayor importe de $" << ventaMayor << " el día " << diaMayor << endl;

    // Mostrar punto D
    if (totalVentas2QuincenaNoU > 0) {
        cout << "El promedio de recaudación por sucursal en la segunda quincena para los clientes No Universitarios es: $"
             << (totalImporte2QuincenaNoU / totalVentas2QuincenaNoU) << endl;
    } else {
        cout << "No hubo ventas a clientes No Universitarios en la segunda quincena." << endl;
    }

    // Mostrar punto E
    int totalVentas = totalVentasU + totalVentasN;
    if (totalVentas > 0) {
        cout << "Porcentaje de ventas a clientes Universitarios: " << (totalVentasU * 100.0 / totalVentas) << "%" << endl;
        cout << "Porcentaje de ventas a clientes No Universitarios: " << (totalVentasN * 100.0 / totalVentas) << "%" << endl;
    } else {
        cout << "No hubo ventas en el mes." << endl;
    }

    return 0;
}

