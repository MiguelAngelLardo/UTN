#pragma once
#include <string>

class Inmueble
{
private:
  int _codigo;
  int _tipoPropiedad;
  char _calle[50];
  char _numero[6];
  int _antiguedad;
  float _superficieTotal;
  int _habitaciones;
  float _precioVenta;
  float _precioAlquiler;
  char _dniDueno[12];
  bool _estado;

public:
  Inmueble();
  Inmueble(int codigo, int tipoPropiedad, std::string calle, std::string numero, int antiguedad, float superficieTotal, int habitaciones, float precioVenta, float precioAlquiler, std::string dniDueno, bool estado);

  void setCodigo(int codigo);
  void setTipoPropiedad(int tipoPropiedad);
  void setCalle(std::string calle);
  void setNumero(std::string numero);
  void setAntiguedad(int antiguedad);
  void setSuperficieTotal(float superficieTotal);
  void setHabitaciones(int habitaciones);
  void setPrecioVenta(float precioVenta);
  void setPrecioAlquiler(float precioAlquiler);
  void setDniDueno(std::string dniDueno);
  void setEstado(bool estado);
  
  int getCodigo();
  int getTipoPropiedad();
  std::string getCalle();
  std::string getNumero();
  int getAntiguedad();
  float getSuperficieTotal();
  int getHabitaciones();
  float getPrecioVenta();
  float getPrecioAlquiler();
  std::string getDniDueno();
  bool getEstado();

  std::string toCSV();
};
