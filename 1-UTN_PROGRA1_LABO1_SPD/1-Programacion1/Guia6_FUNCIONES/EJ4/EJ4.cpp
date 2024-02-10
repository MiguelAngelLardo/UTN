#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****/

int powerFX(int base, int exponent){
  int result = 1;
  for(int x = 0; x < exponent; x ++){
    result = result * base; // result *= base
  }
  return result;
}

void power2FX(int base, int exponent, int& result){
  result = 1;
  for (int x = 0; x < exponent; x ++){
    result *= base;
  }
  cout << "power2FX => Memory Address 'result' in FUNCTION: " << &result << endl;
}

/*****FUNCIONES*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int a, b, h;

  cout << "Enter a number (base): ";
  cin >> a;
  cout << "Enter a number (exponent): ";
  cin >> b;

  h = powerFX(a,b);

  cout << "The answer (VALUE) is: " << h << ". Memory address of 'h': " << &h;

  cout << endl << "************************************" << endl;
  //**********************************************************//

  int res;

  power2FX(a,b,res);
  cout << "The answer (REFERENCE) is: " << res <<". In Memory address 'res': " << &res << endl;

  cout << endl << "***************************" << endl;

  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  
    
  return 0;

}