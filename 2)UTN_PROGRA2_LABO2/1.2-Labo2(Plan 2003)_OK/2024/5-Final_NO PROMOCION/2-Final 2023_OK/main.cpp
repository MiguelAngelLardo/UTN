#include <iostream>
#include <cstring>
using namespace std;

#include"Agente.h"
#include"AgenteArchivo.h"
#include"Multa.h"
#include"MultaArchivo.h"

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

class Examen{

    private:
      char _nombre[50];
      char _apellido[50];
      int _cantMultRealiz;  //cantida de Multas Realizadas
      float _bonifiAOtorgar; //bonificacion a Otorgar
    public:

    //setters y getters
    void setNombre(const char* nombre){strcpy(_nombre, nombre);}
    void setApellido(const char* apellido){strcpy(_apellido, apellido);}
    void setCantMultRealiz(int cantMultRealiz){_cantMultRealiz = cantMultRealiz;}
    void setBonifiAOtorgar(float bonifiAOtorgar){_bonifiAOtorgar = bonifiAOtorgar;}

    void setearTodo(const char* nombre, const char* apellido, int cantMultRealiz, float bonifiAOtorgar){
      setNombre(nombre);
      setApellido(apellido);
      setCantMultRealiz(cantMultRealiz);
      setBonifiAOtorgar(bonifiAOtorgar);
    }

    const char* getNombre(){return _nombre;}
    const char* getApellido(){return _apellido;}
    int getCantMultRealiz(){return _cantMultRealiz;}
    float getBonifiAOtorgar(){return _bonifiAOtorgar;}
    //metodos
    void mostrar(){
      cout<<"Nombre: "<<_nombre<<endl;
      cout<<"Apellido: "<<_apellido<<endl;
      cout<<"Cant. Mult. Realizadas: "<<_cantMultRealiz<<endl;
      cout<<"Bonificacion a Otorgar: "<<(int)_bonifiAOtorgar<<endl;
    }
    void mostrarLineal(){cout<<" "<<_nombre<<" "<<_apellido<<" "<<_cantMultRealiz<<" "<<(int)_bonifiAOtorgar<<endl;}
 
    void cargar(){
      cout<<"Cargar Nombre: "; cargarCadena(_nombre, 50);
      cout<<"Cargar Apellido: "; cargarCadena(_apellido, 50);
      cout<<"Cargar Cantidad de Multas Realizadas: "; cin>>_cantMultRealiz;
      cout<<"Cargar Bonificacion a Otorgar: "; cin>>_bonifiAOtorgar;
    }


    void punto1();
    void punto2();
    void punto2b();
    void punto3();

