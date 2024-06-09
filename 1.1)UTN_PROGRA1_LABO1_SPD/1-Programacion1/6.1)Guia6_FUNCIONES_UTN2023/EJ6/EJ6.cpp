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
bool isPolindrome(int n1, int n2, int n3, int n4, int n5){ //CAPICUA

  if(n1 == n5 && n2 == n4){
    return true;
  }else{
    return false;
  }
}

/*****ARRAY*****/

/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int digit1, digit2, digit3, digit4, digit5;
  bool res;
  cout << "Enter a five-digit number (separate digits whit spaces): ";
  cin >> digit1 >> digit2 >> digit3 >> digit4 >> digit5;

  res = isPolindrome(digit1, digit2, digit3, digit4, digit5);

  cout << "Is a Polindrome?? " << res;
  return 0;

}