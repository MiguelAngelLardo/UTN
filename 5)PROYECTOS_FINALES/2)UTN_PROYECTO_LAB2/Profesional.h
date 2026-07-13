#pragma once
#include <string>
#include "Enum.h"
#include "Persona.h"


class Profesional: public Persona{
private:
  char _matricula [9];
  int _legajo;
  Especialidad _especialidad;
  Rol _rol;
  bool _activo= true;


public:
  Profesional();
  Profesional(std::string nom, std::string ape, std::string dom, std::string dni, std::string mail, std::string tel, 
              std::string matricula, int legajo, Rol rol, Especialidad especialidad);

  void setMatricula(const std::string &matricula);
  void setLegajo(int legajo);
  void setEspecialidad(const Especialidad &especialidad);
  void setRol(const Rol &rol);
  void setActivo(bool activo);


  std::string getMatricula() const;
  int getLegajo() const;
  Especialidad getEspecialidad() const;
  Rol getRol() const;
  bool getActivo() const;

 // virtual std::string getTipo() const = 0;//podria hacer la definicion en cpp pero tambien se usa en .h si es override
  std::string toString() const override;
};