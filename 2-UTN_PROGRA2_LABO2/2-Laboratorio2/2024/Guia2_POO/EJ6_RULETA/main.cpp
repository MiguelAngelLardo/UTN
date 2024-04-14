#include <iostream>

using namespace std;

#include "Ruleta.h"
#include "Funciones.h"

int main()
{

  Ruleta r1 = crearRuleta();///Creo Ruleta
  cargarPremios(r1);///Carga Datos
  jugarRuleta(r1);///Juego

  return 0;
}
