#include <iostream>
#include <cstring>

using namespace std;

/*
5) Modificar el ejercicio 2, de tal manera de no permitir 
que se repita el código de artículo en diferentes registros. Usar para eso la función del ejercicio 3.
*/

const int TAM_ART = 5;

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
int coincidirCadenaPTO3(Articulo *art, char *cadena);

void coincidirCadenaPTO4(Articulo *art, char *cadena);
void mostrarArticuloPTO4(const Articulo *art, int indice);
void mostrarArticuloPTO4(const Articulo *art, int indice, int nuevoPrecio);



int main(){
  Articulo vArt[TAM_ART];
  char vCadena[30];

  llamarMenu(vArt);

  /*
  cout << "\n**PUNTO DEL EJERCICIO 3**\n";
  int posicion = coincidirCadenaPTO3(vArt, vCadena);

  (posicion == -1) ? cout << posicion : cout << "posicion: " << posicion + 1;
  */

  cout << "\n**PUNTO DEL EJERCICIO 4**\n"; 
  coincidirCadenaPTO4(vArt, vCadena);

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
   for(int x = 0; x < TAM_ART; x ++) {
    if(x == 0) {
      cout << x+1 << ") Ingrese el codigo del articulo (4 caracteres): ";
      cin >> art[x].codigoArt;
    }else{
      bool repetido;
      do {
        repetido = false;
        cout << x+1 << ") Ingrese el codigo del articulo (4 caracteres): ";
        cin >> art[x].codigoArt;
        for(int i = 0; i < x; i++) {
          if(strcmp(art[x].codigoArt, art[i].codigoArt) == 0) {
          cout << "Error El codigo de articulo ya ha sido utilizado. Intente nuevamente.\n";
          repetido = true;
          }
        }
      } while(repetido);
    }

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

int coincidirCadenaPTO3(Articulo *art, char *cadena){
  cout << "Ingrese la cadena a coincidir: ";
  cargarCadena(cadena, 30);

  for(int x = 0; x < TAM_ART; x ++){
    if(strcmp(cadena, art[x].descripcion) == 0){
      return x;
    }
  }
  return -1;
}

void coincidirCadenaPTO4(Articulo *art, char *cadena){
  cout << "Ingrese la cadena a coincidir: ";
  cargarCadena(cadena, 30);

  for(int x = 0; x < TAM_ART; x ++){
    if(strcmp(cadena, art[x].descripcion) == 0){
      mostrarArticuloPTO4(art, x);
      return;
    }
  }

  mostrarArticuloPTO4(art, 0, -1);
  
}

void mostrarArticuloPTO4(const Articulo *art, int indice){
  cout << "\nARTICULO Nro #" << indice+1 << endl;
  cout << "Codigo del articulo: " << art[indice].codigoArt << endl;
  cout << "Descripcion: " << art[indice].descripcion << endl;
  cout << "Precio: " << art[indice].precio << endl;
  cout << "STOCK: " << art[indice].stock << endl;
}

void mostrarArticuloPTO4(const Articulo *art, int indice, int nuevoPrecio){
  cout << "\nARTICULO Nro #" << indice+1 << endl;
  cout << "Codigo del articulo: " << art[indice].codigoArt << endl;
  cout << "Descripcion: " << art[indice].descripcion << endl;
  cout << "Precio: " << nuevoPrecio << endl;
  cout << "STOCK: " << art[indice].stock << endl; 
}
