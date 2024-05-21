#include<iostream>
#include <cstring>
#include<iomanip>

using namespace std;
#include "parcialm1.h"

class Punto1{

    private:
    char _codigoObra[5];
      char _direccion[30];
      int _provincia;

    public:

    void setCodigoObra(const char *c){strcpy(_codigoObra,c);}
    void setDireccion(const char *d){strcpy(_direccion,d);}
    void setProvincia(int p){_provincia=p;}
    void setearTodo(const  char * c, const char *d, int p){
      setCodigoObra(c);
      setDireccion(d);
      setProvincia(p);

    
    }  

    const char* getCodigoObra(){return _codigoObra;}
    const char* getDireccion(){return _direccion;}
    int getProvincia(){return _provincia;}



    //metodos
    void mostrar(){
      cout << "Codigo Obra: " << getCodigoObra() << endl;
      cout << "Direccion: " << getDireccion() << endl;
      cout << "Provincia: " << getProvincia() << endl;
    }


    void cargar(){
      cout << "CODIGO OBRA: ";cargarCadena(_codigoObra,4);
      cout << "DIRECCION: ";cargarCadena(_direccion,29);
      cout << "PROVINCIA: ";cin >> _provincia;
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
int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/**/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }

void GuardarArchivo(Punto1& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/**/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/**/  return false;}
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
      
   }
   fclose(p);
}

// bool ExisteDNI(int dni){
//    Punto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       
//    }
//    while(fread(&obj,sizeof(Punto1),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

void punto1(){
  Obra objO;//codigoObra,direccion,provincia, superficie, estadoEjecucion(3 - en ejecucion), activo
  ArchivoObras ARobjO("obras.dat");
  Punto1 objPTO1;
  ArchivoPunto1 ARobjPTO1;
  ARobjPTO1.BorrarArchivo();

  int tam = ARobjO.contarRegistros();

  for (int i = 0; i < tam; i++){
    objO = ARobjO.leerRegistro(i);
    
    if(objO.getActivo()){
      if(objO.getEstadoEjecucion()==3){
        objPTO1.setearTodo(objO.getCodigoObra(), objO.getDireccion(), objO.getProvincia());
        ARobjPTO1.GuardarArchivo(objPTO1);      
      }  
    }
  }

  ARobjPTO1.mostrarArchivo();
  
}

void punto2(){
  Proveedor objP;
  ArchivoProveedor ARobjP("proveedores.dat");

  int tam = ARobjP.contarRegistros();
  int vProvContadorProveedor[24] = {};
  
  for (int i = 0; i < tam; i++){
    objP = ARobjP.leerRegistro(i);
    if(objP.getActivo()){
      vProvContadorProveedor[objP.getProvincia()-1]++;//1 registro ya tengo un proveedor activo de esa provincia que me intersa SI guardar
    }
  }  

  int indexMinimo = 0;
  for (int i = 1; i < 24; i++){
    if(vProvContadorProveedor[i] > 0){
      if(vProvContadorProveedor[i] < vProvContadorProveedor[indexMinimo]){
        indexMinimo = i;
      }
    }
  }  

  int valorMinimo = vProvContadorProveedor[indexMinimo];
  cout << "valor minimo: " << valorMinimo << endl;

  for(int i = 0; i < 24; i++){
    if(vProvContadorProveedor[i] == valorMinimo)
      cout << "provincia: " << i+1 << endl;
  
  }  

  /*
  int menorCantProv = vecCantProvedoresPorProv[0];
  bool band = false;
    for (int i=1 ; i<24 ; i++ ){
        if(vecCantProvedoresPorProv[i] > 0 ){
            if( !band ){
                menorCantProv = vecCantProvedoresPorProv[i];
                band = true;
            }
            else{
                if(vecCantProvedoresPorProv[i] < menorCantProv){
                    menorCantProv = vecCantProvedoresPorProv[i];
                }
            }
        }
    }
  
  */

  


}  
  




int main(){

    //punto1();
    punto2();


    return 0;
}