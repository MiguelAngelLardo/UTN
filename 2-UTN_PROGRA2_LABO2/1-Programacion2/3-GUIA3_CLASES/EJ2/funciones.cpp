#include <iostream>
#include "funciones.h"

void cargarCadena(char palabra[], int tam){
  int i = 0;
  fflush(stdin);
  for(i = 0; i < tam; i ++){
    palabra[i] = std::cin.get(); //lee un solo caracter
    if(palabra[i] == '\n'){ //\n es el enter
      break;
    }
  }
  palabra [i] = '\0'; //fin arreglo
  fflush(stdin);
}