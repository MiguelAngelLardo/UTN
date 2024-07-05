#include<stdio.h>
/*
	Hacer un programa para ingresar cuatro números distintos y luego mostrar por
	pantalla el mayor de ellos.
*/
int main(){
	int n1, n2, n3, n4, mayor;
	printf("Ingrese cuatro numeros:\n");
	scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
	
	if(n1 > n2 ){
		mayor = n1;
	}else{
		mayor = n2;
	}
	
	if(n3 > mayor){
		mayor = n3;
	}
	
	if(n4 > mayor){
		mayor = n4;
	}
	
	printf("El mayor es: %i", mayor);
	
	return 0;
}