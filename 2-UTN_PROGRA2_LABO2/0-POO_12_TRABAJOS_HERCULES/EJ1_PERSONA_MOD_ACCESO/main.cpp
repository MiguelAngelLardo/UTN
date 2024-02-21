#include <iostream>
using namespace std;
#include "Persona.h"
/*
EL nombre no es POO (segun el creador) ya que eso crea un pensamiento ERRONEO! PROGRAMACION ORIENTADA A MENSAJES es el nombre real

Uno con la estructurada piensa => PRIMERO VA ESTE CALCULO, luego va otro, osea se base en la LINEA DE TEMPORALIDAD en la secuencia de pasos
POO => es representar la realidad lo mas posible 
*/
int main (){

  Persona a(11, "pedro", "Gomez", 1987 );//se llaman REFERENCIA por que guarda 'Flechas' que señalan al objeto
  //JAVA
    //Persona a = new Persona();



  cout << a.nombreCompleto() << ": " << a.edad() << " años" << endl;
  cout << a.toString() << endl;

  a.tuNuevoNombre("Julieta");

  cout << a.toString(); 

  return 0;
}