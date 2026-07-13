#include <iostream>
#include <iomanip>

#include "ProfesionalXPacienteManager.h"
#include "ProfesionalManager.h"
#include "Disenio.h"

using namespace std;



bool ProfesionalXPacienteManager::agregarRegistro(const std::string &dniPaciente, const std::string &matriculaProfesional, bool &fallaPorMemoria){ //CAMBIO
  int cantidadRegistros = _profesionalXPacienteArchivo.getCantidadRegistros(_profesionalXPacienteArchivo.getNombreArchivo());
  //verificamos que ese dni y matricula no existan en el archivo
  if (cantidadRegistros>0){
    ProfesionalXPaciente *vecPxP = nullptr;
    vecPxP = new ProfesionalXPaciente[cantidadRegistros];

    if(vecPxP == nullptr){
      fallaPorMemoria = true;
      return false;
    }

    _profesionalXPacienteArchivo.leer(vecPxP, cantidadRegistros, _profesionalXPacienteArchivo.getNombreArchivo());

    for(int i = 0; i < cantidadRegistros; i++) {
      if(vecPxP[i].getDniPaciente() == dniPaciente && vecPxP[i].getMatriculaProfesional() == matriculaProfesional){
        delete[] vecPxP;
        return false;
      }
    }
    delete[] vecPxP;
  }//IF cantidadRegistros>0

  ProfesionalXPaciente nuevoRegistro (dniPaciente, matriculaProfesional);// si no exite la relacion, creo el objeto con los datos que me llegan por parametro


 if(_profesionalXPacienteArchivo.agregarRegistro(nuevoRegistro, _profesionalXPacienteArchivo.getNombreArchivo())){
  return true;
 } else{
  fallaPorMemoria = true;
  return false;
 }

}

void ProfesionalXPacienteManager::bucarProfesionalesPorDniPaciente(const std::string& dniPaciente) {
    int cantidad = _profesionalXPacienteArchivo.contarRegistrosPorDNI(dniPaciente);
    PacienteArchivo pArchivo;
    Paciente paciente = pArchivo.buscarPacientePorDni(dniPaciente);

    if (cantidad == -1) {
        cout << "Error: No se pudo abrir el archivo de profesionales por paciente." << endl;
        rlutil::anykey();
        return;
    }

    if (cantidad == 0) {
       int y = rlutil::trows() / 2;
        string mensaje = "No hay profesionales registrados para el paciente con DNI: " + dniPaciente;
        coutCentrado(mensaje, y);
        return;
    }

    // Si hay registros:
    ProfesionalXPaciente* vecPxP = new ProfesionalXPaciente[cantidad];
    if (vecPxP == nullptr) {
        cout << "Error al reservar memoria." << endl;
        return;
    }

    _profesionalXPacienteArchivo.buscarPorDNI(dniPaciente, vecPxP, cantidad);
    mostrarRegistrosProfesionales(paciente, vecPxP, cantidad);
    delete[] vecPxP;
}



void ProfesionalXPacienteManager::mostrarRegistrosProfesionales(Paciente &paciente, ProfesionalXPaciente *vecPxP, int cantidadRegistros) {
    system("cls");

    // no dibujo el cuadro primcipal, porque tengo que cambiar la fecha de lugar para que no se superponga con los datos de los medicos
      int anchoConsola = rlutil::tcols();
      int altoConsola = rlutil::trows()-1;

     dibujarCuadro(1,1, anchoConsola,altoConsola);
    Fecha fecha;
    rlutil::locate(anchoConsola-10, 2);
    cout << fecha.toString();


    int x = 3, y = 2;

    rlutil::locate(x, y);
    rlutil::setColor(rlutil::CYAN);
    cout << "PACIENTE: " << paciente.getNombre() << " " << paciente.getApellido();
     std::string titulo = cantidadRegistros == 1 ? "PROFESIONAL ASOCIADO" : "PROFESIONALES ASOCIADOS";
    int centrado = (rlutil::tcols() - titulo.length()) / 2;

    rlutil::locate(centrado, y);
    std::cout << titulo;


    y += 2;
   rlutil::setColor(rlutil::YELLOW);

    rlutil::locate(x, y++);
    cout << left;
    cout << setw(9)  << "Mat."
         << setw(8)  << "Leg."
         << setw(12) << "Nombre"
         << setw(12) << "Apellido"
         << setw(14) << "Rol"
         << setw(14) << "Especialidad"
         << setw(18) << "Telefono"
         << setw(15) << "Mail";


    rlutil::locate(x, y++);
    cout << string(rlutil::tcols() - 4, '-');
     rlutil::setColor(rlutil::WHITE);

    for (int i = 0; i < cantidadRegistros; i++) {
        // uso la funcion del manager que trae todos los profesionales a memoria y busca ahi asi no se cierra
        //y abre el archivo con cada iteracion
        ProfesionalManager pm;
        Profesional profe = pm.buscarPorMatricula(vecPxP[i].getMatriculaProfesional());


        rlutil::locate(x, y++);
        cout << setw(9)  << profe.getMatricula()
             << setw(8)  << profe.getLegajo()
             << setw(12) << profe.getNombre()
             << setw(12) << profe.getApellido()
             << setw(14) << rolToString(profe.getRol())
             << setw(14) << especialidadToString(profe.getEspecialidad())
             << setw(18) << profe.getTelefono()
             << setw(15) << profe.getMail();

}

    y++;

       // Botón [SALIR]
    int xSalir = calcularCentradoX("[ SALIR ]");
    int ySalir = 26;
    bool salir = false;
    int tecla;

    while (!salir) {
        rlutil::locate(xSalir, ySalir);
        rlutil::setBackgroundColor(rlutil::BLUE);
        rlutil::setColor(rlutil::WHITE);
        cout << "[ SALIR ]";
        rlutil::resetColor();

        tecla = rlutil::getkey();
        if (tecla == rlutil::KEY_ENTER) salir = true;
    }

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}
