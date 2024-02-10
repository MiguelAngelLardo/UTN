#include<stdio.h>

/*
3. Hacer un programa para ingresar dos números. Si el segundo es distinto de
	cero, calcular la división del primero por el segundo y mostrar el resultado por
	pantalla; caso contrario, emitir un cartel aclarando que no se puede dividir por
	cero.	
*/

int main(){

	int n1, n2, resultado;
	printf("Ingrese dos numeros:\n");
	scanf("%i %i", &n1, &n2); 	
	
	//!= DISTINTO 
	if(n2 != 0 ){
		resultado = n1 / n2;
		printf("El resultado es: %i", resultado);
	}else{
		printf("No se puede dividir por cero");
	}
	
	return 0;
}