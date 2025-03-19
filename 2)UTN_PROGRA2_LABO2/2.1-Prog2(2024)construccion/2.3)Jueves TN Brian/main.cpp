#include <iostream>
using namespace std;
/*
Ejercicio con Vectores, Matrices y Memoria Dinámica
Una universidad desea registrar las notas de los exámenes finales de las 10 materias de una
carrera. 

Para cada materia, se debe cargar la cantidad de alumnos inscriptos, y por cada
alumno se debe registrar la siguiente información:

● Legajo: Un número entero mayor a 0, que identifica al alumno de manera única.
● Llamado: Un número entero entre 1 y 3 que indica el llamado en el que el alumno
rindió el examen final (1 - Primer llamado, 2 - Segundo llamado, 3 - Tercer llamado).
● Modalidad: Un número entero entre 1 y 4 que indica la modalidad del examen (1 -
Presencial, 2 - Distancia, 3 - Híbrido, 4 - Libre).

● Nota: Un número entero entre 0 y 10 que representa la nota obtenida en el examen (0
indica que el alumno estuvo ausente).

La información se encuentra agrupada por materia. Se pide calcular e informar lo siguiente:
1. Materia con más inscripciones: Determinar cuál de las 10 materias tiene la mayor
cantidad de inscripciones.
2. Modalidad con más inscripciones: Determinar cuál de las modalidades tiene la
mayor cantidad de inscripciones entre todas las materias.
3. Estadísticas por llamado: Para cada llamado, la modalidad de examen que más
inscripciones haya registrado.
4. Estadísticas sobre las materias: Por cada materia, la cantidad de alumnos que se
hayan inscripto más de una vez. => son 10 materias, cuantos alumnos hay por materia? */


//son 10 materias => esto es para el for externo
//se ingresa la cantidad de alumnos inscriptos dinamicamente => eso es otro fo

const int CANTIDAD_MATERIAS = 3;

int buscaMaximoEnVector(int v[], int tam=0);

void mostrarMaximosDelVector(int indiceConMaxCantidad, int vMaterias[],int vCantidadAlumnos[], int tam=0);

