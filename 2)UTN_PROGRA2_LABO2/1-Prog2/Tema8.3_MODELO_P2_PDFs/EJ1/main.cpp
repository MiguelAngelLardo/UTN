#include<iostream>
#include<cstring>

using namespace std;

#include"parcial1l.h"
#include"pruebasMaxi.h"

class Punto1{

    private:
    int _idEquipo;//equipo.dat
    char _nombreEquipo[30];//equipo.dat
    int _categoriaDelDeporte;//deporte.dat

    public:

    void setIdEquipo(int idEquipo){_idEquipo=idEquipo;}
    void setNombreEquipo(const char* nombreEquipo){strcpy(_nombreEquipo, nombreEquipo);}
    void setCategoriaDelDeporte(int categoriaDelDeporte){_categoriaDelDeporte=categoriaDelDeporte;}
    
    void setearTodos(int idEquipo, const char* nombreEquipo, int cantJugadoresInscriptos){
        setIdEquipo(idEquipo);
        setNombreEquipo(nombreEquipo);
        setCategoriaDelDeporte(cantJugadoresInscriptos);
    }

   

    //metodos
    void mostrar(){
        cout << "ID equipo: " << _idEquipo << endl;
        cout << "Nombre equipo: " << _nombreEquipo << endl;
        cout << "categoria deporte: " << _categoriaDelDeporte << endl;
    }

    void cargar(){
        cout << "ID equipo: "; cin >> _idEquipo;
        cout << "Nombre equipo: "; cargarCadena(_nombreEquipo, 29);
        cout << "categoria deporte: "; cin >> _categoriaDelDeporte;
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
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

//punto 1 crear archivo con id equipo, nombre equipo,  cantidad jugadores inscriptos
void punto1(){
    Equipo objE; //**numero equipo(PK)**, **nombre**
    ArchivoEquipos ARobjE("equipos.dat");

    Jugador objJ; //DNI(PK), numeroequipo(fk), id deporte (fk) -> 10 o mas
    ArchivoJugadores ARobjJ("jugadores.dat");

    Deporte objD; //id de eporte(PK), **categoria de deporte**
    ArchivoDeportes ARobjD("deportes.dat");

    Punto1 objPunto1;
    ArchivoPunto1 ARobjPunto1;
    ARobjPunto1.BorrarArchivo();

    int tam1 = ARobjE.contarRegistros();
    int tam2 = ARobjJ.contarRegistros(); //relacion con equipo
    int tam3 = ARobjD.contarRegistros(); //relacion con jugador

    int cont=0;

    for(int i=0; i<tam1; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado() == true){
            
            for (int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
                if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){
                    
                    cont++;
                    if(cont == 2){ //cambiamos a cont==2 pero deberia poner cont == 10
                        objPunto1.setIdEquipo(objE.getIDequipo());
                        objPunto1.setNombreEquipo(objE.getNombre());

                        for(int k=0; k<tam3; k++){
                            objD = ARobjD.leerRegistro(k);
                            if((objD.getEstado() == true) && (objJ.getIDdeporte() == objD.getIDdeporte())){
                                    objPunto1.setCategoriaDelDeporte(objD.getIDcategoria());
                                    ARobjPunto1.GuardarArchivo(objPunto1);
                            }
                        }  

                    }
                }    
            } 
            cont=0; 
        }    
    }    
    ARobjPunto1.mostrarArchivo();

}

void punto2corta(){ //manera corta
    Punto1 *objP;
    ArchivoPunto1 ARobjPunto1("Punto1.dat");

    

    int tam = ARobjPunto1.contarRegistros();

    objP = new Punto1[tam];
    if(objP == NULL){
        cout << "No se pudo crear el arreglo" << endl;
    }

    for(int i=0; i<tam; i++){
        objP[i] = ARobjPunto1.leerRegistro(i);
    }

    for(int i=0; i<tam; i++){
        objP[i].mostrar();
        cout<<endl;
    }

}

void CargarVector(int vec[], int tam, int valor=0){
    for(int i=0; i<tam; i++){
        vec[i]=valor;
    }
}


