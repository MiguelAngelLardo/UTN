#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

#include <cstring>
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





class Municipio{
    private:
        int numero; ///1 a135
        char nombre[30];
        int cantidadHabitantes;
        int seccion; /// 1 a 6
        bool estado;///true si el registro est� activo; false si est� borrado
    public:
        Municipio(){estado=false;}
        void setNumero(int n){numero = n;}
        void setSeccion(int c){seccion = c;}
        void setEstado(bool e){estado = e;}
        int getNumero(){return numero;}
        int getCantidadHabitantes(){return cantidadHabitantes;}
        int getSeccion(){return seccion;}
        const char *getNombre(){return nombre;}
        bool getEstado(){return estado;}
        void Cargar();
        void Mostrar();
};

void Municipio::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1){
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE HABITANTES: ";
    cin>>cantidadHabitantes;
    cout<<"SECCION: ";
    cin>>seccion;
    estado=true;
}

void Municipio::Mostrar(){
    if(estado==true){
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE HABITANTES: "<<cantidadHabitantes<<endl;
        cout<<"SECCION: "<<seccion<<endl;
    }
}

class ArchivoMunicipios{
    private:
        char nombre[30];
    public:
        ArchivoMunicipios(const char *n="Municipios.dat"){strcpy(nombre,n);}
        bool grabarRegistro(Municipio obj);
        Municipio leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Municipio obj, int pos);
        bool listarRegistros();
};


bool ArchivoMunicipios::grabarRegistro(Municipio obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoMunicipios::listarRegistros(){
    FILE *p;
    Municipio obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
            obj.Mostrar();
            cout<<endl << endl;
    }
    fclose(p);
    return true;
}

int ArchivoMunicipios::buscarRegistro(int num){
    FILE *p;
    Municipio obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getNumero()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Municipio ArchivoMunicipios::leerRegistro(int pos){
    FILE *p;
    Municipio obj;
    p=fopen(nombre, "rb");
    obj.setNumero(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///funci�n que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoMunicipios::modificarRegistro(Municipio obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///funci�n que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoMunicipios::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///funci�n que permite ubicarse dentro del archivo, en este caso lo ubiqu� al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posici�n actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Municipio);
}
///FIN DE CLASES DE MUNICIPIO

class Empresa{
    private:
        int numero;
        char nombre[30];
        int cantidadEmpleados;
        ///Fecha fechaCreacion;  ///usar un objeto de una clase (Fecha) como propiedad de otra clase (Empresa) ->COMPOSICION
        int categoria; /// 1 a 80
        int numeroMunicipio;  //1 a 135
        bool estado;///true si el registro est� activo; false si est� borrado
    public:
        Empresa(){estado=false;}
        void setNumero(int n){numero = n;}
        void setCategoria(int c){categoria = c;}
        void setEstado(bool e){estado = e;}
        void setCantidadEmpleados(int ce){cantidadEmpleados=ce;}
        int getNumero(){return numero;}
        const char *getNombre(){return nombre;}
        int getCantidadEmpleados(){return cantidadEmpleados;}
        int getNumeroMunicipio(){return numeroMunicipio;}
        int getCategoria(){return categoria;}
        bool getEstado(){return estado;}
        void Cargar();
        void Mostrar();
};

void Empresa::Cargar(){
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1){
        return;
    }
    cout<<"NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"CANTIDAD DE EMPLEADOS: ";
    cin>>cantidadEmpleados;
    cout<<"CATEGORIA: ";
    cin>>categoria;
    cout<<"NUMERO DE MUNICIPIO: ";
    cin>>numeroMunicipio;
    estado=true;
}

void Empresa::Mostrar(){
    if(estado==true){
        Municipio obj;
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE EMPLEADOS: "<<cantidadEmpleados<<endl;
        cout<<"CATEGORIA: "<<categoria<<endl;
        cout<<"NUMERO DE MUNICIPIO: "<<numeroMunicipio << endl;
        //obj=buscarMunicipio(numeroMunicipio);
        //cout<<"NOMBRE DEL MUNICIPIO: "<< nombre << endl;
    }
}

class ArchivoEmpresas{
    private:
        char nombre[30];
    public:
        ArchivoEmpresas(const char *n="empresas.dat"){strcpy(nombre,n);}
        bool grabarRegistro(Empresa obj);
        Empresa leerRegistro(int pos);
        int buscarRegistro(int num);
        int contarRegistros();
        bool modificarRegistro(Empresa obj, int pos);
        bool listarRegistros();
};


bool ArchivoEmpresas::grabarRegistro(Empresa obj){
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}


bool ArchivoEmpresas::listarRegistros(){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    if(p==NULL) return false;
    while(fread(&obj, sizeof obj, 1, p)==1){
        obj.Mostrar();
        cout<<endl << endl;
    }
    fclose(p);
    return true;
}

int ArchivoEmpresas::buscarRegistro(int num){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    int pos=0;
    if(p==NULL) return -1;
    while(fread(&obj, sizeof obj, 1, p)==1){
                if(obj.getNumero()==num){
                    fclose(p);
                    return pos;
                }
                pos++;
    }
    fclose(p);
    return -2;
}

Empresa ArchivoEmpresas::leerRegistro(int pos){
    FILE *p;
    Empresa obj;
    p=fopen(nombre, "rb");
    obj.setNumero(-5);
    if(p==NULL) return obj;
    fseek(p, pos*sizeof obj,0);///funci�n que permite ubicarse dentro del archivo
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

bool ArchivoEmpresas::modificarRegistro(Empresa obj, int pos){
    FILE *p;
    p=fopen(nombre, "rb+"); ///agrega al modo de apertura lo que le falta
    if(p==NULL) return false;
    fseek(p, pos*sizeof obj,0);///funci�n que permite ubicarse dentro del archivo
    bool escribio=fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return escribio;
}

int ArchivoEmpresas::contarRegistros(){
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);///funci�n que permite ubicarse dentro del archivo, en este caso lo ubiqu� al final EOF
    int tam=ftell(p);///me devuelve la cantidad de bytes que hay desde el principio del archivo a la posici�n actual del indicador de pFILE.
    fclose(p);
    return tam/sizeof(Empresa);
}



#endif // CLASES_H_INCLUDED
