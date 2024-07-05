#include <iostream>
#include <iomanip> // Necesario para setprecision

using namespace std;

int main() 
{
  int legajo, codigoMateria, nota, acumNota = 0, contNotas = 0, notaMin = 0, legajoMinNota, contExamenMateria10 = 0;
  int contPorcentajeAprobados = 0, contPorcentajeNOAprobados = 0;
  float porcentajeAprobado = 0, porcentajeNoAprobado = 0;

  cout << "Ingrese el legajo: ";
  cin >> legajo;
  cout << "Ingrese el codigo de materia: ";
  cin >> codigoMateria;
  cout << "Ingrese la nota: ";
  cin >> nota;

  while (legajo < 30000)
  {
    acumNota += nota;
    contNotas ++;

    if(notaMin ==0)
    {
      notaMin = nota;
      legajoMinNota = legajo;
    }
    else
    {
      if(nota < notaMin)
      {
        notaMin = nota;
        legajoMinNota = legajo;
      }
    }

    if (codigoMateria == 10)
    {
      contExamenMateria10 ++;
    }

    if (nota >= 6)
      contPorcentajeAprobados ++;
    else
      contPorcentajeNOAprobados ++;
    
    cout << "Ingrese el legajo: ";
    cin >> legajo;
    if(legajo < 30000){
      cout << "Ingrese el codigo de materia: ";
      cin >> codigoMateria;
      cout << "Ingrese la nota: ";
      cin >> nota;
    }
  }

  porcentajeAprobado = (float)contPorcentajeAprobados*100/contNotas;
  porcentajeNoAprobado = (float)contPorcentajeNOAprobados*100/contNotas;

  cout << endl << "Menor nota: " << notaMin << ". El legajo es: " << legajoMinNota << endl;
  cout << "La nota promedio de todos los estudiantes: " << acumNota/contNotas << endl;
  cout << "Cantidad de examenes rendidos para la meteria 10: " << contExamenMateria10 << endl;
  cout << "Porcentaje de Aprobados %" << porcentajeAprobado << endl;
  cout << "Porcentaje de NO Aprobados %" << porcentajeNoAprobado << endl;

}