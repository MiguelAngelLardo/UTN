#include <iostream>
#include <iomanip>
#include "EstudiosManager.h"
#include "Disenio.h"
#include "Validaciones.h"
using namespace std;


void EstudiosManager::cargarEstudiosPorDefecto() {
  Estudios estudiosPredefinidos[] = {
  Estudios("LABO", "Laboratorio clinico"),
  Estudios("RAYO", "Radiografia"),
  Estudios("TOMO", "Tomografia computada"),
  Estudios("RESO", "Resonancia magnetica"),
  Estudios("ECOG", "Ecografia"),
  Estudios("ECGS", "Electrocardiograma"),
  Estudios("EEGG", "Electroencefalograma"),
  Estudios("ENDG", "Endoscopia"),
  Estudios("COLN", "Colonoscopia"),
  Estudios("BIOP", "Biopsia"),
  Estudios("ERGO", "Ergometria"),
  Estudios("MONI", "Monitoreo"),
  Estudios("DIAB", "Control de glucemia"),
  Estudios("URIN", "Analisis de orina"),
  Estudios("HEMO", "Hemograma completo"),
  Estudios("FUNC", "Funcion hepatica"),
  Estudios("PERF", "Perfil lipidico"),
  Estudios("TSHS", "Perfil tiroideo"),
  Estudios("ORIN", "Orina completa"),
  Estudios("HCGP", "Test de embarazo"),
  Estudios("RXTX", "Radiografia de torax"),
  Estudios("OTRO", "Otro estudio clinico"),
};

  int cantidad = sizeof(estudiosPredefinidos) / sizeof(estudiosPredefinidos[0]);

  for (int i = 0; i < cantidad; i++) {
    if (_estudioArchivo.agregarRegistro(estudiosPredefinidos[i], _estudioArchivo.getNombreArchivo())) {
      std::cout << "Estudio " << estudiosPredefinidos[i].getCodigoEstudio() << " agregado correctamente." << std::endl;
    } else {
      std::cout << "Error al agregar el estudio " << estudiosPredefinidos[i].getCodigoEstudio() << std::endl;
    }
  }
}

Estudios EstudiosManager::listaEstudiosActuales() {
  int opcion;
  Estudios *vecEstudios = nullptr;

  int cantidadRegistros = _estudioArchivo.getCantidadRegistros(_estudioArchivo.getNombreArchivo());
  if (cantidadRegistros == 0) {
    std::cout << "No hay estudios cargados." << std::endl;
    return Estudios(); // Devuelve vacío
  }

  vecEstudios = new Estudios[cantidadRegistros];
  if (vecEstudios == nullptr) {
    std::cout << "Error al reservar memoria para los estudios." << std::endl;
    return Estudios();
  }

  _estudioArchivo.leer(vecEstudios,cantidadRegistros,_estudioArchivo.getNombreArchivo());
  rlutil::cls(); //borrar pantalla ante de entrar al menu
  opcion = crearMenuInteractivo(opcionesParaMenu(vecEstudios, cantidadRegistros));
  rlutil::cls(); //borrar pantalla al salir del menu

  if (opcion == cantidadRegistros + 1) {
    delete[] vecEstudios;
    return Estudios(); // Devuelve vacío si elige salir
  }

  Estudios seleccionado = _estudioArchivo.leer(opcion - 1, _estudioArchivo.getNombreArchivo());
  delete[] vecEstudios;
  return seleccionado;
}

std::string EstudiosManager::opcionesParaMenu(Estudios estudios[], int cantidad) {
  const int anchoCodigo = 10;
  const int anchoDescripcion = 35;
  std::string opciones = "";
  rlutil::setColor(rlutil::YELLOW);
  rlutil::locate(38, 2);
  std::cout << std::left << std::setw(anchoCodigo) << "CODIGO" << std::setw(anchoDescripcion) << "DESCRIPCION" << std::endl;

  rlutil::setColor(rlutil::WHITE);  // Texto del menú
  for (int i = 0; i < cantidad; i++) {
    std::string linea;

    std::string codigo = estudios[i].getCodigoEstudio();
    codigo += std::string(anchoCodigo - codigo.length(), ' ');

    std::string descripcion = estudios[i].getDescripcion();
    descripcion += std::string(anchoDescripcion - descripcion.length(), ' ');

    linea = codigo + descripcion;
    opciones += linea;
    if (i < cantidad - 1) opciones += ",";
  }


  return opciones;
}

// traigo todos los estudios a memoria para poder hacer la busqueda sin abrir y cerrar el archivo todo el tiempo
 Estudios EstudiosManager::buscarEstudioPorCodigo(const string &codigoEstudio){
  int cantidad = _estudioArchivo.getCantidadRegistros(_estudioArchivo.getNombreArchivo());
  if(cantidad == -1){
    cout << "Error al abrir el archivo de estudios." << endl;
    return Estudios();
  } else if(cantidad == -2){
    cout << "No se encontró el estudio con el código: " << codigoEstudio << endl;
    return Estudios();
  }
  Estudios *vecEstudios = new Estudios[cantidad];
  if(vecEstudios == nullptr){
    cout << "Error al reservar memoria para los estudios." << endl;
    return Estudios();
  }
  _estudioArchivo.leer(vecEstudios, cantidad, _estudioArchivo.getNombreArchivo());
    for(int i = 0; i < cantidad; i++){
      if(vecEstudios[i].getCodigoEstudio() == codigoEstudio){
        Estudios estudio= vecEstudios[i];
        delete[] vecEstudios;
        return estudio;
      }
    }
  delete[] vecEstudios;

}

