#include<iostream>
#include<cstring>

using namespace std;

#include"parcial2.h"

class Punto1{

    private:
        char codigoCliente[5];
        char nombreCliente[30];
        float importeVenta;
    public:

    //setters y getters
    void setCodigoCliente(const char* cod){strcpy(codigoCliente, cod);}
    void setNombreCliente(const char* nom){strcpy(nombreCliente, nom);}
    void setImporteVenta(float imp){importeVenta=imp;}

    void setearTodo(const char* cod, const char* nom, float imp){
        setCodigoCliente(cod);
        setNombreCliente(nom);
        setImporteVenta(imp);
    }

    const char* getCodigoCliente(){return codigoCliente;}
    const char* getNombreCliente(){return nombreCliente;}
    float getImporteVenta(){return importeVenta;}
    //metodos
    void mostrar(){
        cout<<"Codigo de cliente: "<<codigoCliente<<endl;
        cout<<"Nombre de cliente: "<<nombreCliente<<endl;
        cout<<"Importe de venta: "<<importeVenta<<endl;
    }

    void cargar(){
        cout<<"Ingrese el Codigo de cliente: ";
        cargarCadena(codigoCliente, 4);
        cout<<"Ingrese el Nombre de cliente: ";
        cargarCadena(nombreCliente, 29);
        cout<<"Ingrese el Importe de venta: ";
        cin>>importeVenta;
    }

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

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"ab");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Punto1 objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Punto1), 1, p);
    }

    fclose(p);
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

// bool ExisteDNI(int dni){
//    Punto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       
//    }
//    while(fread(&obj,sizeof(Punto1),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }

};

bool Venta::operator<(float f){
    if (importe < f){
        return true;
    }
    return false;
}

void punto1(){
    Punto1 objP;
    ArchivoPunto1 ARobjP;
    ARobjP.BorrarArchivo();

    Cliente objC;
    ArchivoClientes ARobjC("clientes.dat");

    Venta objV;
    ArchivoVentas ARobjV("Ventas.dat");

    int tam1 = ARobjC.contarRegistros();
    int tam2 = ARobjV.contarRegistros();

    float AcumImporte=0;

    for(int i=0; i<tam1; i++){
        objC = ARobjC.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objV = ARobjV.leerRegistro(j);

            if((strcmp(objC.getCodigoCliente(),objV.getNumeroDeCliente())==0)&&(objV<15000)){ //de esto = (objV.getImporte()<15000) lo cambiare a esto objV<15000
                AcumImporte=objV.getImporte();
                break;
            }

        }
        if(AcumImporte!=0){
        objP.setearTodo(objC.getCodigoCliente(), objC.getNombre(), AcumImporte);
        ARobjP.GuardarArchivo(objP);
        }
        AcumImporte=0;
    }
//ARobjP.mostrarArchivo();
}

void punto2(){
    Punto1 objP;
    ArchivoPunto1 ARobjP;

    int tam = ARobjP.contarRegistros();

    Punto1 *VecP;
    VecP = new Punto1[tam];
    if(VecP==NULL){
        cout<<"No se pudo crear el vector";
        exit(1);
    }
    for(int i=0; i<tam; i++){
        VecP[i] = ARobjP.leerRegistro(i);
        //VecP[i].mostrar();
    }

    delete[] VecP;
}


int main(){

    punto2();

    return 0;
}