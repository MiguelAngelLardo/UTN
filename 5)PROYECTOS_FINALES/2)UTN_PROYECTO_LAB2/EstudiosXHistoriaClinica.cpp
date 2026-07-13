#include <iostream>
#include <cstring>
#include "EstudiosXHistoriaClinica.h"
using namespace std;
EstudiosXHistoriasClinicas::EstudiosXHistoriasClinicas(){
  _DNI[0]='\0';
  _idHistoriaClinica[0]='\0',
  _codigoEstudio [0]='\0',
  _matriculaMedico[0]='\0',
  _apellidoMedico[0]='\0',
  _nombreMedico[0]='\0',
  _resultadoEstudio[0]='\0';
  _fechaEstudio = Fecha ();
}

//CAMBIO
EstudiosXHistoriasClinicas::EstudiosXHistoriasClinicas(string DNI, string idHistoriaClinica, string codigoEstudio, string matriculaMedico, string apellidoMedico, string nombreMedico, string resultadoEstudio){
  setDNI(DNI);
  setIdHistoriaClinica(idHistoriaClinica);
  setCodigoEstudio(codigoEstudio);
  setMatriculaMedico(matriculaMedico);
  setApellidoMedico(apellidoMedico);
  setNombreMedico(nombreMedico);
  setResultadoEstudio(resultadoEstudio);
  _fechaEstudio = Fecha();
}

void EstudiosXHistoriasClinicas::setDNI(const std::string &DNI){
  if(DNI.length() <= 8){
    strcpy(_DNI, DNI.c_str());
  }else{
    _DNI[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setIdHistoriaClinica(const std::string &idHistoriaClinica){
  if(idHistoriaClinica.length() <= 4){
    strcpy(_idHistoriaClinica, idHistoriaClinica.c_str());
  }else{
    _idHistoriaClinica[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setCodigoEstudio(const std::string &codigoEstudio){
  if(codigoEstudio.length() <=4){
    strcpy(_codigoEstudio, codigoEstudio.c_str());
  }else{
    _codigoEstudio[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setMatriculaMedico(const std::string &matriculaMedico){
  if(matriculaMedico.length() <= 8){
    strcpy(_matriculaMedico, matriculaMedico.c_str());
  }else{
    _matriculaMedico[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setApellidoMedico(const std::string &apellidoMedico){
  if(apellidoMedico.length() <= 20){
    strcpy(_apellidoMedico, apellidoMedico.c_str());
  }else{
    _apellidoMedico[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setNombreMedico(const std::string &nombreMedico){
  if(nombreMedico.length() <= 20){
    strcpy(_nombreMedico, nombreMedico.c_str());
  }else{
    _nombreMedico[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setResultadoEstudio(const std::string &resultadoEstudio){
  if(resultadoEstudio.length() <= 35){
    strcpy(_resultadoEstudio, resultadoEstudio.c_str());
  }else{
    _resultadoEstudio[0]='\0';
  }
}

void EstudiosXHistoriasClinicas::setFechaEstudio(const Fecha &fechaEstudio){
  _fechaEstudio = fechaEstudio;
}

string EstudiosXHistoriasClinicas::getDNI() const{
  return string(_DNI);
}

string EstudiosXHistoriasClinicas::getIdHistoriaClinica() const{
  return string(_idHistoriaClinica);
}

string EstudiosXHistoriasClinicas::getCodigoEstudio() const{
  return string(_codigoEstudio);
}

string EstudiosXHistoriasClinicas::getMatriculaMedico() const{
  return string(_matriculaMedico);
}

string EstudiosXHistoriasClinicas::getApellidoMedico() const{
  return string(_apellidoMedico);
}

string EstudiosXHistoriasClinicas::getNombreMedico() const{
  return string(_nombreMedico);
}

string EstudiosXHistoriasClinicas::getResultadoEstudio() const{
  return string(_resultadoEstudio);
}

Fecha EstudiosXHistoriasClinicas::getFechaEstudio() const{
  return _fechaEstudio;
}
