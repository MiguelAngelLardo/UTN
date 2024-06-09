#include<stdio.h>

int main(){
  int n1;
  printf("Digite su numero:\n");
  scanf("%i", &n1);
    
  if(n1 % 2 == 0){
    printf("El numero es par");
  }else{    
    printf("El numero es impar");
  }
}  