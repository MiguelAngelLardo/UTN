/*
Una empresa que vende insumos informáticos posee varias sucursales
en el país. La misma desea conocer información acerca de las ventas
para cada una de sus treinta sucursales. Para cada registro de venta
posee la siguiente información:
- Código de sucursal
- Importe de la venta
- Forma de pago de la venta ('E' – Efectivo ó 'T' - Tarjeta)
La información se encuentra agrupada (no ordenada) por código de
sucursal y el lote de datos se finaliza ingresando un código de sucursal
igual a cero. Se pide informar:
A) El total facturado por cada sucursal.
B) La cantidad de ventas para cada sucursal.
C) El porcentaje de cantidad de ventas por forma de pago (entre todas
las sucursales).
*/
#include <iostream>
using namespace std;

int main(){
  int cSuc, cSucAnt;
  //
  float importe;
  char formaPago;
  //PUNTO A
  float totalFacturado;
  //PUNTO B
  int cantVentas;
  //PUNTO C
  int cantE, cantT;
  cantE=cantT=0;

  cout << "INGRESAR CODIGO DE SUCURSAL: ";
  cin >> cSuc;

  while(cSuc != 0){
    //PUNTO A
    totalFacturado = 0.0;
    //PUNTO B
    cantVentas = 0;

    cSucAnt = cSuc;
      while(cSucAnt == cSuc){
        cout << "IMPORTE: ";
        cin >> importe;
        cout << "FORMA DE PAGO: ";
        cin >> formaPago;
				//PROCESAR PUNTO A
				totalFacturado += importe;
				//PROCESAR PUNTO B
				cantVentas++;
				//PROCESAR PUNTO C
				if(formaPago=='E' || formaPago=='e'){
				  cantE++;
				}
				else if(formaPago=='T' || formaPago == 't'){
				  cantT++;
				}
        cout << "INGRESAR CODIGO DE SUCURSAL: ";
        cin >> cSuc;
      }
    //LISTAR PUNTO A
    cout << endl << "PUNTO A: TOTAL FACTURADO SUCURSAL " << cSucAnt << " : " << totalFacturado << endl;
    //LISTAR PUNTO B
    cout << endl << "PUNTO B: TOTAL VENTAS SUCURSAL    " << cSucAnt << " : " << cantVentas << endl;
  }
  //PROCESAR PUNTO C
  int totalVentas = cantE + cantT;
  //LISTAR PUNTO C
  if(totalVentas > 0){
    cout << "PUNTO C: PORCENTAJE DE FORMA DE PAGO" << endl << endl;
    cout << "EFECTIVO: " << (float) cantE/totalVentas*100 << "%" << endl;
    cout << "TARJETA : " << (float) cantT/totalVentas*100 << "%" << endl;
  }
  return 0;
}