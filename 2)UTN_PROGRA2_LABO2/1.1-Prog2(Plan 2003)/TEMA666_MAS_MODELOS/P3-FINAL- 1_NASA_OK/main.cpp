#include <iostream>
#include <cstring> //para strcpy
#include <cstdlib>

using namespace std;

#include "clases.h"
#include "crearMostrar.h"

class Punto1{
private:
  int _dni;
  char _nombreApellido[50];


public:
  void setearTodo(int dni, const char* nombreApellido){
    _dni=dni;
    strcpy(_nombreApellido, nombreApellido); 
  }
    
  void cargar(){
    cout << "DNI: ";
    cin >> _dni;
    cout << "Nombre y Apellido: ";
    cargarCadena(_nombreApellido, 50);
  }

  void mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "Nombre y Apellido: " << _nombreApellido << endl;
  }
};

class ArchivoPunto1{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPunto1(const char* nombre="Punto1.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarRegistro(Punto1& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }

Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Punto1), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void BorrarArchivo(){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}


};

class Punto3{
private:
  int _dni;
  char _nombreApellido[50];


public:
  void setearTodo(int dni, const char* nombreApellido){
    _dni=dni;
    strcpy(_nombreApellido, nombreApellido); 
  }

  Punto3(const char* nombreApellido){
    strcpy(_nombreApellido, nombreApellido);
  }
    
  void cargar(){
    cout << "DNI: ";
    cin >> _dni;
    cout << "Nombre y Apellido: ";
    cargarCadena(_nombreApellido, 50);
  }

  void mostrar(){
    cout << "DNI: " << _dni << endl;
    cout << "Nombre y Apellido: " << _nombreApellido << endl;
  }
};


void punto1(){
  Nasa objNasa; // PK DNI
  ArchivoNasa objArcNasa;

  Mision objMision; // fk dni
  ArchivoMision objArcMision;

  Punto1 objPunto1;
  ArchivoPunto1 objArcPunto1;

  objArcPunto1.BorrarArchivo();

  int tamNasa = objArcNasa.contarRegistros();
  int tamMision = objArcMision.contarRegistros();

  bool banderaEsta1Vez;
  for(int x = 0; x < tamNasa; x++){
    objNasa = objArcNasa.leerRegistro(x);

    if(objNasa.getPais() == 1){
  
      for(int y = 0; y < tamMision; y++){
        objMision = objArcMision.leerRegistro(y);

        if(objNasa.getDNI() == objMision.getDNIAstronauta()){
          objPunto1.setearTodo(objNasa.getDNI(), objNasa.getNombreApellido());
          objArcPunto1.GuardarRegistro(objPunto1);
          break;
        }    
  
      }//2do for  
    }//if codigo pais == 1
  }  //1erfor

  objArcPunto1.mostrarArchivo();
}

void punto2(){
  Nasa objAstronautas;
  ArchivoNasa objArcAstronautas;

  int tamAstro = objArcAstronautas.contarRegistros();
  int vecContCategorias[15] = {0};

  for(int x = 0; x < tamAstro; x++){
    objAstronautas = objArcAstronautas.leerRegistro(x);
    vecContCategorias[objAstronautas.getCategoria()-1]++;
  }  

  for (int x = 0; x < 15; x++){
    cout << "Categoria " << x + 1 << ": " << vecContCategorias[x] << endl;
  }

  cout << endl;

  bool banderaMenorCant = false;
  int menorCantidad;
  for (int x = 0; x < 15; x++){
    if(!banderaMenorCant && vecContCategorias[x] != 0){
      menorCantidad = vecContCategorias[x];
      banderaMenorCant = true;
    }else if(vecContCategorias[x] < menorCantidad && vecContCategorias[x] != 0){
      menorCantidad = vecContCategorias[x];
    }
  }

  cout << "La categoria con menor cantidad de astronautas es: ";
  for (int x = 0; x < 15; x++){
    if(vecContCategorias[x] == menorCantidad){
      cout << x + 1 << " ";
    }  
  }  
}

/*
2) Agregar un constructor para alguna de las clases del ejercicio 1, que reciba como
parámetro una cadena de caracteres (2 puntos).
*/
void punto3(){
  Punto3 objPunto3("Juan Perez");
  objPunto3.mostrar();
  objPunto3.cargar();
  objPunto3.mostrar();
}

int main(){

  //crearDat(10);
  //mostrarDat();

  punto3();
  
  return 0;
}