#include<stdio.h>


/*
	Hacer un programa para ingresar 4 números. Luego analizar e informar por
	pantalla si los mismos se encuentran ordenados de forma decreciente.
*/

int main(){
	
	int n1, n2, n3, n4;
	printf("Ingrese 4 numeros:\n");
	scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
	
	/* if(n1 > n2 && n2 > n3 && n3 > n4){
		printf("Ordenado");
	}else{
		printf("Desordenado");
	} */

	(n1 > n2 && n2 > n3 && n3 > n4) ? printf("Ordenado") : printf("Desordenado");
	
	return 0;
}