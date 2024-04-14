#include <iostream>
using namespace std;
#include "Persona.h"
#include "Empleado.h"
#include "Director.h"
#include "Alumno.h"

int main (){
  Director d;

  d.cargar();
  d.mostrar();

  return 0;
}