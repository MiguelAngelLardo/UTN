#include <iostream>
#include <cstring>
#include "HistoriaClinica.h"
#include "rlutil.h"

using namespace std;

HistoriaClinica::HistoriaClinica() {
  _codigoHC[0] = '\0';
  _signosVitales = SignosVitales();
  strcpy(_matriculaProfesional,"No cargado");
  _fechaActual = Fecha();
  strcpy(_diagnostico, "No cargado");
  strcpy(_tratamiento, "No cargado");
  strcpy(_medicacion, "No cargada");
  _altaMedica = false;
  _altaSistema = false;
  _estadoRegistro = true;
}



HistoriaClinica::HistoriaClinica(string codigoHC, string matriculaProf, SignosVitales signosVitales,
                    string diagnostico, string tratamiento, string medicacion,
                    bool altaMedica, bool altaSistema, bool estadoRegistro){
  setCodigoHC(codigoHC);
  _fechaActual = Fecha();
  setMatriculaProfesional(matriculaProf);
  setSignosVitales(signosVitales);

  setDiagnostico(diagnostico);
  setTratamiento(tratamiento);
  setMedicacion(medicacion);

  setAltaMedica(altaMedica);
  setAltaSistema(altaSistema);
  setEstadoRegistro(estadoRegistro);

}



void HistoriaClinica::setCodigoHC(const string &codigoHC) {
  if (codigoHC.length() <= 4) {
    strcpy(_codigoHC, codigoHC.c_str());
  } else {
    _codigoHC[0] = '\0';
  }
}

void HistoriaClinica::setMatriculaProfesional(const std::string &matProf){
  if (matProf.length() <= 8) {
    strcpy(_matriculaProfesional, matProf.c_str());
  } else {
    _matriculaProfesional[0] = '\0';
  }
}


void HistoriaClinica::setSignosVitales(const SignosVitales &signosVitales) {
  _signosVitales = signosVitales;
}

void HistoriaClinica::setDiagnostico(const string &diagnostico) {
  if (diagnostico.length() <= 35) {
    strcpy(_diagnostico, diagnostico.c_str());
  } else {
    _diagnostico[0] = '\0';
  }
}

void HistoriaClinica::setTratamiento(const string &tratamiento) {
  if (tratamiento.length() <= 35) {
    strcpy(_tratamiento, tratamiento.c_str());
  } else {
    _tratamiento[0] = '\0';
  }
}

void HistoriaClinica::setMedicacion(const string &medicacion) {
  if (medicacion.length() <= 35) {
    strcpy(_medicacion, medicacion.c_str());
  } else {
    _medicacion[0] = '\0';
  }
}

void HistoriaClinica::setAltaMedica(const bool &altaMedica) {
  _altaMedica = altaMedica;
}

void HistoriaClinica::setAltaSistema(const bool &altaSistema) {
  _altaSistema = altaSistema;
}

void HistoriaClinica::setEstadoRegistro(const bool &estadoRegistro) {
  _estadoRegistro = estadoRegistro;
}

string HistoriaClinica::getCodigoHC() const {
  return string(_codigoHC);
}

string HistoriaClinica::getMatriculaProfesional() const{
  return string(_matriculaProfesional);
}


Fecha HistoriaClinica::getFecha() const{
  return _fechaActual;
}

SignosVitales HistoriaClinica::getSignosVitales() const {
  return _signosVitales;
}

string HistoriaClinica::getDiagnostico() const {
  return string(_diagnostico);
}

string HistoriaClinica::getTratamiento() const {
  return string(_tratamiento);
}

string HistoriaClinica::getMedicacion() const {
  return string(_medicacion);
}

bool HistoriaClinica::getAltaMedica() const {
  return _altaMedica;
}

string HistoriaClinica::getAltaMedicaStr() const{
  return _altaMedica ? "SI" : "NO";
}

bool HistoriaClinica::getAltaSistema() const{
  return _altaSistema;
}

string HistoriaClinica::getAltaSistemaStr() const{
  return _altaSistema ? "SI" : "NO";
}


bool HistoriaClinica::getEstadoRegistro() const {
  return _estadoRegistro;
}

string HistoriaClinica::getEstadoRegistroStr() const{
  return _estadoRegistro ? "Activo" : "Dado de baja";
}

