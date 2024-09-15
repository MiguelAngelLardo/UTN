#include <iostream>
using namespace std;
/*Unafábrica de caramelos dispone de un presupuesto inicial para inaugurar su
 sucursal en Villa Brian Lara. Se sabe que para producir caramelos tienen los
 siguientes costos:--

Costo de alquiler de $100000
Costo por caramelo producido de $2.50
Costo por mantenimiento cada 1000 caramelos de $50000


 Dados el presupuesto inicial y la cantidad de caramelos a producir el primer
 mes, informar:--
 "El presupuesto es suficiente para cubrir los costos de $XXXX"
 "El presupuesto no es suficiente, necesita un crédito de $XXXX"*/
 
const int TAM_COSTO_ALQUILER = 100000;
const float TAM_COSTO_CARAMELO_PRODUCIDO = 2.50;
const int TAM_COSTO_MANTENIMIETO_1000Caramelos = 50000; 

int main (){
  float presupuestoInicial, presupuestoFinal, costoTotal;
  int cantCaramelosProducidos;

  cout << "Ingrese el presupuesto inicial: ";
  cin >> presupuestoInicial;
  presupuestoFinal = presupuestoInicial;

  cout << "Ingrese la cantidad de caramelos a producir en el primer mes: ";
  cin >> cantCaramelosProducidos;
  
  presupuestoFinal -= (TAM_COSTO_ALQUILER) + (cantCaramelosProducidos * TAM_COSTO_CARAMELO_PRODUCIDO);
  

  int contMantenimientoCada1000;//creo una variable para saber cuantas veces tengo 1000 caramelos => 2560 caramelos => tendre 2 veces 1000 => 2000 => 2 veces restar 50.000
  if (cantCaramelosProducidos > 1000){
    contMantenimientoCada1000 = cantCaramelosProducidos / 1000;
    presupuestoFinal -= contMantenimientoCada1000 * TAM_COSTO_MANTENIMIETO_1000Caramelos;
  }
                   
  costoTotal = presupuestoInicial - presupuestoFinal;

  if(presupuestoFinal >= 0){
    cout << "El presupuesto de $ " << presupuestoInicial << " es suficiente para cubrir los costos de $" << costoTotal;
  }else{
    cout << "El presupuesto de $ " << presupuestoInicial << " no es suficiente para cubrir los costos, Necesita un credito de $ " << presupuestoFinal*-1;//-2000 * -1 = 2000
  }



  return 0;
}