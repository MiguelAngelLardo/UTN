#include <iostream> // Incluimos la librería iostream para entrada/salida estándar
#include <iomanip> // Necesario para setprecision
#include <cstring> // La libreria cstring tiene la funcion 'strcpy' => es para copiar un array a otra variable
#include<locale> //es la biblioteca => tiene funciones como setlocale para configuracion regional del sistema
//setlocale(LC_ALL,"Spanish"); //LC_ALL/Locale Category -> ALL indica q se configuran todas las categorias regionales disponibles 
using namespace std;// Usamos el espacio de nombres estándar

/*****ARRAY*****/
 const int TAM = 10;
/*****FUNCIONES*****///pepa pig apunta a A - la guitarra de pepa es pepa misma

/*
  int *punteroA = &a;
  cout << "Memory Address of 'a': " << &a << endl;
  cout << "punteroA has the memory adress of 'a': " << punteroA << endl;
  cout << "&punteroA has its own memory Adress : " << &punteroA << endl;
  cout << "*punteroA has a value of 'a': " << *punteroA << endl;  */

/*****FUNCIONES*****/

int contarNumeros(){
  int contador = 0;

  for (int x = 1; x < 99999; x ++){
    int temporal = x;
    int contadorDeTres = 0, contadorDeCuatro = 0;
    bool tieneCuatro = false, tieneCinco = false;

    while (temporal > 0){
      int digito = temporal % 10;
      if (digito == 3) {
        contadorDeTres ++;
      } else if (digito == 4) {
        contadorDeCuatro ++;
        tieneCuatro = true;
      } else if (digito == 5) {
        tieneCinco = true;
      }
      temporal /= 10;
    }
    if (contadorDeTres > contadorDeCuatro && tieneCuatro && !tieneCinco) {
      contador++;
    }
  }
  return contador;
}



int main()
{
  int cantidad = contarNumeros();

  cout << "La cantidad de números entre 1 y 99999 que cumplen con las condiciones es: " << cantidad;
 
  return 0;
}