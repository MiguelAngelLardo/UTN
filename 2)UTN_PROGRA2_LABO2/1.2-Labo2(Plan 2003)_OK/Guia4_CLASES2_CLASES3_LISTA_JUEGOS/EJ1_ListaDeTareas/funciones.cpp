#include "funciones.h"
#include <climits>
#include <iostream>
using namespace std;

int getInteger(int minimo = INT_MIN, int maximo = INT_MAX){
   int input;

   while(true){
      cin >> input;
      if (cin.fail() || input < minimo || input > maximo){
         cin.clear();
         cin.ignore();
      }
      else{
         cin.ignore();
         return input;
      }
   }
}

ListaDeTareas hardcodearTareas(){

   ListaDeTareas lista;
   lista.agregar(Tarea(1, "Ara�ar cortinas", Fecha(23, 4, 2023), 2));
   lista.agregar(Tarea(2, "Maullar", Fecha(3, 5, 2023), 1));
   lista.agregar(Tarea(3, "Dormir todo el d�a", Fecha(13, 5, 2023), 1));
   lista.agregar(Tarea(4, "Dejar pelo por todos lados", Fecha(10, 6, 2023), 1));
   lista.agregar(Tarea(5, "Cazar bichos", Fecha(1, 7, 2023), 3));
   lista.agregar(Tarea(6, "Comer croquetas", Fecha(21, 4, 2023), 3));
   lista.agregar(Tarea(7, "Comer at�n", Fecha(27, 4, 2023), 1));
   lista.agregar(Tarea(8, "Morder", Fecha(13, 5, 2023), 1, 1));
   lista.agregar(Tarea(9, "Ir a los techos", Fecha(13, 8, 2023), 2));

   return lista;

}

void mostrarTarea(Tarea tarea){
  cout << "ID         : " << tarea.getID() << endl;
  cout << "Descripcion: " << tarea.getDescripcion() << endl;
  cout << "Fecha      : " << tarea.getFechaLimite().toString() << endl;
  cout << "Dificultad : " << tarea.getNivelDificultad() << endl;
  cout << "Estado     : " << tarea.getDescripcionEstado() << endl;
}

Tarea cargarTarea() {
  string descripcion;
  int dia, mes, anio;
  int dificultad;


  cout << "Ingrese la descripci�n de la tarea: ";
  cin.ignore();
  getline(cin, descripcion);

  cout << "Ingrese d�a l�mite: ";
  cin >> dia;

  cout << "Ingrese mes l�mite: ";
  cin >> mes;

  cout << "Ingrese a�o l�mite: ";
  cin >> anio;

  cout << "Ingrese dificultad de la tarea (1 - Bajo, 2 - Media, 3 - Alta): ";
  dificultad = getInteger(1, 3);

  Tarea aux;
  aux.setFechaLimite(Fecha(dia, mes, anio));
  aux.setNivelDificultad(dificultad);
  aux.setDescripcion(descripcion);

  return aux;
}

int diferenciaDias(Fecha fechaInicial, Fecha fechaFinal){
  int contador = 0;
  bool primerFechaMayor = fechaInicial.toString("YYYY/MM/DD") > fechaFinal.toString("YYYY/MM/DD");

  if(primerFechaMayor)
  {
    Fecha aux = fechaInicial;
    fechaInicial = fechaFinal;
    fechaFinal = aux;
  }

  while(fechaInicial.toString() != fechaFinal.toString())
  {
    fechaInicial.agregarDias(1);
    contador++;
  }

  if(primerFechaMayor)
  {
    return contador *-1;
  }
  else
  {
    return contador;
  }
}
