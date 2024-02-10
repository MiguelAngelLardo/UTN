#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */


/*****FUNCIONES*****/
bool par (int n1){ //CAPICUA
  return (n1 % 2 == 0) ? true : false;
}

/*****ARRAY*****/

/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int n, contPar = 0;

  cout << "Enter a number: ";
  cin >> n;
  while (n != 0)
  { 
   contPar += (par(n) == true) ? 1 : 0;    
    
    cout << "Enter a number: ";
    cin >> n;
  }
    cout << "Amount of even numbers: " << contPar;
  
  return 0;

}