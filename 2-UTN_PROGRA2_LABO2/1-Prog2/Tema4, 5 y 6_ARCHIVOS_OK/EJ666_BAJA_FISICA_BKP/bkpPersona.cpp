#include<iostream>
#include<cstring>

using namespace std;

#include"bkpPersona.h"

void bkpPersona::MostrarBackup(const char* nombre) {
    int tam = objPersona.contarRegistros(nombre);
    for (int i = 0; i < tam; i++) {
        objPersona = objPersona.leerRegistro(i, nombre);
        objPersona.mostrar();
    }
}

void bkpPersona::SetAbrirArchivoConRB(const char* nombre,FILE** p){
    *p=fopen(nombre, "rb");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConRB()" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

void bkpPersona::SetAbrirArchivoConRBMAS(const char* nombre,FILE** p){
    *p=fopen(nombre, "rb+");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConRB()" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

void bkpPersona::SetAbrirArchivoConWB(const char* nombre,FILE **p){
    *p=fopen(nombre, "wb");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConWB()" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

void bkpPersona::SetAbrirArchivoConAB(const char* nombre,FILE** p){
    *p=fopen(nombre, "ab");
    if(*p==NULL){
        cout << "ERROR : AbrirArchivoConWB()" << endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        system("pause");
    }
}

bool bkpPersona::CrearBackup(const char* nombre1,const char* nombre2){
    FILE *original, *backup;
    Persona objpez;

    SetAbrirArchivoConRB(nombre1, &original);
    SetAbrirArchivoConWB(nombre2, &backup);

    while (fread(&objpez, sizeof(Persona), 1, original) == 1) {
        fwrite(&objpez, sizeof(Persona), 1, backup);
    }

    fclose(original);
    fclose(backup);

    return true;
}

bool bkpPersona::RestaurarBackup(const char* nombre1,const char* nombre2){
    FILE *original, *backup;
    Persona obj;
    SetAbrirArchivoConWB(nombre1, &original);
    SetAbrirArchivoConRB(nombre2, &backup);
    while (fread(&obj, sizeof(Persona), 1, backup) == 1) {
        fwrite(&obj, sizeof(Persona), 1, original);
    }

    fclose(original);
    fclose(backup);
    return true;
}

bool bkpPersona::bajaFisica(int edad,const char* nombre1,const char* nombre2){

    FILE *original, *backup;
    Persona obj;
    SetAbrirArchivoConWB(nombre1, &original);
    SetAbrirArchivoConRB(nombre2, &backup);
    while (fread(&obj, sizeof(Persona), 1, backup) == 1) {
        if((obj.getEdad()==edad)|(obj.getEdad()==6666)){
            fwrite(&obj, sizeof(Persona), 1, original);
        }
    }

    fclose(original);
    fclose(backup);
    return true;

}