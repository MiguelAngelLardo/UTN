#pragma once
#include <string>
#include "Fecha.h"
#include "Persona.h"


class Paciente: public Persona
{
public:
  Paciente();
  Paciente(std::string nom, std::string ape, std::string dom, std::string dni, std::string mail, std::string tel, 
         std::string obraSocial, std::string numeroDeAfiliado, std::string antecedenteFamiliar, std::string antecedentePaciente,
         Fecha fechaNacimiento, bool esUTI = true, bool estado = true);
  
  void setObraSocial(const std::string &obraSocial);
  void setNumeroDeAfiliado(const std::string &numeroDeAfiliado);
  void setAntecedenteFamiliar(const std::string &antecedenteFamiliar);
  void setAntecedentePaciente(const std::string &antecedentePaciente);
  void setFechaNacimiento(const Fecha &fechaNacimiento); //seteo fecha y _edad 
  void setEdad(const int &ed);
  void setEsUTI(const bool &esUTI);
  void setEstado(const bool &estado);

  std::string getObraSocial() const;
  std::string getNumeroDeAfiliado() const;
  std::string getAntecedenteFamiliar() const;
  std::string getAntecedentePaciente() const; //no modificolos miembros
  Fecha getFechaNacimiento() const;
  const int &getEdad() const;// const int & => no puedo modificar la referencia - () const es para poder usar paciente const
  bool getEsUTI() const;
  std::string getEsUTIStr() const;
  bool getEstado() const;
  std::string getEstadoStr() const;


  
  std::string toCSV() const;
  std::string toString() const override;  // uso overrride porque estoy sobrescribiendo un metodo virtual de una clase base, en este caso tsoSTring es un metodo virtual
  
  private:
  char _obraSocial[9];
  char _numeroDeAfiliado[9];
  char _antecedenteFamiliar[36];
  char _antecedentePaciente[36];
  Fecha _fechaNacimiento;
  int _edad;
  bool _esUTI;
  bool _estado;
  
  int calcularEdad() const;
  
};