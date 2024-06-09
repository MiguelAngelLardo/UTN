#include <stdio.h>

/*11. Hacer un programa para ingresar cuatro números y luego mostrar por pantalla
cuántos son menores a 100.*/

int main(){
  int n1, n2, n3, n4;
  int contadorMenores = 0; //CONTADOR SE 'INICIALIA' - HARDCODEANDO 
                           // 4194432 VALOR BASURA!
  
  printf("Ingrese 4 numeros:\n");
  scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

  //VARIAS FORMAS DE USAR EL CONTADOR 
  //TERNARIO

  /*if(n1 < 100){
    contadorMenores = contadorMenores + 1; // SUMO UNO
  }*/
  
  //TERNARIO!
  contadorMenores = (n1 < 100) ? contadorMenores + 1 : contadorMenores + 0;  

  if(n2 < 100){
    contadorMenores += 1; // contadorMenores = contadorMenores + 1;
  }

  /*if(n3 < 100){
    contadorMenores ++; // SI O SI SUMA UNO - contadorMenores -- -> RESTO DE A UNO
    -----------------
    contadorMenores = contadorMenores + 1;
  }*/

  contadorMenores += (n3 < 100) ? 1 : 0;

  if(n4 < 100){
    contadorMenores -=- 1;
  }

  printf("contadorMenores: %d", contadorMenores);

}