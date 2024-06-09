#include <iostream>
using namespace std;


/*6 Hacer una función que reciba un número entero por valor llamado día y un
string llamado nombre por referencia y le asigne el nombre correspondiente
según el número de día. Siendo 0 → Domingo y 6 → Sábado.*/

void asignarNombreAlDia (int dia, string &nombrePorReferencia){
  switch (dia)
  {
  case 0:
    nombrePorReferencia = "Domingo";
    break;
  case 1:
    nombrePorReferencia = "Lunes";
    break;
  case 2:
    nombrePorReferencia = "Martes";
    break;
  case 3:
    nombrePorReferencia = "Miercoles";
    break;
  case 4:
    nombrePorReferencia = "Jueves";
    break;
  case 5:
    nombrePorReferencia =  "Viernes";
    break;
  case 6:
    nombrePorReferencia = "Sabado";
    break;
  }
 
}

int main (){

int dia;
string nombre;//X043

cout << "Ingrese un dia del 0 al 6: ";
cin >> dia;

asignarNombreAlDia(dia, nombre);

cout << "El nombre del dia es: " << nombre << endl;

  return 0;
}