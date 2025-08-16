#include <iostream>

#include "Postulante.h"
#include "Evaluador.h"
using namespace std;

/***
  Objeto
  Estado - Comportamiento - Identidad

  Clase
  Propiedades - Metodos - Identificador


  Lapiz
    Color
    Dibujar()


  Lapiz lapizBrian;
  lapizBrian.Dibujar();


  Postulante:
    nombre
    edad
    puesto
    experiencia
  ///
    getter
    setter


  Evaluador:
    cantidadAprobados
    cantidadRechazados

  ///
    bool evaluar(Postulante)


*/
Evaluador cargarEvaluador()
{
  int establecerValores;

  cout << "Quiere establecer valores de evaluacion? 1- Si 0- No";
  cin >> establecerValores;

  if(establecerValores == 1)
  {
    /// pedir valores
    int edadMinima = 0;
    // cin correspondientes

    return Evaluador(edadMinima, 10,2,"Editor"); /// Objeto anonimo
  }
  else
  {
    /// el por defecto
    return Evaluador();
  }
}

int main()
{

  Evaluador evaluador;

  evaluador = cargarEvaluador();

  for(int i=0; i <2; i++)
  {
    Postulante post;

    post.cargar();

    if(evaluador.evaluar(post))
    {
      cout << post.getNombre() << " paso!" << endl;
    }
    else
    {
      cout << post.getNombre() << " no paso!" << endl;
    }
  }
  cout << "Cantidad de evaluados: " << evaluador.getCantidadEvaluados() << endl;
  cout << "Cantidad de rechazados: " << evaluador.getCantidadRechazados() << endl;

  return 0;
}
