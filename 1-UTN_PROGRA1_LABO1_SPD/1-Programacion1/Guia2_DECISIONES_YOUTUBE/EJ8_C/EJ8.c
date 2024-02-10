#include<stdio.h>
/*
	Hacer un programa para ingresar cuatro números distintos y luego mostrar por
	pantalla el menor de ellos.
*/

int main(){
	
	int n1, n2, n3, n4, menor;
	
	printf("Ingrese 4 numeros:\n");
	scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
	
	if(n1 < n2){
		menor = n1;
	}else{
		menor = n2;
	}
	
	if(n3 < menor){
		menor = n3;
	}
	
	if(n4 < menor){
		menor = n4;
	}
	
	printf("El menor es: %i", menor);
	
	return 0;
}