int main()
{
  int codMateria, cantidadInscripciones;
  int legajo, llamado, modalidad, nota; //llamado de 1 a 3, modalidd de 1 a 4

  //punto1 para un maximo
  int pa_codigoMateria, pa_cantidadMaxima = 0;

  //punto1 para varios maximos
  int pa_vCodigoMateria[CANTIDAD_MATERIAS] {};
  int pa_vMateriasMasInscripciones[CANTIDAD_MATERIAS] {};

  //punto2
  int pb_vModalidadesContador[4] {}, pb_modalidadConMasInscripciones;
  string pb_modalidadesNombre[4] = {"Presencial", "Distancia", "Hibrido", "Libre"};

  //punto3
  int pc_mLlamadoModalidadCont[3][4] {}; //3 llamados y 4 modalidades

  //punto4
  int pd_mInscripcionesDuplicadasXMater[CANTIDAD_MATERIAS][2] {};//Materia cantidad

  for(int materias = 0; materias < CANTIDAD_MATERIAS; materias++)
  {
   cout << "Ingese codigo de la materia: ";
   cin >> codMateria;

   cout << "Ingrese la cantidad de alumnos inscriptos: ";
   cin >> cantidadInscripciones;

   //PtoA para un maximo solo   
   if(cantidadInscripciones > pa_cantidadMaxima){
    pa_cantidadMaxima = cantidadInscripciones;
    pa_codigoMateria = codMateria;
   }

    //PtoA para varios maximos
    pa_vCodigoMateria[materias] = codMateria;
    pa_vMateriasMasInscripciones[materias] = cantidadInscripciones;
   
    //PtoD dinamico
    pd_mInscripcionesDuplicadasXMater[materias][0] = codMateria;
    int *pd_vDinLegajosPorMateria = new int[cantidadInscripciones];//hay 5 incriptos pero solo 2 son reales el resto son repetidos
    if(pd_vDinLegajosPorMateria == nullptr){
      cout << "No se pudo asignar la memoria" << endl;
      return -1; //exit(-1);
    }

   for(int j = 0; j < cantidadInscripciones; j++)
   {
    cout << "Ingrese legajo: ";cin >> legajo;
    cout << "Ingrese llamado: ";cin >> llamado;
    cout << "Ingrese modalidad: ";cin >> modalidad;
    cout << "Ingrese nota: ";cin >> nota;

    //ptoB
    pb_vModalidadesContador[modalidad-1]++;

    //ptoC
    pc_mLlamadoModalidadCont[llamado-1][modalidad-1]++;

    //ptoD
    pd_vDinLegajosPorMateria[j] = legajo;
   }//for de inscriptos

   //Logica Punto D
   
   for(int k = 0; k < cantidadInscripciones; k ++){
      if(pd_vDinLegajosPorMateria[k] == 0) continue;
      bool encontreDuplicado = false;
    for(int l = k+1; l < cantidadInscripciones; l ++){
      if(pd_vDinLegajosPorMateria[k] == pd_vDinLegajosPorMateria[l]){
        pd_vDinLegajosPorMateria[l] = 0; 
        encontreDuplicado = true;
      }
    }

    if(encontreDuplicado) pd_mInscripcionesDuplicadasXMater[materias][1]++;
   }//for K

   delete []pd_vDinLegajosPorMateria;

  }//for de 10

  cout << endl << "PUNTO A (1 solo valor): La materia con mas inscripciones es: " << pa_codigoMateria << " con " << pa_cantidadMaxima << " inscriptos" << endl;
  cout << "Punto A con mas de 1 maximo: " << endl;
  mostrarMaximosDelVector(buscaMaximoEnVector(pa_vMateriasMasInscripciones, CANTIDAD_MATERIAS), pa_vCodigoMateria, pa_vMateriasMasInscripciones,3);
  cout << "-----------------------------------" << endl;

  pb_modalidadConMasInscripciones = buscaMaximoEnVector(pb_vModalidadesContador, 4) ;
  cout << "PUNTO B: La modalidad con mas inscripciones es: " << pb_modalidadesNombre[pb_modalidadConMasInscripciones] << " la cual tiene " << pb_vModalidadesContador[pb_modalidadConMasInscripciones] << " inscriptos "<< endl;
  cout << endl << "-----------------------------------" << endl;

  cout << "Punto C: " << endl;
  for (int i = 0; i < 3; i++){
    cout << "Llamdo " << i + 1 <<" => la modalidad con mas incipciones es : " << pb_modalidadesNombre[buscaMaximoEnVector(pc_mLlamadoModalidadCont[i], 4)]<< " con una cantidad de " << pc_mLlamadoModalidadCont[i][buscaMaximoEnVector(pc_mLlamadoModalidadCont[i], 4)] << endl; 
  }
  
  //Punto D
  cout << endl << "Punto D: " << endl;
  for (int x = 0; x < CANTIDAD_MATERIAS; x++){
    cout << "La materia numero " << x+1 << " es la " << pd_mInscripcionesDuplicadasXMater[x][0] << " y tiene " << pd_mInscripcionesDuplicadasXMater[x][1] << " duplicados" << endl;
  }
  

  return 0;
}

int buscaMaximoEnVector(int v[], int tam){
  int indiceConMax = 0;

  for(int i = 1; i < tam; i++){
    if(v[i] > v[indiceConMax]){
      indiceConMax = i;
    }
  }  
  return indiceConMax;
}

void mostrarMaximosDelVector(int indiceConMaxCantidad, int vMaterias[],int vCantidadAlumnos[], int tam){
  int maxCantidad = vCantidadAlumnos[indiceConMaxCantidad];
  for(int i = 0; i < CANTIDAD_MATERIAS; i++){
    if(maxCantidad == vCantidadAlumnos[i]){
      cout << "La materia con mas inscripciones es: " << vMaterias[i] << " con " << vCantidadAlumnos[i] << " inscriptos" << endl;
    }
  }
}


