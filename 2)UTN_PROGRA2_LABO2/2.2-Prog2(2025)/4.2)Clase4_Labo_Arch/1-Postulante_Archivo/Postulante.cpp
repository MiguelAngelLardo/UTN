#include "Postulante.h"
#include <cstring>
using namespace std;

Postulante::Postulante(){
  _id = 0;
  strcpy(_apellidos, "");
  strcpy(_nombres, "");
  _edad = 0;
  strcpy(_puesto, "");
  _aniosExperiencia = 0;
  _contratado = false;
}

Postulante::Postulante(int id, std::string apellidos, std::string nombres, int edad, std::string puesto, int aniosExperiencia, bool contratado){
  setId(id);
  setApellidos(apellidos);
  setNombres(nombres);
  setEdad(edad);
  setPuesto(puesto);
  setAniosExperiencia(aniosExperiencia);
  setContratado(contratado);
}

void Postulante::setId(int id){_id = id;}
void Postulante::setApellidos(std::string apellidos){strcpy(_apellidos, apellidos.c_str());}
void Postulante::setNombres(std::string nombres){strcpy(_nombres, nombres.c_str());}
void Postulante::setEdad(int edad){_edad = edad;}
void Postulante::setPuesto(std::string puesto){strcpy(_puesto, puesto.c_str());}
void Postulante::setAniosExperiencia(int aniosExperiencia){_aniosExperiencia = aniosExperiencia;}
void Postulante::setContratado(bool contratado){_contratado = contratado;}
int Postulante::getId(){return _id;}

std::string Postulante::getApellidos(){return _apellidos;}
std::string Postulante::getNombres(){return _nombres;}
int Postulante::getEdad(){return _edad;}
std::string Postulante::getPuesto(){return _puesto;}
int Postulante::getAniosExperiencia(){return _aniosExperiencia;}
bool Postulante::getContratado(){return _contratado;}
std::string Postulante::toCSV(){
  string str = "";
  str = to_string(_id) + ",";
  str += string(_apellidos) + ",";
  str += string(_nombres) + ",";
  str += to_string(_edad) + ",";
  str += string(_puesto) + ",";
  str += to_string(_aniosExperiencia) + ",";
  str += to_string(_contratado);
  
  return str;
}