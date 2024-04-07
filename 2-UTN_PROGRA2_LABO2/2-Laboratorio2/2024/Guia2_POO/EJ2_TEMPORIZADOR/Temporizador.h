#pragma once
#include <string>

class Temporizador{
private:
  int _hora, _minuto,  _segundo;

public:
  Temporizador();
  Temporizador(int hora, int minuto, int segundo);

  int getHora();
  int getMinuto();
  int getSegundo();
  void setHora(int hora);
  void setMinuto(int minuto);
  void setSegundo(int segundo);
  
  void tic();
  int comparar(const Temporizador &otroTemporizador);
  //const es para que otroTemporizador no sea modificado
  //hago referencia para evitar copias innecesarias

  std::string toString(std::string formato = "HH:MM:SS");

};