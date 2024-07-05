#include<stdio.h>

/*
	5. Hacer un programa que solicite el ingreso de las notas del primer parcial y del
	segundo parcial de una alumna de programación. El programa deberá analizar
	las notas y emitir la situación de la alumna según la siguiente escala:

	a. Si tiene 8 o más en ambos parciales, emitir “aprobación directa”.
	b. Si no tiene 8 o más en ambos pero tiene aprobados ambos parciales (se
	aprueba con 6 o más), emitir “rinde examen final”.
	c. Si tiene menos de 6 en alguno de los dos parciales, emitir “debe
	recuperar”.

	El programa debe emitir solo un cartel, el que corresponda.
*/

int main(){
	int n1, n2;
	printf("Ingrese las notas:\n");
	scanf("%i %i", &n1, &n2);
	
	if(n1 >= 8 && n2 >= 8)
	{
		printf("Aprobacion directa");
	}	
	else
	{
		if(n1 >= 6 && n2 >= 6)
		{
			printf("Rinde examen final");
		} 
		else
		{
			printf("Debe recuperar");
		}
	}
	
	return 0;
}