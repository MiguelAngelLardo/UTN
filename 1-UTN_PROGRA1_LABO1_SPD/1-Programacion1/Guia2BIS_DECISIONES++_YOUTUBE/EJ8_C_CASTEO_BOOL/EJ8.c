#include<stdio.h> 
#include <stdbool.h> //LIBRERIA

/*
8. El negocio de desinfectante antes mencionado vende además detergente
	suelto, y los precios se aplican según la siguiente escala:
	
	a. 25 ARS por litro los primeros 50 litros.
	b. 20 ARS por litro si la venta es de 51 a 200 litros.
	c. 15 ARS por litro si la venta es de 201 a 500 litros.
	d. 10 ARS por litro si la venta es de más de 500 litros.
	
	Además, si paga en efectivo, tiene un adicional del 10% sobre el importe final.
	Hacer un programa que solicite la cantidad de litros vendidos y el tipo de pago
	(ingresará 1 si paga en efectivo y 0 con cualquier otro medio de pago)
*/

int main(){
	
	int litros;
	float importe;
	int tipoPago; // 1 = true 0 = false

	/*
	en c ++ 
	bool bandera = true es igual a decir bool bandera = 1
	En C no sucede eso
	*/
	
	printf("Ingrese la cantidad de litros:\n");
	scanf("%i", &litros);
	printf("Paga con efectivo o con otro medio (1) efectivo - 0) Otro Medio): \n");
	scanf("%d", &tipoPago);
	
	if(litros > 500){
		importe = litros * 10.0f;
	}else if(litros > 200){
		importe = litros * 15.0f;
	}else if(litros > 50){
		importe = litros * 20.0f;
	}else{
		importe = litros * 25.0f;
	}

  //PRIMER FORMA
  /*if(tipoPago == 1) { // TRUE
    importe = importe * 0.90;
  }else{
    importe = importe;
  }*/

  //SEGUNDA FORMA
  /*if(tipoPago) { // tipoPago == 1
    importe = importe * 0.90;
  }else{
    importe = importe;
  }*/
                                                              
  //TERCER FORMA => TERNARIO                    
  importe = (tipoPago) ?  importe * 0.90 : importe;

  printf ("EL importe final es $%.2f", importe);
	
	return 0;
}