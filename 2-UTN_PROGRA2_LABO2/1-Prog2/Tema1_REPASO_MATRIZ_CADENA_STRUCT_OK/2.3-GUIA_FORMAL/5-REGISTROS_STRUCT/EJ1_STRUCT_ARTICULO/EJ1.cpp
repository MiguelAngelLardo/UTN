#include <iostream>

using namespace std;

/*
1) Un negocio representa los artículos con los 
que trabaja de la siguiente manera:
• Código de artículo (char[5])
• Descripción (char[30])
• Precio unitario (float)
• Unidades en stock (int)
Diseñar el struct correspondiente, y hacer un programa con 
funciones para cargar y mostrar un registro de artículo.
*/

struct Articulo{
  char codigoArt[5];
  char descripcion[30];
  float precio;
  int stock;
};

void cargarArticulo(Articulo &art);
void mostrarArticulo(const Articulo &art);


int main(){
  Articulo art;

  cargarArticulo(art);
  mostrarArticulo(art);


  return 0;
}

void cargarArticulo(Articulo &art){
  cout << "Ingrese el codigo del articulo(4 caracteres): ";
  cin >> art.codigoArt;

  cout << "Ingrese la descripcion: ";
  cin.ignore(); // Ignoramos el salto de línea del buffer
  cin.getline(art.descripcion, 30);

  cout << "Ingrese el precio: ";
  cin >> art.precio;

  cout << "Ingrese el stock: ";
  cin >> art.stock;
}

void mostrarArticulo(const Articulo &art){
  cout << "Articulo Cargado\n";
  cout << "Codigo del articulo" << art.codigoArt << endl;
  cout << "Descripcion" << art.descripcion << endl;
  cout << "Precio" << art.precio << endl;
  cout << "STOCK" << art.stock << endl;
}
