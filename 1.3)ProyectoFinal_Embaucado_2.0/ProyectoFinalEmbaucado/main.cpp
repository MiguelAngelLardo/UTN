
#include <iostream>
//#include <cstdlib> //Necesario para rand() y srand() => ver si esto hace falta
#include <ctime> //Necesario para time()
#include "rlutil.h"
using namespace std;
#include "estructuras.h"
#include "menu.h"

int main()
{

  srand(time(NULL));
  rlutil::setColor(rlutil::WHITE);
  rlutil::setBackgroundColor(rlutil::GREEN);
  rlutil::cls();//sin esto el fondo de las letras se pone verde y no todo el tablero

  rlutil::hidecursor();

  mostrarMenu();
  return 0;
}

