#include <iostream>

using namespace std;
/*
1) Una empresa vende 5 diferentes tipos de artículos en 3 sucursales. 
Por cada venta que
realiza, se anotaron los siguientes datos:

- Nro. de artículo (1 a 5)
- Nro. de sucursal (1 a 3)
- Cantidad vendida

Este lote finaliza con un registro con nro. de artículo igual a cero. 
Puede haber más de un registro para el mismo artículo en la misma sucursal. Se desea determinar e
informar:

a) Un listado con la cantidad de artículos vendidos en cada sucursal, 
con el siguiente
formato:
             Sucursal 1 Sucursal 2  Sucursal 3
Artículo 1     X x x    xxxxx       xxxx
Artículo 2     X x x    xxxxx       xxxx
Artículo 5

b) Informar cual fue el nro. de artículo más vendido en total en cada una de las tres
sucursales.
*/

int main (){
  int mArticuloSucursal[5][3] = {};
  int articulo, sucursal, cantidadVendida;

  cout << "Ingrese el articulo(1 a 5): ";
  cin >> articulo;
  while (articulo != 0){
    cout << "Ingrese la sucursal(1 a 3): ";
    cin >> sucursal;
    cout << "Ingrese la  cantidad vendida: ";
    cin >> cantidadVendida;

    mArticuloSucursal[articulo-1][sucursal-1] += cantidadVendida;

    cout << "Ingrese el articulo(1 a 5): ";
    cin >> articulo;
  }

  cout << endl << "PUNTO A" << endl;
  cout << "               Sucursal 1  Sucursal 2  Sucursal 3" << endl;

  for(int i = 0; i < 5; i ++){
    cout << "ARTICULO " << i+1;
    for(int j = 0; j < 3; j++){
      cout << "          " << mArticuloSucursal[i][j];
    }
    cout << endl;
  }

  cout << endl << "PUNTO B " << endl;
  int maxCantArtVendido = 0, acumArticulo, maxNumeroArtVendido;
  for(int i = 0; i < 5; i ++){
    acumArticulo = 0;
    for(int j = 0; j < 3; j++){
      acumArticulo += mArticuloSucursal[i][j];
    }
    if(maxCantArtVendido == 0){
      maxCantArtVendido = acumArticulo;
      maxNumeroArtVendido = i + 1;
    }else if(acumArticulo > maxCantArtVendido){
      maxCantArtVendido = acumArticulo;
      maxNumeroArtVendido = i + 1;
    }  
  }
  cout << "EL numero de articulo con mas ventas es: " << maxNumeroArtVendido;

  



  return 0;
}