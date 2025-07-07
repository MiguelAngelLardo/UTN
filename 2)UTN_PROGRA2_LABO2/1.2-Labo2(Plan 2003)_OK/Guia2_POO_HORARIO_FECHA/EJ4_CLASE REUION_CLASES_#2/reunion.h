#pragma once
#include "fechahorario.h"
#include "persona.h"

class Reunion{
  private:
    FechaHorario _fechaHorario;
    std::string _lugar, _tema;
    int _duracion;
    Persona *_integrantes;//hago un puntero para que sea vector dinamico

    //creo una variable int para el vector dinamico
    int _cantidadIntegrantes; 

  public:
    FechaHorario getFechaHorario();
    std::string getLugar();
    std::string getTema();
    int getDuracion();
    int getCantidadIntegrantes(); // no tiene set por que lo seteo con constructor
    Persona getIntegrante(int indice);

    void setFechaHorario(FechaHorario fechaHorario);
    void setLugar(std::string lugar);
    void setTema(std::string tema);
    void setDuracion(int duracion);
    void setIntegrante(Persona integrante, int indice);

    Reunion(int cantidadIntegrantes);  
    ~Reunion(); //alt126 para el destructor

    std::string toString();
};