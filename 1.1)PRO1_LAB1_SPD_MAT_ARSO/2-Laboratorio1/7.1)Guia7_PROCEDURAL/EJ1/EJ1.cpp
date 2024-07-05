#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
const int RATES_TRASLATION = 3; // hay 20 tipos de tarifas
 
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma


/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */


/*****FUNCIONES*****/

bool multiplo(int n1, int n2);

int main()
{
  int n1, n2;
  bool resultado;
  cout << "Ingrese un numero: ";
  cin >> n1;

  cout << "Ingrese otro numero: ";
  cin >> n2;

  resultado = multiplo(n1, n2);

  if(resultado){
    cout << "El numero " << n1 << " es multiplo de " << n2;
  }else{
    cout << "El numero " << n1 << " NO es multiplo de " << n2;

  }

  return 0;
  
}
bool multiplo(int n1, int n2){
  if(n1 % n2 == 0)
    return true;
  else
    return false;
}