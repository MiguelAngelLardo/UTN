#pragma once
#include <string>

class ProfesionalXPaciente {
private:
  char _dniPaciente[9];
  char _matriculaProfesional[9];
 
public:
    ProfesionalXPaciente();
    ProfesionalXPaciente(const std::string &dniPaciente, const std::string &matriculaProfesional);

    void setDniPaciente(const std::string &dniPaciente);
    void setMatriculaProfesional(const std::string &matriculaProfesional);
    
    std::string getDniPaciente() const;
    std::string getMatriculaProfesional() const;
  
       
};