#include <iostream>
#include <iomanip>

using namespace std;
/*
Una universidad desea conocer los porcentajes de mujeres y hombres en las
carreras de ciencias exactas. Se solicita un programa para cargar la cantidad de
mujeres y la cantidad de hombres y que el mismo calcule y emita por pantalla
los porcentajes correspondientes.*/

int main (){  
  int cantHombres, cantMujeres;

  float porcHombre;
  cout << "Ingrese las cantidades de hombres: ";
  cin >> cantHombres;
  cout << "Ingrese las cantidades de mujeres: ";
  cin >> cantMujeres;

  porcHombre = cantHombres * 100 / (float)(cantHombres + cantMujeres); 
  float porcMujer = cantMujeres * 100 / (float)(cantHombres + cantMujeres);

  cout << "El porcentaje de hombres es: " << fixed << setprecision(2) << porcHombre << endl;
  cout << "El porcentaje de mujeres es: " << porcMujer << endl;

  return 0;
}