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

void cargarVector(int vect[], int tam);
int valorMaximo(int vect [], int tam);

int main()
{
 int vNumeros[TAM], max;

 cargarVector(vNumeros, TAM);
 max = valorMaximo(vNumeros, TAM);

 cout << "Max Value: " << max;

  return 0;
}

void cargarVector(int vect[], int tam){
  cout << "VECTOR: " << endl; 
  for(int x = 0; x < tam; x++){
    cout << x+1 << ") Ingrese un numero: ";
    cin >> vect[x];
  }
}

int valorMaximo(int vect [], int tam){
  int max = vect[0];
  for(int x = 1; x < tam; x ++){
    if(vect[x] > max)
      max = vect[x];
  }
  return max;
}