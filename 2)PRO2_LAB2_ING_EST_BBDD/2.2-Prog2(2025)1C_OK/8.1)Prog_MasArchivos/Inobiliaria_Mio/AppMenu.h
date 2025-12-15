#pragma once
#include "PropietarioMenu.h"
#include "InmuebleMenu.h"

class AppMenu{
public:
  void appMenu();

private:
  PropietarioMenu _propietarioMenu;
  InmuebleMenu _inmuebleMenu;
};

