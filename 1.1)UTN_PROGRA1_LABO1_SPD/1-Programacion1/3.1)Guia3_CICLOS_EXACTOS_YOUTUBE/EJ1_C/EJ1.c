#include <stdio.h>
/*
Hacer un programa que solicite el ingreso de 10 números y que muestre el
mayor de ellos por pantalla. Solo se debe emitir UN valor por pantalla.
*/
int main(){
  int n1, mayor = 0; //PSEUDO BANDERO

  //CICLO EXACTO != CICLO INEXACTO
  // FOR => PROGRAMADOR DECIDE LAS VUELTAS QUE VA A DAR!!!!
  // WHILE => (CONDICION LOGICA) => VERDADERA
  
  //1ºVARIABLE   //2ºCONDICION LOGICA    4ºOPERADOR POST INCREMENTO      
  for(int x = 0;         x < 10;            x ++             ){ // las vueltas son hasta N-1
    //3ºEJECUTA
    printf("%d)Ingrese un numero: ", x+1);
    scanf("%d", &n1);
    
    //vector[0] = {1};
    //vector[1] = {2};
    if(n1 > mayor){
      mayor = n1;
    }
  }

  /*
    VARIANTE USANDO LA 'X' COMO BANDERA
    for(int x = 0; x < 10; x ++)
    {
      if(x==0){
        max = n1;
      }else if(n1 > max){
        max = n1;
      }
    }  
  */

  printf("El mayor numero es #%d", mayor);

  return 0;
}
