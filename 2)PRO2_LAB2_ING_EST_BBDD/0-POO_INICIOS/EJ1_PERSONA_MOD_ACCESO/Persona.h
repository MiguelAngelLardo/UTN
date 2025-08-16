#pragma once

#include <string>

class Persona{
private://ENCAPSULAMIENTO => modificador de acceso "privado"
  int _documento;
  std::string _nombre;
  std::string _apellido;
  int _nacimiento;

public: //el metodo es un MENSAJE

  int getDocumento();
  void setDocumento(int documento);

  std::string getNombre();
  void setNombre(std::string nombre);

  std::string getApellido();
  void setApellido(std::string apellido);

  int getNacimiento();
  void setNacimiento(int nacimiento);

  Persona(int documento, std::string nombre, std::string apellido, int nacimiento);

  std::string nombreCompleto();

  int edad();

  void tuNuevoNombre(std::string nuevoNombre);

  std::string toString();

};