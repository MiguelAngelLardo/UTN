#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 const int TAM = 10;
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
string assignmentNameFX(int day);

int main()
{
  int day;
  string dayName;

  cout << "Enter the day to search (0-Sunday - 6-Saturday): ";
  cin >> day;

  dayName = assignmentNameFX(day);
  cout << "The name of the day is: " << dayName;

  return 0;
}

string assignmentNameFX(int day){
switch (day){
  case 0:
      return "Sunday";
  case 1:
      return "Monday";
  case 2:
      return "Tuesday";
  case 3:
      return "Wednesday";
  case 4:
      return "Thursday";
  case 5:
      return "Friday";
  case 6:
      return "Saturday";
  default:
      return "Invalid day";
  }
}