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
bool primo(int a);

int main()
{
  int n1;
  cout << "Enter a number: ";
  cin >> n1;

  n1 = primo(n1);

  if(n1 == 1)
    cout << "verdadero";
  else
    cout << "Falso";

  return 0;
}

bool primo(int a){
  int counterPrePrimo = 0;
  for(int x = 1; x <= a; x++){
    if(a % x == 0){
      counterPrePrimo ++;
    }    
  }

  if(counterPrePrimo == 2)
    return true;
  else
    return false;
}