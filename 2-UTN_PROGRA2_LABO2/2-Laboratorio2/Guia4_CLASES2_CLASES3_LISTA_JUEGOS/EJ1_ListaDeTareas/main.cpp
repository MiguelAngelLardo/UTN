#include <iostream>
#include <clocale>
#include <cstdio>
#include "Tarea.h"
#include "funciones.h"

using namespace std;

int main()
{
  /*Lee el archivo de tareas y lo muestra por pantalla*/

  Tarea reg;
  FILE *p = fopen("tareas.dat", "rb");
  if(p == NULL){
    cout << "No se pudo abrir el archivo";
    return 1;
  }

  while(fread(&reg, sizeof(Tarea), 1, p)){
    mostrarTarea(reg);
    cout << endl;
  }
  fclose(p);

  /*Escribe en el archivo de tareas 3 tareas*/
  /*Tarea reg1(1, "Aprender archivos", Fecha(29,4, 2023), 3, 0);
  Tarea reg2(2, "Estudiar Estadistica", Fecha(28,4, 2023), 3, 0);
  Tarea reg3(3, "Repasar POO", Fecha(28,4, 2023), 3, 0);

  FILE *p = fopen("tareas.dat", "ab");//write binary
  if(p == NULL){
    cout << "No  se pudo abrir el archivo";
    return 1;
  }

  fwrite(&reg1, sizeof(Tarea), 1, p);
  fwrite(&reg2, sizeof(Tarea), 1, p);
  fwrite(&reg3, sizeof(Tarea), 1, p);
  fclose(p);*/

  /*disponer de un menu que permita guardar nueva tareas y guardarla en el archivo
  // leer todas las tareas y mostrarla por pantalla*/

  return 0;
}
