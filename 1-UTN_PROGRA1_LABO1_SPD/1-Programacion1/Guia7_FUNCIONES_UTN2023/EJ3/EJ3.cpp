#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

int sumaFX(int n1, int n2){ // VALUE
  int resultado;
  resultado = n1 + n2;
  return resultado;
}

int productoFX(int n1, int n2){ // VALUE
  int resultado;
  resultado = n1 * n2;
  return resultado;
}

void suma2FX(int n1, int n2, int& n3){ // REF
  n3 = n1+ n2;
  cout << "Within the FUNTION suma2FX: the memory adress to the n3 using &n3 is: " << &n3 << endl;
}

void producto2FX(int n1, int n2, int& n3){ // REF
  n3 = n1 * n2;
  cout << "Within the FUNTION producto2FX: the memory adress to the n3 using &n3 is: " << &n3 << endl;
}


int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  
  int a, b, sum, prod;

  cout << "Ingrese el numero 1: ";
  cin >> a;
  cout << "Ingrese el numero 2: ";
  cin >> b;

  sum = sumaFX (a,b);
  prod = productoFX (a,b);

  cout << "la suma es (POR VALOR): " << sum << endl;
  cout << "el producto es (POR VALOR): " << prod << endl;

  cout << endl << "************************************" << endl;

  //**********************************************************//

  int su, pro;
  suma2FX (a, b, su); // -> VOID es evacuar -> evacuo la asignacion
  producto2FX (a, b, pro); // -> VOID es evacuar -> evacuo la asignacion
  
  
  cout << "la suma es (POR REFERENCIA): " << su << ". En la direccion &su: " << &su << endl;
  cout << "el producto es (POR REFERENCIA): " << pro << ". En la direccion &pro: " << &pro << endl;;

  cout << endl << "***************************" << endl;

  int *punteroA = &a;

  cout << "&a => " << &a << endl;
  cout << "punteroA is adress of 'a': " << punteroA << endl;
  cout << "&punteroA is adress ot the pointer PunteroA itself: " << &punteroA << endl;
  cout << "*punteroA shows the value of the punteroA is pointing: " << *punteroA;
  
  return 0;

}