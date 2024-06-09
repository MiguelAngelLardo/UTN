#include<stdio.h>

/* Hacer un programa para ingresar un número y luego se emita un cartel por
pantalla “Positivo” si el número es mayor a cero, “Negativo” si el número es
menor a cero o “Cero” si el número es igual a cero */

int main(){
	int n1;
	printf("Digite un numero:");
	scanf("%i", &n1);
	
	if(n1 > 0){
		printf("Positivo");
	}else if(n1 < 0){
		printf("Negativo");
	}else{
		printf("Es igual a 0");
	}
	
/*	if(n1 > 0 )			
	{
		printf("Positivo");
	}
	else
	{
		if(n1 < 0)
		{
			printf("Negativo");
		}
		else
		{
			printf("Es igual a 0");    
		}
	} */
	
	return 0;
}