#include "Profesional.h"
#include <cstring>

using namespace std;

Profesional::Profesional(): Persona(){ //sino le pongo inicializacion me tira error
  _matricula[0] = '\0';
  _legajo = 0;
  _especialidad = Especialidad(Especialidad::No_Definida);
  _rol = Rol(Rol::Medico);
  _activo = true;
}

Profesional::Profesional(string nom,string ape, string dom, string dni, std::string mail, string tel,
                         string matricula, int legajo,Rol rol, Especialidad especialidad)
  : Persona(nom,ape, dom, dni, mail, tel){
  setMatricula(matricula);
  setLegajo(legajo);
  setRol(rol);
  setEspecialidad(especialidad);
}

void Profesional::setMatricula(const string &matricula){
    if (matricula.length() <= 8) {
      strcpy(_matricula, matricula.c_str());
    } else {
      _matricula[0] = '\0';
    }
  }

void Profesional::setLegajo(int legajo){
      _legajo = legajo;
  }

void Profesional::setEspecialidad(const Especialidad &especialidad){
  _especialidad = especialidad;
}

void Profesional::setRol(const Rol &rol){
  _rol = rol;
}

void Profesional::setActivo(bool activo){
  _activo = activo;
}

std::string Profesional::getMatricula() const{
  return string(_matricula);
}

int Profesional::getLegajo() const{
  return _legajo;
}

Especialidad Profesional::getEspecialidad() const{
  return _especialidad;
}

Rol Profesional::getRol() const{
  return _rol;
}

bool Profesional::getActivo() const{
  return _activo;
}



string Profesional::toString() const {
    string str = Persona::toString();
    str += string(_matricula) + ", \n\t";
    str += to_string(_legajo) + ", \n\t";
    str += especialidadToString(_especialidad) + ", \n\t";
    str += rolToString(_rol) + ", \n\t";

    return str;
}
