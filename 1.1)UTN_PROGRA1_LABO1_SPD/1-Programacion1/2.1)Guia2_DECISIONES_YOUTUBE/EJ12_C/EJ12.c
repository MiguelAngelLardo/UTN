#include <stdio.h>
/*
Hacer un programa para ingresar un valor que estará expresado en minutos. Si
los minutos superan los 60, pasar el valor a horas, de lo contrario dejarlo en
minutos. Mostrar el resultado en pantalla aclarando si se muestran minutos u
horas.
*/
int main(){
  int min, hora;

  //OPERADOR ARITMETICO: + - * / %

  printf("Ingrese los minutos: ");
  scanf("%d", &min);

  if(min > 60) 
  {
    hora = min / 60;
    printf("el resultado en horas es: %d", hora); 
  }
  else
  {
    printf("el resultdo en minutos es: %d", min);
  }

  return 0;
}