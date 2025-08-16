#include <iostream>
using namespace std;
#include "Reunion.h"

Reunion::Reunion(){
    _duracion = 0;
    _cantidadIntegrantes = 0;
}
Reunion::Reunion(Fecha fecha, Horario horario, int duracion){
    _fecha = fecha;
    _horario = horario;
    _duracion = duracion;
    _cantidadIntegrantes = 0;
}
Reunion::Reunion(Fecha fecha, Horario horario, string tema, string lugar, int duracion){
    _fecha = fecha;
    _horario = horario;
    _duracion = duracion;
    _tema = tema;
    _lugar = lugar;
    _cantidadIntegrantes = 0;
}
Reunion::Reunion(int dia, int mes, int anio, int hora, int minuto, string tema, string lugar, int duracion):_fecha(dia, mes, anio),_horario(hora, minuto)
{
    _tema = tema;
    _lugar = lugar;
    _duracion = duracion;
    _cantidadIntegrantes = 0;
}
Fecha Reunion::getFecha(){
    return _fecha;
}
Horario Reunion::getHorario(){
    return _horario;
}
int Reunion::getDuracion(){
    return _duracion;
}
string Reunion::getTema(){
    return _tema;
}
string Reunion::getLugar(){
    return _lugar;
}
void Reunion::setFecha(Fecha fecha){
    _fecha = fecha;
}
void Reunion::setHorario(Horario horario){
    _horario = horario;
}
void Reunion::setDuracion(int duracion){
    _duracion = duracion;
}
void Reunion::setTema(string tema){
    _tema = tema;
}
void Reunion::setLugar(string lugar){
    _lugar = lugar;
}

void Reunion::mostrar(){
     cout << "Fecha   : " << _fecha.toString() << endl;
     cout << "Horario : " << _horario.toString() << endl;
     cout << "Lugar   : " << _lugar << endl;
     cout << "Tema    : " << _tema << endl;
     cout << "Duracion: " << (_duracion > 0 ? to_string(_duracion) + " minutos" : "Sin limite de tiempo") << endl;
     if (_cantidadIntegrantes > 0){
      cout << "Integrantes: " << endl;
      for(int i = 0; i<_cantidadIntegrantes; i++){
         cout << _integrantes[i].getApellidoyNombre() << endl;
      }
     }
     cout << endl;
}

void Reunion::agregarPersona(Persona nuevaPersona){
   if (_cantidadIntegrantes < 5){
      _integrantes[_cantidadIntegrantes] = nuevaPersona;
      _cantidadIntegrantes++;
   }
}
Persona Reunion::getPersona(int nro_participante){

   if (nro_participante >= 0 && nro_participante <= 4){
      return _integrantes[nro_participante];
   }

   return Persona();

}
int Reunion::getCantidadIntegrantes(){
   return _cantidadIntegrantes;
}

