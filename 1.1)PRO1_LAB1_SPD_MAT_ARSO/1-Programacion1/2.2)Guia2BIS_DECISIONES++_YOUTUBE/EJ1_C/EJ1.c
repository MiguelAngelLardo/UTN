#include<stdio.h>

/*
	1. Hacer un programa que solicite el ingreso de un número y que luego emita un
	cartel por pantalla aclarando si el mismo es múltiplo de 5.
*/

int main(){
	int n1;
	printf("Ingrese un numero:\n");
	scanf("%i", &n1);
	
	/*if(n1 % 5 == 0 ){
		printf("Es multiplo\n");
	}*/

	(n1 % 5 == 0) ? printf("Es multiplo\n") : printf("No es multiplo\n");

	return 0;
}