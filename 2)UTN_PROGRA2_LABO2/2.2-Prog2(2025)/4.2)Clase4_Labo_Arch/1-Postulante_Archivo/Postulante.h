#pragma once

#include <string>
class Postulante{
private:
  int   _id;
  char  _apellidos[50];
  char  _nombres[50];
  int   _edad;
  char  _puesto[50];
  int   _aniosExperiencia;
  bool  _contratado;

   public:
   Postulante();
   Postulante(int id, std::string apellidos, std::string nombres, int edad, std::string puesto, int aniosExperiencia, bool contratado);
   
   void setId(int id);
   void setApellidos(std::string apellidos);
   void setNombres(std::string nombres);
   void setEdad(int edad);
   void setPuesto(std::string puesto);
   void setAniosExperiencia(int aniosExperiencia);
   void setContratado(bool contratado);
   
   int getId();
   std::string getApellidos();
   std::string getNombres();
   int getEdad();
   std::string getPuesto();
   int getAniosExperiencia();
   bool getContratado();

   std::string toCSV();
};