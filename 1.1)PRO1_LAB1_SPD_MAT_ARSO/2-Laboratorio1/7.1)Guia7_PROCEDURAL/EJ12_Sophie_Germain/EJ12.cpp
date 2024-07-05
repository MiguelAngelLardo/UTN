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
bool primoSophieFX(int n);

int main()
{
  int num;
  cout << "Ingrese un numero:";
  cin >> num;

  if(primoSophieFX(num))
    cout << "Verdadero";
  else
    cout << "Falso";
 
  return 0;
}

bool primoSophieFX(int n){
  int divisor = 0;
  for (int x = 1; x <= n; x++)
    if(n % x == 0)
      divisor ++;
  
  if(divisor == 2){
    int m = 2 * n + 1;
    int divisorSophie = 0;
    for(int x = 1; x <= m; x++){
      if (m % x == 0){
        divisorSophie ++;
      } 
    }  

    if(divisorSophie == 2){
      return true; 
    }  
  }

  return false;
}