#include <iostream>
#include "reunion.h"

using namespace std;

int main(){
  //FechaHorario fechaHora;
  //fechaHora.setFecha(1, 10, 2023);
  //fechaHora.setHorario(0, 0, 19);

  Persona gentes[7];
  gentes[0] = Persona("Lara", "Brian");
  gentes[1] = Persona("Simon", "Angel");
  gentes[2] = Persona("Varela", "Mariano");
  gentes[3] = Persona("Tapia", "Ariel");
  gentes[4] = Persona("Carbonari", "Veronica");
  gentes[5] = Persona("Kloster", "Daniel");
  gentes[6] = Persona("Wenner", "Maxi");

  Reunion reunion(7);
  reunion.setDuracion(90);
  reunion.setFechaHorario(FechaHorario(1,10, 2023, 0, 0, 19)); //reunion.setFechaHorario(fechaHora);
  reunion.setTema("Programacion en C++");
  reunion.setLugar("Buenos Aires");

  for(int x = 0; x < 7 ; x ++){
    reunion.setIntegrante(gentes[x], x);
  }
 

  //cout << reunion.toString();
  cout << reunion.getIntegrante(4).getApellidosYNombres();

  return 0;
}