#include<stdio.h>

/*
	Hacer un programa que solicite cuatro números y emitir un cartel aclaratorio si
	son todos iguales entre sí, caso contrario, no emitir nada.
*/

int main(){
	
	int n1, n2, n3 , n4;
	printf("Digite cuatro numeros:\n");
	scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
	
	(n1 == n2 && n2 == n3 && n3 == n4) ? printf("Son todos iguales"): printf("No son iguales");
	
	return 0;
}