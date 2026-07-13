#pragma once
#include "PacienteMenu.h"
#include "HistoriaClinicaMenu.h"

class AppMenu {
public:
  
 void menuPrincipal();

private:
  PacienteMenu _pacienteMenu;
  HistoriaClinicaMenu _historiaClinicaMenu;
  //ProfesionalMenu _profesionalMenu; 
};