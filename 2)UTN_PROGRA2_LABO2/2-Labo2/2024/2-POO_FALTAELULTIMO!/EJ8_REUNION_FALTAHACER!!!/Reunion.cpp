#include "Reunion.h"

 Reunion::Reunion(Fecha f, Temporizador t, string lugar, string tema, int duracion) :
  _fechaReunion(f), _horario(t), _lugar(lugar), _tema(tema), _duracion(duracion) {}
  
  
void Reunion::setFechaReunion(Fecha f){_fechaReunion = f;}
void Reunion::setTemporizadorReunion(Temporizador t){_horario = t;}
void Reunion::setLugarReunion(string lugar){_lugar = lugar;}
void Reunion::setDuracionReunion(int duracion){_duracion = duracion;}
void Reunion::setPersonaReunion(Persona integrante){
  for (int x = 0; x < 5; x++){
    if(_integrante[x].getNombrePersona() == ""){
      _integrante[x] = integrante;
      break;
    }
  }
}
  
Fecha Reunion::getFechaReunion(){return _fechaReunion;}
Temporizador Reunion::getTemporizadorReunion(){return _horario;}
string Reunion::getLugarReunion(){return _lugar;}
string Reunion::getTemaReunion(){return _tema;}
int Reunion::getDuracionReunion(){return _duracion;}
Persona Reunion::getIntegranteReunion(){return *_integrante;}

void Reunion::cargar(){
  cout << "FECHA: " << endl;
  _fechaReunion.cargar();
  cout << "Temporizador: ";
  _horario.cargar();
  cout << "LUGAR: ";
  getline(cin, _lugar);
  cout << "TEMA: ";
  getline(cin, _tema);
  cout << "DURACION: ";
  cin >> _duracion;
  cout << "INTEGRANTES: ";
  for(int x = 0; x < 5; x ++){
    
  }
  



}



void Reunion::agregarPersona(Persona p){
  setPersonaReunion(p);
}

Persona Reunion::obtenerPersona(int numeroID){
  return _integrante[numeroID];  
}

int Reunion::obtenerCantidadParticipantes(){
  int contador = 0;
  for (int x = 0; x < 5; x++){
    if(_integrante[x].getNombrePersona() != ""){
      contador ++;
    }
  }
  return contador;
}


/*
void::Reunion::agregarParticipante(Persona participante)
{
_participantes[_posicion] = participante;
_posicion++;
}
*/