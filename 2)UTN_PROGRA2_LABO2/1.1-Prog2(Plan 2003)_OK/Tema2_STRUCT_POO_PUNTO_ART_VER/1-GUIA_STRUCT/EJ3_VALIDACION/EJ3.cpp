#include <iostream>
#include <cstring>

using namespace std;

/*
3) Igual al ejercicio anterior, pero la función debe devolver el registro completo. 
En caso que no exista
coincidencia, debe devolver un registro con valor -1 en el campo precio unitario.
*/

const int TAM_ART = 2;

struct Articulo{
  char codigoArt[5];
  char descripcion[30];
  float precio;
  int stock;
};

void llamarMenu(Articulo *art);

void cargarArticulo(Articulo *art);
void mostrarArticulo(const Articulo *art);

void cargarCadena(char *vec, int tam);
int coincidirCadenaPTO2(Articulo *art, char *cadena);

void coincidirCadenaPTO3(Articulo *art, char *cadena);
void mostrarArticuloPTO3(const Articulo *art, int indice);
void mostrarArticuloPTO3(const Articulo *art, int indice, int nuevoPrecio);



int main(){
  Articulo vArt[TAM_ART];
  char vCadena[5];

  llamarMenu(vArt);

  /*
  cout << "\n**PUNTO DEL EJERCICIO 3**\n";
  int posicion = coincidirCadenaPTO2(vArt, vCadena);
  (posicion == -1) ? cout << posicion : cout << "Precio Unitario del codigo '" << vCadena << "' es $" << vArt[posicion].precio;

  */

  cout << "\n**PUNTO DEL EJERCICIO 3**\n"; 
  coincidirCadenaPTO3(vArt, vCadena);

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

void cargarCadena(char *vec, int tam){
  int i;
  fflush(stdin);
  for(i = 0;i < tam;i ++){
    vec[i] = cin.get();
    if(vec[i] == '\n'){
      break;
    }
  }
  vec[i] = '\0';
  fflush(stdin);
}

int coincidirCadenaPTO2(Articulo *art, char *cadena){
  cout << "Ingrese la cadena a coincidir(CODIGO ARTICULO): ";
  cargarCadena(cadena, 5);

  for(int x = 0; x < TAM_ART; x ++){
    if(strcmp(cadena, art[x].descripcion) == 0){
      return x;
    }
  }
  return -1;
}

void coincidirCadenaPTO3(Articulo *art, char *cadena){
  cout << "Ingrese la cadena a coincidir(CODIGO ARTICULO): ";
  cargarCadena(cadena, 5);

  for(int x = 0; x < TAM_ART; x ++){
    if(strcmp(cadena, art[x].codigoArt) == 0){
      mostrarArticuloPTO3(art, x);
      return;
    }
  }

  mostrarArticuloPTO3(art, 0, -1);//sobrecargada
  
}

void mostrarArticuloPTO3(const Articulo *art, int indice){
  cout << "\nARTICULO Nro #" << indice+1 << endl;
  cout << "Codigo del articulo: " << art[indice].codigoArt << endl;
  cout << "Descripcion: " << art[indice].descripcion << endl;
  cout << "Precio: " << art[indice].precio << endl;
  cout << "STOCK: " << art[indice].stock << endl;
}

void mostrarArticuloPTO3(const Articulo *art, int indice, int nuevoPrecio){ //sobrecarga
  cout << "\nARTICULO Nro #" << indice+1 << endl;
  cout << "Codigo del articulo: " << art[indice].codigoArt << endl;
  cout << "Descripcion: " << art[indice].descripcion << endl;
  cout << "Precio: " << nuevoPrecio << endl;
  cout << "STOCK: " << art[indice].stock << endl; 
}
