#include <iostream>

using namespace std;

/*
Una casa de video juegos otorga un descuento dependiendo del importe de la
compra realizada según los siguientes valores:
• Si el importe es menor a ARS 1000, no hay descuento.
• Si el importe es ARS 1000 o más pero menor a ARS 5000, aplica un
descuento del 10%.
• Si el importe es ARS 5000 o más, aplica un descuento del 18%.
Hacer un programa para ingresar un importe de venta y luego muestre por
pantalla el importe final con el descuento que corresponda.*/

int main(){
  float importe;

  cout << "Ingrese el importe: ";
  cin >> importe;

  if(importe >= 5000)
  {
    //importe = importe * 0.82; 
    importe *= 0.82;
  }
  else
  {
    if(importe < 5000 && importe >= 1000)    
    {
      importe = importe * 0.90; // importe *= 0.90
    }
  }
  cout << "El importa final es: " << importe;

  return 0;
}