#include "Fruta.h"
#include "json.hpp"
#include <string>

Fruta::Fruta(){
    setAzucar(0);
}

Fruta::Fruta(nlohmann::json datos){
    setNombre (datos["name"].get<std::string>());
    setID( datos["id"].get<int>());
    setAzucar ( datos["nutritions"]["sugar"].get<float>());
}

Fruta::Fruta(std::string _nombre, int _id, float _azucar){
    setNombre(_nombre);
    setID(_id);
    setAzucar(_azucar);
}

std::string Fruta::getNombre(){
    return _nombre;
}
int Fruta::getID(){
    return _id;
}
float Fruta::getAzucar(){
    return _azucar;
}


void Fruta::setNombre(std::string nombre){
    _nombre = nombre;
}
void Fruta::setID(int id){
    _id = id;
}
void Fruta::setAzucar(float azucar){
    _azucar = azucar;
}

std::string Fruta::toCSV(){
    std::string valor = "";
    valor += std::to_string(_id);
    valor += ",";
    valor += _nombre;
    valor += ",";
    valor += std::to_string(_azucar);
    return valor;
}
