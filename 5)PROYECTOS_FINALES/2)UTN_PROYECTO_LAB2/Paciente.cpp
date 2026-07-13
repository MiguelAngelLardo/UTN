#include <cstring>
#include "Paciente.h"
using namespace std;

Paciente::Paciente(): Persona() {
  _obraSocial[0] = '\0';
  _numeroDeAfiliado[0] = '\0';
  strcpy(_antecedenteFamiliar, "No cargado");
  strcpy(_antecedentePaciente, "No cargado");
  _fechaNacimiento = Fecha();//fecha actual por defecto
  _esUTI = true;
  _estado = true;
}

Paciente::Paciente(string nom, string ape, string dom, string dni, string mail, string tel, string obraSocial, string numeroDeAfiliado, string antecedenteFamiliar, string antecedentePaciente, Fecha fechaNacimiento, bool esUTI, bool estado)
: Persona(nom, ape, dom, dni, mail, tel){
    setObraSocial(obraSocial);
    setNumeroDeAfiliado(numeroDeAfiliado);
    setFechaNacimiento(fechaNacimiento);
    setAntecedenteFamiliar(antecedenteFamiliar);
    setAntecedentePaciente(antecedentePaciente);
    setFechaNacimiento(fechaNacimiento); //inicializo a _fechaNacimiento y calculo solo la edad
    setEsUTI(esUTI);
    setEstado(estado);
}

void Paciente::setObraSocial(const string &obraSocial) {
  if(obraSocial.size() <= 8) {
    strcpy(_obraSocial, obraSocial.c_str());
  } else {
    _obraSocial[0] = '\0';
  }
}

void Paciente::setNumeroDeAfiliado(const string &numeroDeAfiliado) {
  if(numeroDeAfiliado.size() <= 8) {
    strcpy(_numeroDeAfiliado, numeroDeAfiliado.c_str());
  } else {
    _numeroDeAfiliado[0] = '\0';
  }
}


void Paciente::setAntecedenteFamiliar(const string &antecedenteFamiliar) {
  if(antecedenteFamiliar.size() <= 35){
    strcpy(_antecedenteFamiliar, antecedenteFamiliar.c_str());
  }else{
    _antecedenteFamiliar[0] = '\0';
  }
}

void Paciente::setAntecedentePaciente(const string &antecedentePaciente) {
  if(antecedentePaciente.size() <= 35){
    strcpy(_antecedentePaciente, antecedentePaciente.c_str());
  }else{
    _antecedentePaciente[0] = '\0';
  }
}

void Paciente::setFechaNacimiento(const Fecha &fechaNacimiento) {
  _fechaNacimiento = fechaNacimiento;
  _edad = calcularEdad(); 
}

void Paciente::setEdad(const int &ed){
  (ed>0 && ed<120) ? _edad = ed : _edad = 0;
}

void Paciente::setEsUTI(const bool &esUTI) {
  _esUTI = esUTI;
}

void Paciente::setEstado(const bool &estado) {
  _estado = estado;
}

string Paciente::getObraSocial() const {
  return string(_obraSocial);
}

string Paciente::getNumeroDeAfiliado() const {
  return string(_numeroDeAfiliado);
}

string Paciente::getAntecedenteFamiliar() const {
  return string(_antecedenteFamiliar);
}

string Paciente::getAntecedentePaciente() const {
  return string(_antecedentePaciente);
}

Fecha Paciente::getFechaNacimiento() const {
  return _fechaNacimiento;
}

const int &Paciente::getEdad() const{
  return _edad;
}


bool Paciente::getEsUTI() const {
  return _esUTI;
}

string Paciente::getEsUTIStr() const {
  return _esUTI ? "UTI" : "Piso";
}

bool Paciente::getEstado() const {
  return _estado;
}

string Paciente::getEstadoStr() const {
  return _estado ? "Activo" : "Dado de baja";
}

int Paciente::calcularEdad() const {
  Fecha hoy;  
  int edad = hoy.getAnio() - _fechaNacimiento.getAnio();
  if (hoy.getMes() < _fechaNacimiento.getMes() || 
     (hoy.getMes() == _fechaNacimiento.getMes() && hoy.getDia() < _fechaNacimiento.getDia())) {
    edad--;
  }
  return edad; 
}

string Paciente::toCSV() const {  //este lo vamos a usar para guardar
  std::string str = Persona::toString(); 
  str += "," + std::string(_obraSocial);
  str += "," + std::string(_numeroDeAfiliado);
  str += "," + _fechaNacimiento.toString(); 
  str += "," + std::string(_antecedenteFamiliar);
  str += "," + std::string(_antecedentePaciente);
  return str;
}

string Paciente::toString() const { // este lo voy a usar para mostrar en pantalla, por eso estar ordenadito coquette con texto de salida, para que se entienda
  string str = Persona::toString();
  str += "\tobra social: " + string(_obraSocial) + ", \n";
  str += "\tnumero de afiliado: " + string(_numeroDeAfiliado) + ", \n";
  str += "\tfecha de nacimiento: " + _fechaNacimiento.toString() + ", \n";
  str += "\tantecedentes familiares: " + string(_antecedenteFamiliar) + ", \n";
  str += "\tantecedentes del paciente: " + string(_antecedentePaciente);
  return str;
}