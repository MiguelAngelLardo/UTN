#pragma once
#include <string>

using namespace std;

class Persona{
private:
  string _nombre;
  string _apellido;

public:
  void setNombrePersona(string nombre);
  void setapellidoPersona(string apellido);

  string getNombrePersona();
  string getApellidoPersona();

  Persona(string nombre = "S/N", string apellido = "S/A");

  void cargar();

};