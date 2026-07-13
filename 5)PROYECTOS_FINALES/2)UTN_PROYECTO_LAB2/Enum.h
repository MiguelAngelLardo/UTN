#pragma once
#include <string>

enum class Rol{
  Medico, 
  Nutricionista, 
  Kinesiologo,
  Psicologo, 
  Tecnico,
  Enfermero
};


enum class Especialidad {
  Cardiologo,
  Pediatria,
  Virologo,
  Neumologo,
  Traumatologo,
  Fisiatra,
  Psiquiatra,
  Obstetra,
  Nefrologo,
  Neurologo,  
  Oncologo,
  Intensivista,
  Respiratorio,
  Motor,
  Laboratorio,
  Rayos,
  No_Definida
};

std::string especialidadToString(Especialidad esp);
std::string rolToString(Rol rol);