//preguntando la ia como crear un vector dinamico tipo char
//https://sl.bing.net/eqpO4X5NXPw
//https://sl.bing.net/eqpO4X5NXPw
void punto2larga(){ //manera corta
    Equipo objE; //**numero equipo(PK)**, **nombre**
    ArchivoEquipos ARobjE("equipos.dat");

    Jugador objJ; //DNI(PK), numeroequipo(fk), id deporte (fk) -> 10 o mas
    ArchivoJugadores ARobjJ("jugadores.dat");

    Deporte objD; //id de eporte(PK), **categoria de deporte**
    ArchivoDeportes ARobjD("deportes.dat");

    Punto1 objPunto1;
    ArchivoPunto1 ARobjPunto1;
    ARobjPunto1.BorrarArchivo();

    int tam1 = ARobjE.contarRegistros();
    int tam2 = ARobjJ.contarRegistros(); //relacion con equipo
    int tam3 = ARobjD.contarRegistros(); //relacion con jugador

    //crear vectores dinamicos de Equipos
    int *NumDeEquipo;
    char **NombDeEquipo;
    int *CategoriaDeDeporte;


    NumDeEquipo = new int[tam1];
    if(NumDeEquipo == NULL){
        cout << "No se pudo crear el vector" << endl;
        exit(1);
    }

    CargarVector(NumDeEquipo, tam1, -1);

    NombDeEquipo = new char*[tam1];
    for(int i = 0; i < tam1; ++i) {
        NombDeEquipo[i] = new char[30];  // Asume que MAX_NOMBRE_LENGTH es la longitud máxima de un nombre
        if(NombDeEquipo[i] == NULL){
            cout << "No se pudo crear el vector" << endl;
            exit(1);
        }
    
    }

    CategoriaDeDeporte = new int[tam1];  //tam3
    if(CategoriaDeDeporte == NULL){
        cout << "No se pudo crear el vector" << endl;
        exit(1);
    }


    int cont=0;

    for(int i=0; i<tam1; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado() == true){
            
            for (int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
                if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){
                    
                    cont++;
                    if(cont == 2){ //cambiamos a cont==2 pero deberia poner cont == 10
                        //objPunto1.setIdEquipo(objE.getIDequipo());
                        //objPunto1.setNombreEquipo(objE.getNombre());
                        NumDeEquipo[i] = objE.getIDequipo();
                        strcpy(NombDeEquipo[i], objE.getNombre());

                        for(int k=0; k<tam3; k++){
                            objD = ARobjD.leerRegistro(k);
                            if((objD.getEstado() == true) && (objJ.getIDdeporte() == objD.getIDdeporte())){
                                    //objPunto1.setCategoriaDelDeporte(objD.getIDcategoria());
                                    CategoriaDeDeporte[i] = objD.getIDcategoria();
                                    //ARobjPunto1.GuardarArchivo(objPunto1);
                            }
                        }  

                    }
                }    
            } 
            cont=0; 
        }    
    }    
    //ARobjPunto1.mostrarArchivo();

    for(int i=0; i<tam1; i++){

        if(NumDeEquipo[i] != -1){
        cout<<"Numero de equipo: "<<NumDeEquipo[i]<<endl;
        cout<<"Nombre de equipo: "<<NombDeEquipo[i]<<endl;
        cout<<"Categoria del deporte: "<<CategoriaDeDeporte[i]<<endl<<endl;
        }
    }

    delete []NumDeEquipo;

    for(int i = 0; i < tam1; ++i) {
    delete[] NombDeEquipo[i];
    }

    delete []CategoriaDeDeporte;
}


