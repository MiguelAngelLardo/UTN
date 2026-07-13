#pragma once
#include <string>
#include "Fecha.h"
#include "SignosVitales.h"


class HistoriaClinica {
public:
  HistoriaClinica();
  HistoriaClinica(std::string codigoHC, std::string matriculaProf, SignosVitales signosVitales,
                  std::string diagnostico, std::string tratamiento, std::string medicacion,
                  bool altaMedica = false, bool altaSistema = false, bool estadoRegistro = true);

  void setCodigoHC(const std::string &codigoHC);
  void setMatriculaProfesional(const std::string &matProf);
  void setSignosVitales(const SignosVitales &signosVitales);
  void setDiagnostico(const std::string &diagnostico);
  void setTratamiento(const std::string &tratamiento);
  void setMedicacion(const std::string &medicacion);
  void setAltaMedica(const bool &altaMedica);
  void setAltaSistema(const bool &altaSistema);
  void setEstadoRegistro(const bool &estadoRegistro);

  std::string getCodigoHC() const;
  Fecha getFecha() const;
  std::string getMatriculaProfesional() const;
  SignosVitales getSignosVitales() const;
  std::string getDiagnostico() const;
  std::string getTratamiento() const;
  std::string getMedicacion() const;

  bool getAltaMedica() const;
  std::string getAltaMedicaStr() const;
  bool getAltaSistema() const;
  std::string getAltaSistemaStr() const;
  bool getEstadoRegistro() const;
  std::string getEstadoRegistroStr() const;



private:

  char _codigoHC[5];
  Fecha _fechaActual; //fecha ingreso - fecha alta medica, fecha de atencion medica
  char _matriculaProfesional[11];
  SignosVitales _signosVitales;

  char _diagnostico[36];
  char _tratamiento[36];
  char _medicacion[36];

  bool _altaMedica;// si se dio de alta fechaAtencion sale diferente en el  cout
  bool _altaSistema;
  bool _estadoRegistro;//si se le da de alta al paciente y vuelve a entrar
};
