# include "ArchivoPropietarios.h"
# include "Propietario.h"
# include<iostream>
# include<cstring>

using namespace std;

int ArchivoPropietario::buscarPropietario(const char* _dniPropietario){///
    Propietario obj;
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb");

    if(pPropietario==nullptr){  ///NULL
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, tamanioRegistro,1,pPropietario)==1){
       if(strcmp(obj.getDni(),_dniPropietario)==0){
            return pos;
       }
       pos++;
    }

    fclose(pPropietario);
    return -1;
}

int ArchivoPropietario::agregarRegistro(Propietario reg){

    FILE *pPropietario;
    pPropietario=fopen(nombre,"ab");
    if(pPropietario==nullptr){
        return -1;
    }

    int escribio=fwrite(&reg, tamanioRegistro,1,pPropietario);

    fclose(pPropietario);
    return escribio;
}

int ArchivoPropietario::agregarRegistro(char* _nuevoDni){
    Propietario obj;
//    bool pudoCargar=false;
    int escribio=false;

    FILE *pPropietario;
    pPropietario=fopen(nombre,"ab");
//    /// Que no se repita el legajo.
//    char* dni;
//    cout<<"INGRESAR LEGAJO ";
//    cin>>dni;
//    int encontro=buscarPropietario(dni);
//    if(encontro!=-1){
//        cout<<"YA EXISTE EL LEGAJO"<<endl;
//        return -2;
//    }
    if(obj.Cargar(_nuevoDni)){
//        pudoCargar=true;

        if(pPropietario==nullptr){
            return -1;
        }
        escribio=fwrite(&obj, tamanioRegistro,1,pPropietario);
    };
    fclose(pPropietario);
    return escribio;
}

bool ArchivoPropietario::listarRegistros(){
    Propietario obj;
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb");

    if(pPropietario==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pPropietario)==1){
        if(obj.getEstado()){
            obj.Mostrar();
        }
    }

    fclose(pPropietario);
    return true;
}


bool ArchivoPropietario::listarInactivos(){
    Propietario obj;
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb");

    if(pPropietario==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pPropietario)==1){
        if(!obj.getEstado()){
            obj.Mostrar();
        }
    }

    fclose(pPropietario);
    return true;
}

Propietario ArchivoPropietario::leerRegistro(int pos){
    Propietario obj;
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb");
    obj.setDni("-1");
    if(pPropietario==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pPropietario,pos*tamanioRegistro,0);
    fread(&obj, tamanioRegistro,1,pPropietario);
    //obj.Mostrar();

    fclose(pPropietario);
    return obj;

}

int ArchivoPropietario::modificarRegistro(Propietario reg, int pos){
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb+");/// con + se le agrega al modo lo que no puede hacer
    ///rb->leer; wb->empezar de  un archivo; ab->para agregar registro
    if(pPropietario==nullptr){
        return -1;
    }

    fseek(pPropietario, pos*tamanioRegistro,0);
    int escribio=fwrite(&reg, tamanioRegistro,1,pPropietario);

    fclose(pPropietario);
    return escribio;
}

int ArchivoPropietario::contarRegistros(){
    FILE *pPropietario;
    pPropietario=fopen(nombre,"rb");

    if(pPropietario==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pPropietario,0,2);
    int tam=ftell(pPropietario);

    fclose(pPropietario);
    int cantReg;
    cantReg=tam/tamanioRegistro;
    return cantReg;
}

bool ArchivoPropietario::bajaLogica(const char* dni){
    Propietario reg;
    ArchivoPropietario archi;
    int pos=archi.buscarPropietario(dni);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

bool ArchivoPropietario::altaLogica(const char* dni){
    Propietario reg;
    ArchivoPropietario archi;
    int pos=archi.buscarPropietario(dni);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarRegistro(reg, pos);
}
