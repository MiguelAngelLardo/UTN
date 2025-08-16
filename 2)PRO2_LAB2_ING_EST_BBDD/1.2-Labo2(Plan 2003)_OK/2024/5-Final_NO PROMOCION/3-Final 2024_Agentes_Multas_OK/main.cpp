#include<iostream>
#include<cstring>

using namespace std;

#include"Multa.h"
#include"MultaArchivo.h"
#include"MultaManager.h"

#include"Agente.h"
#include"AgenteArchivo.h"


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

void mostrartodoelArchivo(){
    Multa objM;
    MultaArchivo ARobjM("multas.dat");
    MultaManager objMM;

    Agente objA;
    AgenteArchivo ARobjA("agentes.dat");

    int tam1 = ARobjA.getCantidadRegistros();
    int tam2 = ARobjM.getCantidadRegistros();

        
    for(int i=0; i<tam1; i++){
        objA = ARobjA.leer(i);
    }
    cout<<"////////////////////////"<<endl;

}

void punto1(){
/*
Listar la cantidad de agentes distintos que hayan realizado
al menos una multa con un monto individual de más de 
$25000 y que se encuentre pagada.
*/

Agente objA;
AgenteArchivo ARobjA("agentes.dat");

Multa objM;
MultaArchivo ARobjM("multas.dat");

int tam1 = ARobjA.getCantidadRegistros();
int tam2 = ARobjM.getCantidadRegistros();

int cont=0;

for(int i=0; i<tam1; i++){
    objA = ARobjA.leer(i);

    for(int j=0; j<tam2; j++){
        objM = ARobjM.leer(j);

        if((objA.getIdAgente()==objM.getIDAgente()) && (objM.getMonto()>25000) && (objM.getPagada()==true)){
            //cout<<objA.getIdAgente()<<endl;
            cont++;
            break;
        }
    }
}

cout<<"La cantidad de agentes distintos que hayan realizado al menos una multa con un monto individual de mas de $25000 y que se encuentre pagada es: "<<cont<<endl;
}

void punto2(int anio){

    Multa objM;
    MultaArchivo ARobjM("multas.dat");
    int vec[40]={0};
    int tam=ARobjM.getCantidadRegistros();

    for(int i=0; i<tam; i++){
        objM = ARobjM.leer(i);
        if(anio==objM.getFechaMulta().getAnio()){
           vec[objM.getTipoInfraccion()-1]++; 
        }
    }

    int max;
    int pos;

    for(int i=0; i<40; i++){
        if(i==0){
            max=vec[i];
            pos=i+1;
        }else if(vec[i]>max){
            max=vec[i];
            pos=i+1;
        }
    }

    if(max==0){
        cout<<"No hay multas en el anio ingresado por parametro"<<endl;
    }else{
        cout<<"El tipo de infraccion con mas multas en el anio ingresado por parametro es: "<<pos<<" con "<<max<<" multas"<<endl;
    }

}

class AgentesSinMultas{

    private:
    int _idAgente;
    char _apellidos[50];
    char _nombres[50];
    int _anioIngreso;
    int _categoria;
    float _sueldo;
    public:
    //setters y getters

    void setearTodo(int idAgente,const char* apellidos,const char* nombres,int anioIngreso,int categoria,float sueldo){
        _idAgente=idAgente;
        strcpy(_apellidos,apellidos);
        strcpy(_nombres,nombres);
        _anioIngreso=anioIngreso;
        _categoria=categoria;
        _sueldo=sueldo;
    }



    //metodos
    void mostrar(){
        cout<<"Id Agente: "<<_idAgente<<endl;
        cout<<"Apellidos: "<<_apellidos<<endl;
        cout<<"Nombres: "<<_nombres<<endl;
        cout<<"Anio Ingreso: "<<_anioIngreso<<endl;
        cout<<"Categoria: "<<_categoria<<endl;
        cout<<"Sueldo: "<<_sueldo<<endl;
    }

    void cargar(){

    }

    //constructor
    AgentesSinMultas(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~AgentesSinMultas(){}

};

class ArchivoAgentesSinMultas{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoAgentesSinMultas(const char* nombre="AgentesSinMultas.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(AgentesSinMultas& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(AgentesSinMultas),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(AgentesSinMultas);
    }

AgentesSinMultas leerRegistro(int pos){
        AgentesSinMultas reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(AgentesSinMultas& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(AgentesSinMultas), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(AgentesSinMultas), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    AgentesSinMultas objE;
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
    fwrite(&objE, sizeof(AgentesSinMultas), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    AgentesSinMultas objE;
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
    fwrite(&objE, sizeof(AgentesSinMultas), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    AgentesSinMultas objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(AgentesSinMultas), 1, p) == true){
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
//    AgentesSinMultas obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(AgentesSinMultas),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

void punto3(){

    Agente objA;
    AgenteArchivo ARobjA("agentes.dat");

    Multa objM;
    MultaArchivo ARobjM("multas.dat");

    AgentesSinMultas objAg;
    ArchivoAgentesSinMultas ARobjAg;
    ARobjAg.BorrarArchivo();
    
    int tam1 = ARobjA.getCantidadRegistros();
    int tam2 = ARobjM.getCantidadRegistros();

    int cont=0;

    for(int i=0; i<tam1; i++){
        objA = ARobjA.leer(i);

        for(int j=0; j<tam2; j++){
            objM = ARobjM.leer(j);

            if((objA.getIdAgente()==objM.getIDAgente()) && (objM.getIDLocalidad()==5)){
                cont++;
            }
        }

        if(cont==0){
            objAg.setearTodo(objA.getIdAgente(),objA.getApellidos().c_str(),objA.getNombres().c_str(),objA.getAnioIngreso(),objA.getCategoria(),objA.getSueldo());
            ARobjAg.GuardarArchivo(objAg);
        }

        cont=0;
    }
//ARobjAg.mostrarArchivo();
}

int main(){

    punto3();

    return 0;
}