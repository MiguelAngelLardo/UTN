#pragma once
#include <string>
#include "Postulante.h"

class Evaluador{
private:
  int _cantidadAprobados;
  int _cantidadRechazados;
  
  int _edadMinima;
  int _edadMaxima;
  std::string _puesto;
  int _experienciaMinima;
  
  bool validarEdad(Postulante postulante);
  bool validarExperiencia(Postulante postulante);
  bool validarPuesto(Postulante postulante);
  
  void setEdadMinima(int edadMinima);
  void setEdadMaxima(int edadMaxima);
  void setExperienciaMinima(int experienciaMinima);
  void setPuesto(std::string puesto);

public:/// interface
  Evaluador();
  Evaluador(int edadMinima, int edadMaxima, int experienciaMinima, std::string puesto);
  bool evaluar(Postulante postulante);
  int getCantidadEvaluados();
  int getCantidadRechazados();
};
