#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
#include <vector> //es para verctor dinamico STL
#include <ctime> //es para la hs
#include <cstdlib>  // Necesario para std::rand y std::srand

using namespace std;// Usamos el espacio de nombres estándar

float calcularPotencia(int base, int exponente){
  
  float resultado = 1;
  bool exponenteNegativo = false;
  
  if(exponente < 0){
    exponenteNegativo = true;
    exponente = -exponente; //exponente *= -1;
  }
   
  for(int i = 1; i <= exponente ; i ++){
    resultado = resultado * base; // resultado *= base;
  }

  if(exponenteNegativo)
    return 1/resultado;

  return resultado;
}

int main()
{
  int base, exponente;
  float resultado;
  cout << "Ingrese la base: "; 
  cin >> base;
  cout << "Ingrese el exponente: ";
  cin >> exponente;

  resultado = calcularPotencia(base, exponente);
  cout << "Resultado: " << resultado;
 
}