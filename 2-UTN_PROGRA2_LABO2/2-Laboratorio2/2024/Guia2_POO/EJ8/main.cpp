#include <iostream>
#include "Persona.h"
#include "Reunion.h"

int main(){
  Persona p1("Esteban", "Quito");
  Reunion obj;

  obj.agregarPersona(p1);

  Persona p2 = obj.obtenerPersona(0);

  cout << p2.getApellidoPersona();

  
  return 0;
}