#pragma once
#include <string>


class Propietario{
private:
 char _nombre[50];
 char _apellido[50];
 char _DNI[12];
 char _celular [15];
 bool _estado; //true = activo, false = inactivo

 public:
  Propietario();
  Propietario(std::string nombre, std::string apellido, std::string dni, std::string celular, bool estado = true);

  void setNombre(std::string nombre);
  void setApellido(std::string apellido);
  void setDNI(std::string dni);
  void setCelular(std::string celular);
  void setEstado(bool estado);

  std::string getNombre();
  std::string getApellido();
  std::string getDNI(); 
  std::string getCelular();
  bool getEstado();

  std::string toCSV(); // Devuelve una cadena con los datos del propietario
 


};