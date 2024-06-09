
/*
29
Hacer un programa para ingresar los consumos de electricidad de los clientes
de una empresa. Cada registro contiene los siguientes datos:
- Número de cliente
- Localidad del cliente (1, 2 o 3)
- Kilovatios consumidos

El lote finaliza con un registro con número de cliente igual a cero.
 El precio es escalonado según la siguiente escala:
$ 10 por kilovatio por los primeros 100 kilovatios de consumo.
$ 12 por kilovatio por el consumo de 101 a 200 kilovatios.
$ 15 por kilovatio por el consumo de 201 kilovatios en adelante.

Además hay un cargo fijo de $ 100.
Ejemplo A: Consumo de 55 kilovatios, se calculará: $ 10 x 55 + $ 100= $ 650
Ejemplo B: Consumo de 125 kilovatios, se calculará: $ 10 x 100 + $ 12 x 25 + $ 100=$ 1400
Ejemplo C: Consumo de 250 kilovatios, se calculará: $10 x 100+ $12 x 100 + $15 x 50 + $100= $ 3050
Ejemplo D: Consumo de 0 kilovatios, se calculará: $ 10 x 0 + $ 100= $ 100

Se pide determinar e informar:
a) El número de cliente que tuvo la mayor cantidad de Kilovatios consumidos
para cada una de las 3 localidades. Se listan 3 resultados, uno para cada una de las 3 localidades
b) El total de recaudación para cada una de las 3 localidades. Se listan 3 resultados,
uno para cada una de las 3 localidades
c) El número de cliente que tuvo la menor cantidad de Kilovatios consumidos excluyendo
a los clientes que tuvieron Kilovatios consumidos con valor cero. Se lista 1 resultado.
*/
#include <iostream>
using namespace std;


int main(){
    setlocale(LC_ALL, "Spanish");
    int cliente, localidad, kwConsumidos, precio;
    int clienteMayor1, clienteMayor2, clienteMayor3, clienteMenor;
    int kwMayor1=0, kwMayor2=0,kwMayor3=0, kwMenor;
    int total1=0, total2=0,total3=0;
    bool esMenor=false;

    cout << "Ingrese el número de cliente: ";
    cin >> cliente;

    while (cliente != 0) {
        cout << "Ingrese la localidad (1, 2, o 3): ";
        cin >> localidad;

        cout << "Ingrese los kw consumidos: ";
        cin >> kwConsumidos;

        if (kwConsumidos <= 100) {
            precio = 100 + kwConsumidos * 10;
        } else if (kwConsumidos <= 200) {
            precio = 100 + 100 * 10 + (kwConsumidos - 100) * 12;
        } else {
            precio = 100 + 100 * 10 + 100 * 12 + (kwConsumidos - 200) * 15;
        }

        switch (localidad) {
            case 1:
                if (kwConsumidos > kwMayor1) {
                    kwMayor1 = kwConsumidos;
                    clienteMayor1 = cliente;
                }
                total1 += precio;
                break;
            case 2:
                if (kwConsumidos > kwMayor2) {
                    kwMayor2 = kwConsumidos;
                    clienteMayor2 = cliente;
                }
                total2 += precio;
                break;
            case 3:
                if (kwConsumidos > kwMayor3) {
                    kwMayor3 = kwConsumidos;
                    clienteMayor3 = cliente;
                }
                total3 += precio;
                break;
        }

        if (!esMenor || kwConsumidos < kwMenor) {
            kwMenor = kwConsumidos;
            clienteMenor = cliente;
            esMenor = true;
        }

        cout << "Ingrese el número de cliente: ";
        cin >> cliente;
    }

    cout << "El cliente de mayor consumo de kw para la zona 1 fue el N° " << clienteMayor1 << endl;
    cout << "El cliente de mayor consumo de kw para la zona 2 fue el N° " << clienteMayor2 << endl;
    cout << "El cliente de mayor consumo de kw para la zona 3 fue el N° " << clienteMayor3 << endl;

    cout << "El total recaudado para la zona 1 fue de $ " << total1 << endl;
    cout << "El total recaudado para la zona 2 fue de $ " << total2 << endl;
    cout << "El total recaudado para la zona 3 fue de $ " << total3 << endl;

    cout << "El cliente de menor consumo de kw fue el N° " << clienteMenor << endl;

    return 0;
}
