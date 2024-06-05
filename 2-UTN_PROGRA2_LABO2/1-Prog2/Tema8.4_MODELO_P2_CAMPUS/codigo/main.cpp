#include<iostream>
#include<cstring>

using namespace std;

#include"parcial2.h"


/*
Generar un archivo con los proveedores a los que no se les haya hecho compras el año actual. Por cada proveedor al que no se le hayan hecho compras este año se debe registrar el número de proveedor, el nombre del proveedor y la provincia del proveedor.
*/
class Punto1{

    private:
    int numProv;
    char nombreProv[30];
    int provincia;
    int anio;
    public:

    //setters y getters
    void setNumProv(int numProv){this->numProv = numProv;}
    void setNombreProv(const char* nombreProv){strcpy(this->nombreProv, nombreProv);}
    void setProvincia(int provincia){this->provincia = provincia;}
    void setAnio(int anio){this->anio = anio;}

    void setearTodo(int numProv, const char* nombreProv, int provincia, int anio){
        setNumProv(numProv);
        setNombreProv(nombreProv);
        setProvincia(provincia);
        setAnio(anio);
    }

    int getNumProv(){return numProv;}
    const char* getNombreProv(){return nombreProv;}
    int getProvincia(){return provincia;}
    int getAnio(){return anio;}
    //metodos
    void mostrar(){
        cout<<"NumProv: "<<getNumProv()<<endl;
        cout<<"NombreProv: "<<getNombreProv()<<endl;
        cout<<"Provincia: "<<getProvincia()<<endl;
        cout<<"Anio: "<<getAnio()<<endl;
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
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }

Punto1 leerRegistro(int pos){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
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
        //cout<<"En la Linea: "<<__LINE__<<endl;
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
        //cout<<"En la Linea: "<<__LINE__<<endl;
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
        //cout<<"En la Linea: "<<__LINE__<<endl;
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
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

// bool ExisteDNI(int dni){
//    Punto1 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
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

void punto1(){//probar con excel 
    Punto1 objP;
    ArchivoPunto1 ARobjP;
    ARobjP.BorrarArchivo();

    Proveedor objPro;
    ArchivoProveedores ARobjPro("proveedores.dat");

    Compra objCom;
    ArchivoCompras ARobjCom("compras.dat");

    int tam1 = ARobjPro.contarRegistros();
    int tam2 = ARobjCom.contarRegistros();
    int contAnioActual=0;

    bool bandera;
    for(int i=0; i<tam1; i++){
        objPro = ARobjPro.leerRegistro(i);
        
        bandera = false;
        for(int j=0; j<tam2; j++){
            objCom = ARobjCom.leerRegistro(j);
        
            if((objPro.getNumeroProveedor()==objCom.getNumeroproveedor()) && (objCom.getFechaCompra().getAnio()==2024)){
                bandera = true;
                break;
            }
        }

        if(!bandera){
            objP.setearTodo(objPro.getNumeroProveedor(),objPro.getNombre(),objPro.getProvincia(),objCom.getFechaCompra().getAnio());
            ARobjP.GuardarArchivo(objP);
        }
    }
    ARobjP.mostrarArchivo();
}

//proveedor id 1 PK
//compra FK id1 2021 vuelta 1 => FALSO
//compra FK id1 2022 vuelta 3=> TRUE 

//El tipo de material con menos cantidad de materiales (ignorando los tipos sin materiales).
void punto2(){

    Material objMat;
    ArchivoMateriales ARobjMat("materiales.dat");

    Compra objCom;
    ArchivoCompras ARobjCom("compras.dat");

    int vecTipo[6]={0}; //vamos a acumular la cantidad en cada uno de tus tipo

    int tam1 = ARobjMat.contarRegistros();
    int tam2 = ARobjCom.contarRegistros();

    for(int i=0; i<tam1; i++){
        objMat = ARobjMat.leerRegistro(i);
        for(int j=0; j<tam2; j++){
            objCom = ARobjCom.leerRegistro(j);
            if(objCom.getCodigoMaterial()==objMat.getCodigoMaterial()){
                vecTipo[objMat.getTipo()-1]+=objCom.getCantidad();
            }
        }
    }

    int min=0;
    int band=true;
    int indice=0;
    for(int i=0; i<6; i++){
        if((band==true)&&(vecTipo[i]>0)){
            min=vecTipo[i];
            indice=i;
            band=false;
        }else{
            if((vecTipo[i]<min)&&(vecTipo[i]>0)){
                min=vecTipo[i];
                indice=i;
            }
        }
    }
    cout<<"El tipo con menos materiales es: "<<indice+1<<endl;
    cout<<"La cantidad de materiales es: "<<min<<endl;

}

//Generar un vector dinámico con todos los materiales y listar luego los materiales del vector que pertenezcan a un tipo que se ingresa por teclado.

void punto3(){
    Material objMat;
    ArchivoMateriales ARobjMat("materiales.dat");
    int tam=ARobjMat.contarRegistros();

    Material *vec;
    vec = new Material[tam];
    if(vec==NULL){
        cout<<"No se pudo crear el vector dinamico"<<endl;
    }

    for(int i=0; i<tam; i++){
        vec[i] = ARobjMat.leerRegistro(i);
    }

    int tipo;
    cout<<"Ingrese el tipo: ";
    cin>>tipo;

    for(int i=0; i<tam; i++){
        if(vec[i].getTipo()==tipo){
            objMat=vec[i];
            objMat.Mostrar();
        }
    }

    
}
//Sobrecargar el operador == para la clase Obra de manera tal que sea verdadero cuando el objeto que llama al método tenga un valor de superficie igual a un valor de tipo
//float que se recibe como parámetro

bool Obra::operator==(float s){
    if(superficie == s){
        return true;
    }
    return false;
}


void punto4(){
    float superficie;
    Obra objOb;
    ArchivoObras ARobjOb("obras.dat");
    cout<<"ingrese la superficie: ";
    cin>>superficie;

    int tam=ARobjOb.contarRegistros();
    for(int i=0; i<tam; i++){
        objOb = ARobjOb.leerRegistro(i);
        if(objOb.getSuperficie()==superficie){
            objOb.Mostrar();
        }
    }
}

int main(){
   punto4();


    // Proveedor objPro;
    // ArchivoProveedores ARobjPro("proveedores.dat");

    // int tam=ARobjPro.contarRegistros();
    // for(int i=0; i<tam; i++){
    //     objPro = ARobjPro.leerRegistro(i);
    //     objPro.Mostrar();
    // }

    // cout<<"////////////////////"<<endl;

    // Compra objCom;
    // ArchivoCompras ARobjCom("compras.dat");

    // tam=ARobjCom.contarRegistros();
    // for(int i=0; i<tam; i++){
    //     objCom = ARobjCom.leerRegistro(i);
    //     objCom.Mostrar();
    // }

    // cout<<"////////////////////"<<endl;
    // cout<<"////////////////////"<<endl;

    //objCom.Cargar();
    //ARobjCom.grabarRegistro(objCom);

    // Material objMat;
    // ArchivoMateriales ARobjMat("materiales.dat");

    // tam=ARobjMat.contarRegistros();
    // for(int i=0; i<tam; i++){
    //     objMat = ARobjMat.leerRegistro(i);
    //     objMat.Mostrar();
    // }

    // Obra objObra;
    // ArchivoObras ARobjObra("obras.dat");

    // int tam=ARobjObra.contarRegistros();
    // for(int i=0; i<tam; i++){
    //     objObra = ARobjObra.leerRegistro(i);
    //     objObra.Mostrar();
    // }

    return 0;
}