#pragma once
#include <string>


class Postulante{
private:
  int _edad;
  int _aniosExp;
  std::string _nombre;
  std::string _puesto;

public:
  //setean y desp los que muestram

  void setEdad(int edad);
  void setAniosExp(int anio);
  void setNombre(std::string nombre);
  void setPuesto(std::string puesto);

  int getEdad();
  int getAniosExp();
  std::string getNombre();
  std::string getPuesto();

  void cargar();
  void mostrar();
};























