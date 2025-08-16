#include <iostream>

using namespace std;

/*
Escribe un programa que simule la gestión de un club de lectura.
El programa debe solicitar al usuario la cantidad de libros que desea cargar y
posteriormente pedir los nombres de dichos libros. Una vez cargados los libros
se debe mostrar un menú con las siguientes opciones:
1- Listado: Debe listar los libros en el orden en que fueron cargados.
2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar
un mensaje aclaratorio. Si el libro existe, ingresar la cantidad de minutos que le
llevó su lectura.
3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a
Menor.
4- Salir: el programa debe salir del programa
*/

string *cargarLibros(int &tam);
void listarLibros(string vLib[], int &tam);
int *tiempoLectura(string vLib[], int &tam);
void ordenadosMayorAMenor(string vLib[], int vTiempoLectura[], int &tam);

int main() {
  string *vDinLibros = nullptr;
  int *vDinTiempoLectura = nullptr;

  int tam;
  cout << "ingrese la cantidad de libros: ";
  cin >> tam;

  vDinLibros = cargarLibros(tam);
  if(vDinLibros == nullptr) exit(500);

  int opcion;

  do{
    cout << "1- Listado: Debe listar los libros en el orden en que fueron cargados.\n";
    cout << "2- Tiempo de lectura: Se solicita el nombre del libro. Si no existe debe mostrar un mensaje aclaratorio. Si el libro existe, ingresar la cantidad de minutos que le llevo su lectura.\n";
    cout << "3- Ranking: Mostrar los libros ordenados por tiempo de lectura de Mayor a Menor.\n";
    cout << "4- Salir: el programa debe salir del programa\n";
    cin >> opcion;

    switch (opcion)
    {
      case 1:{
        listarLibros(vDinLibros, tam);
      }break;
      
      case 2:{
        vDinTiempoLectura = tiempoLectura(vDinLibros, tam);
        if(vDinTiempoLectura == nullptr) exit(500);
      }break;
      case 3:{
        ordenadosMayorAMenor(vDinLibros, vDinTiempoLectura, tam);
      }break;
      case 4:{
        cout << "Saliendo. " << endl;
        delete [] vDinLibros;
        delete [] vDinTiempoLectura;
      }break;
    }
    system("pause");
    system("cls");

  }while(opcion != 4);

  return 0;
}

string *cargarLibros(int &tam){
  string *vDinLib = nullptr;
  vDinLib = new string[tam];

  if(vDinLib == nullptr) exit(500);

  for(int i = 0; i < tam; i++){
    cout << "Libro " << i + 1 << ": ";
    cin >> vDinLib[i];
  }  

  return vDinLib;
}

void listarLibros(string vLib[], int &tam){
  cout << "Los libros son: \n";

  for(int i = 0; i < tam; i++){
    cout << vLib[i] << endl;
  }  
}

int *tiempoLectura(string vLib[], int &tam){
  string nombreLibro;

  int *tiempoLectura = nullptr;
  tiempoLectura = new int[tam];
  if(tiempoLectura == nullptr) exit(500);

  bool elLibroExiste = false;
  for(int i = 0; i < tam; i++){
    cout << "Ingrese el nombre del libro: ";
    cin >> nombreLibro;
    if(vLib[i] == nombreLibro){
      cout << "Existe, ingrese el tiempo de lectura: ";
      cin >> tiempoLectura[i];
      elLibroExiste = true;
    }  
  }  
  if(!elLibroExiste){
    cout << "El libro no existe" << endl;
  }  
  cout << "tiempo lecutura: " << endl;
  for(int i = 0; i < tam; i++){
    cout << tiempoLectura[i] << endl;
  }  

  return tiempoLectura;
}

void ordenadosMayorAMenor(string vLib[], int vTiempoLectura[], int &tam){
  int aux;
  string aux2;

  for(int i = 0; i < tam; i++){
    for(int j = i+1; j < tam; j++){
      if(vTiempoLectura[i] < vTiempoLectura[j]){
        aux = vTiempoLectura[i];
        vTiempoLectura[i] = vTiempoLectura[j];
        vTiempoLectura[j] = aux;

        aux2 = vLib[i];
        vLib[i] = vLib[j];
        vLib[j] = aux2;
      }
    }  
  }  

  cout << "Los libros ordenados son: \n";

  for(int i = 0; i < tam; i++){
    cout << "Libro " << vLib[i] << " Tiempo de lectura: " << vTiempoLectura[i] << endl;
  }  

}
