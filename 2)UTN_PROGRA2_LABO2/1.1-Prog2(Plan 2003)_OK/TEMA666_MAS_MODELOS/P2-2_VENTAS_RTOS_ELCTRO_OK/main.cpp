#include<iostream>
#include<cstring>

using namespace std;

#include"funciones.h"
#include "clases.h"

class Pto1{

private:
    int _DNI;
    char _nomApe[50];
    float _acumImporteTotalNoAnoPasado;    

    public:
    void setearTodo(int DNI, const char* nomApe, float acumImporteTotalNoAnoPasado){
        _DNI=DNI;
        strcpy(_nomApe,nomApe);
        _acumImporteTotalNoAnoPasado=acumImporteTotalNoAnoPasado;
    }

    void mostrar(){
        cout<<"DNI: "<<_DNI<<endl;
        cout<<"NomApe: "<< _nomApe<<endl;
        cout<<"AcumImporteTotalNoAnoPasado: "<<_acumImporteTotalNoAnoPasado<<endl;
    }

    void cargar(){
        cout<<"DNI: "; cin>>_DNI;
        cout<<"NomApe: "; cargarCadena(_nomApe,50);
        cout<<"AcumImporteTotalNoAnoPasado: "; cin>>_acumImporteTotalNoAnoPasado;
    }

    Pto1(int dni = 0, const char *nomApe = "", float acumImporteTotalNoAnoPasado = 0.0){
        setearTodo(dni,nomApe,acumImporteTotalNoAnoPasado);
    }

};

class ArchivoPto1{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPto1(const char* nombre="Pto1.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Pto1& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Pto1),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pto1);
    }

Pto1 leerRegistro(int pos){
        Pto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Pto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Pto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Pto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Pto1 objE;
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
    fwrite(&objE, sizeof(Pto1), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Pto1 objE;
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
    fwrite(&objE, sizeof(Pto1), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Pto1 objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Pto1), 1, p) == true){
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
//    Pto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Pto1),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

// bool ExisteDNIchar(const char* dni){
//    Pto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Pto1),1,p)){
//       if(strcmp(obj.getDNI(),dni)==0){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

};

// void pto1(){
//     Clientes objC;//dni PK  y nombre
//     ArchivoClientes arObjC;

//     Ventas objV;//dni FK, año (no 2024),  importe
//     ArchivoVentas arObjV;

//     Pto1 objP1;
//     ArchivoPto1 arObjP1;
//     arObjP1.BorrarArchivo();

//     int tamCliente = arObjC.contarRegistros();
//     int tamVenta = arObjV.contarRegistros();

//     for (int i = 0; i < tamCliente; i++){
//         objC = arObjC.leerRegistro(i);

//         float acumImporteTotalNoAnoPasado = 0.0;
//         for (int j = 0; j < tamVenta; j++){
//             objV = arObjV.leerRegistro(j);

//             if((objC.getDNI() == objV.getDNICliente()) && ((objV.getFechaVenta().getAnio() == 2024))){
//                 acumImporteTotalNoAnoPasado += objV.getImporte();
//             }

    
//         } //for venta

//         // if(acumImporteTotalNoAnoPasado > 0.0){
//         //     objP1.setearTodo(objC.getDNI(), objC.getNombreApellido(), acumImporteTotalNoAnoPasado);
//         //     arObjP1.GuardarArchivo(objP1);
//         // }

//             objP1.setearTodo(objC.getDNI(), objC.getNombreApellido(), acumImporteTotalNoAnoPasado);
//             arObjP1.GuardarArchivo(objP1);
//     }//for cliente

//     arObjP1.mostrarArchivo();
// }

void pto1(){
    Clientes objC;//dni PK  y nombre
    ArchivoClientes arObjC;

    Ventas objV;//dni FK, año (no 2024),  importe
    ArchivoVentas arObjV;

    Pto1 objP1;
    ArchivoPto1 arObjP1;
    arObjP1.BorrarArchivo();

    int tamCliente = arObjC.contarRegistros();
    int tamVenta = arObjV.contarRegistros();



    for (int i = 0; i < tamCliente; i++){
        objC = arObjC.leerRegistro(i);

        float acumImporteTotalNoAnoPasado = 0.0;
        for (int j = 0; j < tamVenta; j++){
            objV = arObjV.leerRegistro(j);

            if((objC.getDNI() == objV.getDNICliente()) && ((objV.getFechaVenta().getAnio() != 2024))){
                acumImporteTotalNoAnoPasado += objV.getImporte();
            }

    
        } //for venta

        // if(acumImporteTotalNoAnoPasado > 0.0){
        //     objP1.setearTodo(objC.getDNI(), objC.getNombreApellido(), acumImporteTotalNoAnoPasado);
        //     arObjP1.GuardarArchivo(objP1);
        // }
        
            objP1.setearTodo(objC.getDNI(), objC.getNombreApellido(), acumImporteTotalNoAnoPasado);
            arObjP1.GuardarArchivo(objP1);
    }//for cliente

    arObjP1.mostrarArchivo();
}

void pto2(){
    Clientes objC;//dni PK  y nombre localidad 1 a 150
    ArchivoClientes arObjC;

    int vec[150]={0};

    int tamCliente = arObjC.contarRegistros();

    for (int i = 0; i < tamCliente; i++){
        objC = arObjC.leerRegistro(i);
        vec[objC.getLocalidad()-1]++;//localidad 1 a 150
    }

    for (int i = 0; i < 150; i++){
        if(vec[i] > 0){
            cout<<"Localidad: "<<i+1<<endl;
            cout<<"Cantidad de Clientes: "<<vec[i]<<endl;
        }
    }
    

}

void pto3(){
    Pto1 objP1;
    ArchivoPto1 arObjP1;
    
    int tamPto1 = arObjP1.contarRegistros();

    Pto1 *vecDinamPto1 = nullptr;
    vecDinamPto1 = new Pto1[tamPto1];

    for(int i=0; i<tamPto1; i++){
        vecDinamPto1[i] = arObjP1.leerRegistro(i);
    }

    for(int i=0; i<tamPto1; i++){
        vecDinamPto1[i].mostrar();
    }

    delete [] vecDinamPto1;
}

int main(){

    pto3();



    //cargarArchivos(19);
    //mostrarArchivos();

    
    

    return 0;
}