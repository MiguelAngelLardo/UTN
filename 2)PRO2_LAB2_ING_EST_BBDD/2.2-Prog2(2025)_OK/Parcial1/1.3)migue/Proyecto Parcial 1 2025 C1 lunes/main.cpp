#include <iostream>

using namespace std;

#include "Examen.h"

int main()
{
    Examen resolucion;

    /*
    El método EjemploDeListado muestra cómo se puede generar un listado de los registros a partir de los datos de
    restaurant.dat, se recomienda tomarlo de ejemplo para la resolución de los demás puntos.

    Tener en cuenta que deben entregar los archivos Examen.cpp y Examen.h con la resolución de los puntos solicitados.
    Todo código que quieran agregar para la resolución debe estar dentro de esos archivos.
    No modifiquen ninguno de los otros archivos ya que no tendrán permitido subir esos cambios en la entrega.
    */
   // resolucion.EjemploDeListado();
   system("cls");
   cout << "PUNTO 1 " << endl;
   resolucion.Punto1();
    cout << "PUNTO 2 " << endl;
    resolucion.Punto2();
    cout << "PUNTO 3 " << endl;
    resolucion.Punto3();

    return 0;
}
