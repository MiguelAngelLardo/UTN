#include "Reclutador.h"

bool Reclutador::aprobarEvaluacion(Postulante pos){
  if(pos.getEdad() < 22 || pos.getEdad() > 50){
    _contadorRechazados ++;
    return false;
  }

  if(pos.getAniosExp() < 2){
    _contadorRechazados ++;
    return false;
  }
                  
          //    0                   *              1              *              1
  if(pos.getPuesto() != "Programador" && pos.getPuesto() != "Tester" && pos.getPuesto() != "Diseniador"){
    _contadorRechazados ++;
    return false;
  } 

  _contadorAprobados ++;
  return true;
}

int Reclutador::getCantPersonasEvaluadas(){
  int total = _contadorAprobados + _contadorRechazados;
  return total;// 1+2 = 3
}
int Reclutador::getCantPersonasRechazadas(){
  return _contadorRechazados;
}

/*
La persona debe tener entre 22 y 50 años inclusive.
○	Debe contar con al menos 2 años de experiencia laboral.
○	El puesto al que aplica debe ser uno de los aceptados (por ejemplo: Programador, Tester o Diseñador).

*/