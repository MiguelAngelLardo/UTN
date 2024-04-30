#include <iostream>
#include <cstring>

using namespace std;

/*
#include <iostream>
#include <cstring>

using namespace std;

/*
6) Hacer una función para ordenar de manera ascendente el vector de artículos del ejercicio anterior por el
campo precio unitario.
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
int coincidirCadenaPTO2(Articulo *art, char *cadena);

void coincidirCadenaPTO3(Articulo *art, char *cadena);
void mostrarArticuloPTO3(const Articulo *art, int indice);
void mostrarArticuloPTO3(const Articulo *art, int indice, int nuevoPrecio);

void ordenarAscendenteDescr(Articulo *articulos); //PTO5

void ordenarAscendentePrecio(Articulo *articulos); // PTO6
void intercambiar(Articulo &a, Articulo &b);






int main(){
  //Articulo vArt[TAM_ART];
  Articulo vArt[TAM_ART] = {
    {"001", "Agua", 10.0, 50},
    {"002", "Fuego", 15.0, 30},
    {"003", "Tierra", 20.0, 40},
    {"004", "Aire", 25.0, 20},
    {"005", "Luz", 18.0, 25}
  };
  

  llamarMenu(vArt);

  /*
  char vCadena[5];
  
  cout << "\n**PUNTO DEL EJERCICIO 2**\n";
  int posicion = coincidirCadenaPTO2(vArt, vCadena);
  (posicion == -1) ? cout << posicion : cout << "Precio Unitario del codigo '" << vCadena << "' es $" << vArt[posicion].precio;

  cout << "\n**PUNTO DEL EJERCICIO 3**\n"; 
  coincidirCadenaPTO3(vArt, vCadena);
  */

  return 0;
}

void llamarMenu(Articulo *art){
  int opc;

  do{
    cout << "\n***INGRESE LA OPCION***\n";
    cout << "1-CARGAR ARTICULOS\n";
    cout << "2-MOSTRAR ARTICULOS\n";
    cout << "3-ORDENAR ASCENDENTE(DESCRIPCION)\n";
    cout << "4-ORDENAR ASCENDENTE(PRECIO)\n";
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
    
    case 3:
      ordenarAscendenteDescr(art);
      break;

    case 4:      
     ordenarAscendentePrecio(art);  

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

void ordenarAscendenteDescr(Articulo *articulos){
  for(int y = 0; y < TAM_ART; y ++){
    for(int i = 0; i < TAM_ART-1; i ++){
      if(strcmp(articulos[i].descripcion, articulos[i+1].descripcion) == 1){// x > x+1
        Articulo temp = articulos[i+1];//temp = aire
        articulos[i+1] = articulos[i];//aire = tierra
        articulos[i] = temp; //tierra = temp
      }
    }
  }
}


void ordenarAscendentePrecio(Articulo *articulos){
  for(int y = 0; y < TAM_ART; y ++){
    for(int x = 0; x < TAM_ART-1; x ++){
      if(articulos[x].precio > articulos[x+1].precio){
        intercambiar(articulos[x], articulos[x+1]);
      }
    }
  }
}

void intercambiar(Articulo &a, Articulo &b){
  Articulo aux;
  aux = b;
  b = a;
  a = aux;
}
