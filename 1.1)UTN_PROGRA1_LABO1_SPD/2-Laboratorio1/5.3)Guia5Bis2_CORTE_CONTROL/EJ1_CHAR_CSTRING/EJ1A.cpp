#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main(){
  int codigoSucursal, codigoSucursalAnterior;
  float importe;
  char formaPago;
  float totalFacturadoPorSucursal; //A)
  int cantidadVentasPorSucursal; //B)
  int contadorEfectivo, contadorTarjeta; // C)
	contadorEfectivo = contadorTarjeta = 0; //C)

  cout << "Ingrese el codigo de sucursal (Corta con cero): ";
  cin >> codigoSucursal;
  
  while(codigoSucursal != 0)
  {
    totalFacturadoPorSucursal = 0.0; //A)
    cantidadVentasPorSucursal = 0;//B)
    
    codigoSucursalAnterior = codigoSucursal;
    while(codigoSucursalAnterior == codigoSucursal)
    {	
    //PROCESAR-LISTAR DATOS DE CADA VENTA
      cout << "Ingrese el importe de la venta: ";
      cin >> importe;
      cout << "Ingrese la forma de pego (E efectivo - T tarjeta): ";
      cin >> formaPago;

      totalFacturadoPorSucursal += importe; // PROCESAR A
      cantidadVentasPorSucursal ++; //PROCESAR B

	      if(formaPago == 'E'){ // PROCESAR C
        contadorEfectivo ++;
      }else if (formaPago == 'T'){
        contadorTarjeta ++;
      }

       cout << "Ingrese el codigo de sucursal (Corta con cero): ";
       cin >> codigoSucursal;
        
      }

    //LISTAR DATOS DE CADA SUCURSAL => A y B
      cout << "La sucursal " << codigoSucursalAnterior << " facturo $" << totalFacturadoPorSucursal << endl;
      cout << "Cantidad de ventas #" << cantidadVentasPorSucursal << endl << endl;
  }

//LISTAR DATOS GLOBALES => C
  cout << endl << "Porcentaje de ventas por EFECTIVO: %" << fixed << setprecision(2) << (float)contadorEfectivo * 100 / (contadorEfectivo + contadorTarjeta) << endl; 
  cout << "Porcentaje de ventas por TARJETA: %" << fixed << setprecision(2) << (float)contadorTarjeta * 100 / (contadorEfectivo + contadorTarjeta) << endl; 

  return 0;
}