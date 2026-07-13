#pragma once

#include <string>

class Estudios {
private:
  char _codigoEstudio [5];
  char _descripcion [36];

public:
  Estudios();
  Estudios(std::string codigoEstudio, std::string descripcion);

  void setCodigoEstudio(const std::string &codigoEstudio);
  void setDescripcion(const std::string &descripcion);

  std::string getCodigoEstudio() const;
  std::string getDescripcion() const;

  void mostrar() const;


};
