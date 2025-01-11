#include<iostream>
#include<cstring>

using namespace std;

#include"archivos.h"
#include"crearymostrar.h"
#include"borrar.h"

class Punto1{

    private:
    char codigoJugador[6];
    char nombreJugador[30];
    char nombrePais[30];
    int Goles;
    public:

    //setters y getters
    void setCodigoJugador(const char *codJug){strcpy(codigoJugador, codJug);}
    void setNombreJugador(const char *nom){strcpy(nombreJugador,nom);}
    void setNombrePais(const char *nom){strcpy(nombrePais,nom);}
    void setGoles(const int goles){Goles=goles;}

    const char *getCodigoJugador(){return codigoJugador;}
    const char *getNombreJugador(){return nombreJugador;}
    const char *getNombrePais(){return nombrePais;}
    int getGoles(){return Goles;}

    void setearTodo(const char *nomPais, const char *nomJug, const char *codJug, const int goles){
        setNombrePais(nomPais);
        setNombreJugador(nomJug);
        setCodigoJugador(codJug);
        setGoles(goles);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo del jugador: "<<codigoJugador<<endl;
        cout<<"Nombre del jugador: "<<nombreJugador<<endl;
        cout<<"Nombre del pais: "<<nombrePais<<endl;
        cout<<"Goles: "<<Goles<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo del jugador: "; cargarCadena(codigoJugador, 6);
        cout<<"Ingrese el nombre del jugador: "; cargarCadena(nombreJugador, 30);
        cout<<"Ingrese el nombre del pais: "; cargarCadena(nombrePais, 30);
        cout<<"Ingrese la cantidad de goles: "; cin>>Goles;
    }

    //constructor
    Punto1(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Punto1(){}

    Punto1& operator=(const char *f){
        strcpy(codigoJugador,f);
        return *this;
    }

};

class ArchivoPunto1{

    public:
//metodos

void GuardarArchivo(Punto1& obj,const char* nombre = "Punto1.dat"){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto1),1,p);
   fclose(p);
}

int contarRegistros(const char* nombre="Punto1.dat"){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto1);
    }

