#pragma once
/// dependencias
#include <string>

class Postulante{
private:
  std::string _nombre;
  int _edad;
  int _experiencia;
  std::string _puesto;
  
public:
  std::string getNombre();
  void setNombre(std::string nombre);
  
  int getEdad();
  void setEdad(int edad);
  
  int getExperiencia();
  void setExperiencia(int experiencia);
  
  std::string getPuesto();
  void setPuesto(std::string puesto);
  
  void cargar();
};
