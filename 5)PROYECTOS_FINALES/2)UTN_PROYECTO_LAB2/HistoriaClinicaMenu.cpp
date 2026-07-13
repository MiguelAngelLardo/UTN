#include <iostream>
#include "HistoriaClinicaMenu.h"
#include "Disenio.h"
#include "rlutil.h"
using namespace std;

void HistoriaClinicaMenu::historiaClinicaMenu(){
  int opcion;
  do{ 
    rlutil::cls();
    opcion = crearMenuInteractivo("CARGAR REGISTRO DE UN PACIENTE,LISTAR HISTORIAS CLINICAS,ALTA MEDICA / REINGRESO,MODIFICAR HISTORIA CLINICA");
    rlutil::cls();

    switch(opcion){
      case 1: _historiaClinicaManager.cargarRegistro(); break;
      case 2: _historiaClinicaManager.listarHistoriasClinicas(); break;
      case 3: _historiaClinicaManager.altaMedica(); break;
      case 4: _historiaClinicaManager.modificarHistoriaClinica(); break;
    }

   

  } while (opcion != 5);


}
