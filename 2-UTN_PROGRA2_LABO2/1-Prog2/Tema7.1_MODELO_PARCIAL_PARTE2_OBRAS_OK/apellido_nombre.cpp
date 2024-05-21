#include <iostream>
#include <cstring>
using namespace std;
#include "parcialm1.h"


void punto1();
void punto2();


int main() {
  //punto1();
  punto2();


  
  return 0;
}
//1-generar un archivo con el codigo de  obra, direccion y la provincia, de las obras cuyo estado de ejecucion sea "en ejecucion"

class Punto1{
  private:
    char _codigoObra[5];
    char _direccion[30];
    int _provincia;

  public:
    Punto1(const char *codObra = "x", const char *direc = "x", int prov = 0){
     strcpy(_codigoObra, codObra);
     strcpy(_direccion, direc);
     _provincia = prov;
    }

    //setters y getters
    void setCodigoObra(const char *codObra){strcpy(_codigoObra, codObra);}
    void setDireccion(const char *direc){strcpy(_direccion, direc);}
    void setProvincia(int prov){_provincia = prov;}
    void setearTodo(const char *codObra, const char *direc, int prov){
      setCodigoObra(codObra);
      setDireccion(direc);
      setProvincia(prov);
    }

    const char* getCodigoObra(){return _codigoObra;}
    const char* getDireccion(){return _direccion;}
    int getProvincia(){return _provincia;}

    //metodos  
    
    void mostrar(){
      cout<<_codigoObra<<endl;
      cout<<_direccion<<endl;
      cout<<_provincia<<endl;
    }
};

class ArchivoPunto1{

  private:
    char _nombre[30];
  public:
    ArchivoPunto1(const char *nom){
      strcpy(_nombre, nom);
    }

   void GuardarArchivo(Punto1& obj){
   FILE *p;
   p = fopen(_nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
  }

  void borrarArchivo(){
    Punto1 obj;
    FILE *p;
    p = fopen(_nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo borrarArchivo" << endl;
        exit(1);
    }
    fclose(p);
  }

  void mostrarArchivo(){
    Punto1  obj;
    FILE *p;
    p = fopen(_nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        exit(1);
    }

    while (fread(&obj, sizeof(Punto1), 1, p) == true){
      obj.mostrar();
      cout << endl;
    }

    fclose(p);
  }

};

void punto1(){
  Obra objO;//codigoObra(char), direccion(char),provincia(int),superficie(float),estadoEjecucion(1 a 5 - 3 ejecucion),activo(bool)
  ArchivoObras ARobjO("obras.dat");
  
  Punto1 objPunto1;
  ArchivoPunto1 ARobjPunto1("punto1.dat");
  ARobjPunto1.borrarArchivo();   //<-----------------

  int tam = ARobjO.contarRegistros();
  
  for(int i=0; i<tam; i++){
    objO = ARobjO.leerRegistro(i);

    if((objO.getActivo()) && (objO.getEstadoEjecucion() == 3)){
      objPunto1.setearTodo(objO.getCodigoObra(), objO.getDireccion(), objO.getProvincia());
      ARobjPunto1.GuardarArchivo(objPunto1);
    }
  }

  ARobjPunto1.mostrarArchivo();

}

//la provincia con menos proveedores (ignorando las provincias sin proveedores)
void punto2(){
  Proveedor objP;//numProvedor(1 al 60), nombre, telefono, direccion, provincia (1 a 24)
  ArchivoProveedores ARobjP("proveedores.dat");

  int tam = ARobjP.contarRegistros();
  int vProvinciasContProv[24] = {};


  for (int i=0; i<tam; i++){
    objP = ARobjP.leerRegistro(i);
    if(objP.getActivo()){
      vProvinciasContProv[objP.getProvincia() - 1] ++;  
    }  
  }  

  // int minimo = 0;
  // int band=true;
  // for(int i=0; i<24; i++){
  //   if(vProvinciasContProv[i] !=0){

  //     if(band){
  //       minimo = i+1;
  //       band=false;
  //     }else if((vProvinciasContProv[i] < minimo) && (!band)){ //<------- i?
  //       minimo = i+1;      
  //     }
  //   }  
  // }
  
  int minimo = 0;
  for(int i=1; i<24; i++){
    if(vProvinciasContProv[i] !=0){

      if((vProvinciasContProv[i] < vProvinciasContProv[minimo])){ //<------- i?
        minimo = i+1;      
      }
    }  
  }

  for(int i=0; i<24; i++){
    if(vProvinciasContProv[i] == vProvinciasContProv[minimo]){
      cout << "La provincia con menos proveedor es: " << i+1 << " -> cantidad de proveedor: " << vProvinciasContProv[i] << endl;
    }  
  }  

}



