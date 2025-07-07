#include "Inmueble.h"
#include <cstring>

using namespace std;

Inmueble::Inmueble(){
  _codigo = 0;
  _tipoPropiedad = 0;
  _calle[0] = '\0';
  _numero[0] = '\0';
  _antiguedad = 0;
  _superficieTotal = 0;
  _habitaciones = 0;
  _precioVenta = 0;
  _precioAlquiler = 0;
  _dniDueno[0] = '\0';
  _estado = true;
}

Inmueble::Inmueble(int codigo, int tipoPropiedad, string calle, string numero, int antiguedad, float superficieTotal, int habitaciones, float precioVenta, float precioAlquiler, string dniDueno, bool estado){
  setCodigo(codigo);
  setTipoPropiedad(tipoPropiedad);
  setCalle(calle);
  setNumero(numero);
  setAntiguedad(antiguedad);
  setSuperficieTotal(superficieTotal);
  setHabitaciones(habitaciones);
  setPrecioVenta(precioVenta);
  setPrecioAlquiler(precioAlquiler);
  setDniDueno(dniDueno);
  setEstado(estado);
}

void Inmueble::setCodigo(int codigo){
  _codigo = codigo;
}

void Inmueble::setTipoPropiedad(int tipoPropiedad){
  _tipoPropiedad = tipoPropiedad;
}

void Inmueble::setCalle(std::string calle){
  strcpy(_calle, calle.c_str());
}

void Inmueble::setNumero(std::string numero){
  strcpy(_numero, numero.c_str());
}

void Inmueble::setAntiguedad(int antiguedad){
  _antiguedad = antiguedad;
} 

void Inmueble::setSuperficieTotal(float superficieTotal){
  _superficieTotal = superficieTotal;
}

void Inmueble::setHabitaciones(int habitaciones){
  _habitaciones = habitaciones;
}

void Inmueble::setPrecioVenta(float precioVenta){
  _precioVenta = precioVenta;
}

void Inmueble::setPrecioAlquiler(float precioAlquiler){
  _precioAlquiler = precioAlquiler;
}

void Inmueble::setDniDueno(std::string dniDueno){
  strcpy(_dniDueno, dniDueno.c_str());
}

void Inmueble::setEstado(bool estado){
  _estado = estado;
}

int Inmueble::getCodigo(){
  return _codigo;
}

int Inmueble::getTipoPropiedad(){
  return _tipoPropiedad;
}

std::string Inmueble::getCalle(){
  return _calle;

}

std::string Inmueble::getNumero(){
  return _numero;
}

int Inmueble::getAntiguedad(){
  return _antiguedad;
}

float Inmueble::getSuperficieTotal(){
  return _superficieTotal;
}

int Inmueble::getHabitaciones(){
  return _habitaciones;
}

float Inmueble::getPrecioVenta(){
  return _precioVenta;
}

float Inmueble::getPrecioAlquiler(){
  return _precioAlquiler;
}

std::string Inmueble::getDniDueno(){
  return _dniDueno;
}

bool Inmueble::getEstado(){
  return _estado;
}

std::string Inmueble::toCSV(){
  string str = "";
  str = "Codigo " + to_string(_codigo) + ", ";
  str += "Tipo Propiedad " + to_string(_tipoPropiedad) + ", ";
  str += "Calle " + string(_calle) + ", ";
  str += "Numero " + string(_numero) + ", ";
  str += "Antiguedad " + to_string(_antiguedad) + ", ";
  str += "Superficie Total " + to_string(_superficieTotal) + ", ";
  str += "Habitaciones " + to_string(_habitaciones) + ", ";
  str += "Precio Venta " + to_string(_precioVenta) + ", ";
  str += "Precio Alquiler " + to_string(_precioAlquiler) + ", ";
  str += "DNI Dueno " + string(_dniDueno) + ", ";
  return str;
}

