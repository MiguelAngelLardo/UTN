#include <iostream>
//#include <cstdlib> //Necesario para rand() y srand() => ver si esto hace falta
#include <ctime> //Necesario para time()

using namespace std;
#include "estructuras.h"
#include "menu.h"

int main()
{
  setlocale(LC_ALL, "Spanish");
  srand(time(NULL));

  Jugador jugador1, jugador2;

  //FUNCION MENÚ()
  desplegarMenu();

    return 0;
}
