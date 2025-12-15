#include "Evaluador.h"

/***
La persona debe tener entre 22 y 50 a¤os inclusive.
Debe contar con al menos 2 a¤os de experiencia laboral.
El puesto al que aplica debe ser uno de los aceptados (por ejemplo: Programador, Tester o Dise¤ador).

*/

Evaluador::Evaluador(){
  _cantidadAprobados = 0;
  _cantidadRechazados = 0;
  
  _edadMinima = 22;
  _edadMaxima = 50;
  _experienciaMinima = 2;
  _puesto = "Programador";
}

Evaluador::Evaluador(int edadMinima, int edadMaxima, int experienciaMinima, std::string puesto){
  _cantidadAprobados = 0;
  _cantidadRechazados = 0;
  
  setEdadMinima(edadMinima); 
  setEdadMaxima(edadMaxima);
  setExperienciaMinima(experienciaMinima);
  setPuesto(puesto);

}

void Evaluador::setEdadMinima(int edadMinima){
  _edadMinima = edadMinima;
}

void Evaluador::setEdadMaxima(int edadMaxima){
  _edadMaxima = edadMaxima;
}

void Evaluador::setExperienciaMinima(int experienciaMinima){
  _experienciaMinima = experienciaMinima;
}

void Evaluador::setPuesto(std::string puesto){
  _puesto = puesto;
}

bool Evaluador::validarEdad(Postulante postulante){
  return postulante.getEdad() >= _edadMinima && postulante.getEdad() <= _edadMaxima;
}

bool Evaluador::validarExperiencia(Postulante postulante){
  return postulante.getExperiencia() >= _experienciaMinima;
}

bool Evaluador::validarPuesto(Postulante postulante){
  return postulante.getPuesto() == _puesto;
}

bool Evaluador::evaluar(Postulante postulante)
{
  if(!validarEdad(postulante)
     || !validarExperiencia(postulante)
     || !validarPuesto(postulante))
  {
    _cantidadRechazados++;
    return false;
  }
  
  _cantidadAprobados++;
  return true;
}

int Evaluador::getCantidadEvaluados()
{
  return _cantidadAprobados + _cantidadRechazados;
}

int Evaluador::getCantidadRechazados()
{
  return _cantidadRechazados;
}
