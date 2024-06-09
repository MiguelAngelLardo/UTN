#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std; // Usamos el espacio de nombres estándar

int sumarFX(int n1, int n2){ //POR VALOR
  int resultado;
  resultado = n1 + n2;
  return resultado;
}

void sumar2FX(int n1, int n2, int& RES){ //REFERENCIA
  RES = n1 + n2;
  cout << "FUNCION: La direccion de 'RES' es: " << &RES << endl; // Imprimimos la dirección de memoria de 'RES'.
}

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 

  int numero1, numero2, H;
  cout << "Ingrese el numero 1: ";
  cin >> numero1;
  cout << "Ingrese el numero 2: ";
  cin >> numero2;

  H = sumarFX (numero1, numero2);
  cout << "La suma POR VALOR ES: " << H << endl;
  cout << "*************************************" << endl << endl; 

  int K;
  sumar2FX(numero1, numero2, K);
  cout << "La suma es POR REFERENCIA es : " << K << ". La direccion de memoria de la variable (MAIN): " << &K << endl;

  // Ahora, creamos un puntero 'pK' que apunte a 'K'.
  int* pNumero1 = &numero1;
  int* pNumero2 = &numero2;
  int* pK = &K;

  // Imprimimos el valor al que apunta 'pK'. 
  cout << "El puntero *pNumero1 guarda &numero1: " << *pNumero1 <<endl;
  cout << "El puntero *pNumero2 guarda &numero2: " << *pNumero2 << endl;
  cout << "El puntero *pK guarda &K: " << *pK << endl;

  return 0;

}