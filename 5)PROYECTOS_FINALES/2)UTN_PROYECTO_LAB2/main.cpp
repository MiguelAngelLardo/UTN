#include <iostream>
#include "AppMenu.h"
#include "Disenio.h"
#include "ProfesionalManager.h"
using namespace std;


int main()
{


  dibujarLogo();
  rlutil::msleep(2500);
  system ("cls");
  AppMenu appMenu;
  appMenu.menuPrincipal();
  system("cls");




    return 0;

}
