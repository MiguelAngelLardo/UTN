#include "Persona.h"

   Persona::Persona(){
      _apellido = "";
      _nombre = "";
   }

   Persona::Persona(std::string apellido, std::string nombre){
      _apellido = apellido;
      _nombre = nombre;
   }

// Getters
    std::string Persona::getApellido(){
        return _apellido;
    }

    std::string Persona::getNombre(){
        return _nombre;
    }

    std::string Persona::getApellidoyNombre(){
       return _apellido + ", " + _nombre;
    }

    // Setters
    void Persona::setApellido(std::string apellido) {
        _apellido = apellido;
    }

    void Persona::setNombre(std::string nombre) {
        _nombre = nombre;
    }
