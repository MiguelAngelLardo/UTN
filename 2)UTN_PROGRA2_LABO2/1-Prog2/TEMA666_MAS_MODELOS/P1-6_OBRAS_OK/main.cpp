#include<iostream>
#include<cstring>
#include"iomanip"

using namespace std;

#include"parcialm1.h"

void mostrarArchivos(){
    Compra objC;
    ArchivoCompra objA("compras.dat");
    int tam1 = objA.contarRegistros();
    for(int i=0; i<tam1; i++){
        objC = objA.leerRegistro(i);
        objC.Mostrar();
    }
    cout<<"////////////////////////////////////////////"<<endl;
    Material objM;
    ArchivoMaterial objB("materiales.dat");
    int tam2 = objB.contarRegistros();
    for(int i=0; i<tam2; i++){
        objM = objB.leerRegistro(i);
        objM.Mostrar();
    }
    cout<<"////////////////////////////////////////////"<<endl;
    Proveedor objP;
    ArchivoProveedor objD("proveedores.dat");
    int tam3 = objD.contarRegistros();
    for(int i=0; i<tam3; i++){
        objP = objD.leerRegistro(i);
        objP.Mostrar();
    }
    cout<<"////////////////////////////////////////////"<<endl;
    Obra objO;
    ArchivoObras objE("obras.dat");
    int tam4 = objE.contarRegistros();
    for(int i=0; i<tam4; i++){
        objO = objE.leerRegistro(i);
        objO.Mostrar();
    }
    cout<<"////////////////////////////////////////////"<<endl;
}

void mostrarArchivosLineal(){
    Compra objC;
    ArchivoCompra objA("compras.dat");
    int tam1 = objA.contarRegistros();
    for(int i=0; i<tam1; i++){
        objC = objA.leerRegistro(i);
        objC.MostrarLineal();
        cout<<endl;
    }
    cout<<endl;
    cout<<"////////////////////////////////////////////"<<endl;
    Material objM;
    ArchivoMaterial objB("materiales.dat");
    int tam2 = objB.contarRegistros();
    for(int i=0; i<tam2; i++){
        objM = objB.leerRegistro(i);
        objM.MostrarLineal();
        cout<<endl;
    }
    cout<<endl;
    cout<<"////////////////////////////////////////////"<<endl;
    Proveedor objP;
    ArchivoProveedor objD("proveedores.dat");
    int tam3 = objD.contarRegistros();
    for(int i=0; i<tam3; i++){
        objP = objD.leerRegistro(i);
        objP.MostrarLineal();
        cout<<endl;
    }
    cout<<endl;
    cout<<"////////////////////////////////////////////"<<endl;
    Obra objO;
    ArchivoObras objE("obras.dat");
    int tam4 = objE.contarRegistros();
    for(int i=0; i<tam4; i++){
        objO = objE.leerRegistro(i);
        objO.MostrarLineal();
        cout<<endl;
    }
    cout<<endl;
    cout<<"////////////////////////////////////////////"<<endl;
}

class Punto1{

    private:
    char codigoObra[5];
    char dirreccion[30];
    int provincia;
    public:
    //setters y getters
    void setCodigoObra(const char* co){strcpy(codigoObra, co);}
    void setDirreccion(const char* di){strcpy(dirreccion, di);}
    void setProvincia(int pr){provincia = pr;}
    const char* getCodigoObra(){return codigoObra;}
    const char* getDirreccion(){return dirreccion;}
    int getProvincia(){return provincia;}

    void setearTodo(const char* co, const char* di, int pr){
        setCodigoObra(co);
        setDirreccion(di);
        setProvincia(pr);
    }
    //metodos
    void mostrar(){
        cout<<"CODIGO OBRA: "<<codigoObra<<endl;
        cout<<"DIRECCION: "<<dirreccion<<endl;
        cout<<"PROVINCIA: "<<provincia<<endl;
    }

