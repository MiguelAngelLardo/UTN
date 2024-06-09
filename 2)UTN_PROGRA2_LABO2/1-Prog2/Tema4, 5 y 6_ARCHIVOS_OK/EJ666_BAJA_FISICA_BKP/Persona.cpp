#include<iostream>
#include<cstring>

using namespace std;

#include"Persona.h"

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



void Persona::setEdad(int edad){this->edad = edad;}
int Persona::getEdad(){return edad;}

void Persona::setNombre(const char *n){strcpy(nombre, n);}
const char *Persona::getNombre(){return nombre;}

void Persona::cargar(){
    cout<<"Nombre: "; cargarCadena(nombre, 30);
    cout<<"Edad: "; cin>>edad;
}

void Persona::mostrar(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
}

void Persona::crearArchivo(int tam,const char* nombre){
    Persona objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Persona), 1, p);
    }

    fclose(p);
}

void Persona::cargarArchivo(int tam,const char* nombre){
    Persona objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Persona), 1, p);
    }

    fclose(p);
}

void Persona::mostrarArchivo(const char* nombre){
    Persona objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Persona), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void Persona::BorrarArchivo(const char* nombre){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

int Persona::contarRegistros(const char* nombre){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){cout<<"Error en Linea: "<<__LINE__<<endl;  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Persona);
    }

Persona Persona::leerRegistro(int pos,const char* nombre){
        Persona reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){cout<<"Error en Linea: "<<__LINE__<<endl;  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }











