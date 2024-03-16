#include <stdio.h>
/*
2. Hacer	un	programa	que	solicite 50	números	enteros	y	los	guarde en	un	vector.
Luego	recorrer los	elementos y	determinar	e	informar	cuál	es	el	valor máximo	
y	su	posición	dentro	del	vector.
*/
int main(){
  int vNumeros[5];

  for(int x = 0; x < 5; x++){
    printf("%d)Ingrese un numero:", x+1);
    scanf("%d", &vNumeros[x]);
  }

  int maxNum = vNumeros[0]; // 10
  int posicion = 1; 

  for(int x = 1; x < 5; x ++){
    if(vNumeros[x] > maxNum){
      maxNum = vNumeros[x];
      posicion = x + 1;
    }
  }

  /*bool bandera = false; // primer num 45
  if (!bandera){        //seg num 40
    numMax = n;         //tercera 50  
    bandera = true;
  }else if(n > numMax){
    numMax = n;
  }*/

  printf("El maximo numero es #%d y esta en la posicion %d", maxNum, posicion);

  return 0;
}