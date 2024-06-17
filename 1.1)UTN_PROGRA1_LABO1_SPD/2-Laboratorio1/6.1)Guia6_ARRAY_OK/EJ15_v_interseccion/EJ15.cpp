#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema

using namespace std;// Usamos el espacio de nombres estándar

/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/


/*****ARRAY*****/
const int VECT_1 = 5;
const int VECT_2 = 10;
/*****ARRAY*****/

int main()
{
  setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
  int vNumFive[VECT_1] = {}, vNumTen[VECT_2] = {}, vNumIntersection[VECT_1+VECT_2] = {}, n;

  cout << "IN ONE VECTOR: " << endl;
  for(int x = 0; x < VECT_1; x ++){
    cout << x+1 <<") Enter a number: ";
    cin >> n;
    vNumFive[x] = n;
  }

  cout << endl << "IN SECOND VECTOR: " << endl;
  for(int x = 0; x < VECT_2; x ++){
    cout << x+1 <<") Enter a number: ";
    cin >> n;
    vNumTen[x] = n;
  }

  int intersectionIndex = 0; // Index for the intersection array
  for (int i = 0; i < VECT_1; i++){
    for (int j = 0; j < VECT_2; j++){
      if (vNumFive[i] == vNumTen[j]){
        vNumIntersection[intersectionIndex] = vNumFive[i];
        intersectionIndex++;
      }
    }
  }

  cout << endl << "OUT THIRD  VECTOR: " << endl;
  for(int x = 0; x < VECT_1+VECT_2; x ++)
    if(vNumIntersection [x] != 0)
      cout << "Number #" << x+1 << ": " << vNumIntersection[x] << endl; 
  return 0;
}