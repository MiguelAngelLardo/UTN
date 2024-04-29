#include <iostream>

using namespace std;
#include "MamiferoAcuatico.h"
#include "MamiferoTerrestre.h"
#include "Pez.h"
#include "Anfibio.h"
#include "Reptil.h"
#include "Ave.h"


int main()
{
  MamiferoAcuatico ma;
  MamiferoTerrestre mt;
  Pez p;
  Anfibio an;
  Reptil rp;
  Ave av;

  av.cargar();
  av.mostrar();


  return 0;
}
