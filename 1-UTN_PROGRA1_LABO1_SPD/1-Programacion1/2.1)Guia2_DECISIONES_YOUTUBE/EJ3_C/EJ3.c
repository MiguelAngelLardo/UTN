#include<stdio.h>

/* Hacer un programa para ingresar dos números y que luego emita por pantalla
el mayor de ellos o un cartel aclaratorio “Son iguales” en el caso de que así sea.
Nota: los números pueden ser iguales. */


int main(){
	int n1,n2;
	printf("Digite dos numeros\n");
	scanf("\n%i %i", &n1, &n2);
	  
  if(n1 > n2){
		printf("El numero %i es el mayor", n1);
	}else if(n2 > n1){
    printf("El numero %i es el mayor", n2);
  }else{
    printf("Ambos numeros son iguales");
  }

	/*if(n1 > n2)
  {
		printf("El numero %i es el mayor", n1);
	}
  else
  {    
    if(n2 > n1)
    {
		  printf("El numero %i es el mayor", n2);
    }
    else
    {
      printf("Ambos numeros son iguales");
    }
	}*/



	return 0;
}  