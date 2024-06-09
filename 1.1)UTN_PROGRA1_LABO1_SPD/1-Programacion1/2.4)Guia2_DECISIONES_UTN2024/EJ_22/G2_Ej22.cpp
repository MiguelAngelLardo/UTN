/*22 Una fábrica de caramelos dispone de un presupuesto inicial para inaugurar su
sucursal en Villa Brian Lara. Se sabe que para producir caramelos tienen los
siguientes costos:
- Costo de alquiler de $100000
- Costo por caramelo producido de $2.50
- Costo por mantenimiento cada 1000 caramelos de $50000
Dados el presupuesto inicial y la cantidad de caramelos a producir el primer
mes, informar:
- "El presupuesto es suficiente para cubrir los costos de $XXXX"
- "El presupuesto no es suficiente, necesita un crédito de $XXXX"*/

#include <iostream>
using namespace std;


int main(){

    int alquiler = 100000, mantenimiento = 50000, presupuesto, cantidadCaramelos, resto;
    float costoCaramelo = 2.5, costoProduccion, costoUnidad;

    cout << "Ingrese el monto de su presupuesto " << endl;
    cin >> presupuesto;
    cout << "Ingrese la cantidad de caramelos a producir el primer mes " << endl;
    cin >> cantidadCaramelos;

    if (cantidadCaramelos > 1000){
            resto = cantidadCaramelos % 1000;

            if( resto!=0){
                mantenimiento = (((cantidadCaramelos-resto)/1000)+1)*5000;
            }else{
                mantenimiento = cantidadCaramelos/1000 * 5000;
            }
    };

    costoProduccion = alquiler + (costoCaramelo*cantidadCaramelos) + mantenimiento;

    if ( presupuesto > costoProduccion){
        cout << "El presupuesto es suficiente para cubrir los costos de $" << costoProduccion << endl;
    }else{
        cout << "El presupuesto no es suficiente, necesita un crédito de $" << costoProduccion - presupuesto << endl;

    }

return 0;
}
