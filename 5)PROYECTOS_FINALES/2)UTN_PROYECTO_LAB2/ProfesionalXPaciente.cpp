#include <cstring>
#include "ProfesionalXPaciente.h"
using namespace std;

ProfesionalXPaciente::ProfesionalXPaciente(){
  _dniPaciente[0] = '\0';
  _matriculaProfesional[0] = '\0';
}

ProfesionalXPaciente::ProfesionalXPaciente(const string &dniPaciente, const string &matriculaProfesional){
  setDniPaciente(dniPaciente);
  setMatriculaProfesional(matriculaProfesional);
}

void ProfesionalXPaciente::setDniPaciente(const string &dniPaciente) {
    if(dniPaciente.size() <= 8){
      strcpy(_dniPaciente, dniPaciente.c_str());
    }else{
      _dniPaciente[0] = '\0';
    }
}
void ProfesionalXPaciente::setMatriculaProfesional(const string &matriculaProfesional) {
    if(matriculaProfesional.size() <= 8){
      strcpy(_matriculaProfesional, matriculaProfesional.c_str());
    }else{
      _matriculaProfesional[0] = '\0';
    }
}
std::string ProfesionalXPaciente::getDniPaciente() const {
    return string(_dniPaciente);
}
std::string ProfesionalXPaciente::getMatriculaProfesional() const {
    return string(_matriculaProfesional);
}