#include <iostream>

using namespace std;

/*
4) Diseñar una rutina que liste 
por pantalla en forma de columna las letras de una palabra dada.
*/

void cargarCadena(char *palabra, int tamanio);

int main(){
  char vCadena[50];
  cout << "Ingrese la frase: ";
  cargarCadena(vCadena, 49);

  int i = 0;
  while(vCadena[i] != '\0'){
    cout << vCadena[i] << endl;
    i++;
  }

  return 0;
}

void cargarCadena(char *palabra, int tamanio){
  int i;
  fflush(stdin);

  for(i = 0; i < tamanio; i ++){
    palabra[i] = cin.get();
    if(palabra[i] == '\n'){
      break;
    }
  }
  palabra[i] = '\0';
  fflush(stdin);
}