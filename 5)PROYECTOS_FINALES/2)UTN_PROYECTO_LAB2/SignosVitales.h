#pragma once
#include <string>

class SignosVitales{
private:
  char _sistolica[11]; 
  char _diastolica[11];
  char _frecuenciaCardiaca[11];
  char _frecuenciaRespiratoria[11];
  char _saturacionOxigeno[11];
  char _temperatura[11];

public:
  SignosVitales();
  SignosVitales(std::string sist, std::string diast, std::string fc, std::string fr, std::string sat, std::string temp);
  void setSistolica(const std::string &sistolica);
  void setDiastolica(const std::string &diastolica);
  void setFrecuenciaCardiaca(const std::string &frecuenciaCardiaca);
  void setFrecuenciaRespiratoria(const std::string &frecuenciaRespiratoria);
  void setSaturacionOxigeno(const std::string &saturacionOxigeno);
  void setTemperatura(const std::string &temperatura);

  std::string getSistolica() const;
  std::string getDiastolica() const;
  std::string getFrecuenciaCardiaca() const;
  std::string getFrecuenciaRespiratoria() const;
  std::string getSaturacionOxigeno() const;
  std::string getTemperatura() const;
  
  void mostrar (int x, int &y) const;

    
};