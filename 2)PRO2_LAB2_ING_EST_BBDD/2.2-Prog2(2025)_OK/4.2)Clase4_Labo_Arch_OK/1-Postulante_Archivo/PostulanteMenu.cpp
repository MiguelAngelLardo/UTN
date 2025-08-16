#include "PostulanteMenu.h"
#include "PostulanteManager.h"
#include <iostream>
using namespace std;

// void PostulanteMenu::mostrar(){
//   PostulanteManager objPostMan;

//   int opcion;
//   do{
//     cout << "========================================================" << endl;
//     cout << "        SISTEMA DE REGISTRO DE POSTULANTES" << endl;
//     cout << "========================================================" << endl;
//     cout << "1. Registrar nuevo postulante" << endl;
//     cout << "2. Listar todos los postulantes" << endl;
//     cout << "3. Buscar postulantes por puesto y experiencia" << endl;
//     cout << "4. Mostrar postulantes contratados" << endl;
//     cout << "5. Cantidad de Registros" << endl;
//     cout << "6. Modificar postulante por ID" << endl;
//     cout << "0. Salir" << endl;
//     cout << "===============================" << endl;
//     cout << "Ingrese una opcion: ";

//     cin >> opcion;

//     switch(opcion) 
//     {
//     case 1:
//       objPostMan.cargarPostulante();
//       break;
//   case 2:
//       objPostMan.listarTodosLeyendoDeAUno();
//       break;
//     case 3:
//       objPostMan.mostrarPorPuestoYExperiencia();
//       break;
//     case 4:
//       objPostMan.listarContratados();
//       break;
//     case 5:
//       objPostMan.mostrarCantidadRegistros();
//       break;
//     case 6:{
//       objPostMan.modificarPostulante();
//     }break;
//     case 0:
//       cout << "Saliendo..." << endl;
//     break;
//    }


//     cout << endl << endl;

//   }while(opcion != 0);
// }