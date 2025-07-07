#include <iostream>

using namespace std;

/*
2) Un comercio vende un total de 50 artículos diferentes. 
Para cada uno de ellos almacena la información que se 
detalló en el ejercicio anterior.
Hacer un programa para cargar y mostrar por pantalla la lista de artículos. 
El programa debe tener un menú con funciones.
*/

const int TAM_ART = 3;

struct Articulo{
  char codigoArt[5];
  char descripcion[30];
  float precio;
  int stock;
};

void llamarMenu(Articulo *art);

void cargarArticulo(Articulo *art);
void mostrarArticulo(const Articulo *art);


int main(){
  Articulo vArt[TAM_ART];
  llamarMenu(vArt);




  return 0;
}

void llamarMenu(Articulo *art){
  int opc;

  do{
    cout << "\n***INGRESE LA OPCION***\n";
    cout << "1-CARGAR ARTICULOS\n";
    cout << "2-MOSTRAR ARTICULOS\n";
    cout << "0-SALE DEL PROGRAMA\n";
    cout << "OPCION: ";
    cin >> opc;

    switch (opc)
    {
    case 1:
      cargarArticulo(art);
      break;
    
    case 2:
      mostrarArticulo(art);
      break;
    }
  }while (opc != 0);
}


void cargarArticulo(Articulo *art){
  for(int x = 0; x < TAM_ART; x ++){
    cout << x+1 << ")Ingrese el codigo del articulo(4 caracteres): ";
    cin >> art[x].codigoArt;

    cout << x+1 << ")Ingrese la descripcion: ";
    cin.ignore(); // Ignoramos el salto de línea del buffer
    cin.getline(art[x].descripcion, 30);

    cout << x+1 << ")Ingrese el precio: ";
    cin >> art[x].precio;

    cout << x+1 << ")Ingrese el stock: ";
    cin >> art[x].stock;
    cout << endl;
  }
}

void mostrarArticulo(const Articulo *art){
  for(int x = 0; x < TAM_ART; x ++){
    cout << "\nARTICULO Nro #" << x+1 << endl;
    cout << "Codigo del articulo: " << art[x].codigoArt << endl;
    cout << "Descripcion: " << art[x].descripcion << endl;
    cout << "Precio: " << art[x].precio << endl;
    cout << "STOCK: " << art[x].stock << endl;
  }
}
