#include "reunion.h"

FechaHorario Reunion::getFechaHorario(){return _fechaHorario;}

std::string Reunion::getLugar(){return _lugar;}

std::string Reunion::getTema(){return _tema;}

int Reunion::getDuracion(){return _duracion;}

int Reunion::getCantidadIntegrantes(){return _cantidadIntegrantes;}

Persona Reunion::getIntegrante(int indice){
  /*if(indice >= 0 && indice <= _cantidadIntegrantes -1){
    return _integrantes[indice];
  }else{
    return _integrantes[0];
  }*/

  return _integrantes[indice];
}

void Reunion::setFechaHorario(FechaHorario fechaHorario){_fechaHorario = fechaHorario;}

void Reunion::setLugar(std::string lugar){_lugar = lugar;}

void Reunion::setTema(std::string tema){_tema = tema;}

void Reunion::setDuracion(int duracion){
  _duracion = duracion;
}

void Reunion::setIntegrante(Persona integrante, int indice){
  _integrantes[indice] = integrante;

}

Reunion::Reunion(int cantidadIntegrantes){
  if(cantidadIntegrantes > 0){
    _integrantes = nullptr;
    _integrantes = new Persona[cantidadIntegrantes]; //al puntero le asigno la direccion de memoria 
    if(_integrantes == nullptr){
      _cantidadIntegrantes = 0;
    }else{
      _cantidadIntegrantes = cantidadIntegrantes;
    }
  }else{ //si ingresa numero negativo
    _cantidadIntegrantes = 0;
  }
  _duracion = 0;
  _tema = "";
  _lugar = "";
}  


Reunion::~Reunion(){
  if(_cantidadIntegrantes > 0){ //_integrantes != nullptr => ya que si es nullptr no existe
    delete []_integrantes;
  }
}


std::string Reunion::toString(){
  std::string aux = _fechaHorario.toString();

  aux += ", " + _lugar; //getLugar()
  aux += ", " + _tema; //getTema()
  aux += ", " + std::to_string(_duracion); // getDuracion
  for(int x = 0; x < _cantidadIntegrantes; x ++){
    aux += ", " + _integrantes[x].getApellidos();
    aux += ", " + _integrantes[x].getNombres();
  }
  
  return aux;
}




