#include <stdio.h>

/*Hacer un programa para ingresar cinco números distintos y luego mostrar por
pantalla el mayor y el menor de ellos*/

int main (){
  int n1, n2, n3, n4, n5, menor, mayor;

  printf("Ingrese 5 numeros:\n");
  scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
  
  if(n1 > n2)
  {
    mayor = n1;
    menor = n2;
  }
  else
  {
    mayor = n2; 
    menor = n1; 
  }
    
  if(n3 > mayor)
  {
    mayor = n3;
  }
  else
  {    
    if(n3 < menor)
    {
      menor = n3;
    }
  }

	if(n4 > mayor)
	{
		mayor = n4;
	}
  else
	{
  	if(n4 < menor)
		{
  		menor = n4;
		}
	}
	
	if(n5 > mayor)
	{
		mayor = n5;
	}
	else
	{
		if(n5 < menor)
		{
			menor = n5;
		}
	}

	printf("El menor es: %d\n", menor);
	printf("El mayor es: %d", mayor);

  return 0;
}