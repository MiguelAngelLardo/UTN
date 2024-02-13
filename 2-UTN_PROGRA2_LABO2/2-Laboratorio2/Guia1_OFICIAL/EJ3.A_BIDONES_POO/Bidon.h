#pragma once
#include "Vaso.h"
#include <string>

class Bidon
{
private:
  int _capacidadMaxima;
  int _capacidadActual;
  std::string _sabor;

  void setCapacidadMaxima(int cantidad);
    
public:
  Bidon ();
  Bidon (int cantidad, std::string sabor);

  int getCapacidad();
  std::string getSabor();
  void cargar ();
  void servir(Vaso vaso);
};    