#include <stdio.h>

/*
1. Hacer	un	programa	que	solicite 50	números	enteros	y	los	guarde en	un	vector.	
Luego	recorrer el	vector	y	determinar	e	informar	cuál	es	la	suma de	los	valores	del	mismo.
*/

const int TAM = 5;

int main (){
  int vNumero[TAM]; //INICIALIZO EL VECTOR => PIENSO COMO HUMANO va de 1 a 50
  int acum = 0; //contador => SE INICIALIZA EN CERO!

  //vNumero[0] = 6
  //vNumero[1] = 9
  //vNumero[49] = 65
  //vNumero[50] = ?
  //printf o scanf => LO PIENSO COMO MAQUINA => 0 a 49

   //VECTOR y FOR => PAREJA QUE NO SE DISOCIA!!!
  // vectores de tamanio FIJO => pone el programador => aprender
 // vectores dinamico => memoria heap => fijo pero editable por el usuario
//lista-vectores => durante la ejecucion puede agrandarse o achicarse

  //UN FOR PARA CARGAR
  for(int x = 0; x < TAM; x ++){ // x <=4
    printf("%d)Ingrese un numero:", x+1);
    scanf("%d", &vNumero[x]);
  }

  //OTRO FOR PARA MOSTRAR
  for(int x = 0; x < TAM; x ++){
    acum += vNumero[x]; //acum = acum + vNumero[x];[0] - [1] - [2]
  }

  printf("%d", acum);

  return 0;
}