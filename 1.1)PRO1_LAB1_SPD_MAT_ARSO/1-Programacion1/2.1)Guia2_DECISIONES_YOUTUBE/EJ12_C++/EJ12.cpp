#include <iostream>

using namespace std;

/*Hacer un programa para ingresar un valor que estará expresado en minutos. Si
los minutos superan los 60, pasar el valor a horas, de lo contrario dejarlo en
minutos. Mostrar el resultado en pantalla aclarando si se muestran minutos u
horas.*/

int main(){
  float min;

  cout << "Ingrese los minutos: ";
  cin >> min;

  if(min > 60){
    min = min/60;
    cout << "La hora es: " << min;
  }else{
    cout << "Los minutos son: " << min;
  }

  return 0;
}