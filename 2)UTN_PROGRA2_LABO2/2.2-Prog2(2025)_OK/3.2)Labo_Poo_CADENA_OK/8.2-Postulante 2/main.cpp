#include <iostream>
#include "Postulante.h"
#include "Reclutador.h"

using namespace std;

/*
🧑‍💻 Historias de Usuario
●	Como reclutador, quiero poder registrar la información de una persona que se postula, 
incluyendo su nombre, edad, puesto al que aplica y años de experiencia laboral.
●	Como reclutador, quiero poder evaluar si una persona cumple con los requisitos mínimos para continuar en el proceso de selección.
●	Como empresa, necesito que los criterios de evaluación sean:

○	La persona debe tener entre 22 y 50 años inclusive.
○	Debe contar con al menos 2 años de experiencia laboral.
○	El puesto al que aplica debe ser uno de los aceptados (por ejemplo: Programador, Tester o Diseñador).

●	Como reclutador, quiero que el sistema me indique con claridad si la persona pasó o no la evaluación, y que además me 
permita llevar un conteo total de personas evaluadas y cuántas fueron rechazadas.

●	Como reclutador, quiero poder ver cuántas personas han sido evaluadas hasta el momento, y de ellas, 
cuántas no cumplieron los requisitos.

EXTRA:
●	Como reclutador quiero poder establecer los criterio de evaluación, edad mínima, edad máxima, experiencia mínima y puesto

class Postulante
class Reclutdor
la clase tiene las cualidades que quiero representar en el OBJETO 

//.h es para la DECLARACION/Firma/Prototipo de los atributos/miembros/propiedad + Metodos/funciones
//.cpp es para la Definicion/implementacion
*/

int main(){
  system("cls");
  Postulante migue;
  Reclutador ella;

  for(int x = 0; x < 3; x ++){
    migue.cargar();

    if(ella.aprobarEvaluacion(migue)){
      cout << "El postulante " << migue.getNombre() << " paso la prueba." << endl;
    } else{
      cout << "No paso la prueba." << endl;
    }
  }

  cout << ella.getCantPersonasEvaluadas() << endl;
  cout << ella.getCantPersonasRechazadas() << endl;

  return 0;
}