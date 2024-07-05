#include <stdio.h>

int main(){
	float longitud1, longitud2, longitud3;
	
	printf("Digite la longitud del primer lado:\n");
	scanf("%f", &longitud1);
	printf("Digite la longitud del segundo lado:\n");
	scanf("%f", &longitud2);
	printf("Digite la longitud del tercer lado:\n");
	scanf("%f", &longitud3);
	
	if(longitud1 == longitud2 && longitud2 == longitud3)
	{
		printf("Su triangulo es equilatero");		
	}
	else
	{
		if(longitud1 == longitud2 || longitud2 == longitud3 || longitud3 == longitud1)
		{
			printf("Su triangulo es isosceles");
		}
		else
		{
			if(longitud1 != longitud2 && longitud2 != longitud3 )
			{
				printf("Su triangulo es escaleno");
			}
		}
	}
	
	return 0;
}