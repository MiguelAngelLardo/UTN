#pragma once
#include "Tarea.h"
#include "Fecha.h"
#include <string>

class Tarea
{
private:
  int _ID;
  char _descripcion[30];
  Fecha _fechaLimite;
  int _nivel;
  int _estado;

public:
  Tarea();
  Tarea(int ID, std::string descripcion, Fecha fechaLimite, int nivel, int estado = 0);

  int getID();
  void setID(int ID);

  std::string getDescripcion();
  void setDescripcion(std::string descripcion);

  Fecha getFechaLimite();
  void setFechaLimite(Fecha fechaLimite);

  std::string getNivelDificultad();
  void setNivelDificultad(int nivelDificultad);

  std::string getDescripcionEstado();
  void setEstado(int estado);
};

