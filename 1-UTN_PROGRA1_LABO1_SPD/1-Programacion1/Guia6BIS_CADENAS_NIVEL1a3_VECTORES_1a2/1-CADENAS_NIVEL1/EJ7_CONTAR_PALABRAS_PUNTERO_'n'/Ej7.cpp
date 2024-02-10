#include <iostream>

using namespace std;
/*
7) Diseñar una rutina que cuente las palabras de una cadena de caracteres dada, asumiendo que existen uno o varios espacios en
blanco separando una palabra de la otra.
*/
int main(){
  char palabras[50];

  cout << "Ingrese una palabra con el getline: ";
  cin.getline(palabras, 50);
  cout << palabras << endl;;

  char* ptr = palabras; // %palabras[0]
  while(*ptr != '\0'){
    cout << *ptr;
    ptr++;
  }

  cout << endl;
  cout << "Ingrese una palabra con el for:";
  int x;
  bool bandera = false;
  for(x = 0; x < 49 && bandera == false; x ++){
    palabras[x] = cin.get();// atrapa un caracter y el espacio
    bandera = (palabras[x] == '\n') ? true : false;
  }
  //palabras[x-1] = '\0';//le resto uno para quitar el \n por el \0
  palabras[x] = '\0';
  
  int len = 0;
  while(palabras[len] != '\0'){//si pongo "hola" habran un largo de 4 len => por que va del 0 al 4 (el 4to es '\0')
    len++;
  }

  int contPalabras = 0;
  for(int x = 0; x < len; x++){
    if(palabras[x] == ' ' || palabras[x] == '\n'){ //necesito el \n para determinar la ultima palabra
      contPalabras ++;
    }
  }

  cout << "EL texto tiene: " << contPalabras << " palabras";

  return 0;
}