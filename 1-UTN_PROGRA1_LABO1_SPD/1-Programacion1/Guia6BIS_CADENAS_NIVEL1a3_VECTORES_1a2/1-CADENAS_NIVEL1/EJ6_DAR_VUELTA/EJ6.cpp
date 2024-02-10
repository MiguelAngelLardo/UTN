#include <iostream>

using namespace std;

int main(){
  char vPalabras[30];
  bool unaPalabra;
  int len;

  /*cout << "Ingrese palabra con getline: ";
  cin.getline(vPalabras, 30); */

  do{
    cout << "Ingrese palabra con el for:"; //estos espacios no modifican el len
    int x;
    bool bandera = false;
    for(x = 0; x < 29 && bandera == false; x ++){
      vPalabras[x] = cin.get();     
      bandera = (vPalabras[x] == '\n') ? true : false;
    }
    vPalabras[x-1] = '\0';//le resto uno para quitar el \n por el \0
    
    len = 0;
    while (vPalabras[len] != '\0'){ //si pongo "hola" habran un largo de 4 len => por que va del 0 al 4 (el 4to es '\0')
      len ++;
    }


    unaPalabra = true;
    for(int x = 0; x < len; x ++){
      if(vPalabras[x] == ' '){
        unaPalabra = false;
      }
    }
    cout << (!unaPalabra ? "Ingrese una palabra sin espacios\n" : ""); //(!unaPalabra) ? cout << "Ingrese una palabra sin espacios" : cout << "";

  }while(unaPalabra == false);  

  for(int x = len-1; x >= 0; x--){ //si len es 4 lo inicializo en 3 => ya que hace 3,2,1,0 => igual c++ no muestra el nulo
      cout << vPalabras[x];
  }

  return 0;
}