#include <iostream>
//#include <cstdlib> //Necesario para rand() y srand() => ver si esto hace falta
#include <ctime> //Necesario para time()
#include "rlutil.h"
using namespace std;
#include "estructuras.h"
#include "menu.h"

int main()
{
  setlocale(LC_ALL, "Spanish");
  srand(time(NULL));



  desplegarMenu();

  return 0;
}
