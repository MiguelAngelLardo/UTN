#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "funciones.h"

void cargarCadena(char *pal, int tam){
    int i;
    tam = tam-1; //<--- esto es opcional
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}


class Fecha{
  private:
      int dia,mes, anio;
  public:
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}
  
      void Cargar(){
          cout << "Dia: "; cin>>dia;
          cout << "Mes: "; cin>>mes;
          cout << "Anio: "; cin>>anio;
      }
      void Mostrar(){
          cout<<dia<<"/";
          cout<<mes<<"/";
          cout<<anio<<endl;
      }
      int getDia(){return dia;}
      int getMes(){return mes;}
      int getAnio(){return anio;}
  
      void setDia(int d){dia=d;}
      void setMes(int m){mes=m;}
      void setAnio(int a){anio=a;}
  };


class Clientes{

private:
  int _DNI;
  char _nombreApellido[50];
  int _localidad;//1 al 150
  int _edad; //1 al 3 
  char _Genero[10];
public:
  void setDni (int dni){_DNI=dni;}
  void setNombreApellido(const char* n){strcpy(_nombreApellido,n);}
  void setLocalidad(int l){_localidad=l;}
  void setEdad(int e){_edad=e;}
  void setGenero(const char* g){strcpy(_Genero,g);}
  int getDNI(){return _DNI;}
  const char* getNombreApellido(){return _nombreApellido;}
  int getLocalidad(){return _localidad;}
  int getEdad(){return _edad;}
  const char* getGenero(){return _Genero;}

  void cargar(){
    cout << "DNI: "; cin>>_DNI;
    cout << "Nombre y Apellido: "; cargarCadena(_nombreApellido, 50);
    cout << "Localidad: "; cin>>_localidad;
    cout << "Edad: "; cin>>_edad;
    cout << "Genero: "; cargarCadena(_Genero, 10);
  }


  void mostrar(){
    cout << "DNI: " << _DNI << endl;
    cout << "Nombre y Apellido: " << _nombreApellido << endl;
    cout << "Localidad: " << _localidad << endl;
    cout << "Edad: " << _edad << endl;
    cout << "Genero: " << _Genero << endl;
  }
};

class ArchivoClientes{

  private:
      char nombre[30];
  public:
      //constructor
      ArchivoClientes(const char* nombre="Clientes.dat"){
          strcpy(this->nombre, nombre);
      }

//metodos

void GuardarArchivo(Clientes& obj){
 FILE *p;
 p = fopen(nombre,"ab");
 if(p == NULL){
    cout<<"No se pudo abrir el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fwrite(&obj,sizeof(Clientes),1,p);
 fclose(p);
}

int contarRegistros(){
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
      fseek(p, 0,2);
      int tam=ftell(p);
      fclose(p);
      return tam/sizeof(Clientes);
  }

Clientes leerRegistro(int pos){
      Clientes reg;
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
      fseek(p, sizeof reg*pos,0);
      fread(&reg, sizeof reg,1, p);
      fclose(p);
      return reg;
  }

bool reemplazarRegistro(Clientes& reg, int posicionAReemplazar){
  FILE *p = fopen(nombre, "rb+");
  if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
  fseek(p, posicionAReemplazar * sizeof(Clientes), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Clientes), 1, p);
  fclose(p);
  return pudoEscribir;
}

void cargarArchivo(int tam=1){
  Clientes objE;
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
  fwrite(&objE, sizeof(Clientes), 1, p);
  }

  fclose(p);
}

void crearArchivo(int tam=1){
  Clientes objE;
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
  fwrite(&objE, sizeof(Clientes), 1, p);
  }

  fclose(p);
}

void mostrarArchivo(){
  Clientes objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
      cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
      //cout<<"En la Linea: "<<__LINE__<<endl;
      exit(1);
  }
while (fread(&objE, sizeof(Clientes), 1, p) == true){
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

// bool ExisteDNI(int dni){
//  Clientes obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Clientes),1,p)){
//     if(obj.getDNI()==dni){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

// bool ExisteDNIchar(const char* dni){
//  Clientes obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Clientes),1,p)){
//     if(strcmp(obj.getDNI(),dni)==0){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }


};

