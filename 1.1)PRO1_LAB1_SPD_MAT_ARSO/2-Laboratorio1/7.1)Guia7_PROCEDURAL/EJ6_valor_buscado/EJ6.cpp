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

void pedirNumero(int &n);
void cargarVector(int vect[], int tam);
void valorBuscado (int n1, int vect[], int tam);

int main()
{
 int vNumeros[TAM], n1;

 pedirNumero(n1);
 cargarVector(vNumeros, TAM);
 valorBuscado(n1, vNumeros, TAM);
 



  return 0;
}

void pedirNumero(int &n){
  cout << "Ingrese un numero: ";
  cin >> n;
}

void cargarVector(int vect[], int tam){
  cout << "VECTOR: " << endl; 
  for(int x = 0; x < tam; x++){
    cout << x+1 << ") Ingrese un numero: ";
    cin >> vect[x];
  }
}

void valorBuscado (int n1, int vect[], int tam){
  bool flag = false;
  for(int x = 0; x < tam; x ++){
    if (n1 == vect[x])
      flag = true;    
  }

  cout << ((flag) ? "Verdadero" : "Falso"); 
}