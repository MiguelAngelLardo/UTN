#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std; // Usamos el espacio de nombres estándar

int maximoFX (int n1, int n2){ // POR VALOR
  int max;
  if(n1 > n2)
    max = n1;
  else  
    max = n2;
  return max;  
}

void maximoFX2(int n1, int n2, int& max){ // REFERENCIA
  if(n1 > n2)
    max = n1;
  else  
    max = n2;

  cout << endl << "WITHIN THE FUNTION: the memory adress of the 'max' variable By REFERENCE is: " << &max;  
}

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  int a, b, max;

  cout << "Enter the first number: ";
  cin >> a;
  cout << "Enter the second number: ";
  cin >> b;

  max = maximoFX (a,b);
  cout << "The maximum number in Parameter by Value mode is: " << max << endl;
  
  //************************************************************************************//

  int K;
  int *pA = &a;
  int *punteroK = &K;


  maximoFX2 (a, b, K); // VOID -> es evacuar -> se evacua la asignacion (process whotout returning a value)
  cout << endl << "Whitin the MAIN: the memory adress of the 'K' variable By REFERENCE is: " << &K << endl;
  cout << "The maximum number in Parameter by Reference mode is " << *punteroK << ". In memory adress: " << punteroK << ". i using adress of the pointer: " << &punteroK << endl;

  cout << endl << "************************" << endl;
  cout << "&a is adress of the 'a': " << &a << endl;
  cout << "pA points/apunta to the address of 'a': " << pA << endl;
  cout << "&pA is the adress of the pointer pA itself : " << &pA << endl;
  cout << "*pA shows the value to which pA is pointing: " << *pA << endl;

  //pepa pig apunta a A - la guitarra de pepa es pepa misma
  return 0;

}