    //constructor
    Examen(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Examen(){}

};

class ArchivoExamen{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoExamen(const char* nombre="Examen.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Examen& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Examen),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Examen);
    }

Examen leerRegistro(int pos){
        Examen reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Examen& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Examen), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Examen), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Examen objE;
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
    fwrite(&objE, sizeof(Examen), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Examen objE;
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
    fwrite(&objE, sizeof(Examen), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Examen objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Examen), 1, p) == true){
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
//    Examen obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Examen),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

void Examen::punto1(){
  Examen objEx;
  ArchivoExamen ARobjEx;
  ARobjEx.BorrarArchivo();

  Agente objAg;
  AgenteArchivo ARobjAg("agentes.dat");

  Multa objMu;
  MultaArchivo ARobjMu("multas.dat");

  int tam1 = ARobjAg.getCantidadRegistros();
  int tam2 = ARobjMu.getCantidadRegistros();

  int cont=0;
  float boniSueldo=0; //bonificacionSueldo
  float boniMultas=0; //bonificacionMultas

  for(int i=0; i<tam1; i++){
    objAg = ARobjAg.leer(i);

    for(int j=0; j<tam2; j++){
      objMu = ARobjMu.leer(j);

      if((objAg.getIdAgente() == objMu.getIDAgente()) && (objMu.getFechaMulta().getAnio()==2023) ){
        cont++;
      }
    }
  
    if(cont>=11){
      boniSueldo=objAg.getSueldo()*2;
      boniMultas=objMu.getMonto()*1.5;
    }else if((cont>=6)&&(cont<=10)){
      boniSueldo=objAg.getSueldo()*1.2;
      boniMultas=objMu.getMonto()*1.4;
    }else if((cont<=5)&&(cont>=1)){
      boniSueldo=objAg.getSueldo()*1.1;
      boniMultas=objMu.getMonto()*1.05;
    }
  
  if(cont>0){
    float boniTotal = boniSueldo+boniMultas;
    objEx.setearTodo(objAg.getNombres().c_str(),objAg.getApellidos().c_str(),cont,boniTotal);
    ARobjEx.GuardarArchivo(objEx);
  }

  boniSueldo=0;
  boniMultas=0;
  }

  
  ARobjEx.mostrarArchivo();
}
// 
void CargarSoloVector(int vec[], int tam, int valor=0){
    for(int i=0; i<tam; i++){
        vec[i]=valor;
    }
}


void Examen::punto2(){ //Maxi

  Multa obj;
  MultaArchivo ARobj("multas.dat");
  int cant=ARobj.getCantidadRegistros();

  int max=0;
  for(int i=0; i<cant; i++){
    obj = ARobj.leer(i);

    if(obj.getIDLocalidad()>max){
      max = obj.getIDLocalidad();
    }
  }

  int *localidadPagada;
  localidadPagada = new int[max];
  if(localidadPagada==NULL){
    cout<<"No se pudo crear el arreglo";
    exit(1);
  }
  CargarSoloVector(localidadPagada, max);
  
  int *LocalidadNoPagada;
  LocalidadNoPagada = new int[max];
  if(LocalidadNoPagada==NULL){
    cout<<"No se pudo crear el matriz";
    exit(1);
  }
  CargarSoloVector(LocalidadNoPagada, max);

  for(int i=0; i<cant; i++){
    obj = ARobj.leer(i);

    if(obj.getPagada()){
      localidadPagada[obj.getIDLocalidad()-1]++;
    }else{
      LocalidadNoPagada[obj.getIDLocalidad()-1]++;
    }

  }

  for(int i=0; i<max; i++){
    if(localidadPagada[i]>LocalidadNoPagada[i]){
      cout<<"Localidad: "<<i+1<<" Paga: "<<localidadPagada[i]<<" No paga: "<<LocalidadNoPagada[i]<<endl;
    }
  }

  delete [] localidadPagada;
  delete [] LocalidadNoPagada;

}

class Punto3{

    private:
      int _anio;
      int _cantMultas; //cantidad de multas
      float _recauDeMult; //recaudacion de multas
      int _CantDeMultEliminadas; //cantidad de multas eliminadas
    public:
    //setters y getters
    void setAnio(int anio){_anio = anio;}
    void setCantMultas(int cantMultas){_cantMultas = cantMultas;}
    void setRecauDeMult(float recauDeMult){_recauDeMult = recauDeMult;}
    void setCantDeMultEliminadas(int cantDeMultEliminadas){_CantDeMultEliminadas = cantDeMultEliminadas;}

    void setearTodo(int anio, int cantMultas, float recauDeMult, int cantDeMultEliminadas){
        setAnio(anio);
        setCantMultas(cantMultas);
        setRecauDeMult(recauDeMult);
        setCantDeMultEliminadas(cantDeMultEliminadas);
    }

    int getAnio(){return _anio;}
    int getCantMultas(){return _cantMultas;}
    float getRecauDeMult(){return _recauDeMult;}
    int getCantDeMultEliminadas(){return _CantDeMultEliminadas;}

    //metodos
    void mostrar(){
        cout<<"Anio: "<<_anio<<endl;
        cout<<"Cant. Multas: "<<_cantMultas<<endl;
        cout<<"Recaudacion de Multas: "<<(int)_recauDeMult<<endl;
        cout<<"Cant. Multas Eliminadas: "<<_CantDeMultEliminadas<<endl;
    }

    void cargar(){
        cout<<"Cargar Anio: "; cin>>_anio;
        cout<<"Cargar Cantidad de Multas: "; cin>>_cantMultas;
        cout<<"Cargar Recaudacion de Multas: "; cin>>_recauDeMult;
        cout<<"Cargar Cantidad de Multas Eliminadas: "; cin>>_CantDeMultEliminadas;
    }

    //constructor
    Punto3(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Punto3(){}

};

class ArchivoPunto3{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPunto3(const char* nombre="Punto3.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Punto3& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto3),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto3);
    }

Punto3 leerRegistro(int pos){
        Punto3 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto3& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto3), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto3), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Punto3 objE;
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
    fwrite(&objE, sizeof(Punto3), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Punto3 objE;
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
    fwrite(&objE, sizeof(Punto3), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Punto3 objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Punto3), 1, p) == true){
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


};

void Examen::punto3(){

  Punto3 objP;
  ArchivoPunto3 ARobjP;
  ARobjP.BorrarArchivo();

  Multa objM;
  MultaArchivo ARobjM;

  int tam= ARobjM.getCantidadRegistros();

  int cantMultas=0; //cantidad de multas
  float recauDeMult=0; //recaudacion de multas
  int CantDeMultEliminadas=0; //cantidad de multas eliminadas



  for(int x=2000; x<=2024; x++){

      for(int i=0; i<tam; i++){
        objM = ARobjM.leer(i);

        if(objM.getFechaMulta().getAnio() == x){
          cantMultas++;
          recauDeMult+=objM.getMonto();

          if(objM.getEliminado()==true){
            CantDeMultEliminadas++;
          }
        }

      }
      objP.setearTodo(x,cantMultas,recauDeMult,CantDeMultEliminadas);
      ARobjP.GuardarArchivo(objP);
  
        cantMultas=0;
        recauDeMult=0;
        CantDeMultEliminadas=0;
  }


  ARobjP.mostrarArchivo();

}


int main(){

  Examen obj;

  obj.punto3();

  return 0;
}
