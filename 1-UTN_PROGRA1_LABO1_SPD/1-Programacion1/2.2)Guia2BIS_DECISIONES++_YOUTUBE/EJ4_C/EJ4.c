#include<stdio.h>

/*
	4. Un importante negocio de desinfectante líquido realiza descuentos
	dependiendo de la cantidad de litros vendidos según la siguiente escala:

	a. Si vende menos de 100 litros, no hay descuento.
	b. Si vende entre 101 y 300 litros, el descuento es del 10%.
	c. Si vende entre 301 y 500 litros, el descuento es del 15%.
	d. Finalmente, si la venta es de más de 500 litros, el descuento es del 25%.

	Hacer un programa que solicite el ingreso del importe total de la venta y la
	cantidad de litros vendidos y calcule y emita el importe con el descuento
	aplicado.
*/

int main(){
	int litros;
	float importe;
  
	printf("Ingrese el importe:\n");
	scanf("%f", &importe);
	printf("Ingrese los litros:\n");
	scanf("%i", &litros);
	
	if(litros > 500){
		importe = importe * 0.75; //importe *= 0.75
	}else if(litros > 300){
		importe *= 0.85;
	}else if(litros > 100){
		importe *= 0.90;
	}

	printf("El importe a pagar es: $%.2f", importe);
	return 0;
}