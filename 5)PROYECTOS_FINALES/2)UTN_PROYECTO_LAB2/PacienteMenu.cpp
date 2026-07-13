#include <iostream>
#include "PacienteMenu.h"
#include "PacienteArchivo.h"
#include "PacienteManager.h"  //asi puede usar las funcionesd e cargar lista modificar etc etc
#include "Disenio.h"

using namespace std;

void PacienteMenu::pacienteMenu(){
  int opcion;

  do{
    rlutil::cls();
    opcion = crearMenuInteractivo("CARGAR UN PACIENTE,LISTAR PACIENTES,MODIFICAR PACIENTE,BUSCAR PACIENTE,LISTAR ESTUDIOS,LISTAR PROFESIONALES");
    rlutil::cls();
    switch (opcion)
    {
      case 1: _pacienteManager.cargarPaciente(); break;
      case 2: _pacienteManager.listarPacientes(); break;
      case 3: _pacienteManager.modificarPaciente(); break;
      case 4: _pacienteManager.buscarPaciente(); break;  
      case 5: _pacienteManager.listarEstudios();break;
      case 6: _pacienteManager.listarProfesionales(); break;

    }

  }while(opcion!=7);

   
}
