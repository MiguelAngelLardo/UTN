#pragma once


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

class Paises{

    private:
        int codigoPais;
        char nombrePais[30];
        char grupo[3];
    public:

    //setters y getters
    void setCodigoPais(const int codP){codigoPais=codP;}
    void setNombrePais(const char *nom){strcpy(nombrePais,nom);}
    void setGrupo(const char *nom){strcpy(grupo,nom);}
    
    int getCodigoPais(){return codigoPais;}
    const char *getNombrePais(){return nombrePais;}
    const char *getGrupo(){return grupo;}

    void setearTodo(int codigoPais,const char* nombrePais, const char* grupo){
        setCodigoPais(codigoPais);
        setNombrePais(nombrePais);
        setGrupo(grupo);
    }

    //metodos
    void mostrar(){
        cout<<"Codigo del pais: "<<codigoPais<<endl;
        cout<<"Nombre del pais: "<<nombrePais<<endl;
        cout<<"Nombre del grupo: "<<grupo<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo del pais: "; cin>>codigoPais;
        cout<<"Ingrese el nombre del pais: "; cargarCadena(nombrePais, 30);
        cout<<"Ingrese el nombre del grupo: "; cargarCadena(grupo, 3);
    }

    //constructor
    Paises(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Paises(){}

};

class ArchivoPaises{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPaises(const char* nombre="Paises.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Paises& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Paises),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Paises);
    }

Paises leerRegistro(int pos){
        Paises reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Paises& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Paises), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Paises), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Paises objE;
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
    fwrite(&objE, sizeof(Paises), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Paises objE;
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
    fwrite(&objE, sizeof(Paises), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Paises objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Paises), 1, p) == true){
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
//    Paises obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Paises),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

class Jugadores{

    private:
    char codigoJugador[6];
    char nombreJugador[30];
    int codigoPais;
    int edad;
    public:
    //setters y getters
    void setCodigoJugador(const char *codJug){strcpy(codigoJugador, codJug);}
    void setNombreJugador(const char *nom){strcpy(nombreJugador,nom);}
    void setCodigoPais(const int codP){codigoPais=codP;}
    void setEdad(const int ed){edad=ed;}

    const char *getCodigoJugador(){return codigoJugador;}
    const char *getNombreJugador(){return nombreJugador;}
    int getCodigoPais(){return codigoPais;}
    int getEdad(){return edad;}

    void setearTodo(const char *codJug, const char *nom, const int codP, const int ed){
        setCodigoJugador(codJug);
        setNombreJugador(nom);
        setCodigoPais(codP);
        setEdad(ed);
    }

    //metodos
    void mostrar(){
        cout<<"Codigo del jugador: "<<codigoJugador<<endl;
        cout<<"Nombre del jugador: "<<nombreJugador<<endl;
        cout<<"Codigo del pais: "<<codigoPais<<endl;
        cout<<"Edad del jugador: "<<edad<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo del jugador: "; cargarCadena(codigoJugador, 6);
        cout<<"Ingrese el nombre del jugador: "; cargarCadena(nombreJugador, 30);
        cout<<"Ingrese el codigo del pais: "; cin>>codigoPais;
        cout<<"Ingrese la edad: "; cin>>edad;
    }

    //constructor
    Jugadores(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Jugadores(){}

};

class ArchivoJugadores{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoJugadores(const char* nombre="Jugadores.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Jugadores& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Jugadores),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugadores);
    }

Jugadores leerRegistro(int pos){
        Jugadores reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Jugadores& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Jugadores), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Jugadores), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Jugadores objE;
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
    fwrite(&objE, sizeof(Jugadores), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Jugadores objE;
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
    fwrite(&objE, sizeof(Jugadores), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Jugadores objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Jugadores), 1, p) == true){
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
//    Jugadores obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Jugadores),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

class Goles{

    private:
        int codigodepartido;
        int minuto;
        int tiempo;
        char codigoJugador[6];
        int tipodegol;
    public:

    //setters y getters
    void setcodigodepartido(int cod){codigodepartido=cod;}
    void setminuto(int min){minuto=min;}
    void settiempo(int tiemp){tiempo=tiemp;}
    void setcodigoJugador(const char* codJug){strcpy(codigoJugador,codJug);}
    void settipodegol(int tip){tipodegol=tip;}

    int getcodigodepartido(){return codigodepartido;}
    int getminuto(){return minuto;}
    int gettiempo(){return tiempo;}
    const char* getcodigoJugador(){return codigoJugador;}
    int gettipodegol(){return tipodegol;}

    void setearTodo(int cod, int min, int tiemp, const char* codJug){
        setcodigodepartido(cod);
        setminuto(min);
        settiempo(tiemp);
        setcodigoJugador(codJug);
        settipodegol(1);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo del partido: "<<codigodepartido<<endl;
        cout<<"Minuto: "<<minuto<<endl;
        cout<<"Tiempo: "<<tiempo<<endl;
        cout<<"Codigo del jugador: "<<codigoJugador<<endl;
        cout<<"Tipo de gol: "<<tipodegol<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo del partido: "; cin>>codigodepartido;
        cout<<"Ingrese el minuto: "; cin>>minuto;
        cout<<"Ingrese el tiempo: "; cin>>tiempo;
        cout<<"Ingrese el codigo del jugador: "; cargarCadena(codigoJugador, 6);
        cout<<"Ingrese el tipo de gol: "; cin>>tipodegol;
    }

    //constructor
    Goles(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Goles(){}

};

class ArchivoGoles{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoGoles(const char* nombre="Goles.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Goles& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Goles),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Goles);
    }

Goles leerRegistro(int pos){
        Goles reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Goles& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Goles), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Goles), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Goles objE;
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
    fwrite(&objE, sizeof(Goles), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Goles objE;
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
    fwrite(&objE, sizeof(Goles), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Goles objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Goles), 1, p) == true){
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
//    Goles obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Goles),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

class Partidos{

    private:
        char codigoPartido[6];
        int codigoJugador1;
        int codigoJugador2;
        Fecha fecha;
        char hora[100];
        int codigodesede;
    public:
    //setters y getters
    void setcodigoPartido(const char* cod){strcpy(codigoPartido,cod);}
    void setcodigoJugador1(int cod){codigoJugador1=cod;}
    void setcodigoJugador2(int cod){codigoJugador2=cod;}
    void setfecha(const Fecha& fec){fecha=fec;}
    void sethora(const char* hor){strcpy(hora,hor);}
    void setcodigodesede(int cod){codigodesede=cod;}

    //metodos
    void mostrar(){
        cout<<"Codigo del partido: "<<codigoPartido<<endl;
        cout<<"Codigo del jugador 1: "<<codigoJugador1<<endl;
        cout<<"Codigo del jugador 2: "<<codigoJugador2<<endl;
        cout<<"Fecha del partido: "; fecha.mostrar();
        cout<<"Hora del partido: "<<hora<<endl;
        cout<<"Codigo de sede: "<<codigodesede<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo del partido: "; cargarCadena(codigoPartido, 6);
        cout<<"Ingrese el codigo del jugador 1: "; cin>>codigoJugador1;
        cout<<"Ingrese el codigo del jugador 2: "; cin>>codigoJugador2;
        cout<<"Ingrese la fecha del partido: "; fecha.cargar();
        cout<<"Ingrese la hora del partido: "; cargarCadena(hora, 100);
        cout<<"Ingrese el codigo de sede: "; cin>>codigodesede;
    }

    //constructor
    Partidos(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Partidos(){}

};

class ArchivoPartidos{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPartidos(const char* nombre="Partidos.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Partidos& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Partidos),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Partidos);
    }

Partidos leerRegistro(int pos){
        Partidos reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Partidos& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Partidos), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Partidos), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Partidos objE;
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
    fwrite(&objE, sizeof(Partidos), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Partidos objE;
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
    fwrite(&objE, sizeof(Partidos), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Partidos objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Partidos), 1, p) == true){
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
//    Partidos obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Partidos),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};

class Sedes{

    private:
        int codigodesede;
        char nombreSede[30];
        int capacidad;
    public:
    //setters y getters
    void setcodigodesede(int cod){codigodesede=cod;}
    void setnombreSede(const char* nom){strcpy(nombreSede,nom);}
    void setcapacidad(int cap){capacidad=cap;}

    int getcodigodesede(){return codigodesede;}
    const char* getnombreSede(){return nombreSede;}
    int getcapacidad(){return capacidad;}
    //metodos
    void mostrar(){
        cout<<"Codigo de la sede: "<<codigodesede<<endl;
        cout<<"Nombre de la sede: "<<nombreSede<<endl;
        cout<<"Capacidad de la sede: "<<capacidad<<endl;
    }

    void cargar(){
        cout<<"Ingrese el codigo de la sede: "; cin>>codigodesede;
        cout<<"Ingrese el nombre de la sede: "; cargarCadena(nombreSede, 30);
        cout<<"Ingrese la capacidad de la sede: "; cin>>capacidad;
    }

    //constructor
    Sedes(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Sedes(){}

};

class ArchivoSedes{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoSedes(const char* nombre="Sedes.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Sedes& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Sedes),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Sedes);
    }

Sedes leerRegistro(int pos){
        Sedes reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Sedes& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Sedes), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Sedes), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Sedes objE;
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
    fwrite(&objE, sizeof(Sedes), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Sedes objE;
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
    fwrite(&objE, sizeof(Sedes), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Sedes objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Sedes), 1, p) == true){
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
//    Sedes obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Sedes),1,p)){
//       if(obj.getDNI()==dni){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }



};















