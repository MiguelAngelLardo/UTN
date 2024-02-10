#pragma once
#include <string>
#include "fecha.h"

class Investigador{
  private:
    char _nombre[30];
    std::string _apellido;
    Fecha _fechaNacimiento;
    int _unidadAcademica;// 1 al 30
    int _categoria; // 1 al 5
    int _especialidad; //1 al 10
    int dni;

  public: 
    const char* getNombre();
    std::string getApellido();
    Fecha getFechaNacimiento();
    int getUnidadAcademica();
    int getCategoria();
    int getEspecialidad();
    int getDNI();

    void setNombre (const char n[]);
    void setApellido (std::string apellido);
    void setFechaNacimiento (Fecha fechaNacimiento);
    void setUnidadAcademica (int unidadAcademica);
    void setCategoria (int categoria);
    void setEspecialidad (int especialidad);
    void setDNI (int dni);

    Investigador();
    Investigador (const char *nombre, std::string apellido, Fecha fechaNAcimiento,  int unidadAcademica, int categoria, int especialidad, int dni);
    std::string toString();
};