#pragma once
#include <string>

class Persona{
  private:
    std::string _nombres, _apellidos;


  public: 
    std::string getNombres();
    std::string getApellidos();
    std::string getApellidosYNombres();

    void setNombres(std::string nombres);
    void setApellidos(std::string apellidos);

    Persona();
    Persona(std::string apellidos, std::string nombres);



};