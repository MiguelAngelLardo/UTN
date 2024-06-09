#include<iostream>
#include<cstring>

using namespace std;

#include"clasesp1m.h"

class Punto1{

    private:
    int CodigoMulta;
    char descripcion[40];
    int CantidadDeInfracciones;
    public:
    //setters y getters
    void setCodigoMulta(int CodigoMulta){this->CodigoMulta=CodigoMulta;}
    void setDescripcion(const char* descripcion){strcpy(this->descripcion,descripcion);}
    void setCantidadDeInfracciones(int CantidadDeInfracciones){this->CantidadDeInfracciones=CantidadDeInfracciones;}

    void setearTodo(int CodigoMulta,const char* descripcion,int CantidadDeInfracciones){
        setCodigoMulta(CodigoMulta);
        setDescripcion(descripcion);
        setCantidadDeInfracciones(CantidadDeInfracciones);
    }

    int getCodigoMulta(){return CodigoMulta;}
    const char* getDescripcion(){return descripcion;}
    int getCantidadDeInfracciones(){return CantidadDeInfracciones;}

    //metodos
    void mostrar(){
        cout<<"Codigo de multa: "<<getCodigoMulta()<<endl;
        cout<<"Descripcion: "<<getDescripcion()<<endl;
        cout<<"Cantidad de infracciones: "<<getCantidadDeInfracciones()<<endl;
    }

    void cargar(){}

    //constructor
    Punto1(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Punto1(){}

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

void GuardarArchivo(Punto1& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }

Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
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

};

void punto1(){
    Multa objM;
    ArchivoMultas ARobjM("Multas.dat");

    Infraccion objI;
    ArchivoInfracciones ARobjI("Infracciones.dat");

    int tam1= ARobjM.contarRegistros();
    int tam2= ARobjI.contarRegistros();

    Punto1 objP;
    ArchivoPunto1 ARobjP;
    ARobjP.BorrarArchivo();

    int cantDeInfra=0; //cantidad de infracciones

    for(int i=0; i<tam1; i++){
        objM=ARobjM.leerRegistro(i);

        if((objM.getEstado()==true)){


            for(int j=0; j<tam2; j++){
                objI=ARobjI.leerRegistro(j);

                //le pongo estado==true en la infraccion y se rompe, por eso no lo puse

                if((objI.getCodigoMulta()==objM.getCodigo())&& (objI.getLocalidad()==2)){
                    cantDeInfra++;
                }
            }

            objP.setearTodo(objM.getCodigo(),objM.getDescripcion(),cantDeInfra);
            ARobjP.GuardarArchivo(objP);
            cantDeInfra=0;

        }
    }
    ARobjP.mostrarArchivo();
}


int main(){

    punto1();

    return 0;
}