#include<stdio.h>

/*
	11. Hacer un programa para ingresar tres números y luego mostrarlos ordenados
	de menor a mayor.
*/

int main(){
	
	int n1, n2, n3;
	
	printf("Ingrese tres numeros:\n");
	scanf("%i %i %i", &n1, &n2, &n3);
	
	if(n1 < n2 && n1 < n3)
	{
		printf("%i\n", n1);
		if(n2 < n3)
		{
			printf("%i\n%i", n2, n3);
		}
		else
		{
			printf("%i\n%i", n3, n2);
		}
	}
	else
	{
		if(n2 < n1 && n2 < n3)
		{
			printf("%i", n2);
			if(n1 < n3)
			{
				printf("%i\n%i", n1, n3);
			}
			else
			{
				printf("%i\n%i", n3, n1);
			}
		}
		else
		{
			printf("%i", n3);
			if(n1 < n2)
			{
				printf("%i\n%i", n1, n2);
			}
			else
			{
				printf("%i\n%i", n2, n1);
			}
		}
	}

	return 0;
}