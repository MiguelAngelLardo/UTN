#include <iostream>
#include <cstring>
#include <cstdlib>  // para atof, strtof => castea de char a float
#include "rlutil.h"

#include "SignosVitales.h"

using namespace std;

 SignosVitales::SignosVitales(){
  strcpy(_sistolica,"No cargado");
  strcpy(_diastolica,"No cargado");
  strcpy(_frecuenciaCardiaca,"No cargado");
  strcpy(_frecuenciaRespiratoria,"No cargado");
  strcpy(_temperatura,"No cargado");
  strcpy(_saturacionOxigeno,"No cargado");
}

SignosVitales::SignosVitales(std::string sist, std::string diast, std::string fc, std::string fr, std::string sat, std::string temp){
  setSistolica(sist);
  setDiastolica(diast);
  setFrecuenciaCardiaca(fc);
  setFrecuenciaRespiratoria(fr);
  setSaturacionOxigeno(sat);
  setTemperatura(temp);
}

void SignosVitales::setSistolica(const std::string &sistolica){
  if(sistolica.length() >= 2 && sistolica.length() <= 3) {
    strcpy(_sistolica, sistolica.c_str());
  }else{
    _sistolica[0] = '\0';
  }
}

void SignosVitales::setDiastolica(const std::string &diastolica){
  if(diastolica.length() >= 2 && diastolica.length() <= 3) {
    strcpy(_diastolica, diastolica.c_str());
  }else{
    _diastolica[0] = '\0';
  }
}

void SignosVitales::setFrecuenciaCardiaca(const std::string &frecuenciaCardiaca){
  if(frecuenciaCardiaca.length() >= 2 && frecuenciaCardiaca.length() <= 3) {
    strcpy(_frecuenciaCardiaca, frecuenciaCardiaca.c_str());
  }else{
    _frecuenciaCardiaca[0] = '\0';
  }
}

void SignosVitales::setFrecuenciaRespiratoria(const std::string &frecuenciaRespiratoria){
  if(frecuenciaRespiratoria.length() >= 1 && frecuenciaRespiratoria.length() <= 2) {
    strcpy(_frecuenciaRespiratoria, frecuenciaRespiratoria.c_str());
  }else{
    _frecuenciaRespiratoria[0] = '\0';
  }
}

void SignosVitales::setSaturacionOxigeno(const std::string &saturacionOxigeno){
  if(saturacionOxigeno.length() >= 1 && saturacionOxigeno.length() <= 2) {
    strcpy(_saturacionOxigeno, saturacionOxigeno.c_str());
  }else{
    _saturacionOxigeno[0] = '\0';
  }
}

void SignosVitales::setTemperatura(const std::string &temperatura){
  float temperaturaCasteada = atof(temperatura.c_str());  // string → char* → float
  if(temperaturaCasteada >= 25 && temperaturaCasteada <= 45) {//comparo float con numero constante
    strcpy(_temperatura, temperatura.c_str());
  } else {
    _temperatura[0] = '\0';
  }
}

string SignosVitales::getSistolica() const{
  return string(_sistolica);
}

string SignosVitales::getDiastolica() const{
  return string(_diastolica);
}

string SignosVitales::getFrecuenciaCardiaca() const{
  return string(_frecuenciaCardiaca);
}

string SignosVitales::getFrecuenciaRespiratoria() const{
  return string(_frecuenciaRespiratoria);
}

string SignosVitales::getSaturacionOxigeno() const{
  return string(_saturacionOxigeno);
}

string SignosVitales::getTemperatura() const{
  return string(_temperatura);
}

void SignosVitales::mostrar(int x, int &y) const {
  rlutil::locate(x, y++); cout << "Presion Arterial: " << _sistolica <<"/"<< _diastolica;
  rlutil::locate(x, y++); cout << "Frecuencia cardiaca: " << _frecuenciaCardiaca;
  rlutil::locate(x, y++); cout << "Frecuencia respiratoria: " << _frecuenciaRespiratoria;
  rlutil::locate(x, y++); cout << "Temperatura: " << _temperatura;
  rlutil::locate(x, y++); cout << "Saturacion Oxigeno: " << _saturacionOxigeno;
}
