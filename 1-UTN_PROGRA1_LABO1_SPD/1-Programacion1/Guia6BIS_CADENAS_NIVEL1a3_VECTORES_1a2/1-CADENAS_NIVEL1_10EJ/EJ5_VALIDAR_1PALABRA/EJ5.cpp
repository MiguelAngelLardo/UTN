#include <iostream>

using namespace std;

int main (){
  char vPalabras[30];

  cout << "Ingrese la palabra con el cin.getline: ";
  cin.getline(vPalabras, 30);

  cout << "Ingrese la palabra con el cin.get: ";
  int x; 
  bool bandera = false;
  for(x = 0; x < 29 && bandera == false; x ++){
    vPalabras[x] = cin.get();
    if(vPalabras[x] == '\n'){
      bandera = true;
    }
  }
  vPalabras[x-1] = '\0';//le resto uno para quitar el \n por el \0

  x = 0;
  bool espacio = false;
  while (vPalabras[x] != '\0'){
    if(vPalabras[x] == ' '){
      espacio = true;
    }
    x ++;
  }
  
  if(espacio){
    cout << "1"; 
  }else{
    cout << "0";
  }

  return 0;
}