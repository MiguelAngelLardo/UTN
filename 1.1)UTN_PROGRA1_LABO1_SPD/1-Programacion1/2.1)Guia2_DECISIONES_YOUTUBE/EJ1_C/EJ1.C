#include <stdio.h>

int main(){
  int n1;
  printf("Escriba un numero: ");
  scanf("%d", &n1);// % especificador de formato d de decimal - & e spara la direccion de memoria de n1

  if(n1 > 10){
    printf("EL numero %d es mayor a diez. ", n1);
  }else{
    printf("El numero %d no es mayor a diez.", n1);
  }

  

  return 0;
}























