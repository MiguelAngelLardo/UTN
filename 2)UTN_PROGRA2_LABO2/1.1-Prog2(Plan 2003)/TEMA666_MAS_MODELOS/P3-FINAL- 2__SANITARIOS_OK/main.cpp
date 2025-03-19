#include<iostream>
#include<cstring>//para strcpy


using namespace std;

#include"clases.h"
#include"funciones.h"


class Pto1{
private:
    int _DNI;
    char _nombreApellido[50];
    int _contTipo1;
    public:

    void cargarTodo(int dni, const char* nombreApellido, int contTipo1){
        _DNI = dni;
        strcpy(_nombreApellido,nombreApellido);
        _contTipo1 = contTipo1;
    }

    void mostrar(){
        cout<<"DNI: "<<_DNI<<endl;
        cout<<"Nombre y Apellido: "<<_nombreApellido<<endl;
        cout<<"Contador de Tipo 1: "<<_contTipo1<<endl;
    }

    void cargar(){
        cout<<"DNI: "; cin>>_DNI;
        cout<<"Nombre y Apellido: "; cargarCadena1(_nombreApellido,50);
        cout<<"Contador de Tipo 1: "; cin>>_contTipo1;
    }

    Pto1(){}

    Pto1(const char* cadena){
        cout << "la cadena ingresada es: " << cadena<<endl;
        strcpy(_nombreApellido,cadena);
        cout << "la cadena ingresada es: " << _nombreApellido<<endl;

    }
};

class ArchivoPto1{

public:
void GuardarArchivo(Pto1& obj,const char* nombre = "Pto1.dat"){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Pto1),1,p);
   fclose(p);
}

int contarRegistros(const char* nombre="Pto1.dat"){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Pto1);
    }

Pto1 leerRegistro(int pos,const char* nombre="Pto1.dat"){
        Pto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Pto1& reg, int posicionAReemplazar,const char* nombre="Pto1.dat"){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Pto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Pto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1,const char* nombre="Pto1.dat"){
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

void crearArchivo(int tam=1,const char* nombre="Pto1.dat"){
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

void mostrarArchivo(const char* nombre="Pto1.dat"){
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

void BorrarArchivo(const char* nombre="Pto1.dat"){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

// bool ExisteDNI(int dni,const char* nombre="Pto1.dat"){
//    Pto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Pto1),1,p)){
//       if((obj.getDNI()==dni)&&(obj.getEstado())){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

// bool ExisteCHAR(const char* dni,const char* nombre="Pto1.dat"){
//    Pto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Pto1),1,p)){
//       if((strcmp(obj.getCodigoJugador(),dni)==0)&&(obj.getEstado()){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

};

void pto1(){
    Tecnicos objT; //DNI (PK) Nombre Apellido
    ArchivoTecnicos arObjT;

    Tecnicos_Obras objTO;// Nro Obra PK, DNI FK, Tipo 1 a 5
    ArchivoTecnicos_Obras arObjTO;

    Pto1 objpto1; //DNI (PK) Nombre Apellido, Contador tipo 1
    ArchivoPto1 arObjPto1;

    arObjPto1.BorrarArchivo();
    
    int tamTecnico = arObjT.contarRegistros();
    int tamTecnicoObras = arObjTO.contarRegistros();
    int contador;

    for(int i=0; i<tamTecnico; i++){
        objT = arObjT.leerRegistro(i);

        contador = 0;
        for(int j=0; j<tamTecnicoObras; j++){
            objTO = arObjTO.leerRegistro(j);
            
            if((objT.getDni() == objTO.getDNITecnico()) && (objTO.getTipo() == 1)){
                contador++;
            }


        }//for Tecnicos Obras    

            objpto1.cargarTodo(objT.getDni(),objT.getNombreApellido(),contador);
            arObjPto1.GuardarArchivo(objpto1);

    
    }//forTecnicos    
    
    arObjPto1.mostrarArchivo();
}

//cantidad de tecnicos en cada puesto
void pto2a(){

    int vec[10]={};

    Tecnicos objT;
    //Tecnicos objT2;
    ArchivoTecnicos arObjT;

    int tamTecnico = arObjT.contarRegistros();

    for(int z=0; z<10; z++){

        for(int i=0; i<tamTecnico; i++){
            objT = arObjT.leerRegistro(i);

            if(objT.getPuesto() == (z+1)){
                vec[z]++;
            }   
        }
    }


    cout<<"lo que contiene el vector: "<<endl;

    for(int i=0; i<10; i++){
        cout<<vec[i]<<endl;
    }
}

void pto2b(){
    int vec [10] = {};
    Tecnicos objT;
    ArchivoTecnicos arObjT;

    int tam = arObjT.contarRegistros();

    for (int x = 0; x < tam; x++){
        objT = arObjT.leerRegistro(x);
        vec[objT.getPuesto()-1]++;
    }

    
    cout<<"lo que contiene el vector: "<<endl;

    for(int i=0; i<10; i++){
        cout<<vec[i]<<endl;
    }

}

int main(){
    
    Pto1 a("hola");
    
    return 0;
}