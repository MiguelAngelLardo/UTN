#include<stdio.h>

/* Una casa de video juegos otorga un descuento dependiendo del importe de la
compra realizada según los siguientes valores:
• Si el importe es menor a ARS 1000, no hay descuento.
• Si el importe es ARS 1000 o más pero menor a ARS 5000, aplica un
descuento del 10%.
• Si el importe es ARS 5000 o más, aplica un descuento del 18%.
Hacer un programa para ingresar un importe de venta y luego muestre por
pantalla el importe final con el descuento que corresponda. */

int main(){
	float importe;
	printf("Ingrese el importe:");
	scanf("%f", &importe);
	
	if(importe < 1000){
		printf("No hay descuento");                  
	}else if(importe >= 1000 && importe < 5000){
    //descuento = importe * 0.90; // 1050 * 0.90 = ESTOY a 1050 RESTANDOLE el 10
    importe = importe * 0.90; // SINONIMO importe *= 0.90; 
	}else{
    importe = importe * 0.82; // SINONIMO importe *= 0.82; 
  }
	
  printf("El importe total a pagar es: %.2f", importe);
	
	return 0;
}