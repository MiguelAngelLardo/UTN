#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{

  int legajoDelAlumno, codigoMateria, nota, legajoActual;
  int contExamenRendidoPorAlumno, acumNotasSumadas; //A)
  int maxMateria, maxNota; //B)
  int maxLegajo = 0; //C)
  float promedioNotas, maxPromedio = 0; //C)

  cout << "Ingrese el Legajo del alumno: ";
  cin >> legajoDelAlumno;
 
  while(legajoDelAlumno != 0)
  {
    contExamenRendidoPorAlumno = acumNotasSumadas = 0; //A)
    maxMateria = maxNota = 0;

    legajoActual = legajoDelAlumno;
    while (legajoDelAlumno == legajoActual)
    {
      cout << "Ingrese el codigo de la materia: ";
      cin >> codigoMateria;
      cout << "Ingrese la nota: ";
      cin >> nota;
      while (nota < 0 || nota > 10){
        cout << "INGRESEUNA NOTA VALIDA!!!";
        cin >> nota;
      }

      //PUNTO A)
      contExamenRendidoPorAlumno ++;
      acumNotasSumadas += nota;

      //PUNTO B)
      if(nota > maxNota){
        maxNota = nota;
        maxMateria = codigoMateria;
      }

      //PUNTO D)
      if(nota == 10)
        cout << endl << "Te sacaste 10 en la materia: " << codigoMateria << endl;
      
      cout << "Ingrese el Legajo del alumno: ";
      cin >> legajoDelAlumno;      
    }

    if(contExamenRendidoPorAlumno > 0){
      cout << "El alumno: " << legajoActual << ". Tiene de promedio " << fixed << setprecision(2) << (float)acumNotasSumadas / contExamenRendidoPorAlumno << ". Cantidad de examenes: " << contExamenRendidoPorAlumno << endl;
    }

    if(maxMateria != 0){
      cout << "La materia " << maxMateria << " obtuvo la mejor nota => " << maxNota << endl;
    }

    promedioNotas = (float)acumNotasSumadas / contExamenRendidoPorAlumno;

    if(promedioNotas > maxPromedio){
      maxPromedio = promedioNotas;
      maxLegajo = legajoActual;
    }  
  }

  if(maxLegajo != 0)
    cout << "El alumno con legajo " << maxLegajo << " Obtuvo el mejor promedio (" << maxPromedio << ")" << endl;
 
  return 0;
}