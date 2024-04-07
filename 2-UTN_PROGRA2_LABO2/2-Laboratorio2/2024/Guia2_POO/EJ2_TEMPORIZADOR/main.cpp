#include <iostream>
#include "Temporizador.h"

using namespace std;

int main(){
  Temporizador tem(25, 61, 8);

  cout << "getHora: " << tem.getHora() << endl;
  cout << "getMin: " << tem.getMinuto() << endl;
  cout << "getSegundo: " << tem.getSegundo() << endl;

  tem.tic();
  cout << "\ntem.tic()\n";

  cout << "getHora: " << tem.getHora() << endl;
  cout << "getMin: " << tem.getMinuto() << endl;
  cout << "getSegundo: " << tem.getSegundo() << endl;
 
  cout << endl << "toString() => " << tem.toString();
  cout << endl << "toString() => " << tem.toString("SS:MM:HH");
  cout << endl << "toString() => " << tem.toString("hola");

  Temporizador t1(20,50,50);
  Temporizador t2(20,50,53);

  int resultado = t1.comparar(t2);

  if(resultado > 0){
    cout << "\nEl temporizador recibido tiene MENOS tiempo que el objeto";
  }else if(resultado < 0){
    cout << "\nEl temporizador recibido tiene MAS tiempo que el objeto";
  }else{
    cout << "\nAMBOS SON IGUALES";
  }




  return 0;
}