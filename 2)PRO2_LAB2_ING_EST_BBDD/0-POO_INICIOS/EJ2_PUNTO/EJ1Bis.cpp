#include <iostream>
using namespace std;
#include "Punto.h" // Asegúrate de incluir la clase Punto correctamente

int main() {
  //si esta en 3 y 4 la distancia es 5 => asi hago un angulo recto sin tener
  //transportador ni escuadra => asi se hacen las casas 
  //sin escuadra usando linea de 3 y 4 con compas
  Punto miPunto(3.0, 4.0); // Crea un objeto Punto con coordenadas (3.0, 4.0)

  // Imprime las coordenadas directamente para verificar
  cout << "Coordenadas del punto: (" << miPunto.getX() << ", " << miPunto.getY() << ")" << std::endl;

  // Llama a toString() y muestra el resultado
  cout << "Representación del punto: " << miPunto.toString() << endl;

  return 0;
}