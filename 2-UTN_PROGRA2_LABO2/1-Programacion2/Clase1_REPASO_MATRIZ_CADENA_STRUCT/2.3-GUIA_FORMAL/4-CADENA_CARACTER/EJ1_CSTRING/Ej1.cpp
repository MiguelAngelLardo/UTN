#include <iostream>
#include <cstring>

using namespace std;
/*
1) Hacer funciones que reciban los mismos parámetros y realicen las mismas acciones que las siguientes
 funciones de la librería string.h:
- int strcmp(char *, char *) OK
- void strcpy(char*, char *)
- int strlen(char *) OK
- char * strcat(char *, char *)
*/

int strlen2(char *vec);                                        // 1raes + grande  1ra es mas chica
int strcmp2(char *vec1, char *vec2);// 0 son iguales en valor / 1 hola vs chau / -1 hola vs saludo
void strcpy2(char *vec1, char *vec2);
char *strcat2(char *, char *);


int main(){
  char cadena1 [] = "hola";
  char cadena2 [] = "chauaaaaaa";

  strcat2(cadena1, cadena2);
  cout << cadena1 << endl; 
  
  return 0;
}

int strlen2(char *vec){
  int indice = 0;            // h o l a '\a' 
  while(vec[indice] != '\0'){// 0 1 2 3  4
    indice ++;
  }
  return indice; //devuelve 4
}



int strcmp2(char *vec1, char *vec2){
  int longitud1 = strlen(vec1);
  int longitud2 = strlen(vec2);

  if(longitud1 == longitud2){
    if(vec1[0] == vec2[0]){
      return 0;
    }else if(vec1[0] > vec2[0]){
      return 1;
    }else{
      return -1;
    }
  }else if(longitud1 > longitud2){
    return 1;    
  }else{
    return -1;
  }
}


void strcpy2(char *vec1, char *vec2){
  int i = 0;
  while(vec2[i] != '\0'){
    vec1[i] = vec2[i];
    i ++;
  }
  vec1[i] = '\0';
}

char *strcat2(char *vec1, char *vec2){
  int long1 = strlen2(vec1);
  int long2 = strlen2(vec2);

  int i = 0;
  while (vec2[i] != '\0'){
    vec1[long1+i] = vec2[i];
    i ++;
  }
  vec1[long1+long2] = '\0'; 

  return vec1;   
}
