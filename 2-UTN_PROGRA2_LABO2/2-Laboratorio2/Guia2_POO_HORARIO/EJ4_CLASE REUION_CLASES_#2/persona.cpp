#include "persona.h"

std::string Persona::getNombres(){
  return _nombres;
}
std::string Persona::getApellidos(){
  return _apellidos;
}
std::string Persona::getApellidosYNombres(){
  if(_apellidos.length() == 0 && _nombres == ""){
    return "";
  }else{
    return _apellidos + ", " + _nombres;
  }
}

void Persona::setNombres(std::string nombres){
 _nombres = nombres;
}
void Persona::setApellidos(std::string apellidos){
   _apellidos = apellidos;
}
Persona::Persona(){
  _apellidos = "";
  _nombres = "";
}

Persona::Persona(std::string apellidos, std::string nombres){
  _apellidos = apellidos;
  _nombres = nombres;
}
