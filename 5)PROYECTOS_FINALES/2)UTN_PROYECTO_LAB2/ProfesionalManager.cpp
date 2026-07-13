#include <iostream>
#include <iomanip>
#include "profesionalManager.h"
#include "Disenio.h"
#include "Validaciones.h"

using namespace std;

ProfesionalManager::ProfesionalManager()
{
    _profesionalArchivo = ProfesionalArchivo();
}


int ProfesionalManager::establecerLegajo(){
  const int LEGAJO_BASE = 10000;
  int legajo;
  int cantidadRegistros = _profesionalArchivo.getCantidadRegistros(_profesionalArchivo.getNombreArchivo());
  return  legajo = LEGAJO_BASE + (cantidadRegistros + 1);

}





Profesional ProfesionalManager ::ProfesionalManager::buscarPorMatricula(const string &matricula)
{
    int pos = _profesionalArchivo.buscarPorMatricula(matricula);
    if (pos < 0)
    {
        return Profesional();
    }
     return _profesionalArchivo.leer(pos, _profesionalArchivo.getNombreArchivo());
}


Profesional ProfesionalManager :: listaProfesionalesActuales(){
int opcion;
Profesional *vecProfesionales = nullptr;

 int cantidadRegistros = _profesionalArchivo.getCantidadRegistros(_profesionalArchivo.getNombreArchivo());
  if (cantidadRegistros == 0){
    cout << "No hay profesionales registrados." << endl;
    return Profesional();
  }


  vecProfesionales = new Profesional[cantidadRegistros];
  if (vecProfesionales == nullptr){
    cout << "Error al reservar memoria para los profesionales." << endl;
    return Profesional();
  }

  _profesionalArchivo.leer(vecProfesionales, cantidadRegistros, _profesionalArchivo.getNombreArchivo()); //lcargo vec con leer
  rlutil::cls(); //borrar pantalla ante de entrar al menu
  opcion= crearMenuInteractivo(opcionesParaMenu(vecProfesionales, cantidadRegistros));
  rlutil::cls(); //borrar pantalla al salir del menu

  if (opcion == cantidadRegistros + 1) {//si elige salir sale y me da objeto vacio
    delete[] vecProfesionales;
    return Profesional(); // Devuelve objeto vacío si elige salir
  }

  delete[] vecProfesionales;
  return _profesionalArchivo.leer(opcion-1, _profesionalArchivo.getNombreArchivo());//le resto uno por que va de 0 a n-1
}


std::string ProfesionalManager::opcionesParaMenu(Profesional profesionales[], int cantidad) {
    // Constantes para el ancho de cada columna
  int anchoLegajo = 10; //tiene 10 de ancho y el setw lo
  int anchoApellido = 13;
  int anchoNombre = 13;
  int anchoRol= 12;
  int anchoEspecialidad = 15;

  std::string opciones = "";
  rlutil::setColor(rlutil::YELLOW);
  rlutil::locate(29, 2);
  std::cout << std::left << std::setw(anchoLegajo) << "LEGAJO"  << std::setw(anchoApellido) << "APELLIDO"
            << std::setw(anchoNombre) << "NOMBRE"  << std::setw(anchoRol) << "ROL"
            << std::setw(anchoEspecialidad) << "ESPECIALIDAD"  << std::endl;//lo mando en cout normal sin parametro de menu interactivo

  rlutil::setColor(rlutil::WHITE); // Recorrer profesionales y construir línea alineada por cada uno

  for (int i = 0; i < cantidad; i++) {//cant vector
        std::string linea = "";

        std::string legajo = std::to_string(profesionales[i].getLegajo());
        legajo += std::string(anchoLegajo - legajo.length(), ' ');//10000 + 5 espacios

        std::string apellido = profesionales[i].getApellido();
        apellido += std::string(anchoApellido - apellido.length(), ' ');

        std::string nombre = profesionales[i].getNombre();
        nombre += std::string(anchoNombre- nombre.length(), ' ');

        std::string rol = rolToString(profesionales[i].getRol());
        rol += std::string(anchoRol - rol.length(), ' ');

        std::string especialidad = especialidadToString(profesionales[i].getEspecialidad());
        especialidad += std::string(anchoEspecialidad - especialidad.length(), ' ');

        linea = legajo + apellido + nombre + rol + especialidad;

        opciones += linea;

        if (i < cantidad - 1) {
            opciones += ",";  // separador para el vector de opciones
        }
    }

    return opciones;
}

