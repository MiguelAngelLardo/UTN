#pragma once
#include <string> 

void cargarDatos(int *notas, std::string *nombreApellido, int tam);
int promedioGeneral(int *notas, int tam);
int ptoACantidadMayorPromedio(int *notas, int tam);
void ptoBListadoMayorPromedio(int *notas, std::string *nombreApellido, int tam);