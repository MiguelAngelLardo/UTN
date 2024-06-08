#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****/
int calculateAgeFX(int bd, int bm, int by, int cd, int cm, int cy){
  int age;
  age = cy - by;
  if(cm < bm || (cm == bm && cd < bd))
    age --;
  return age;
}

void calculateAge2FX(int bd, int bm, int by, int cd, int cm, int cy, int &age){
  age = cy - by;
  if(cm < bm || (cm == bm && cd < bd))
    age --;
  cout << "Memory Address in 'age': " << &age << endl;
}
/*****FUNCIONES*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear, age;

  cout << "Enter the date of birth (dd mm yyyy): ";
  cin >> birthDay >> birthMonth >> birthYear;

  cout << "Enter the current date (dd mm yyyy): ";
  cin >> currentDay >> currentMonth >> currentYear;

  age = calculateAgeFX(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear);
  int *pointerAge = &age;
  cout << "Your age is (IN VALUE FUNCTION): " << *pointerAge << endl;

  cout << endl << "************************************" << endl;
  //**********************************************************//
  int ag;
  calculateAge2FX(birthDay, birthMonth, birthYear, currentDay, currentMonth, currentYear, ag);
  int *pointerAg = &ag;
  cout << "Memory address of 'ag': " << &ag << endl;
  cout << "Your age is (IN REFERENCE FUNCTION): " << *pointerAg << endl; 
  cout << "Memory Address of its own pointerAg: " << &pointerAg; 

  cout << endl << "***************************" << endl;

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */
    
  return 0;

}