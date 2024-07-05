#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
int redounding(float a);

int main()
{
  float n1;
  cout << "Eneter a float nubmer: ";
  cin >> n1;

  n1 = redounding(n1);

  cout << "Rounder Number: " << n1;
  

  return 0;
}

int redounding(float a){
  int integerPart = (int)a;
  float decimapPart = a - integerPart;

  if(decimapPart >= 0.5)
    return integerPart + 1;
  else
  return integerPart;

}