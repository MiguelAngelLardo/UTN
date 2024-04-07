#include "Temporizador.h"

Temporizador::Temporizador (){
  _hora = _minuto = _segundo = 0;
}

Temporizador::Temporizador(int hora, int minuto, int segundo){
  setHora(hora);
  setMinuto(minuto);
  setSegundo(segundo);
}

int Temporizador::getHora(){return _hora;}
int Temporizador::getMinuto(){return _minuto;}
int Temporizador::getSegundo(){return _segundo;}

void Temporizador::setHora(int hora){
  if(hora < 0 || hora > 24){
    _hora = 0;
  }else{
    _hora = hora;
  }
}

void Temporizador::setMinuto(int minuto){
  _minuto = (minuto < 0 || minuto > 59) ? 0 : minuto;
}

void Temporizador::setSegundo(int segundo){
  _segundo = (segundo < 0 || segundo > 59) ? 0 :segundo;

}

void Temporizador::tic(){_segundo ++;}

int Temporizador::comparar(const Temporizador &otroTemporizador){
  if (_hora < otroTemporizador._hora) {
    return +1;
  } else if (_hora > otroTemporizador._hora) {
    return -1;
  }
  
  if (_minuto < otroTemporizador._minuto) {
    return +1;
  } else if (_minuto > otroTemporizador._minuto) {
    return -1;
  }
  
  if (_segundo < otroTemporizador._segundo) {
     return +1;
  } else if (_segundo > otroTemporizador._segundo) {
    return -1;
  }
    
  return 0;
}

std::string Temporizador::toString(std::string formato){
  std::string tiempoFormateado;
  std::string HH, MM, SS;

  if(_hora < 10){
    HH = "0" + std::to_string(_hora);
  }else{
    HH = std::to_string(_hora);
  }

  if(_minuto < 10){
    MM = "0" + std::to_string(_minuto);
  }else{
    MM = std::to_string(_minuto);
  }

  if(_segundo < 10){
    SS = "0" + std::to_string(_segundo);
  }else{
    SS = std::to_string(_segundo);
  }

  if(formato == "HH:MM:SS"){
    tiempoFormateado = HH + ":" + MM + ":" + SS;
  }else if(formato == "SS:MM:HH"){
    tiempoFormateado = SS + "\"" + MM + "'" + HH + "H";
  }else{
    tiempoFormateado = HH + ":" + MM + ":" + SS;
  }

  return tiempoFormateado;
}