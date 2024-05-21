#include <iostream>
#include <cstring>

using namespace std;
#include "clases.h"
/*
1)
- A partir de un número de municipio que se ingresa por teclado, generar un archivo con las empresas que pertenezcan e ese municipio.
Los registros del archivo nuevo deben tener el siguiente formato:
- Número empresa, nombre de la empresa y cantidad de empleados.

2)
A partir de un número de sección que se ingresa por teclado, generar un archivo nuevo con aquellas empresas que pertenezcan a municipios de esa sección. 
Los registros del archivo nuevo deben tene el mismo formato que el archivo del punto anterior.
NOTA: las clases para trabajar con los archivos de empresas y municipios se encuentran en el archivo clases.h que se adjunta.
Crear la/s clase/s necesarias para resolver los puntos
*/

class Punto1{
  private:
    int numero;
    char nombre[30];
    int cantidadEmpleados;
  public:


    void setNumero(int num){numero = num;}
    void setNombre(const char *nom){strcpy(nombre, nom);}
    void setCantidadEmpleados(int ce){cantidadEmpleados = ce;}      
    void setearTododos(int num, const char *nom, int ce){
      setNumero(num);
      setNombre(nom);
      setCantidadEmpleados(ce);
    }

    int getNumero(){return numero;}
    const char *getNombre(){return nombre;}
    int getCantidadEmpleados(){return cantidadEmpleados;}

    void mostrar(){
      cout << "Numero" << numero << "\tNombre:" << nombre << "\tCantidad de empleados:" << cantidadEmpleados;
    }
};

class ArchivoPunto1{
  private:
    char nombre[30];
  public:
    ArchivoPunto1(const char *n = "punto1.dat"){strcpy(nombre, n);}  

    
  int contarRegistros(){//cuantos registros tengo
  FILE *p = fopen(nombre, "rb");
  if(p==NULL) return -1;
  
  fseek(p, 0,2); //cursor al final del codigo
  int tam=ftell(p); //del principio hasta donde esta el cursor
  
  fclose(p);
  return tam/sizeof(Punto1); //calculo para devolver la cantidad => si alumno pesa 30 y tengo 3 registros, devolveria 3(90/30)
  
  }

void listarArticulo(const char *nombre="punto1.dat"){
  Punto1 obj;
  FILE *p;
  p = fopen(nombre, "rb");
  if (p == NULL){
    cout << "Error de apertura";
    return;
  }

  while (fread(&obj, sizeof(Punto1), 1, p) == 1){
    obj.mostrar();
    cout << endl;
  }
  fclose(p);
}
    
    
  bool GuardarArchivo(Punto1 obj, const char *nombre="punto1.dat"){
    bool result;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p == NULL){return false;}
    result = fwrite(&obj,sizeof(Punto1),1,p);
    fclose(p);
    return result;
   }

   void borrarArchivo(const char *nombre="punto1.dat"){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
  }

};
    

void punto1(){
  Empresa objE;//numero, nombre, cantidadEmpleados, categoria(1 a 80), numeroMunicipio (1 a 153)
  ArchivoEmpresas ARobjE;

  Punto1 objPunto1;
  ArchivoPunto1 ARobjPunto1;
  ARobjPunto1.borrarArchivo();
  
  int numMunicipio;
  cout << "Ingrese el numero de municipio: ";
  cin >> numMunicipio;

  int tam = ARobjE.contarRegistros();

  for (int i = 0; i < tam; i++){
      objE = ARobjE.leerRegistro(i);
      if (objE.getNumeroMunicipio() == numMunicipio){
        objPunto1.setearTododos(objE.getNumero(), objE.getNombre(), objE.getCantidadEmpleados());
        ARobjPunto1.GuardarArchivo(objPunto1);        
      }  
  }

  ARobjPunto1.listarArticulo();
}

void punto2(){
  Empresa objE;//numero, nombre, cantidadEmpleados, categoria(1 a 80), numeroMunicipio (1 a 153)
  ArchivoEmpresas ARobjE;//int contar,Empresa leerIndice,int buscarPorNumero,bool modificar, bool guardar/grabar, bool listar 

  Municipio objM; //numero(1 a 135), nombre, cantidadHabitantes, seccion(1 a 6), estado
  ArchivoMunicipios ARobjM;

  Punto1 objPTO1;
  ArchivoPunto1 ARobjPunto1;
  ARobjPunto1.borrarArchivo("punto2.dat");
  
  
  int numSeccion;
  cout << "Ingrese la seccion(1 al 6) del municipio para mostrar que empresas pertenencen a esa seccion del municipio: ";
  cin >> numSeccion;

  int tam1 = ARobjE.contarRegistros();
  int tam2 = ARobjM.contarRegistros();

  for (int i = 0; i < tam1; i++){
    objE = ARobjE.leerRegistro(i);
    if(objE.getEstado() == true){
    
      for(int j = 0; j < tam2; j++){
        objM = ARobjM.leerRegistro(j);
        if(objM.getEstado()){

          if(objE.getNumeroMunicipio() == objM.getNumero()){
            if(objM.getSeccion() == numSeccion){
              objPTO1.setearTododos(objE.getNumero(), objE.getNombre(), objE.getCantidadEmpleados());
              ARobjPunto1.GuardarArchivo(objPTO1, "punto2.dat");              
            }
          }    
        }  
      }  
    }
  }

  ARobjPunto1.listarArticulo("punto2.dat");


}

void menu(){
  Empresa objE;//numero, nombre, cantidadEmpleados, categoria(1 a 80), numeroMunicipio (1 a 153)
  ArchivoEmpresas ARobjE;//int contar,Empresa leerIndice,int buscarPorNumero,bool modificar, bool guardar/grabar, bool listar 

  Municipio objM; //numero(1 a 135), nombre, cantidadHabitantes, seccion(1 a 6), estado
  ArchivoMunicipios ARobjM;

  int opc;
  while (true)
  { 
    system ("cls");
    cout << "*****MENU*****" << endl;
    cout << "1-Cargar Empresa" << endl;//numero, nombre, cantidadEmpleados, categoria(1 a 80), numeroMunicipio (1 a 153)
    cout << "2-Mostrar Empresas" << endl;
    cout << "3-cargar Municipio" << endl;//numero(1 a 135), nombre, cantidadHabitantes, seccion(1 a 6), estado
    cout << "4-Mostrar Municipios" << endl;
    cout << "---------------------" << endl;
    cout << "5-PUNTO 1" << endl;
    cout << "6-PUNTO 2" << endl;
    cout << "0-Salir" << endl;
    cout << "Opcion: ";
    cin >> opc;
    system("cls");

    switch (opc)
    {
    

    case 1:{
    int num;
    cout<<"ingrese cantidad de registros: "; cin>>num;
      for(int i; i<num; i++){
        objE.Cargar();
        cout << (ARobjE.grabarRegistro(objE) ?  "Registro guardado correctamente\n" : "Error de apertura\n") << endl;
      }
    }break;

    case 2:
      ARobjE.listarRegistros();//dentro tiene el mostrar

      break;
    case 3:{
      int num;
      cout << "Ingrese la cantidad de registros a cargar: "; cin >> num;
      for (int i = 0; i < num; i++){
        objM.Cargar();
        ARobjM.grabarRegistro(objM);
        cout << endl;
      }
      }break;
    case 4:
      ARobjM.listarRegistros();
      break;
    /**********************/

    case 5:{
      punto1();
    }break;

    case 6:{
      punto2();
    }break;

    case 0:
      return;
    default:
        cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
        system("pause");
      break;
    }
    system("pause");
  } 
}

int main(){
 
  menu();

  return 0;
}



