#pragma once
#include <string>

class Persona {
   private:
      std::string _apellido;
      std::string _nombre;

   public:
      Persona();
      Persona(std::string apellido, std::string nombre);
      std::string getApellido();
      std::string getNombre();
      std::string getApellidoyNombre();
      void setApellido(std::string apellido);
      void setNombre(std::string nombre);
};
