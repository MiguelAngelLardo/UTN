#include <iostream>

using namespace std;

/*
8. El negocio de desinfectante antes mencionado vende además detergente
suelto, y los precios se aplican según la siguiente escala:
a. 25 ARS por litro los primeros 50 litros.
b. 20 ARS por litro si la venta es de 51 a 200 litros.
c. 15 ARS por litro si la venta es de 201 a 500 litros.
d. 10 ARS por litro si la venta es de más de 500 litros.
Además, si paga en efectivo, tiene un adicional del 10% sobre el importe final.
Hacer un programa que solicite la cantidad de litros vendidos y el tipo de pago
(ingresará 1 si paga en efectivo y 0 con cualquier otro medio de pago)*/

int main(){
  float importe;
  int litros;
  bool modoPago; //1 = TRUE - 0 = FALSE

  cout << "Ingrese los litros a cargar: ";
  cin >> litros;
  cout << "Paga con efectivo o con otro medio (1) efectivo - 0) Otro Medio): ";
  cin >> modoPago;

  if(litros > 500){
    importe = litros * 10;
  }else if(litros > 200){
    importe = litros * 15;
  }else if(litros > 50){
    importe = litros * 20;
  }else{
    importe = litros * 25;
  }

  //if(TRUE)

  /*if(modoPago){ //modoPago == 1
    importe = importe * 0.90;
  }else{
    importe = importe;
  }*/

  //operador ternario => SOLO FUNCIONA cuando tengo UNA CONDICION para el IF y UNA CONDICION para el FALSE 
  //AHORRO LINEAS DE CODIGO PERO LA RESULTANTE ES EXACTAMENTE IGUAL QUE IF - ELSE NORMALITO
  importe = (modoPago) ? importe * 0.90 : importe;

  cout << "Importe total a pagar: $" << importe;

  return 0;
}