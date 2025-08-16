# include "ArchivoPropiedades.h"
# include "Inmueble.h"
# include<iostream>
# include<cstring>

using namespace std;

int ArchivoPropiedades::buscarInmueble(int codInmueble){///
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");

    if(pInmueble==nullptr){  ///NULL
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
       if(obj.getCodInmueble()==codInmueble){
            return pos;
       }
       pos++;
    }

    fclose(pInmueble);
    return -1;
}

int ArchivoPropiedades::buscarInmueble(const char* _calle, const char* _numero){///
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");

    if(pInmueble==nullptr){  ///NULL
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(strcmp(_numero,"0")==0){
            if(strcmp(obj.getCalle(),_calle)==0){
            return pos;
            }
       }
        else{
            if(strcmp(obj.getCalle(),_calle)==0){
                if(strcmp(obj.getNumero(),_numero)==0){
                    return -3;
                }
            }
        }
       pos++;
    }

    fclose(pInmueble);
    return -1;
}

int ArchivoPropiedades::agregarRegistro(Inmueble reg){

    FILE *pInmueble;
    pInmueble=fopen(nombre,"ab");
    if(pInmueble==nullptr){
        return -1;
    }

    int escribio=fwrite(&reg, tamanioRegistro,1,pInmueble);

    fclose(pInmueble);
    return escribio;
}

int ArchivoPropiedades::agregarRegistro(){
    Inmueble obj;
    int escribio;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"ab");
    if(pInmueble==nullptr){
        return -1;
    }

    if(obj.Cargar()){
        escribio=fwrite(&obj, tamanioRegistro,1,pInmueble);
   }
   else{
    escribio=0;
   }

    fclose(pInmueble);
    return escribio;
}

bool ArchivoPropiedades::listarInactivos(){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(!obj.getEstado()){
            obj.Mostrar();
        }
    }

    fclose(pInmueble);
    return true;
}

bool ArchivoPropiedades::listarRegistros(){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(obj.getEstado()){
            obj.Mostrar();
        }
    }

    fclose(pInmueble);
    return true;
}

int ArchivoPropiedades::listarPropiedadesPorCliente(const char* _dni){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    int contador=0;

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(obj.getEstado()){
            if(strcmp(obj.getDniPropietario(),_dni)==0){
                obj.Mostrar();
                contador++;
            }
        }
    }

    fclose(pInmueble);
    return contador;
}

bool ArchivoPropiedades::listarRegistrosPorDireccion(const char* _calle){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    int contador=0;

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(obj.getEstado()){
            if(strcmp(obj.getCalle(),_calle)==0){
                obj.Mostrar();
                contador++;
            }
        }
        cout<<endl;
    }

    fclose(pInmueble);
    if(contador==0){return false;}
    return true;
}

int ArchivoPropiedades::listarRegistrosPorRangoDePrecios(float precioMin, float precioMax, int _tipoOperacion){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    int contador=0;

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&obj, tamanioRegistro,1,pInmueble)==1){
        if(obj.getEstado()){
            if(_tipoOperacion==1){
                if(obj.getPrecioVenta()>=precioMin && obj.getPrecioVenta()<=precioMax){
                    obj.Mostrar();
                    contador++;
                }
            }
            if(_tipoOperacion==2){
                if(obj.getPrecioAlquier()>=precioMin && obj.getPrecioAlquier()<=precioMax){
                    obj.Mostrar();
                    contador++;
                }
            }
        }
        cout<<endl;
    }

    fclose(pInmueble);
    return contador;
}
Inmueble ArchivoPropiedades::leerRegistro(int pos){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    obj.setCodInmueble(-1);
    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pInmueble,pos*tamanioRegistro,0);
    fread(&obj, tamanioRegistro,1,pInmueble);

    fclose(pInmueble);
    return obj;

}

int ArchivoPropiedades::modificarRegistro(Inmueble reg, int pos){
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb+");/// con + se le agrega al modo lo que no puede hacer
    ///rb->leer; wb->empezar de  un archivo; ab->para agregar registro
    if(pInmueble==nullptr){
        return -1;
    }
    fseek(pInmueble, pos*tamanioRegistro,0);
    int escribio=fwrite(&reg, tamanioRegistro,1,pInmueble);

    fclose(pInmueble);
    return escribio;
}

int ArchivoPropiedades::contarRegistros(){
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pInmueble,0,2);
    int tam=ftell(pInmueble);

    fclose(pInmueble);
    int cantReg;
    cantReg=tam/tamanioRegistro;
    return cantReg;
}

bool ArchivoPropiedades::bajaLogica(int _codigo){
    Inmueble reg;
    ArchivoPropiedades archi;
    int pos=archi.buscarInmueble(_codigo);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

bool ArchivoPropiedades::altaLogica(int _codigo){
    Inmueble reg;
    ArchivoPropiedades archi;
    int pos=archi.buscarInmueble(_codigo);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(true);
    return archi.modificarRegistro(reg, pos);
}

int ArchivoPropiedades::proximoId(){
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    int cantReg=0;

    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return cantReg;
    }
    fseek(pInmueble,0,2);
    int tam=ftell(pInmueble);

    fclose(pInmueble);
    cantReg=tam/tamanioRegistro;
    cantReg++;

    return cantReg;
}

int ArchivoPropiedades::obtenerTipoDePropiedad(int pos){
    Inmueble obj;
    FILE *pInmueble;
    pInmueble=fopen(nombre,"rb");
    obj.setTipoPropiedad(-1);
    if(pInmueble==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj.getTipoPropiedad();
    }

    fseek(pInmueble,pos*tamanioRegistro,0);
    fread(&obj, tamanioRegistro,1,pInmueble);

    fclose(pInmueble);
    return obj.getTipoPropiedad();

}
