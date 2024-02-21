#pragma once
#include <string>

class Horario{
  private:
    int _hora, _minuto, _segundo;
  
  public:
    int getHora();
    int getMinuto();
    int getSegundo();
    void setHora(int hora);
    void setMinuto(int minuto);
    void setSegundo(int segundo);
    Horario(); //pone hora del sistema
    Horario(int hora, int minuto, int segundo);
    std::string toString();
};