#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 const int TAM = 5;
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/
void recepcion (int vect[], int tam, int n);

int main()
{
  int vCifras[TAM], numero;
  cout << "Ingrese un numero: ";
  cin >> numero;

  recepcion(vCifras, TAM, numero);

  cout << "El vector resultante es: ";
  for (int x = TAM -1; x >= 0; x --){
    cout << vCifras[x] << " ";
  }

  return 0;
}

void recepcion (int vect[], int tam, int n){
  for(int x = 0; x < tam; x++){
   vect [x] = n % 10; //obtengo la ultiam cifra del numero
   n = n / 10; // Elimino la ultima cifra del numero
  }
}