#include<stdio.h>

/*
2. Hacer un programa que solicite el ingreso de dos números y luego calcular:
	a. La resta si el primero es mayor que el segundo.
	b. La suma si son iguales.
	c. El producto si el primero es menor.
	Se deberá emitir un cartel por pantalla con el resultado correspondiente.	
*/

int main(){
	
	int n1, n2, resultado;
	printf("Ingrese dos numeros:\n");
	scanf("%i %i", &n1, &n2);
	
	if(n1 > n2){
		resultado = n1 - n2;
	}else if(n1 == n2){
		resultado = n1 + n2;
	}else{
		resultado = n1 * n2;
	}
	printf("El resultado es: %i", resultado);
	
	return 0;
}