#include "funciones.h"
#include <iostream>

void cargarDatos(int *notas, std::string *nombreApellido, int tam){
  for(int x = 0; x < tam; x++){
    std::cin.ignore();
    printf("%d) Ingrese el Nombre y Apellido: ", x+1);
    getline(std::cin, nombreApellido[x]);

    std::cout << x+1 <<") Ingrese la nota: ";
    std::cin >> notas[x]; 
    std::cout << std::endl;   
  }
}

int promedioGeneral(int *notas, int tam){
  int suma = 0;

  for (int i = 0; i < tam; i++){
    suma += notas[i];
  }
 

  return suma/tam; 
}

int ptoACantidadMayorPromedio(int *notas, int tam){
  int promedio, cantidadMayorPromedio = 0;
  promedio = promedioGeneral(notas, tam);

  for (int i = 0; i < tam; i++){
    if(notas[i] > promedio){
      cantidadMayorPromedio ++;
    }
  }
  
  return cantidadMayorPromedio;
}

void ptoBListadoMayorPromedio(int *notas, std::string *nombreApellido, int tam){
  int promedio, indice = 0;;
  promedio = promedioGeneral(notas, tam);
  printf("LISTADO ALUMNOS CON NOTAS MAYOR AL PROMEDIO (#%d)\n", promedio);
  for (int i = 0; i < tam; i++){
    indice ++;
    if(notas[i] > promedio){
      std::cout << indice <<" -> " << nombreApellido[i] << std::endl; 
    }
  }

}