class Ventas{

private:
  int _DNICliente;
  Fecha _FechaVenta;
  int _tipoProducto;//1 al 60
  float _importe;

public:

  void setDNICliente(int dni){_DNICliente=dni;}
  void setFechaVenta(Fecha f){_FechaVenta=f;}
  void setTipoProducto(int t){_tipoProducto=t;}
  void setImporte(float i){_importe=i;}
  int getDNICliente(){return _DNICliente;}
  Fecha getFechaVenta(){return _FechaVenta;}
  int getTipoProducto(){return _tipoProducto;}
  float getImporte(){return _importe;}

  //metodos
  void cargar(){
    cout << "DNI: "; cin>>_DNICliente;
    cout << "Fecha de Venta: "; _FechaVenta.Cargar();
    cout << "Tipo de Producto: "; cin>>_tipoProducto;
    cout << "Importe: "; cin>>_importe;
  }
  void mostrar(){
    cout << "DNI: " << _DNICliente << endl;
    cout << "Fecha de Venta: "; _FechaVenta.Mostrar();
    cout << "Tipo de Producto: " << _tipoProducto << endl;
    cout << "Importe: " << _importe << endl;
  }




};

class ArchivoVentas{

  private:
      char nombre[30];
  public:
      //constructor
      ArchivoVentas(const char* nombre="Ventas.dat"){
          strcpy(this->nombre, nombre);
      }

//metodos

void GuardarArchivo(Ventas& obj){
 FILE *p;
 p = fopen(nombre,"ab");
 if(p == NULL){
    cout<<"No se pudo abrir el archivo";
    //cout<<"En la Linea: "<<__LINE__<<endl;
 }
 fwrite(&obj,sizeof(Ventas),1,p);
 fclose(p);
}

int contarRegistros(){
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
      fseek(p, 0,2);
      int tam=ftell(p);
      fclose(p);
      return tam/sizeof(Ventas);
  }

Ventas leerRegistro(int pos){
      Ventas reg;
      FILE *p;
      p=fopen(nombre, "rb");
      if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
      fseek(p, sizeof reg*pos,0);
      fread(&reg, sizeof reg,1, p);
      fclose(p);
      return reg;
  }

bool reemplazarRegistro(Ventas& reg, int posicionAReemplazar){
  FILE *p = fopen(nombre, "rb+");
  if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
  fseek(p, posicionAReemplazar * sizeof(Ventas), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Ventas), 1, p);
  fclose(p);
  return pudoEscribir;
}

void cargarArchivo(int tam=1){
  Ventas objE;
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
  fwrite(&objE, sizeof(Ventas), 1, p);
  }

  fclose(p);
}

void crearArchivo(int tam=1){
  Ventas objE;
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
  fwrite(&objE, sizeof(Ventas), 1, p);
  }

  fclose(p);
}

void mostrarArchivo(){
  Ventas objE;
  FILE *p;
  p = fopen(nombre,"rb");
  if(p==NULL){
      cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
      //cout<<"En la Linea: "<<__LINE__<<endl;
      exit(1);
  }
while (fread(&objE, sizeof(Ventas), 1, p) == true){
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

// bool ExisteDNI(int dni){
//  Ventas obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Ventas),1,p)){
//     if(obj.getDNI()==dni){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }

// bool ExisteDNIchar(const char* dni){
//  Ventas obj;
//  FILE *p;
//  p = fopen(nombre,"rb");
//  if(p == NULL){
//     cout<<"No se pudo abrir el archivo";
//     //cout<<"En la Linea: "<<__LINE__<<endl;
//  }
//  while(fread(&obj,sizeof(Ventas),1,p)){
//     if(strcmp(obj.getDNI(),dni)==0){
//        fclose(p);
//        return true;
//     }
//  }
//  fclose(p);
//  return false;
// }


};