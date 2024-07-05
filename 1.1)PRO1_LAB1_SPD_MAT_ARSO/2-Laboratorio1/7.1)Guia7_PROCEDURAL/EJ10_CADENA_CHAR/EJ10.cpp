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
char *assignmentNameFX(char vect[], int tam, int day);

int main()
{
  int day;
  char vWeeks[TAM], *dayName;

  cout << "Enter the day to search (0-Sunday - 6-Saturday): ";
  cin >> day;

  dayName = assignmentNameFX(vWeeks, TAM, day);
  cout << "The name of the day is: " << dayName;

  return 0;
}

char *assignmentNameFX(char vect[], int tam, int day){
  switch (day){
    case 0:
      strcpy(vect, "Sunday");
    break;
    case 1:
      strcpy(vect, "Monday");
    break;
    case 2:
      strcpy(vect, "Tuesday");
    break;
    case 3:
      strcpy(vect, "Wednesday");
    break;
    case 4:
      strcpy(vect, "Thursday");
    break;
    case 5:
      strcpy(vect, "Friday");
    break;
    case 6:
      strcpy(vect, "Saturday");
    break;
    
    default:
      strcpy(vect, "Invalid day");
    break;
  }
  return vect;
}