#pragma once
#include "Postulante.h"


//.h es para la DECLARACION/Firma/Prototipo de los atributos/miembros/propiedad + Metodos/funciones
//.cpp es para la Definicion/implementacion
//incluyendo su nombre, edad, puesto al que aplica y años de experiencia laboral.

/*
○	La persona debe tener entre 22 y 50 años inclusive.
○	Debe contar con al menos 2 años de experiencia laboral.
○	El puesto al que aplica debe ser uno de los aceptados (por ejemplo: Programador, Tester o Diseñador).

●	Como reclutador, quiero que el sistema me indique con claridad si la persona pasó o no la evaluación, y que además me 
permita llevar un 
conteo total de personas evaluadas y cuántas fueron rechazadas.

●	Como reclutador, quiero poder ver cuántas personas han sido evaluadas hasta el momento, y de ellas, 
cuántas no cumplieron los requisitos.

*/

class Reclutador{
private:
  int _contadorAprobados;//=0 no se inicializa en la declaracion
  int _contadorRechazados;

public:
  bool aprobarEvaluacion(Postulante pos);
  int getCantPersonasEvaluadas();
  int getCantPersonasRechazadas();
};