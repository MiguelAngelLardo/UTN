#pragma once
//#include "Paciente.h"
#include <string>
#include "PacienteArchivo.h"

class PacienteManager{
private:
  PacienteArchivo _pacienteArchivo;

  //FX UTILITARIAS
  void validarPacienteGetEstado(int indice, int yActual, int deltaYEstatica, bool modificale = false);
  bool validarPacienteGetNroafiliado_OS(std::string os, std::string nroAfiliado, int yActual, int deltaYEstatica);

  bool seleccionarTipoHabitacion(const std::string& textoAMostrar, int &yActual);
  

  //templates para el buscar => podria haber hecho paciente solo y hacer un cast a persona pero preferi mantenerlo separado
  template <typename T> // Para métodos de Persona (nombre, apellido, etc.)
  Paciente *buscarPorAtributoPersona(T (Persona::*getGeter)() const, const std::string &criterioSeleccion, int &contDeBusqueda);//no puedo inicializar una referencia en un valor
  template <typename T>//T = type de dato -  getGeter () por q no recibe param => se usa en el buscar
  Paciente *buscarPorAtributoPaciente(T (Paciente::*getGeter)() const, const std::string &criterioSeleccion, int &contDeBusqueda);

public:

  void cargarPaciente();
  void listarPacientes();
  void modificarPaciente();
  void buscarPaciente();
  
  /***tablas aux */
  void listarEstudios();
  void listarProfesionales();
};

