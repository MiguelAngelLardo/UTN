#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
  int legajo, codMateria, legajoAnterior, nota;

  //PUNTO A
  int sumaNotas, cantExamenes;
  float promNotas;
  //PUNTO B
  int maxMateria, maxNota;
  //PUNTO C
  int maxLegajo = 0;
  float maxPromedio = 0;

  cout << "LEGAJO: ";
  cin >> legajo;

  while(legajo != 0){
    legajoAnterior = legajo;

    cantExamenes = sumaNotas = 0;
    maxNota = maxMateria = 0;

    while(legajoAnterior == legajo){
      cout << "CODIGO MATERIA: ";
      cin >> codMateria;
      cout << "NOTA: ";
      cin >> nota;
      while(nota < 0 || nota > 10){
        cout << "--NOTA: ";
        cin >> nota;
      }

      //PUNTO A
      cantExamenes++;
      sumaNotas+= nota;

      //PUNTO B
      if(nota > maxNota){
        maxNota = nota;
        maxMateria = codMateria;
      }

      //PUNTO D
      if(nota == 10){
        cout << endl << "PUNTO D) CODIGO MATERIA: " << codMateria << endl;
      }

      cout << "LEGAJO: ";
      cin >> legajo;
    }

    //PUNTO A
    if(cantExamenes > 0){
      promNotas = (float) sumaNotas / cantExamenes;
      cout << endl << "PUNTO A" << endl << "----------------" << endl;
      cout << "LEGAJO: " << legajoAnterior << endl;
      cout << "PROMEDIO: " << promNotas << endl;
      cout << "CANT EXAMENES: " << cantExamenes << endl;
    }
    //PUNTO B
    if(maxMateria != 0){
      cout << endl << "PUNTO B" << endl << "----------------" << endl;
      cout << "La materia " << maxMateria << " obtuvo la mejor nota (" << maxNota << ")" << endl;
    }
    //PUNTO C
    if(promNotas > maxPromedio){
      maxPromedio = promNotas;
      maxLegajo = legajoAnterior;
    }
  }
  if(maxLegajo != 0){
    cout << endl << "PUNTO C" << endl << "----------------" << endl;
    cout << "El alumno con legajo " << maxLegajo << " obtuvo el mejor promedio (" << maxPromedio << ")" << endl;
  }




  return 0;
}
