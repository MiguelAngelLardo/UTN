#pragma once
#include "HistoriaClinicaArchivo.h"
#include "PacienteArchivo.h"//es para buscar por el DNI - ya me trae #include "Paciente.h"
#include "ProfesionalManager.h"
#include "EstudiosManager.h"
#include "ProfesionalXPacienteManager.h"
#include "EstudiosXHistoriaClinicaManager.h"

class HistoriaClinicaManager{
public: 
  //primarias
  void cargarRegistro();
  void listarHistoriasClinicas();
  void altaMedica();
  void modificarHistoriaClinica();
  


private:
  HistoriaClinicaArchivo _historiaClinicaArchivo;
  ProfesionalManager _profesionalManager;
  EstudiosManager _estudiosManager;
  ProfesionalXPacienteManager _profesionalXPacienteManager;
  EstudiosXHistoriaClinicaManager _estudiosXHistoriaClinicaManager;

    
  //utilitarias
  std::string generarCodigoHC(std::string nombreArchivo);
  std::string obtenerDniDelPuntoDat(std::string nombreArchivo);
  void primeraCargaHistorica(std::string nombreArchivo, int &yActual);//adentro tiene un wb - dentro de cargarRegistro
  void adicionarRegistro(std::string nombreArchivo, int &yActual);//adentrode cargarRegistro
  void adicionarAlta_Reingreso(Paciente paciente, std::string nombreArchivo, int &yActual, int deltaYEstatica, bool altaMedica);//esta dentro de altaMEdica()
  bool validarAlta_Medica_Sistema_Estado(std::string nombreDelArchivo, int indice, int yActual, int deltaYEstatica);
  bool validarGetEstadoPaciente_cargaIndice(std::string dniPaciente, int &indiceDelDniBuscado, int &yActual, int deltaYEstatica);//se usa en carga y altaMedica
  void replicarY3(std::string dni);



};