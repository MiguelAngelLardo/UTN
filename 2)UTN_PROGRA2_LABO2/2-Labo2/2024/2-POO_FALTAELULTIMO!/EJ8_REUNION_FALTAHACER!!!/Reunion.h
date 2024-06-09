#pragma once

#include <string>
using namespace std;
#include "Persona.h"
#include "Fecha.h"
#include "Temporizador.h"

class Reunion{
private:
  Fecha _fechaReunion;
  Temporizador _horario;
  string _lugar;
  string _tema;
  int _duracion;
  Persona _integrante[5] = {}; 

public:
  void setFechaReunion(Fecha f);
  void setTemporizadorReunion(Temporizador t);
  void setLugarReunion(string lugar);
  void setDuracionReunion(int duracion);
  void setPersonaReunion(Persona integrante);
  
  Fecha getFechaReunion();
  Temporizador getTemporizadorReunion();
  string getLugarReunion();
  string getTemaReunion();
  int getDuracionReunion();
  Persona getIntegranteReunion();

  Reunion(Fecha f = Fecha(), Temporizador t = Temporizador(), string lugar = "S/L", string tema = "S/T", int duracion = 0);

  void agregarPersona(Persona p);
  Persona obtenerPersona(int numeroID);
  int obtenerCantidadParticipantes();

  void cargar();


};