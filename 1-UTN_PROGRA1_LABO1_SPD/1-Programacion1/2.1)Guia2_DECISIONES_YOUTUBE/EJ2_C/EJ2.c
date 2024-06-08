#include<stdio.h>

/* Hacer un programa para ingresar dos números distintos y luego se muestre por
pantalla el menor de ellos. */

int main(){
	
	int n1, n2;   // Declarar variables sin asignarle valor .... n2 = 10 DECLARAR e INICIALIZAR
	
	printf("Ingrese un numero:");
	scanf("%i", &n1);
	printf("Ingrese otro numero:");
	scanf("%i", &n2);
	
	if(n1 < n2){
		printf("El menor es %i", n1);
	}else{
		printf("El menor es %i", n2);
	}
	
	return 0;
}