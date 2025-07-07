#include<iostream>
#include<cstring>

using namespace std;

#include"funciones.h"

class punto1A{

    private:
        char _CodigoDeVendedor[5];
        char _NombreVendedor[30];
    public:

    //setters y getters
    void setCodigoDeVendedor(const char* _CodigoDeVendedor){strcpy(this->_CodigoDeVendedor, _CodigoDeVendedor);}
    const char* getCodigoDeVendedor(){return _CodigoDeVendedor;}

    void setNombreVendedor(const char* _NombreVendedor){strcpy(this->_NombreVendedor, _NombreVendedor);}
    const char* getNombreVendedor(){return _NombreVendedor;}
    
    void setearTodo(const char* _CodigoDeVendedor, const char* _NombreVendedor){
        setCodigoDeVendedor(_CodigoDeVendedor);
        setNombreVendedor(_NombreVendedor);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo de vendedor: "<<_CodigoDeVendedor<<endl;
        cout<<"Nombre de vendedor: "<<_NombreVendedor<<endl;
    }

    void cargar(){
        cout<<"Codigo de vendedor: ";cin>>_CodigoDeVendedor;
        cout<<"Nombre de vendedor: ";cin>>_NombreVendedor;
    }

    //constructor
    punto1A(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~punto1A(){}

};

class Archivopunto1A{

    private:
        char nombre[30];
    public:
        //constructor
        Archivopunto1A(const char* nombre="punto1A.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(punto1A& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      
   }
   fwrite(&obj,sizeof(punto1A),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(punto1A);
    }

punto1A leerRegistro(int pos){
        punto1A reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(punto1A& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){  return false;}
    fseek(p, posicionAReemplazar * sizeof(punto1A), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(punto1A), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    punto1A objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(punto1A), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    punto1A objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(punto1A), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    punto1A objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        
        exit(1);
    }
while (fread(&objE, sizeof(punto1A), 1, p) == true){
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

void punto1a(){

    Vendedores objV;
    ArchivoVendedores ARobjV;

    Ventas objV2;
    ArchivoVentas ARobjV2;

    int tam1 = ARobjV.contarRegistros();
    int tam2 = ARobjV2.contarRegistros();

    punto1A objP1A;
    Archivopunto1A objArchivopunto1A;
    objArchivopunto1A.BorrarArchivo();

    bool ventas;

    for(int i=0; i<tam1; i++){
        ventas=true;
        objV = ARobjV.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objV2 = ARobjV2.leerRegistro(j);

            if((strcmp(objV.getCodigoDeVendedor(), objV2.getCodigoDeVendedor())==0)&&(objV2==2024)){ //(objV2.getFecha().getAnio()==2024)
                ventas=false;
                //break;  //esto si uno quiere lo pone por si quiere terminar antes
            }
        }

        if(ventas==true){
            objP1A.setearTodo(objV.getCodigoDeVendedor(), objV.getNombreVendedor());
            objArchivopunto1A.GuardarArchivo(objP1A);
        }
    }
    objArchivopunto1A.mostrarArchivo();
}

void punto2b(){

    Usuarios objU;
    ArchivoUsuarios ARobjU;

    int tam = ARobjU.contarRegistros();

    int vMeses[12]={0};

    for(int i=0; i<tam; i++){
        objU = ARobjU.leerRegistro(i);
        
        if(objU.getFecha().getAnio()==2023){
            vMeses[objU.getFecha().getMes()-1]++;
        }
    }

    for(int i=0; i<12; i++){
        cout<<"Mes: "<<i+1<<" Cantidad de usuarios: "<<vMeses[i]<<endl;
    }

}

void punto3c(){
    Vendedores objV;
    ArchivoVendedores ARobjV;

    Ventas objVent;
    ArchivoVentas ARobjVent;

    int tam1 = ARobjV.contarRegistros();
    int tam2 = ARobjVent.contarRegistros();

    int cont=0;

    for(int i=0; i<tam1; i++){
        objV = ARobjV.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objVent = ARobjVent.leerRegistro(j);

            if( (strcmp(objV.getCodigoDeVendedor(), objVent.getCodigoDeVendedor())==0) 
            && (objVent.getFecha().getAnio()==2024) 
            && ( (objVent.getFecha().getMes()>=1) && (objVent.getFecha().getMes()<=6) ) ){

                if((objVent.getProvincia()>=8) && (objVent.getProvincia()<=10)){
                    cont++;
                }
            }
        }
    }
    cout<<"La cantidad de vendedores que venden entre enero y junio es: "<<cont<<endl;
}


int main(){

    punto3c();

    // Vendedores objV;
    // ArchivoVendedores ARobjV;

    // ARobjV.crearArchivo(10);

    // Ventas objV2;
    // ArchivoVentas ARobjV2;

    // ARobjV2.crearArchivo(10);

    // Usuarios objU;
    // ArchivoUsuarios ARobjU;

    // ARobjU.crearArchivo(10);


    return 0;
}