void punto2largaB(){ //manera corta
    Equipo objE; //**numero equipo(PK)**, **nombre**
    ArchivoEquipos ARobjE("equipos.dat");

    Jugador objJ; //DNI(PK), numeroequipo(fk), id deporte (fk) -> 10 o mas
    ArchivoJugadores ARobjJ("jugadores.dat");

    Deporte objD; //id de eporte(PK), **categoria de deporte**
    ArchivoDeportes ARobjD("deportes.dat");


    int tam1 = ARobjE.contarRegistros();
    int tam2 = ARobjJ.contarRegistros(); //relacion con equipo
    int tam3 = ARobjD.contarRegistros(); //relacion con jugador

    //crear vectores dinamicos de Equipos
    int *NumDeEquipo;
    char **NombDeEquipo;
    int *CategoriaDeDeporte;

    int contadorMas10;
    int contadorUnidades;
    bool bandera10 = true;

    for(int i=0; i<tam1; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado() == true){
            
            contadorUnidades = 0;
            bandera10 = true;
            for (int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
                if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){
                    
                    contadorUnidades++;//cuando llega a 2
                    
                    if(contadorUnidades == 2){
                        bandera10 = false;                        
                    }

                    if((contadorUnidades == 2) && (bandera10 == false)){ 
                        contadorMas10++;//deberia tener
                        bandera10 = true;
                    }
                }    
            } 
        }    
    }    
    
   
    NumDeEquipo = new int[contadorMas10];
    if(NumDeEquipo == NULL){cout << "No se pudo reservar memoria" << endl;exit(1);}
    
    NombDeEquipo = new char*[contadorMas10];
    for(int i= 0; i<contadorMas10; i++){
        NombDeEquipo[i] = new char[20];
        if(NombDeEquipo[i] == NULL){cout << "No se pudo reservar memoria" << endl;exit(1);}
    }
    
    
    
    CategoriaDeDeporte = new int[contadorMas10];
    if(CategoriaDeDeporte == NULL){cout << "No se pudo reservar memoria" << endl;exit(1);}

    int indexVector = 0;
    for(int i=0; i<tam1; i++){
        objE = ARobjE.leerRegistro(i);

        if(objE.getEstado() == true){
            
            contadorUnidades = 0;
            
            for (int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
                if((objJ.getEstado() == true) && (objE.getIDequipo() == objJ.getIDequipo())){
                    contadorUnidades++;
                    if(contadorUnidades == 2){
                        NumDeEquipo[indexVector] = objE.getIDequipo();
                        strcpy(NombDeEquipo[indexVector], objE.getNombre());

                        for(int k=0; k<tam3; k++){
                            objD = ARobjD.leerRegistro(k);
                            if(objD.getIDdeporte() == objJ.getIDdeporte()){
                                CategoriaDeDeporte[indexVector] = objD.getIDcategoria();
                                indexVector++;
                            }
                        }    
                    }
                }    
            } 
        }    
    } 

    for(int i = 0; i < contadorMas10; i++){
        cout << "NUMERO EQUIPO " << NumDeEquipo[i] << endl;
        cout << "NOMBRE EQUIPO " << NombDeEquipo[i] << endl;
        cout << "CATEGORIA DE DEPORTE " << CategoriaDeDeporte[i] << endl;
        cout << endl;   
    }    

    delete []NumDeEquipo;
    for(int i = 0; i < contadorMas10; i++){
        delete []NombDeEquipo[i];}
    delete []CategoriaDeDeporte;
}

void puntoC(){
    //PUNTO C
    Jugador objJ;
    ArchivoJugadores ARobjJ("jugadores.dat");
    
    Deporte objD;
    ArchivoDeportes ARobjD("deportes.dat");

    int tam1 = ARobjJ.contarRegistros();
    int tam2 = ARobjD.contarRegistros();

    for(int i=0; i<tam1; i++){
        objJ = ARobjJ.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objD = ARobjD.leerRegistro(j);

            if(objJ==objD){
                cout<<"/////////////////////"<<endl;
                cout << "JUGADOR: "<<endl;
                cout<<objJ.getIDdeporte()<<endl;
                cout<<objD.getIDdeporte()<<endl;
            }
        }
    }

}

class puntoD{
private:
    int _idDeporte, _categoriaDeporte, _anioOrigen;
    char _nombre[30];

public:
    void setIdDeporte (int idDeporte){_idDeporte = idDeporte;}
    void setCategoriaDeporte (int categoriaDeporte){_categoriaDeporte = categoriaDeporte;}
    void setAnioOrigen (int anioOrigen){_anioOrigen = anioOrigen;}
    void setNombre (const char* nombre){strcpy(_nombre, nombre);}
    void setearTodos(int idDeporte, const char* nombre, int categoriaDeporte, int anioOrigen) {
        setIdDeporte(idDeporte); setNombre(nombre); setCategoriaDeporte(categoriaDeporte); setAnioOrigen(anioOrigen);
    }

    void mostrar(){
        cout << "ID deporte: " << _idDeporte << endl;
        cout << "NOMBRE deporte: " << _nombre << endl;
        cout << "CATEGORIA deporte: " << _categoriaDeporte << endl;
        cout << "ANIO ORIGEN deporte: " << _anioOrigen << endl;
    }

};