Punto1 leerRegistro(int pos,const char* nombre="Punto1.dat"){
        Punto1 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto1& reg, int posicionAReemplazar,const char* nombre="Punto1.dat"){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto1), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto1), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1,const char* nombre="Punto1.dat"){
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

void crearArchivo(int tam=1,const char* nombre="Punto1.dat"){
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

void mostrarArchivo(const char* nombre="Punto1.dat"){
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

void BorrarArchivo(const char* nombre="Punto1.dat"){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}

bool ExisteCodJug(const char* codigojugador,const char* nombre="Punto1.dat"){
   Punto1 obj;
   FILE *p;
   p = fopen(nombre,"rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   while(fread(&obj,sizeof(Punto1),1,p)){
      if(strcmp(obj.getCodigoJugador(),codigojugador)==0){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}




};

void punto1a(){ //con ExisteCodJug
    Punto1 objPunto1;
    ArchivoPunto1 objARPunto1;

    objARPunto1.BorrarArchivo();

    Paises objPaises;
    ArchivoPaises objAPaises;

    Jugadores objJugadores;
    ArchivoJugadores objAJugadores;

    Goles objGoles;
    ArchivoGoles objAGoles;

    int tam1 = objAPaises.contarRegistros();
    int tam2 = objAJugadores.contarRegistros();
    int tam3 = objAGoles.contarRegistros();

    char nombrePais[30];
    int Goles=0;
    char nombreJugador[30];
    char codigoJugador[30];
    bool band=false;

    for(int i=0; i<tam1; i++){
        objPaises = objAPaises.leerRegistro(i);
    
        for(int j=0; j<tam2; j++){
            objJugadores = objAJugadores.leerRegistro(j);

            if(objPaises.getCodigoPais()==objJugadores.getCodigoPais()){
                strcpy(nombrePais,objPaises.getNombrePais());
            
                for(int k=0; k<tam3; k++){
                    objGoles = objAGoles.leerRegistro(k);
                    if((strcmp(objJugadores.getCodigoJugador(),objGoles.getcodigoJugador())==0)){
                        
                        strcpy(codigoJugador,objJugadores.getCodigoJugador());
                        strcpy(nombreJugador,objJugadores.getNombreJugador());

                        if(objGoles.gettipodegol()!=2){
                            Goles++;
                        }
                    }

                }

                if(objARPunto1.ExisteCodJug(codigoJugador)==false){
                    objPunto1.setearTodo(nombrePais,nombreJugador,codigoJugador,Goles);
                    objARPunto1.GuardarArchivo(objPunto1);
                    Goles = 0;
                }
                
            }

        }
    }

    objARPunto1.mostrarArchivo();
}

void punto1b(){ //con bandera
    Punto1 objPunto1;
    ArchivoPunto1 objARPunto1;

    objARPunto1.BorrarArchivo();

    Paises objPaises;
    ArchivoPaises objAPaises;

    Jugadores objJugadores;
    ArchivoJugadores objAJugadores;

    Goles objGoles;
    ArchivoGoles objAGoles;

    int tam1 = objAPaises.contarRegistros();
    int tam2 = objAJugadores.contarRegistros();
    int tam3 = objAGoles.contarRegistros();

    char nombrePais[30];
    int Goles=0;
    char nombreJugador[30];
    char codigoJugador[30];
    bool band;

    for(int i=0; i<tam1; i++){
        band=true;
        objPaises = objAPaises.leerRegistro(i);
    
        for(int j=0; j<tam2; j++){
            objJugadores = objAJugadores.leerRegistro(j);

            if(objPaises.getCodigoPais()==objJugadores.getCodigoPais()){
                strcpy(nombrePais,objPaises.getNombrePais());
            
                for(int k=0; k<tam3; k++){
                    objGoles = objAGoles.leerRegistro(k);
                    if((strcmp(objJugadores.getCodigoJugador(),objGoles.getcodigoJugador())==0)){
                        
                        strcpy(codigoJugador,objJugadores.getCodigoJugador());
                        strcpy(nombreJugador,objJugadores.getNombreJugador());

                        if(objGoles.gettipodegol()!=2){
                            Goles++;
                        }
                    }else{
                        band=false;
                    }

                }

                if(band){
                    objPunto1.setearTodo(nombrePais,nombreJugador,codigoJugador,Goles);
                    objARPunto1.GuardarArchivo(objPunto1);
                    Goles = 0;
                }
                
            }

        }
    }

    objARPunto1.mostrarArchivo();
}

void punto2a(){ //sin Sobrecarga de operador
    Punto1 objPunto1;
    ArchivoPunto1 objARPunto1;

    objARPunto1.BorrarArchivo();

    Paises objPaises;
    ArchivoPaises objAPaises;

    Jugadores objJugadores;
    ArchivoJugadores objAJugadores;

    Goles objGoles;
    ArchivoGoles objAGoles;

    int tam1 = objAPaises.contarRegistros();
    int tam2 = objAJugadores.contarRegistros();
    int tam3 = objAGoles.contarRegistros();

    char nombrePais[30];
    int Goles=0;
    char nombreJugador[30];
    char codigoJugador[30];
    int max=0;

    for(int i=0; i<tam1; i++){
        objPaises = objAPaises.leerRegistro(i);
    
        for(int j=0; j<tam2; j++){
            objJugadores = objAJugadores.leerRegistro(j);

            if(objPaises.getCodigoPais()==objJugadores.getCodigoPais()){
                strcpy(nombrePais,objPaises.getNombrePais());
            
                for(int k=0; k<tam3; k++){
                    objGoles = objAGoles.leerRegistro(k);
                    if((strcmp(objJugadores.getCodigoJugador(),objGoles.getcodigoJugador())==0)){
                        
                        strcpy(codigoJugador,objJugadores.getCodigoJugador());
                        strcpy(nombreJugador,objJugadores.getNombreJugador());

                        if(objGoles.gettipodegol()!=2){
                            Goles++;
                        }
                    }

                }

                if(Goles>max){
                    max=Goles;
                    objPunto1.setearTodo(nombrePais,nombreJugador,codigoJugador,Goles);
                }
                Goles = 0;
                
            }

        }
    }

    objPunto1.mostrar();

    cout<<"///////////////////////////"<<endl;

    for(int i=0; i<tam2; i++){
        objJugadores = objAJugadores.leerRegistro(i);
        if(strcmp(objJugadores.getCodigoJugador(),objPunto1.getCodigoJugador())==0){
            objJugadores.mostrar();
        }
    }

}

void punto2b(){ //con Sobrecarga un operador
    Punto1 objPunto1;
    ArchivoPunto1 objARPunto1;

    objARPunto1.BorrarArchivo();

    Paises objPaises;
    ArchivoPaises objAPaises;

    Jugadores objJugadores;
    ArchivoJugadores objAJugadores;

    Goles objGoles;
    ArchivoGoles objAGoles;

    int tam1 = objAPaises.contarRegistros();
    int tam2 = objAJugadores.contarRegistros();
    int tam3 = objAGoles.contarRegistros();

    char nombrePais[30];
    int Goles=0;
    char nombreJugador[30];
    char codigoJugador[30];
    int max=0;

    for(int i=0; i<tam1; i++){
        objPaises = objAPaises.leerRegistro(i);
    
        for(int j=0; j<tam2; j++){
            objJugadores = objAJugadores.leerRegistro(j);

            if(objPaises.getCodigoPais()==objJugadores.getCodigoPais()){
                strcpy(nombrePais,objPaises.getNombrePais());
            
                for(int k=0; k<tam3; k++){
                    objGoles = objAGoles.leerRegistro(k);
                    if((strcmp(objJugadores.getCodigoJugador(),objGoles.getcodigoJugador())==0)){
                        
                        strcpy(codigoJugador,objJugadores.getCodigoJugador());
                        strcpy(nombreJugador,objJugadores.getNombreJugador());

                        if(objGoles.gettipodegol()!=2){
                            Goles++;
                        }
                    }

                }

                if(Goles>max){
                    max=Goles;
                    objPunto1 = codigoJugador;
                }
                Goles = 0;
                
            }

        }
    }

    objPunto1.mostrar();

    cout<<"///////////////////////////"<<endl;

    for(int i=0; i<tam2; i++){
        objJugadores = objAJugadores.leerRegistro(i);
        if(strcmp(objJugadores.getCodigoJugador(),objPunto1.getCodigoJugador())==0){
            objJugadores.mostrar();
        }
    }

}


int main(){

    punto2a();
    cout<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-."<<endl;
    punto2b();


    return 0;
}