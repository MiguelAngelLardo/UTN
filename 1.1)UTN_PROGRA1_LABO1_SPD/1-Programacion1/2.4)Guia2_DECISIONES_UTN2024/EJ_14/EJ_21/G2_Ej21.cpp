/*21 Una marroquinería dispone de 45 carteras blancas, 50 carteras negras, 40
marrones y 49 grises. Se pide hacer un programa donde se ingresen tres
ventas. Cada venta está compuesta por:
- Cantidad de carteras
- Tipo de cartera (1 - Blanco, 2 - Negro, 3- Marrón, 4 - Gris)
Calcular e informar:
A- Cantidad total de carteras vendidas en total.
B- Cuántas carteras quedaron de cada tipo.
C- Los colores de carteras que no se vendieron.
NOTA: Ninguna venta superará las 10 carteras.*/

#include <iostream>
using namespace std;


int main(){
    int cBlancas = 45, cNegras = 50, cMarrones = 40, cGrises = 49,cantidadVenta1,cantidadVenta2,cantidadVenta3;
    int carteraVenta1, carteraVenta2, carteraVenta3, ventasTotales;
    string color;
    cout << "-----------------------------------------------------------" << endl;
    cout << "                      VENTA 1                       " << endl;
    cout << " Cantidad vendida =                                 ";
    cin >> cantidadVenta1;
    cout << " Tipo de cartera (1-Blanco,2-Negro,3-Marron,4-Gris) ";
    cin >> carteraVenta1;
    cout << "-----------------------------------------------------------" << endl;
    cout << "                      VENTA 2                       " << endl;
    cout << " Cantidad vendida =                                 ";
    cin >> cantidadVenta2;
    cout << " Tipo de cartera (1-Blanco,2-Negro,3-Marron,4-Gris) ";
    cin >> carteraVenta2;
    cout << "------------------------------------------------------------" << endl;
    cout << "                      VENTA 3                       " << endl;
    cout << " Cantidad vendida =                                 ";
    cin >> cantidadVenta3;
    cout << " Tipo de cartera (1-Blanco,2-Negro,3-Marron,4-Gris) ";
    cin >> carteraVenta3;
    cout << "------------------------------------------------------------" << endl;

    //PUNTO A
    ventasTotales = cantidadVenta1 + cantidadVenta2 + cantidadVenta3;
     cout << " Ventas totales =                                  " << ventasTotales << " U " << endl;
     cout << "-----------------------------------------------------------" << endl;

    //PUNTO B
    switch (carteraVenta1){
    case 1:
        cBlancas -= cantidadVenta1;
        break;
    case 2:
        cNegras -=cantidadVenta1;
         break;
    case 3:
        cMarrones -= cantidadVenta1;
         break;
    case 4:
        cGrises -= cantidadVenta1;
         break;
    };

       switch (carteraVenta2){
    case 1:
        cBlancas -= cantidadVenta2;
         break;
    case 2:
        cNegras -=cantidadVenta2;
         break;
    case 3:
        cMarrones -= cantidadVenta2;
         break;
    case 4:
        cGrises -= cantidadVenta2;
         break;
    };

       switch (carteraVenta3){
    case 1:
        cBlancas -= cantidadVenta3;
         break;
    case 2:
        cNegras -=cantidadVenta3;
         break;
    case 3:
        cMarrones -= cantidadVenta3;
         break;
    case 4:
        cGrises -= cantidadVenta3;
         break;
    };

    //PUNTO C
    if(cBlancas == 45){
        cout << "No se vendieron carteras de color Blanco" << endl;
    }else{
    cout << "Carteras Blancas restantes  =                       " << cBlancas << " U " << endl;
    };
    if(cNegras == 50){
        cout << "No se vendieron carteras de color Negro" << endl;
    }else{
    cout << "Carteras Negras restantes   =                       " << cNegras << " U " << endl;
    };
    if(cMarrones == 40){
        cout << "No se vendieron carteras de color Marron" << endl;
    }else{
    cout << "Carteras Marrones restantes =                       " << cMarrones << " U " << endl;
    };
    if(cGrises == 49){
        cout << "No se vendieron carteras de color Gris" << endl;
    }else{
    cout << "Carteras Grises restantes   =                       " << cGrises << " U " << endl;
    };




return 0;
}
