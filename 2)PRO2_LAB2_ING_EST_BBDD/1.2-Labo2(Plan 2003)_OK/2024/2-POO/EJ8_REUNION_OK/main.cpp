#include <vector>
#include <iostream>
using namespace std;
#include "Reunion.h"
#include "Persona.h"
#include "Hora.h"
#include "Fecha.h"

void crearReuniones(Reunion[]);

int main()
{
   Reunion lista[6], masExtensa;
   crearReuniones(lista);

   int duracionMaxima = 0;

   for(int i = 0 ; i < 6; i++){
      if (lista[i].getDuracion() > duracionMaxima){
         masExtensa = lista[i];
         duracionMaxima = lista[i].getDuracion();
      }
   }

   cout << "Reunion mas extensa: ";
   masExtensa.mostrar();


   return 0;
}

void crearReuniones(Reunion reuniones[]){

   reuniones[0].setFecha(Fecha(1, 10, 23));
   reuniones[0].setHorario(Horario(19, 0));
   reuniones[0].setLugar("Buenos Aires");
   reuniones[0].setTema("Programacion en C++");
   reuniones[0].setDuracion(90);
   reuniones[0].agregarPersona(Persona("Lara", "Brian"));
   reuniones[0].agregarPersona(Persona("Simon", "Angel"));

   reuniones[1].setFecha(Fecha(1, 11, 2023));
    reuniones[1].setHorario(Horario(19, 0));
    reuniones[1].setLugar("UTN FRGP");
    reuniones[1].setTema("Strings vs Vectores de char");
    reuniones[1].setDuracion(100);
    reuniones[1].agregarPersona(Persona("Kloster", "Daniel"));
   reuniones[1].agregarPersona(Persona("Simon", "Angel"));

    reuniones[2].setFecha(Fecha(20, 11, 2024));
    reuniones[2].setHorario(Horario(23, 0));
    reuniones[2].setLugar("Discord");
    reuniones[2].setTema("Goto Gamejam 4");
    reuniones[2].setDuracion(0);

    reuniones[3].setFecha(Fecha(1, 3, 2024));
    reuniones[3].setHorario(Horario(18, 0));
    reuniones[3].setLugar("Buenos Aires");
    reuniones[3].setTema("Bases de Datos con SQL");
    reuniones[3].setDuracion(60);

    reuniones[4].setFecha(Fecha(1, 4, 2024));
    reuniones[4].setHorario(Horario(18, 0));
    reuniones[4].setLugar("Discord");
    reuniones[4].setTema("C#");
    reuniones[4].setDuracion(50);

    reuniones[5].setFecha(Fecha(5, 4, 2025));
    reuniones[5].setHorario(Horario(21, 0));
    reuniones[5].setLugar("Steam");
    reuniones[5].setTema("Torneo de Age of Empires");
    reuniones[5].setDuracion(80);

}