//funcion para cargar por defecto 20 profesionales y gurdarlos en el .dat
void ProfesionalManager::generarProfesionalesDePrueba() {
    _profesionalArchivo.agregarRegistro(Profesional("Juan", "Gomez", "Av. Siempreviva 742", "12345678", "juan.gomez@gmail.com", "+54 11 4000-1234", "112233", establecerLegajo(), Rol::Medico, Especialidad::Cardiologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Ana", "Fernandez", "Pringles 123", "23456789", "ana.fernandez@hotmail.com", "+54 11 4001-5678", "113344", establecerLegajo(), Rol::Medico, Especialidad::Pediatria), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Carlos", "Lopez", "Boulevard Central 456", "34567890", "carlos.lopez@yahoo.com", "+54 11 4002-6789", "114455", establecerLegajo(), Rol::Medico, Especialidad::Nefrologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Lucia", "Martinez", "Av. Libertad 890", "45678901", "lucia.martinez@outlook.com", "+54 11 4003-7890", "115566", establecerLegajo(), Rol::Medico, Especialidad::Neurologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Pedro", "Perez", "Bolivar 321", "56789012", "pedro.perez@gmail.com", "+54 11 4004-8901", "116677", establecerLegajo(), Rol::Medico, Especialidad::Traumatologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Sofia", "Garcia", "Calle 9 de Julio 555", "67890123", "sofia.garcia@hotmail.com", "+54 11 4005-9012", "117788", establecerLegajo(), Rol::Medico, Especialidad::Psiquiatra), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Luis", "Rodriguez", "Avenida Mitre 876", "78901234", "luis.rodriguez@yahoo.com", "+54 11 4006-0123", "118899", establecerLegajo(), Rol::Medico, Especialidad::Oncologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Clara", "Torres", "Independencia 432", "11223344", "clara.torres@hotmail.com", "+54 11 4009-3456", "154328", establecerLegajo(), Rol::Medico, Especialidad::Neumologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Valentin", "Silva", "Sarmiento 654", "22334455", "valentin.silva@yahoo.com", "+54 11 4010-4567", "123212", establecerLegajo(), Rol::Medico, Especialidad::Neurologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Florencia", "Ruiz", "Avenida Rivadavia 888", "33445566", "flor.ruiz@outlook.com", "+54 11 4011-5678", "132244", establecerLegajo(), Rol::Enfermero, Especialidad::No_Definida), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Diego", "Vazquez", "Moreno 111", "44556677", "diego.vazquez@gmail.com", "+54 11 4012-6789", "145566", establecerLegajo(), Rol::Enfermero, Especialidad::Intensivista), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Tomas", "Castro", "Ituzaingo 444", "88990011", "tomas.castro@gmail.com", "+54 11 4016-0123", "145466", establecerLegajo(), Rol::Medico, Especialidad::Fisiatra), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Martin", "Ibarra", "Avenida Colon 101", "10111223", "martin.ibarra@yahoo.com", "+54 11 4018-2345", "165432", establecerLegajo(), Rol::Medico, Especialidad::Virologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Agustina", "Navarro", "La Pampa 202", "11121324", "agus.navarro@outlook.com", "+54 11 4019-3456", "112121", establecerLegajo(), Rol::Medico, Especialidad::Obstetra), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Bruno", "Reino", "Pasteur 123", "22233344", "bruno.reino@hospital.com", "+54 11 4020-1234", "154321", establecerLegajo(), Rol::Tecnico, Especialidad::Laboratorio), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Carla", "Vega", "Avenida Rayos 456", "33344455", "carla.vega@hospital.com", "+54 11 4021-2345", "165432", establecerLegajo(), Rol::Tecnico, Especialidad::Rayos), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Dario", "Ramirez", "Sarmiento 789", "44455566", "dario.ramirez@rehab.com", "+54 11 4022-3456", "176543", establecerLegajo(), Rol::Kinesiologo, Especialidad::Motor), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Elena", "Acosta", "Salta 321", "55566677", "elena.acosta@rehab.com", "+54 11 4023-4567", "187654", establecerLegajo(), Rol::Kinesiologo, Especialidad::Respiratorio), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Federico", "Sosa", "Independencia 654", "66677788", "federico.sosa@hpc.com", "+54 11 4024-5678", "198765", establecerLegajo(), Rol::Enfermero, Especialidad::No_Definida), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Gabriela", "Juarez", "Pelayo 987", "77788899", "gabriela.nunez@hpc.com", "+54 11 4025-6789", "209876", establecerLegajo(), Rol::Enfermero, Especialidad::Intensivista), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Ignacio", "Herrera", "Storni", "88899900", "ignacioherrera@hpc.com", "+54 11 4026-7890", "210987", establecerLegajo(), Rol::Medico, Especialidad::Cardiologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Jazmin", "Ortega", "Armenia 222", "99900011", "jaz.ortega@hospital.com", "+54 11 4027-8901", "221098", establecerLegajo(), Rol::Medico, Especialidad::Virologo), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Lucas", "Mendez", "Brown 333", "00011122", "lucas.mendez@hospital.com", "+54 11 4028-9012", "232109", establecerLegajo(), Rol::Tecnico, Especialidad::Laboratorio), _profesionalArchivo.getNombreArchivo());
    _profesionalArchivo.agregarRegistro(Profesional("Milagros", "Benitez", "Belgrano 444", "11122233", "mili.benitez@hospital.com", "+54 11 4029-0123", "243210", establecerLegajo(), Rol::Tecnico, Especialidad::Rayos), _profesionalArchivo.getNombreArchivo());
}
