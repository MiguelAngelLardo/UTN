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
bool primo(int n1){ //CAPICUA
  
  int prePrimo = 0;
  for(int x = 1; x <= n1; x ++){
    if(n1 % x == 0)
      prePrimo++;     
  }

 return (prePrimo == 2) ? true : false;
}

/*****ARRAY*****/

/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int n, contPrimo = 0;

  cout << "Enter a number: ";
  cin >> n;
  while (n != 0)
  { 
    if(primo(n))
      contPrimo ++;
    
    cout << "Enter a number: ";
    cin >> n;
  }
    cout << "Amount of primo numbers: " << contPrimo;
  
  return 0;

}