class ArchivoPuntoD{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPuntoD(const char* nombre="PuntoD.dat"){
            strcpy(this->nombre, nombre);
        }

void GuardarRegistro(puntoD& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(puntoD),1,p);
   fclose(p);
}
void listarArchivo(){
    puntoD objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(puntoD), 1, p) == true){
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


void PuntoD(){
    Deporte objD; //**idDeporte (PK)**, **nombre**, **categoria **, **anio origen**
    ArchivoDeportes ARobjD("deportes.dat");

    Jugador objJ; //idDeporte (fk) -> claustro 1 a 4
    ArchivoJugadores ARobjJ("jugadores.dat");

    puntoD objPuntoD;
    ArchivoPuntoD ARobjPuntoD;
    ARobjPuntoD.BorrarArchivo();

    int tam1 = ARobjD.contarRegistros();
    int tam2 = ARobjJ.contarRegistros();

    for (int i = 0; i < tam1; i++) {
        objD = ARobjD.leerRegistro(i);

        if(objD.getEstado() == true) {
            for(int j = 0; j < tam2; j++) {
                objJ = ARobjJ.leerRegistro(j);

                if(objJ.getEstado() == true) {
                    if((objD.getIDdeporte() == objJ.getIDdeporte()) && (objJ.getClaustro() >= 1) && (objJ.getClaustro() <= 4)){

                        objPuntoD.setearTodos(objD.getIDdeporte(), objD.getNombre(), objD.getIDcategoria(), objD.getAnioOrigen());
                        ARobjPuntoD.GuardarRegistro(objPuntoD);                        
                    }
                }    
            }    
        }    
    }    
    ARobjPuntoD.listarArchivo();
}

class PuntoG{
private:
    int _dni;
    char _nombreJugador[30];
    char _apellidosJugador[30];
    int _claustro;
    char _nombreDeporte[30];

public:

    void setearTodos(int dni, const char* nombreJugador, const char* apellidosJugador, int claustro, const char* nombreDeporte){
        _dni = dni;
        strcpy(_nombreJugador, nombreJugador);
        strcpy(_apellidosJugador, apellidosJugador);
        _claustro = claustro;
        strcpy(_nombreDeporte, nombreDeporte);
    }

    void mostrar(){
        cout<<"DNI: "<<_dni<<endl;
        cout<<"NOMBRE: "<<_nombreJugador<<endl;
        cout<<"Apellidos: "<<_apellidosJugador<<endl;
        cout<<"Claustro: "<<_claustro<<endl;
        cout<<"Deporte: "<<_nombreDeporte<<endl;
    }
};


class ArchivoPuntoG{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPuntoG(const char* nombre="PuntoG.dat"){
            strcpy(this->nombre, nombre);
        }

void GuardarRegistro(PuntoG& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(PuntoG),1,p);
   fclose(p);
}
void listarArchivo(){
    PuntoG objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(PuntoG), 1, p) == true){
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

void puntoG(){
    Deporte objD;//idDeporte (PK), **nombre de deporte**
    ArchivoDeportes ARobjD("deportes.dat");

    Jugador objJ;//**DNI(PK)**, **nombre**, **apellido**, **claustro**, id deporte (fk) -> matricula > 10000 y fecha inscrip == 2024
    ArchivoJugadores ARobjJ("jugadores.dat");

    PuntoG objPuntoG;
    ArchivoPuntoG ARobjPuntoG;
    ARobjPuntoG.BorrarArchivo();

    int tam1 = ARobjD.contarRegistros();
    int tam2 = ARobjJ.contarRegistros();

    for(int i=0; i<tam1; i++){
        objD = ARobjD.leerRegistro(i);
        if(objD.getEstado() == true){
        
            for(int j=0; j<tam2; j++){
                objJ = ARobjJ.leerRegistro(j);
            
                if((objJ.getEstado() == true) && (objD.getIDdeporte() == objJ.getIDdeporte())){ 
                    
                    if((objJ.getMatricula() > 10000) && (objJ.getFechaInscirpcion().getAnio() == 2024)){
                        objPuntoG.setearTodos(objJ.getDNI(), objJ.getNombre(), objJ.getApellido(), objJ.getClaustro(), objD.getNombre());
                        ARobjPuntoG.GuardarRegistro(objPuntoG);
                    }
                }     
            }        
        }    
    }  

    ARobjPuntoG.listarArchivo();

}

void puntoH(){//equipo 1 tiene 3 jugadores, equipio 2 tiene 1 jugadores, equipo 3 tiene 2 jugadores, equipo 4 no tiene
    Jugador objJ;
    ArchivoJugadores ARobjJ("jugadores.dat");

    int numEquipo;
    Jugador *vJugadores;
    int tamJugadoresPorEquipo;

    int tam1 = ARobjJ.contarRegistros();

    cout << "Ingre se el numero de equipo para listar a los jugadores: ";
    cin >> numEquipo;//1

    for(int i=0; i<tam1; i++){
        objJ = ARobjJ.leerRegistro(i);

        if((objJ.getEstado()) && objJ.getIDequipo() == numEquipo){
            tamJugadoresPorEquipo++;
        }
    }   

    vJugadores = new Jugador[tamJugadoresPorEquipo];
    if(vJugadores == NULL){cout << "No se pudo crear el vector" << endl; exit(1);}

     
    int index = 0;
    for(int i=0; i<tam1; i++){
        objJ = ARobjJ.leerRegistro(i);

        if((objJ.getEstado()) && objJ.getIDequipo() == numEquipo){
            vJugadores[index] = objJ;
            index ++;
        }
    }  

    cout << "MOSTRANDO LOS JUGADORES PERTENENCIENTES AL EQUIPO: " << numEquipo << endl;
    
    if(tamJugadoresPorEquipo ==0){
        cout << "EL EQUIPO "<< numEquipo <<" NO TIENE JUGADORES" << endl;
    }else{
        for(int i=0; i<tamJugadoresPorEquipo; i++){
            vJugadores[i].Mostrar();
            cout << "///////////////////" << endl;
        }
    }


    delete [] vJugadores;
}



void puntoEcorta(){ //manera corta MIA
    Equipo *vecInicial;
    Equipo aux;
    ArchivoEquipos ARobjE("equipos.dat");
    int tam= ARobjE.contarRegistros();

    vecInicial = new Equipo[tam];
    if(vecInicial == NULL){cout << "No se pudo crear el vector" << endl; exit(1);}
    
    for(int i=0; i<tam; i++){
        vecInicial[i].setNivel(-1);
    }

    for(int i=0; i<tam; i++){
        aux = ARobjE.leerRegistro(i); //aqui solo se utiliza el "Equipo aux;"

        if(aux.getNivel()==1){
            vecInicial[i] = ARobjE.leerRegistro(i);
        }
    }

    for(int i=0; i<tam; i++){
        if(vecInicial[i].getNivel()!=-1){
            vecInicial[i].Mostrar();
        }
    }
}

void puntoElarga(){ //manera larga Miguel
    Equipo objE;
    ArchivoEquipos ARobjE("equipos.dat");
    Equipo *vEquipo;//getNivel ==1

    int tam = ARobjE.contarRegistros();

    int cont = 0;
    for (int i = 0; i < tam; i++){
        objE = ARobjE.leerRegistro(i);
        if(objE.getNivel() == 1){
           cont ++; 
        }
    }
    
    vEquipo = new Equipo[cont];
    if(vEquipo == NULL){cout << "No se pudo crear el vector" << endl; exit(1);}

    int index = 0;
   for (int i = 0; i < tam; i++) {
    objE = ARobjE.leerRegistro(i);
    if (objE.getNivel() == 1) {
        vEquipo[index++] = objE;
    }
}

    cout << "Mostrando Equipo con nivel 1" << endl;
    for (int i = 0; i < cont; i++){
        cout << "Equipo: #" << i+1 << endl;
        vEquipo[i].Mostrar();
    }
    //cout<<"///////////////////////"<<endl;
    //MostrarVector(vEquipo, cont);
    //cout<<"///////////////////////"<<endl;

    delete [] vEquipo;

}






int main(){
    
    // punto1();
    // cout<<"///////////////////"<<endl;
    // punto2corta();
    // cout<<"///////////////////"<<endl;
    // punto2larga();
    // cout<<"///////////////////"<<endl;
    // punto2largaB();
    // cout<<"///////////////////"<<endl;

    // puntoEcorta();
    // cout<<"///////////////////"<<endl;
    // puntoElarga();+

    //punto F
    Jugador objE;

    objE.setClaustro(2);
    int num;
    cout << "Ingrese el claustro a comparar: ";
    cin >> num;

    if(objE == num){
        cout << "El numero es igual al claustro";
    }else{
        cout << "El numero es diferente al claustro";
    }


    //puntoG();

    //punto H();

    // //punto I
    // Jugador obj1;
    // obj1.Cargar();

    // Jugador obj2;
    // obj2.Cargar();

    // if(obj1 > obj2){
    //     cout << "La fecha de obj1 es mayor";
    // }else{
    //     cout << "La fecha de obj1 no es mayor";
    // }





    // ArchivoEquipos ARobjE("equipos.dat");
    // ARobjE.crearArchivo(10);

    //ArchivoJugadores ARobjJ("jugadores.dat");
    //ARobjJ.crearArchivo(10);

    // ArchivoDeportes ARobjD("deportes.dat");
    // ARobjD.crearArchivo(10);

    return 0;
}