    void cargar(){
        cout<<"CODIGO OBRA: "; cargarCadena(codigoObra,4);
        cout<<"DIRECCION: "; cargarCadena(dirreccion,29);
        cout<<"PROVINCIA: "; cin>>provincia;
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
//       if((obj.getDNI()==dni)&&(obj.getEstado())){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }


};

void punto1(){
    Obra objO;
    ArchivoObras ARobjO("obras.dat");

    int tam = ARobjO.contarRegistros();

    Punto1 objP; 
    ArchivoPunto1 ARobjP;
    ARobjP.BorrarArchivo();

    for(int i=0; i<tam; i++){
        objO = ARobjO.leerRegistro(i);
        if(objO.getEstadoEjecucion() == 3){
            objP.setearTodo(objO.getCodigoObra(), objO.getDireccion(), objO.getProvincia());
            ARobjP.GuardarArchivo(objP);
        }
    
    }    
    
    //ARobjP.mostrarArchivo();
    
}

//La provincia con menos proveedores (ignorando las provincias sin proveedores).
void punto2(){
    Proveedor objP;
    ArchivoProveedor ARobjP("proveedores.dat");

    int vContadorProvinciasProvdeedor[24] = {};
    int min;
    bool band=true;

    int tam= ARobjP.contarRegistros();

    for(int i=0; i<tam; i++){
        objP = ARobjP.leerRegistro(i);
        vContadorProvinciasProvdeedor[objP.getProvincia()-1]++;
    }

    for(int i=0; i<24; i++){
        if((band==true) && (vContadorProvinciasProvdeedor[i] !=0 )){
            min = vContadorProvinciasProvdeedor[i];
            band=false;
        }else if((vContadorProvinciasProvdeedor[i]<min) && (vContadorProvinciasProvdeedor[i]!=0)){
            min = vContadorProvinciasProvdeedor[i];
        }
    }


    for(int i=0; i<24; i++){
        if((vContadorProvinciasProvdeedor[i] == min)){
            cout << "LA PROVINCIA CON MENOS PROVEEDORES ES: " << i+1 << endl;
            cout<<"CANTIDAD DE PROVEEDORES: "<< min << endl << endl;
        }

    }

}


//punto 1 para caa material la cantidad de compras
void puntoA1(){
    Material objM; // codigoMaterial (PK) int
    ArchivoMaterial ARobjM("materiales.dat");

    Compra objC; // nmeroCompra (PK) int - codigomaterla (fk)
    ArchivoCompra ARobjC("compras.dat");
    
    int tam1 = ARobjM.contarRegistros();
    int tam2 = ARobjC.contarRegistros();

    int contadorComprasPorMaterial;

    for(int i=0; i<tam1; i++){ //PK
        objM = ARobjM.leerRegistro(i);
        for(int j=0; j<tam2; j++){
            objC = ARobjC.leerRegistro(j);
            if(objM.getCodigoMaterial() == objC.getCodigoMaterial()){
                contadorComprasPorMaterial++;
            }
        }    

        cout << "EL MATERIAL ...\n";
        objM.Mostrar();
        cout << "TIENE " << contadorComprasPorMaterial << " COMPRAS\n\n";

        contadorComprasPorMaterial=0;
    }    
    
}


void puntoA2(){
//El nombre del proveedor que mayor importe haya obtenido entre todas las compras que se le realizaron.
    Proveedor objP;
    ArchivoProveedor ARobjP("proveedores.dat");

    Compra objC;
    ArchivoCompra ARobjC("compras.dat");

    int tam1 = ARobjP.contarRegistros();
    int tam2 = ARobjC.contarRegistros();

    int vPro[60]={};

    for(int i=0; i<tam1; i++){
        objP = ARobjP.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objC = ARobjC.leerRegistro(j);

             if(objP.getNumeroProveedor() == objC.getNumeroproveedor()){
                 vPro[objP.getNumeroProveedor()-1] += objC.getImporte() * objC.getCantidad();   
             }   
        }
    }

// for(int i=0; i<60; i++){
//     cout<<vPro[i]<<endl;
// }

