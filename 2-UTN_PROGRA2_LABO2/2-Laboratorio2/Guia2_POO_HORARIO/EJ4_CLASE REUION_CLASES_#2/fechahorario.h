#pragma once
#include "fecha.h"
#include "horario.h"


class FechaHorario{
  private:
  //composicion => atributo de una clase que sea una instancia de otra clase
    Fecha _fecha;
    Horario _horario;

  public:
    Fecha getFecha();
    Horario getHorario();

    void setFecha(Fecha fecha);
    void setHorario(Horario horario);
    void setFecha(int dia, int mes, int anio);
    void setHorario(int segundo, int minuto, int hora);

    FechaHorario();
    FechaHorario(int dia, int mes, int anio, int segundo, int minuto, int hora);
    FechaHorario(Fecha fecha, Horario horario);

    std::string toString();
};