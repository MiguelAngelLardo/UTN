#pragma once
#include <string>
#include "ProfesionalArchivo.h"

class ProfesionalManager {
private:

  ProfesionalArchivo _profesionalArchivo;

  Rol seleccionarRol();
  Especialidad seleccionarEspecialidad();

public:
  ProfesionalManager();

  int establecerLegajo();

  Profesional buscarPorMatricula(const std::string &matricula);

  void generarProfesionalesDePrueba();//en el main genero profesionales.dat

  Profesional listaProfesionalesActuales();//dentro carga vec con leer del .dat => tiene menuInteractico(opcionesParaMenu)
  std::string opcionesParaMenu(Profesional profesionales[], int cantidad);

};
