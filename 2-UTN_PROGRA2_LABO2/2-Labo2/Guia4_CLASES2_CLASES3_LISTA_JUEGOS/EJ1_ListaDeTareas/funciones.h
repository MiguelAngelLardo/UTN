#pragma once
#include <string>
#include "Tarea.h"
#include "ListaDeTareas.h"

Tarea cargarTarea();
void mostrarTarea(Tarea tarea);
int getInteger(int minimo, int maximo);
ListaDeTareas hardcodearTareas();
int diferenciaDias(Fecha fechaInicial, Fecha fechaFinal);
