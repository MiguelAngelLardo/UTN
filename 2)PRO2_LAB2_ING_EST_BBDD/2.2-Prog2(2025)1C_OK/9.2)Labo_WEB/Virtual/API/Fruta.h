#pragma once
#include <string>
#include "json.hpp"

class Fruta{
public:
  Fruta();
  Fruta(int id, std::string nombre, int calorias, std::string familia);
  Fruta(nlohmann::json &data);
  
  void setID(int id);
  void setNombre(std::string nombre);
  void setCalorias(int calorias);
  void setFamilia(std::string familia);
  
  int getID();
  std::string getNombre();
  int getCalorias();
  std::string getFamilia();
  
  std::string toCSV();
  
private:
  int _id;
  std::string _nombre;
  int _calorias;
  std::string _familia;
};