    int max = vPro[0];
    int pos = 1;

     for(int i=1; i<60; i++){
      if(vPro[i] > max){
           max = vPro[i];
           pos = i+1;
      }
    }

    cout << "EL proveedor [60] con mayor importe obtenido " << pos << " -> El importe es: " << max << endl;
}


void puntoA3(){
    //Los número de los proveedores a los que no se les compró nada el año pasado.

    Proveedor objP;
    ArchivoProveedor ARobjP("proveedores.dat");

    Compra objC;
    ArchivoCompra ARobjC("compras.dat");

    int tam1 = ARobjP.contarRegistros();
    int tam2 = ARobjC.contarRegistros();

    int vPro[60]={};


    for(int i=0; i<tam1; i++){
        objP = ARobjP.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objC = ARobjC.leerRegistro(j);

             if((objP.getNumeroProveedor() == objC.getNumeroproveedor()) && (objC.getFechaCompra().getAnio()==2022)){
                 vPro[objP.getNumeroProveedor()-1] += objC.getImporte() * objC.getCantidad();   
             }    
        }
    }


     for(int i=0; i<60; i++){
      if(vPro[i]==0){
           cout << "EL proveedor [" << i+1 << "] no se le compro" << endl;
      }
    }

}

//El gasto en obra gruesa para cada uno de las obras. (analizar bien. Es el punto más complejo
//porque requiere del uso de 3 archivos)
void puntoA4(){
    Obra objO; //codigoObra Char (PK)
    ArchivoObras ARobjO("obras.dat");

    Compra objC; //codigo obra char (fk), codigo material (fk)
    ArchivoCompra ARobjC("compras.dat");

    Material objM; // codigo material int (PK), tipo 1 = obra gruesa
    ArchivoMaterial ARobjM("materiales.dat");

    int tam1 = ARobjO.contarRegistros();
    int tam2 = ARobjC.contarRegistros();
    int tam3 = ARobjM.contarRegistros();

    float gastoParaCadaObra;

    for (int i=0; i<tam1; i++){
        objO = ARobjO.leerRegistro(i);
        gastoParaCadaObra = 0.0;
        for(int j=0; j<tam2; j++){
            objC = ARobjC.leerRegistro(j);
            if(strcmp(objO.getCodigoObra(), objC.getCodigoObra())== 0){ 
                for (int k=0; k<tam3; k++){
                    objM = ARobjM.leerRegistro(k);
                    if(objC.getCodigoMaterial() == objM.getCodigoMaterial()){
                        if(objM.getTipo()==1){
                            gastoParaCadaObra += objC.getCantidad() * objM.getPU();
                        }    
                    }        
                }            
            }
        }
        cout << "La obra [" << objO.getCodigoObra() << "] tiene un gasto de: " << gastoParaCadaObra << endl;
    }
}

void puntoA5(){
    //A5)  La/s provincia/s con más de 22 proveedores
    
    Proveedor objP;
    ArchivoProveedor ARobjP("proveedores.dat");
    
    int tam=ARobjP.contarRegistros();
    int vProvinciaGuardaProveedor[24] = {0};


    for(int i=0; i<tam; i++){
        objP = ARobjP.leerRegistro(i);
        vProvinciaGuardaProveedor[objP.getProvincia()-1]++;
    }

    for(int i=0; i<24; i++){
        if(vProvinciaGuardaProveedor[i] > 22){
            cout << "LA PROVINCIA CON MAS DE 22 PROVEEDORES ES: " << i+1 << endl;
            cout<<"CANTIDAD DE PROVEEDORES: "<< vProvinciaGuardaProveedor[i] << endl << endl;
        }
    }
}  

      

int main(){
    
    
    puntoA5();

    return 0;
}