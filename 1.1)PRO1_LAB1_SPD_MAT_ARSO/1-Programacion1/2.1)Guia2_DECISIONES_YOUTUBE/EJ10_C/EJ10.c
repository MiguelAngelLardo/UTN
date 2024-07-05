#include <stdio.h>
/*
Hacer un programa para ingresar cuatro números y luego mostrar por pantalla
cuáles son mayores a 100.
*/

int main(){
  int n1, n2, n3, n4;

  printf("Ingrese 4 numeros:\n");
  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

  if(n1 > 100)
  {
    printf ("%d\n", n1);
  }

  if(n2 > 100)
  {
    printf ("%d\n", n2);
  }

  if(n3 > 100)
  {
    printf ("%d\n", n3);
  }

  if(n4 > 100)
  {
    printf ("%d\n", n4);
  }
}