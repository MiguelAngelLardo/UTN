#include <iostream>
#include "AppMenu.h"
#include "Disenio.h"
#include "rlutil.h"
#include <thread> // Incluye la biblioteca de hilos para reproducir la musica separadamente

using namespace std;

void AppMenu::menuPrincipal() {
  int opcion;

  do{
    opcion = crearMenuInteractivo("MENU PACIENTE,MENU HISTORIA CLINICA");
    rlutil::cls();
    switch(opcion){
      case 1:
      _pacienteMenu.pacienteMenu();
      break;
      case 2:
      _historiaClinicaMenu.historiaClinicaMenu();
      break;
      case 3:
        mensajeSalida();
        break;
    }

  }while(opcion != 3); // 4 es la opción de salir

}


