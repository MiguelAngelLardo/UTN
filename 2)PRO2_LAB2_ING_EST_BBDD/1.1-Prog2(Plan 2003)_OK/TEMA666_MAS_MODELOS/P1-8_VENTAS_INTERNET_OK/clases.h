#pragma once

#include<iostream>
#include<cstring>

using namespace std;


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

class Fecha{

    private:
        int dia,mes,anio;
    public:

    //setters y getters
    void setDia(const int dia){this->dia=dia;}
    void setMes(const int mes){this->mes=mes;}
    void setAnio(const int anio){this->anio=anio;}

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setearTodo(const int dia, const int mes, const int anio){
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }

    //metodos
    void mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    void cargar(){
        cout<<"Ingrese el dia: "; cin>>dia;
        cout<<"Ingrese el mes: "; cin>>mes;
        cout<<"Ingrese el anio: "; cin>>anio;
    }

    //constructor
    Fecha(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Fecha(){}
};

class Vendedores{

private:
    char _codigoVendedor[5];
    char _nombreVendedor[30];
    int _provincia;//1 a 24
    int _calificacion;//1 a 10

public:
    void setCodigoVendedor(const char* codigoVendedor){strcpy(_codigoVendedor, codigoVendedor);}
    void setNombreVendedor(const char* nombreVendedor){strcpy(_nombreVendedor, nombreVendedor);}
    void setProvincia(const int provincia){_provincia=provincia;}
    void setCalificacion(const int calificacion){_calificacion=calificacion;}

    const char *getCodigoVendedor(){return _codigoVendedor;}
    const char *getNombreVendedor(){return _nombreVendedor;}
    int getProvincia(){return _provincia;}
    int getCalificacion(){return _calificacion;}

    void cargar(){
        cout << "Ingrese el codigo del vendedor(5): "; cargarCadena(_codigoVendedor, 5);
        cout << "Ingrese el nombre del vendedor(30): "; cargarCadena(_nombreVendedor, 30);
        cout << "Ingrese la provincia(1 a 24): "; cin >> _provincia;
        cout << "Ingrese la calificacion(1 a 10): "; cin >> _calificacion;
    }
    

    void mostrar(){
        cout << "EL codigo del vendedor es: " << _codigoVendedor << endl;
        cout << "El nombre del vendedor es: " << _nombreVendedor << endl;
        cout << "La provincia es: " << _provincia << endl;
        cout << "La calificacion es: " << _calificacion << endl;
    }


    //constructor
    Vendedores(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Vendedores(){}

};

class ArchivoVendedores{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoVendedores(const char* nombre="Vendedores.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Vendedores& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Vendedores),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Vendedores);
    }

Vendedores leerRegistro(int pos){
        Vendedores reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Vendedores& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Vendedores), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Vendedores), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Vendedores objE;
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
    fwrite(&objE, sizeof(Vendedores), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Vendedores objE;
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
    fwrite(&objE, sizeof(Vendedores), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Vendedores objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Vendedores), 1, p) == true){
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
//    Vendedores obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Vendedores),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

// bool ExisteDNIchar(const char* dni){
//    Vendedores obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Vendedores),1,p)){
//       if(strcmp(obj.getDNI(),dni)==0){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }






};

class Usuarios{

private:
    char _codigoUsuario[5];
    char _nombreUsuario[30];
    int _dni;
    Fecha _fechaRegistracion;

public:

    void codigoUsuario(const char* codigoUsuario){strcpy(_codigoUsuario, codigoUsuario);}
    void nombreUsuario(const char* nombreUsuario){strcpy(_nombreUsuario, nombreUsuario);}
    void dni(const int dni){_dni=dni;}
    void fechaRegistracion(const Fecha fechaRegistracion){_fechaRegistracion=fechaRegistracion;}

    const char *codigoUsuario(){return _codigoUsuario;}
    const char *nombreUsuario(){return _nombreUsuario;}
    int dni(){return _dni;}
    Fecha getFechaRegistracion(){return _fechaRegistracion;}

    //metodos
    void cargar(){
        cout << "Ingrese el codigo del usuario(5): "; cargarCadena(_codigoUsuario, 5);
        cout << "Ingrese el nombre del usuario(30): "; cargarCadena(_nombreUsuario, 30);
        cout << "Ingrese el DNI: "; cin >> _dni;
        _fechaRegistracion.cargar();
    }
    void mostrar(){
        cout << "El codigo del usuario es: " << _codigoUsuario << endl;
        cout << "El nombre del usuario es: " << _nombreUsuario << endl;
        cout << "El DNI es: " << _dni << endl;
        cout << "La fecha de registracion es: "; _fechaRegistracion.mostrar();
    }


