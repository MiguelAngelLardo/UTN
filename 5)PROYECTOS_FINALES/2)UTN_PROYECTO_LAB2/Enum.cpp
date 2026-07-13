#include "Enum.h"

using namespace std;

// Implementación de especialidadToString
string especialidadToString(Especialidad esp) {
  switch (esp) {
    case Especialidad::Cardiologo:   return "Cardiologo";
    case Especialidad::Pediatria:    return "Pediatria";
    case Especialidad::Virologo:     return "Virologo";
    case Especialidad::Neumologo:    return "Neumologo";
    case Especialidad::Traumatologo: return "Traumatologo";
    case Especialidad::Fisiatra:     return "Fisiatra";
    case Especialidad::Psiquiatra:   return "Psiquiatra";
    case Especialidad::Obstetra:     return "Obstetra";
    case Especialidad::Nefrologo:    return "Nefrologo";
    case Especialidad::Neurologo:    return "Neurologo";
    case Especialidad::Oncologo:     return "Oncologo";
    case Especialidad::Intensivista: return "Intensivista";
    case Especialidad::Respiratorio: return "Respiratorio";
    case Especialidad::Motor:        return "Motor";
    case Especialidad::Laboratorio:  return "Laboratorio";
    case Especialidad::Rayos:        return "Rayos";
    case Especialidad::No_Definida:  return "No definida";
    default:                         return "Especialidad no definida";
  }
}

string rolToString(Rol rol) {
  switch (rol) {
    case Rol::Medico:            return "Medico";
    case Rol::Nutricionista:     return "Nutricionista";
    case Rol::Kinesiologo:       return "Kinesiologo";
    case Rol::Psicologo:         return "Psicologo";
    case Rol::Tecnico:           return "Tecnico";
    case Rol::Enfermero:         return "Enfermero";
    default:                     return "Rol no definido";
  }
}