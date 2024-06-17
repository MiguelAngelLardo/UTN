//TP         : 06 sugeridos
//EJERCICIO  : 03
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

short compararFechas(short dia1, short mes1, short anio1, short dia2, short mes2, short anio2){
  if(anio1 < anio2){
    return -1;
  }
  else if(anio1 > anio1){
    return 1;
  }
  else{ //Años iguales
    if(mes1 < mes2){
      return -1;
    }
    else if(mes1 > mes2){
      return 1;
    }
    else{ //Meses iguales
      if(dia1 < dia2){
        return -1;
      }
      else if(dia1 > dia2){
        return 1;
      }
      else{ //Días iguales
        return 0;
      }
    }
  }
}

int main(void){
  short d1, m1, a1, d2, m2, a2, res;
  cout << "Ingrese la primer fecha (separada por espacios): ";
  cin >> d1 >> m1 >> a1;
  cout << "Ingrese la segunda fecha (separada por espacios): ";
  cin >> d2 >> m2 >> a2;

  res=compararFechas(d1, m1, a1, d2, m2, a2);
  cout << endl;
  if(res>0){
    cout << "La primer fecha es posterior.";
  }
  else if(res<0){
    cout << "La primer fecha es anterior.";
  }
  else{
    cout << "Las fechas son iguales.";
  }
  return 0;
}