    //constructor
    Usuarios(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Usuarios(){}

};
/*
Código de usuario (char[5]) 
Nombre 
DNI 
Fecha de registración */
class ArchivoUsuarios{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoUsuarios(const char* nombre="Usuarios.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Usuarios& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Usuarios),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Usuarios);
    }

Usuarios leerRegistro(int pos){
        Usuarios reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Usuarios& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Usuarios), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Usuarios), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Usuarios objE;
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
    fwrite(&objE, sizeof(Usuarios), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Usuarios objE;
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
    fwrite(&objE, sizeof(Usuarios), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Usuarios objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Usuarios), 1, p) == true){
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
//    Usuarios obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Usuarios),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

// bool ExisteDNIchar(const char* dni){
//    Usuarios obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Usuarios),1,p)){
//       if(strcmp(obj.getDNI(),dni)==0){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }






};

class Ventas{
private:
    int _NumdeCompra;
    char _codigoVendedor[5];
    char _codigoUsuario[5];
    float _importe;
    Fecha _fechaVenta;
    int _tipoPago;//1-credito, 2-mercado pago, 3-pago facil
public:
    void setNumdeCompra(const int NumdeCompra){_NumdeCompra=NumdeCompra;}
    void setCodigoVendedor(const char* codigoVendedor){strcpy(_codigoVendedor, codigoVendedor);}
    void setCodigoUsuario(const char* codigoUsuario){strcpy(_codigoUsuario, codigoUsuario);}
    void setImporte(const float importe){_importe=importe;}
    void setFechaVenta(const Fecha fechaVenta){_fechaVenta=fechaVenta;}
    void setTipoPago(const int tipoPago){_tipoPago=tipoPago;}

    int getNumdeCompra(){return _NumdeCompra;}
    const char *getCodigoVendedor(){return _codigoVendedor;}
    const char *getCodigoUsuario(){return _codigoUsuario;}
    float getImporte(){return _importe;}
    Fecha getFechaVenta(){return _fechaVenta;}
    int getTipoPago(){return _tipoPago;}

    //metodos
    void cargar(){
        cout << "Ingrese el numero de compra: "; cin >> _NumdeCompra;
        cout << "Ingrese el codigo del vendedor(5): "; cargarCadena(_codigoVendedor, 5);
        cout << "Ingrese el codigo del usuario(5): "; cargarCadena(_codigoUsuario, 5);
        cout << "Ingrese el importe: "; cin >> _importe;
        _fechaVenta.cargar();
        cout << "Ingrese el tipo de pago(1-credito, 2-mercado pago, 3-pago facil): "; cin >> _tipoPago;
    }
    void mostrar(){
        cout << "El numero de compra es: " << _NumdeCompra << endl;
        cout << "El codigo del vendedor es: " << _codigoVendedor << endl;
        cout << "El codigo del usuario es: " << _codigoUsuario << endl;
        cout << "El importe es: " << _importe << endl;
        cout << "La fecha de venta es: "; _fechaVenta.mostrar();
        cout << "El tipo de pago es: " << _tipoPago << endl;
    }


    //constructor
    Ventas(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Ventas(){}

};

class ArchivoVentas{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoVentas(const char* nombre="Ventas.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Ventas& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Ventas),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Ventas);
    }

Ventas leerRegistro(int pos){
        Ventas reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Ventas& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Ventas), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Ventas), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Ventas objE;
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
    fwrite(&objE, sizeof(Ventas), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Ventas objE;
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
    fwrite(&objE, sizeof(Ventas), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Ventas objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Ventas), 1, p) == true){
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
//    Ventas obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Ventas),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

// bool ExisteDNIchar(const char* dni){
//    Ventas obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Ventas),1,p)){
//       if(strcmp(obj.getDNI(),dni)==0){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }






};

void cargarDats(){
    ArchivoVendedores objV;
    ArchivoUsuarios objU;
    ArchivoVentas objVt;
    objV.crearArchivo(10);
    objU.crearArchivo(10);
    objVt.crearArchivo(10);
}









