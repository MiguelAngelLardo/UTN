#pragma once
#include <string>

class Fecha{
private:
  int _dia, _mes, _anio;

  void establecerFechaPorDefecto();
  bool esBisiesto();
  void agregarDia();
  void restarDia();

public:
  Fecha();
  Fecha(int dia, int mes, int anio);

  int getDia();
  int getMes();
  int getAnio();

  void agregarDias(int cantidad);
  void restarDias(int cantidad);

  std::string toString(std::string formatoFecha = "DD/MM/YYYY");

};