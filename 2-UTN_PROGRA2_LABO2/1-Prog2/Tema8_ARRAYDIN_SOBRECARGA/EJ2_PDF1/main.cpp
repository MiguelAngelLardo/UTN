#include<iostream>
#include<cstring>

using namespace std;

#include"funcionesGlobales.h"

class Fecha{

    private:
        int dia,mes,anio;
    public:
    //setters y getters
        void setDia(int dia){this->dia=dia;}
        void setMes(int mes){this->mes=mes;}
        void setAnio(int anio){this->anio=anio;}

        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;} 
    //metodos
    void mostrar(){cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}
    void cargar(){
        cout<<"Dia: ";cin>>dia;
        cout<<"Mes: ";cin>>mes;
        cout<<"Anio: ";cin>>anio;
    }

    //constructor
    Fecha(){
        dia=0;
        mes=0;
        anio=0;
    }

};

class Ventas{

    private:
        int _NumeroVenta;
        Fecha _fecha;
        int _CodigoDeProducto;
        float _Importe;
        int _CantidadVendida;
    public:

    //setters y getters
        void setNumeroVenta(int _NumeroVenta){this->_NumeroVenta=_NumeroVenta;}
        void setFecha(int _dia, int _mes, int _anio){_fecha.setDia(_dia);_fecha.setMes(_mes);_fecha.setAnio(_anio);}
        void setCodigoDeProducto(int _CodigoDeProducto){this->_CodigoDeProducto=_CodigoDeProducto;}
        void setImporte(float _Importe){this->_Importe=_Importe;}
        void setCantidadVendida(int _CantidadVendida){this->_CantidadVendida=_CantidadVendida;}

        int getNumeroVenta(){return _NumeroVenta;}
        Fecha& getFecha(){return _fecha;}
        int getCodigoDeProducto(){return _CodigoDeProducto;}
        float getImporte(){return _Importe;}
        int getCantidadVendida(){return _CantidadVendida;}
    //metodos
    void mostrar(){
        cout<<"Numero de Venta: "<<_NumeroVenta<<endl;
        cout<<"Fecha: ";  _fecha.mostrar();
        cout<<"Codigo de Producto: "<<_CodigoDeProducto<<endl;
        cout<<"Importe: "<<_Importe<<endl;
        cout<<"Cantidad Vendida: "<<_CantidadVendida<<endl;
    }

    void cargar(){
        cout<<"Numero de Venta: ";cin>>_NumeroVenta;
        cout<<"Fecha: ";  _fecha.cargar();
        cout<<"Codigo de Producto: ";cin>>_CodigoDeProducto;
        cout<<"Importe: ";cin>>_Importe;
        cout<<"Cantidad Vendida: ";cin>>_CantidadVendida;
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


};

void puntoa(){
    Ventas objV;
    ArchivoVentas ARobjV;

    int tam = ARobjV.contarRegistros();
    float mx[12][120]={};

    for(int i=0; i<tam; i++){
        objV = ARobjV.leerRegistro(i);
        if(objV.getFecha().getAnio()==2020){
            mx[objV.getFecha().getMes()-1][objV.getCodigoDeProducto()-1] += (objV.getImporte()*objV.getCantidadVendida());
        }
    }

    for(int i=0; i<12; i++){
                cout<<"Mes: "<<i+1<<endl;
        for(int j=0; j<120; j++){
            if(mx[i][j]>0){
                cout<<"Producto Nro: "<<j+1<<endl;
                cout<<"La rentabilidad fue de: "<<mx[i][j]<<endl<<endl;
            }
        }
    }

}

void puntob(){ //sin vector dinamico
    Ventas objV;
    ArchivoVentas ARobjV;
    int tam = ARobjV.contarRegistros();
    int vec[120]={};

    for(int i=0; i<tam; i++){
        objV = ARobjV.leerRegistro(i);
        if(objV.getFecha().getAnio()==2020){
            vec[objV.getCodigoDeProducto()-1]+= (objV.getImporte()*objV.getCantidadVendida());
        }
    }

    int posProducto=0;
    int maxCantidad=0;

    for(int i=0; i<120; i++){
        if(vec[i]>maxCantidad){
            maxCantidad=vec[i];
            posProducto=i+1;
        }
    }

    cout<<"El producto mayor es: "<<posProducto<<endl;
    cout<<"La Cantidad fue de: "<<maxCantidad<<endl;
}

void puntoB(){ //con vector dinamico
    Ventas objV;
    ArchivoVentas ARobjV;
    int tam = ARobjV.contarRegistros();
    
    int max=0;

    for(int i=0; i<tam; i++){
        objV = ARobjV.leerRegistro(i);

        if(objV.getCodigoDeProducto()>max){
            max=objV.getCodigoDeProducto();
        }
    }

    int *vec;
    vec = new int[max];
    if(vec==NULL){
        cout<<"No se pudo asignar memoria"<<endl;
        cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
    CargarVector(vec, max, 0);

    for(int i=0; i<tam; i++){
        objV = ARobjV.leerRegistro(i);
        if(objV.getFecha().getAnio()==2020){
            vec[objV.getCodigoDeProducto()-1]+= (objV.getImporte()*objV.getCantidadVendida());
        }
    }

    int posProducto=0;
    int maxCantidad=0;

    for(int i=0; i<max; i++){
        if(vec[i]>maxCantidad){
            maxCantidad=vec[i];
            posProducto=i+1;
        }
    }

    cout<<"El producto mayor es: "<<posProducto<<endl;
    cout<<"La Cantidad fue de: "<<maxCantidad<<endl;

}

int main(){

    puntob();
    cout<<"///////////////////////////////////////////////////"<<endl;
    puntoB();

return 0;
}