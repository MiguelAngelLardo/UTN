#include <cstring>
#include "PacienteArchivo.h"
using namespace std;

PacienteArchivo::PacienteArchivo(string nombreArchivo) {
  _nombreArchivo = nombreArchivo;
}

string PacienteArchivo::getNombreArchivo() const {
    return _nombreArchivo;
}

/** 
* @brief Busca el paciente con el DNI ingresado y devuelve su posición en el archivo
* @param dni DNI a buscar
* @return Posición del paciente en el archivo, si no lo encuentra devuelve -2 => significa que no esta en el archivo
*/
int PacienteArchivo::buscarPorDni(const string &dni) {
  Paciente reg;  
  FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
  if (pArchivo == nullptr) {
    return -1; 
  }

  int pos = 0;
  while (fread(&reg, sizeof(Paciente), 1, pArchivo)){
    if (reg.getDni() == dni) {
      fclose(pArchivo);
      return pos;
    }
    pos ++;
  }

  fclose(pArchivo);
  return -2;  
}


Paciente PacienteArchivo::buscarPacientePorDni(const string &dni) {  //este devuelve el objeto de paciente, el de abajo busca la posicion para sobreescribir
  int cantidad = getCantidadRegistros(getNombreArchivo());
  for (int i = 0; i < cantidad; ++i) {
      Paciente p = leer(i, getNombreArchivo());
      if(p.getDni() == dni){
        return p;
      }
  }
  return Paciente();  // supongo que si esta vacio devuelve vacio, tengo que probarlo
}


Paciente PacienteArchivo::buscarPacientePorNombre(const string &nombre) {
    int cantidad = getCantidadRegistros(getNombreArchivo());
    for (int i = 0; i < cantidad; ++i) {
        Paciente p = leer(i, getNombreArchivo());
        if (p.getNombre() == nombre){
          return p;
        }
    }
    return Paciente();
}

Paciente PacienteArchivo::buscarPacientePorApellido(const string &apellido) {
    int cantidad = getCantidadRegistros(getNombreArchivo());
    for (int i = 0; i < cantidad; ++i) {
        Paciente p = leer(i, getNombreArchivo());
        if (p.getApellido() == apellido){
            return p;  //aca etsa devolviendo el paciente
        }
    }
    return Paciente();
}

