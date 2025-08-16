#include "Fruta.h"

Fruta::Fruta() 
: _id(0), _nombre(""), _calorias(0), _familia(""){

}

Fruta::Fruta(int id, std::string nombre, int calorias, std::string familia)
{
  setID(id);
  setNombre(nombre);
  setCalorias(calorias);    
  setFamilia(familia);
}

Fruta::Fruta(nlohmann::json &data){
  setID(data["id"].get<int>());
  setNombre(data["name"].get<std::string>());
  setCalorias(data["nutritions"]["calories"].get<int>());
  setFamilia(data["family"].get<std::string>());
}

void Fruta::setID(int id) {
    _id = id;
}

void Fruta::setNombre(std::string nombre) {
    _nombre = nombre;
}

void Fruta::setCalorias(int calorias) {
    _calorias = calorias;
}

void Fruta::setFamilia(std::string familia){
  _familia = familia;
}

int Fruta::getID() {
    return _id;
}

std::string Fruta::getNombre() {
    return _nombre;
}

int Fruta::getCalorias() {
    return _calorias;
}

std::string Fruta::getFamilia(){
  return _familia;
}


std::string Fruta::toCSV(){
  return std::to_string(_id) + "," + _nombre + "," + std::to_string(_calorias) +","+_familia; 
}
