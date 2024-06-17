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
string estacionDelAnioFX(int dia, int mes, int hemisferio);

int main()
{
  int dia, mes, hemisferio;
  string estacion;

  cout << "Ingrese el dia: ";
  cin >> dia;

  cout << "Ingrese el mes: ";
  cin >> mes;

  cout << "Ingrese el hemisferio (0 para Sur, 1 para Norte): ";
  cin >> hemisferio;

  estacion = estacionDelAnioFX(dia, mes, hemisferio);

  cout << "La estacion del anioo es: " << estacion << endl;


  return 0;
}

string estacionDelAnioFX(int dia, int mes, int hemisferio){
  if (hemisferio == 0) // Hemisferio Sur
  {
    if ((mes >= 3 && mes <= 5) || (mes == 2 && dia >= 21) || (mes == 6 && dia <= 20))
      return "Otoño";
    else if ((mes >= 6 && mes <= 8) || (mes == 5 && dia >= 21) || (mes == 9 && dia <= 20))
      return "Invierno";
    else if ((mes >= 9 && mes <= 11) || (mes == 8 && dia >= 21) || (mes == 12 && dia <= 20))
      return "Primavera";
    else
      return "Verano";
  }
  else // Hemisferio Norte
  {
    if ((mes >= 3 && mes <= 5) || (mes == 2 && dia >= 21) || (mes == 6 && dia <= 20))
        return "Primavera";
    else if ((mes >= 6 && mes <= 8) || (mes == 5 && dia >= 21) || (mes == 9 && dia <= 20))
        return "Verano";
    else if ((mes >= 9 && mes <= 11) || (mes == 8 && dia >= 21) || (mes == 12 && dia <= 20))
        return "Otoño";
    else
        return "Invierno";
  }
}

/*
En el hemisferio sur, las estaciones del año están distribuidas de la siguiente manera:

Verano:
Inicia el 21 de diciembre.
Termina el 20 de marzo.

Otoño:
Inicia el 21 de marzo.
Termina el 20 de junio.

Invierno:
Inicia el 21 de junio.
Termina el 20 de septiembre.

Primavera:
Inicia el 21 de septiembre.
Termina el 20 de diciembre.*/