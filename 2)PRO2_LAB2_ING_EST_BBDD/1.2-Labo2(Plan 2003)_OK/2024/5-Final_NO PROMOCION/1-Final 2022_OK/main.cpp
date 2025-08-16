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

class Conjunto{

    private:
        int *p;
        int _tam;
        int _indice;
    public:

    //setters y getters
    int getTamanio(){return _indice+1;}
    int getElemento(int pos){pos--; return p[pos];}
    int getTam(){return _tam;}
    //metodos
    void Agregar(int valor){
        bool distinto=false;

        for(int i=0;i<_indice;i++){
            if(p[i]!=valor){
                distinto=true;
            }   
        }

        if((distinto==true)&&(_indice<_tam)){
            p[_indice]=valor;
            _indice++;
        }
    }
    //constructor
    Conjunto(int tam){
        _tam = tam;
        p = new int [_tam];
        if(p == NULL){
            cout<<"Error de memoria"<<endl;
            exit(1);
        }
        _indice=0;
    }

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Conjunto(){}

};

bool CompararConjuntos(Conjunto A, Conjunto B){

    bool existe;

    if(A.getTam()==B.getTam()){
        for(int i=0;i<A.getTam();i++){
        existe=false;
            for(int j=0;j<B.getTam();j++){

                if(A.getElemento(i+1)==B.getElemento(j+1)){
                    existe=true;
                }
            }
            if(existe==false){break;}
        }
    }
    return existe;
}

class Participante{
    private:
        int _DNI;
        char _apellido[20];
        char _nombre[20];
        char _genero[20];
    public:

    //setters y getters
        void setDNI(int dni){_DNI=dni;}
        void setApellido(const char* apellido){strcpy(_apellido, apellido);}
        void setNombre(const char* nombre){strcpy(_nombre, nombre);}
        void setGenero(const char* genero){strcpy(_genero, genero);}

        int getDNI(){return _DNI;}
        const char* getApellido(){return _apellido;}
        const char* getNombre(){return _nombre;}
        const char* getGenero(){return _genero;}
    //metodos
    void mostrar(){
        cout<<"DNI: "<<_DNI<<endl;
        cout<<"Apellido: "<<_apellido<<endl;
        cout<<"Nombre: "<<_nombre<<endl;
        cout<<"Genero: "<<_genero<<endl;
    }

    void cargar(){
        cout<<"DNI: "; cin>>_DNI;
        cout<<"Apellido: "; cargarCadena(_apellido, 20);
        cout<<"Nombre: "; cargarCadena(_nombre, 20);
        cout<<"Genero: "; cargarCadena(_genero, 20);
    }

    //constructor
    Participante(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Participante(){}

};

class ArchivoParticipante{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoParticipante(const char* nombre="participante.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Participante& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Participante),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Participante);
    }

Participante leerRegistro(int pos){
        Participante reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Participante& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Participante), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Participante), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Participante objE;
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
    fwrite(&objE, sizeof(Participante), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Participante objE;
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
    fwrite(&objE, sizeof(Participante), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Participante objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Participante), 1, p) == true){
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

class Participacion{

    private:
        int _ID;
        int _lanzamiento;
        int _DNI;
    public:

    //setters y getters
    void setID(int ID){_ID=ID;}
    void setLanzamiento(int lanzamiento){_lanzamiento=lanzamiento;}
    void setDNI(int DNI){_DNI=DNI;}

    int getID(){return _ID;}
    int getLanzamiento(){return _lanzamiento;}
    int getDNI(){return _DNI;}
    //metodos
    void mostrar(){
        cout<<"ID: "<<_ID<<endl;
        cout<<"Lanzamiento: "<<_lanzamiento<<endl;
        cout<<"DNI: "<<_DNI<<endl;
    }

    void cargar(){
        cout<<"ID: "; cin>>_ID;
        cout<<"Lanzamiento: "; cin>>_lanzamiento;
        cout<<"DNI: "; cin>>_DNI;
    }

    //constructor
    Participacion(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Participacion(){}

};

class ArchivoParticipacion{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoParticipacion(const char* nombre="participaciones.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Participacion& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Participacion),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Participacion);
    }

Participacion leerRegistro(int pos){
        Participacion reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Participacion& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Participacion), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Participacion), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Participacion objE;
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
    fwrite(&objE, sizeof(Participacion), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Participacion objE;
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
    fwrite(&objE, sizeof(Participacion), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Participacion objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Participacion), 1, p) == true){
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

void cargarTodo(){
    ArchivoParticipante obj1;
    ArchivoParticipacion obj2;

    obj1.crearArchivo(8);
    obj2.crearArchivo(8);
}

void mostrarTodo(){
    ArchivoParticipante obj1;
    ArchivoParticipacion obj2;

    obj1.mostrarArchivo();
    cout<<"/////////////"<<endl;
    obj2.mostrarArchivo();
}

void punto2(){
    Participante objP1;
    Participante partMax;  //participante Max
    ArchivoParticipante ARobjP1;

    Participacion objP2;
    ArchivoParticipacion ARobjP2;

    int tam1 = ARobjP1.contarRegistros();
    int tam2 = ARobjP2.contarRegistros();
    for(int i=0; i<tam1; i++){
        int max=0;
        objP1 = ARobjP1.leerRegistro(i);

        if(objP1.getGenero()[0]=='M'){

            for(int j=0; j<tam2; j++){
                objP2 = ARobjP2.leerRegistro(j);

                if((objP1.getDNI()==objP2.getDNI())){
                    if(objP2.getLanzamiento()>max){
                        max = objP2.getLanzamiento();
                        partMax = objP1;
                    }
                }
            }

            if(max!=0){
            cout<<"el lanzamiento mayor es: "<<max<<endl;
            cout<<"Nombre: "<<partMax.getNombre()<<endl;
            cout<<"Apellido: "<<partMax.getApellido()<<endl;
            }
            max=0;
        }
    }
}

void punto3(){
    Participante objP1;
    ArchivoParticipante ARobjP1;

    Participacion objP2;
    ArchivoParticipacion ARobjP2;

    int tam1 = ARobjP1.contarRegistros();
    int tam2 = ARobjP2.contarRegistros();


    int cont=0;
    for(int i=0; i<tam1; i++){
        objP1 = ARobjP1.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objP2 = ARobjP2.leerRegistro(j);

            if((objP1.getDNI()==objP2.getDNI()) && (objP2.getLanzamiento()==0)){
                cont++;
                break;
            }
        }
    }

    cout<<"la cantidad de participantes sin lanzamiento es: "<<cont<<endl;
}

int main(){

    punto3();

    return 0;
}