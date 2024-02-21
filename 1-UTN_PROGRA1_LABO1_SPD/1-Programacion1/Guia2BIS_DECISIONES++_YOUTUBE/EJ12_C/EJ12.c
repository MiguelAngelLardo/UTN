#include <stdio.h>
/*
12. Hacer un programa para ingresar tres números y emitir un cartel aclaratorio si
la suma de los dos primeros es mayor al producto del segundo con el tercero
*/
int main(){
  int n1, n2, n3, suma, producto;

  printf("Ingrese 3 numeros:\n");
  scanf("%d %d %d", &n1, &n2, &n3);

  suma = n1 + n2;
  producto = n2 * n3;

  (suma > producto) ? printf ("La suma es mayor") : printf("el producto es mayor");

  return 0;
}