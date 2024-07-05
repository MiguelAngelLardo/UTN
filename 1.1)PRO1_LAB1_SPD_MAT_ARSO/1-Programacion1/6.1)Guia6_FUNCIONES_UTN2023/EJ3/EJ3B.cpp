#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma
void sumProductFX(int n1, int n2, int &suma, int &producto){
  suma = n1 + n2;
  producto = n1 * n2;
}

/*****FUNCIONES*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int a, b, sum, product;

  cout << "Enter a number: ";
  cin >> a;
  cout << "Enter a number: ";
  cin >> b;

  sumProductFX(a, b, sum, product);

  cout << "The sum of the two number is: " << sum << endl;
  cout << "The product of the two number is: " << product << endl;

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */
    
  return 0;

}