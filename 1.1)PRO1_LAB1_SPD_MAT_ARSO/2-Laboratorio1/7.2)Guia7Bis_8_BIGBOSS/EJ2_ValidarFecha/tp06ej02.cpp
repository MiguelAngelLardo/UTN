//TP         : 06 sugeridos
//EJERCICIO  : 02
//AUTOR      : Angel Simón - asimon@frgp.utn.edu.ar
//DESCRIPCION: -
#include <iostream>
using namespace std;

bool esBisiesto(int anio){
  bool bisiesto=false;
  if(anio % 4 == 0){
    bisiesto = true;
    if(anio % 100 == 0){
      bisiesto = false;
      if(anio % 400 == 0){
        bisiesto = true;
      }
    }
  }
  return bisiesto;
}

bool esFechaValida(int dia, int mes, int anio){
  if(dia<1 || mes<1 || anio<1)
    return false;
  if(mes > 12)
    return false;
  //Febrero
  if(mes==2){
    if(esBisiesto(anio) && dia > 29)
      return false;
    else if(!esBisiesto(anio) && dia > 28)
      return false;
  }
  /*if(mes==2 && ((esBisiesto(anio) && dia > 29) || (!esBisiesto(anio) && dia > 28))){
    return false;
  }*/
  //Meses de 30 dias
  if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
    if(dia > 30)
      return false;
  }
  //Acá ya no llegaría si es Febrero (osea meses 1, 3, 5, 7, 8, 10 y 12
  else{
    if(dia > 31)
      return false;
  }
  return true;
}

int main(void){
  int dia, mes, anio;
  cout << "Ingresar dia: ";
  cin >> dia;
  cout << "Ingresar mes: ";
  cin >> mes;
  cout << "Ingresar anio: ";
  cin >> anio;

  if(esFechaValida(dia, mes, anio)){
    cout << endl << "La fecha es valida.";
  }
  else{
    cout << endl << "La fecha no es valida.";
  }
  return 0;
}
