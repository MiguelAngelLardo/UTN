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
int cuadrante(float x, float y){
  int cuadrante;

  if(x>0){ //puede ser 1 o 4
    if(y>0){
      cuadrante = 1;
    }else{
      cuadrante = 4;
    }
  }else{
    if(y>0){
      cuadrante = 2;
    }else{
      cuadrante = 3;
    }
  }
  return cuadrante;
}

/*****ARRAY*****/

/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  // X positiva => cuadrante 1 o 4 luego con la Y determina si esta en cuadrante 1 o 4
  int quadrant;
  float x, y;

  cout << "Enter x: ";
  cin >> x;
  cout << "Enter Y: ";
  cin >> y;

  while(x != 0 && y != 0)
  {
    quadrant = cuadrante(x,y);
    cout << "The Quadrant is: " << quadrant << endl;

    cout << "Enter x: ";
    cin >> x;
    cout << "Enter Y: ";
    cin >> y;
  }

  return 0;

}