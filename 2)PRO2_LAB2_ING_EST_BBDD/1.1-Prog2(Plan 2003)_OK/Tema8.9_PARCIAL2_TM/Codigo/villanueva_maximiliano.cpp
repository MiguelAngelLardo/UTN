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

class Fecha{

    private:
        int dia,mes,anio;
    public:
    //setters y getters
    void setDia(int dia){this->dia=dia;}
    int getDia(){return dia;}
    void setMes(int mes){this->mes=mes;}
    int getMes(){return mes;}
    void setAnio(int anio){this->anio=anio;}
    int getAnio(){return anio;}
    //metodos
    void mostrar(){cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}

    void cargar(){
        cout<<"Dia: ";cin>>dia;
        cout<<"Mes: ";cin>>mes;
        cout<<"Anio: ";cin>>anio;
    }

    //constructor
    Fecha(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Fecha(){}

};

class talleres{

    private:
    int CodigoDeTaller;
    char NombreDeTaller[30];
    bool estado;
    public:

    //setters y getters
    void setCodigoDeTaller(int CodigoDeTaller){this->CodigoDeTaller=CodigoDeTaller;}
    int getCodigoDeTaller(){return CodigoDeTaller;}
    void setNombreDeTaller(const char* NombreDeTaller){strcpy(this->NombreDeTaller, NombreDeTaller);}
    const char* getNombreDeTaller(){return NombreDeTaller;}
    void setEstado(bool estado){this->estado=estado;}
    bool getEstado(){return estado;}

    void setearTodo(int CodigoDeTaller, const char* NombreDeTaller, bool estado){
        setCodigoDeTaller(CodigoDeTaller);
        setNombreDeTaller(NombreDeTaller);
        setEstado(estado);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo de taller: "<<CodigoDeTaller<<endl;
        cout<<"Nombre de taller: "<<NombreDeTaller<<endl;
        //cout<<"Estado: "<<estado<<endl;
    }

    void cargar(){
        cout<<"Codigo de taller: ";cin>>CodigoDeTaller;
        cout<<"Nombre de taller: ";cargarCadena(NombreDeTaller,30);
        estado=true;
    }

    //constructor
    talleres(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~talleres(){}

};

class Archivotalleres{

    private:
        char nombre[30];
    public:
        //constructor
        Archivotalleres(const char* nombre="talleres.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(talleres& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(talleres),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(talleres);
    }

talleres leerRegistro(int pos){
        talleres reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(talleres& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(talleres), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(talleres), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    talleres objE;
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
    fwrite(&objE, sizeof(talleres), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    talleres objE;
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
    fwrite(&objE, sizeof(talleres), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    talleres objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(talleres), 1, p) == true){
if(objE.getEstado()){
    objE.mostrar();
    cout << endl;
}
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
//    talleres obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(talleres),1,p)){
//       if((obj.getDNI()==dni)&&(obj.getEstado())){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }


};

class clientes{

    private:
        int CodigoDeCliente;
        char NombreDeCliente[30];
        bool estado;
    public:

    //setters y getters
    void setCodigoDeCliente(int CodigoDeCliente){this->CodigoDeCliente=CodigoDeCliente;}
    int getCodigoDeCliente(){return CodigoDeCliente;}
    void setNombreDeCliente(const char* NombreDeCliente){strcpy(this->NombreDeCliente, NombreDeCliente);}
    const char* getNombreDeCliente(){return NombreDeCliente;}
    void setEstado(bool estado){this->estado=estado;}
    bool getEstado(){return estado;}

    void setearTodo(int CodigoDeCliente, const char* NombreDeCliente, bool estado){
        setCodigoDeCliente(CodigoDeCliente);
        setNombreDeCliente(NombreDeCliente);
        setEstado(estado);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo de cliente: "<<CodigoDeCliente<<endl;
        cout<<"Nombre de cliente: "<<NombreDeCliente<<endl;
        //cout<<"Estado: "<<estado<<endl;
    }

    void cargar(){
        cout<<"Codigo de cliente: ";cin>>CodigoDeCliente;
        cout<<"Nombre de cliente: ";cargarCadena(NombreDeCliente,30);
        estado=true;
    }

    //constructor
    clientes(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~clientes(){}

};

class Archivoclientes{

    private:
        char nombre[30];
    public:
        //constructor
        Archivoclientes(const char* nombre="clientes.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(clientes& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(clientes),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(clientes);
    }

clientes leerRegistro(int pos){
        clientes reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(clientes& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(clientes), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(clientes), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    clientes objE;
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
    fwrite(&objE, sizeof(clientes), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    clientes objE;
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
    fwrite(&objE, sizeof(clientes), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    clientes objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(clientes), 1, p) == true){
if(objE.getEstado()){
    objE.mostrar();
    cout << endl;
}
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
//    clientes obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(clientes),1,p)){
//       if((obj.getDNI()==dni)&&(obj.getEstado())){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }


};

class reparaciones{

    private:
        int CodigoDeTaller;
        int CodigoDeCliente;
        Fecha FechaDeLaReparacion;
        int TipoDeReparacion;
        float Importe;
        int NumeroDeProvincia;
        bool estado;
    public:
    //setters y getters
        void setCodigoDeTaller(int CodigoDeTaller){this->CodigoDeTaller = CodigoDeTaller;}
        int getCodigoDeTaller(){return CodigoDeTaller;}
        void setCodigoDeCliente(int CodigoDeCliente){this->CodigoDeCliente = CodigoDeCliente;}
        int getCodigoDeCliente(){return CodigoDeCliente;}
        void setFecha(const Fecha& FechaDeLaReparacion){this->FechaDeLaReparacion = FechaDeLaReparacion;}
        Fecha& getFecha(){return FechaDeLaReparacion;}
        void setTipoDeReparacion(int TipoDeReparacion){this->TipoDeReparacion = TipoDeReparacion;}
        int getTipoDeReparacion(){return TipoDeReparacion;}
        void setImporte(float Importe){this->Importe = Importe;}
        float getImporte(){return Importe;}
        void setNumeroDeProvincia(int NumeroDeProvincia){this->NumeroDeProvincia = NumeroDeProvincia;}
        int getNumeroDeProvincia(){return NumeroDeProvincia;}
        void setEstado(bool estado){this->estado = estado;}
        bool getEstado(){return estado;}

        void setearTodo(int CodigoDeTaller, int CodigoDeCliente, const Fecha& FechaDeLaReparacion, int TipoDeReparacion, float Importe, int NumeroDeProvincia, bool estado){
            setCodigoDeTaller(CodigoDeTaller);
            setCodigoDeCliente(CodigoDeCliente);
            setFecha(FechaDeLaReparacion);
            setTipoDeReparacion(TipoDeReparacion);
            setImporte(Importe);
            setNumeroDeProvincia(NumeroDeProvincia);
            setEstado(estado);
        }
    //metodos
    void mostrar(){
        cout<<"Codigo de taller: "<<CodigoDeTaller<<endl;
        cout<<"Codigo de cliente: "<<CodigoDeCliente<<endl;
        cout<<"Fecha de la reparacion: "; FechaDeLaReparacion.mostrar();
        cout<<"Tipo de reparacion: "<<TipoDeReparacion<<endl;
        cout<<"Importe: "<<Importe<<endl;
        cout<<"Numero de provincia: "<<NumeroDeProvincia<<endl;
        //cout<<"Estado: "<<estado<<endl;
    }

    void cargar(){
        cout<<"Codigo de taller: "; cin>>CodigoDeTaller;
        cout<<"Codigo de cliente: "; cin>>CodigoDeCliente;
        FechaDeLaReparacion.cargar();
        cout<<"Tipo de reparacion: "; cin>>TipoDeReparacion;
        cout<<"Importe: "; cin>>Importe;
        cout<<"Numero de provincia: "; cin>>NumeroDeProvincia;
        estado = true;
    }

    //constructor
    reparaciones(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~reparaciones(){}

    //SOBRECARGA DE OPERADORES
//Punto3
bool operator!=(talleres &objT){
        if(objT.getCodigoDeTaller() != CodigoDeTaller) return true;
        return false;
    }
};

class Archivoreparaciones{

    private:
        char nombre[30];
    public:
        //constructor
        Archivoreparaciones(const char* nombre="reparaciones.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(reparaciones& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(reparaciones),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(reparaciones);
    }

reparaciones leerRegistro(int pos){
        reparaciones reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(reparaciones& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(reparaciones), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(reparaciones), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    reparaciones objE;
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
    fwrite(&objE, sizeof(reparaciones), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    reparaciones objE;
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
    fwrite(&objE, sizeof(reparaciones), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    reparaciones objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(reparaciones), 1, p) == true){
if(objE.getEstado()){
    objE.mostrar();
    cout << endl;
}
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
//    reparaciones obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(reparaciones),1,p)){
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
    reparaciones objR;
    Archivoreparaciones ARobjR;

    int tam = ARobjR.contarRegistros();

    int vDia[31] = {0}; //mes marzo, año 2024

    for(int i=0; i<tam; i++){
        objR = ARobjR.leerRegistro(i);

        if((objR.getFecha().getAnio()==2024) && (objR.getFecha().getMes()==3)){
            vDia[objR.getFecha().getDia()-1]++;
        }
    }

    int max=0;
    int pos=0;

    for(int i=0; i<31; i++){
        if(vDia[i]>max){
            max = vDia[i];
            pos = i;
        }
    }
    cout<<"El dia del mes con mas reparaciones es: "<<pos+1<<endl;
    cout<<"Su cantidad es: "<<max<<endl;
}

class Punto2{

    private:
    int CodigoDeTaller;
    char NombreDeTaller[30];
    bool estado;
    public:

    //setters y getters
    void setCodigoDeTaller(int CodigoDeTaller){this->CodigoDeTaller=CodigoDeTaller;}
    int getCodigoDeTaller(){return CodigoDeTaller;}
    void setNombreDeTaller(const char* NombreDeTaller){strcpy(this->NombreDeTaller, NombreDeTaller);}
    const char* getNombreDeTaller(){return NombreDeTaller;}
    void setEstado(bool estado){this->estado=estado;}
    bool getEstado(){return estado;}

    void setearTodo(int CodigoDeTaller, const char* NombreDeTaller, bool estado){
        setCodigoDeTaller(CodigoDeTaller);
        setNombreDeTaller(NombreDeTaller);
        setEstado(estado);
    }
    //metodos
    void mostrar(){
        cout<<"Codigo de taller: "<<CodigoDeTaller<<endl;
        cout<<"Nombre de taller: "<<NombreDeTaller<<endl;
        //cout<<"Estado: "<<estado<<endl;
    }

    void cargar(){
        cout<<"Codigo de taller: ";cin>>CodigoDeTaller;
        cout<<"Nombre de taller: ";cargarCadena(NombreDeTaller,30);
        estado=true;
    }

    //constructor
    Punto2(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Punto2(){}

};

class ArchivoPunto2{


    private:
        char nombre[30];
    public:
        //constructor
        ArchivoPunto2(const char* nombre="Punto2.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Punto2& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Punto2),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Punto2);
    }

Punto2 leerRegistro(int pos){
        Punto2 reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Punto2& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Punto2), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Punto2), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Punto2 objE;
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
    fwrite(&objE, sizeof(Punto2), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Punto2 objE;
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
    fwrite(&objE, sizeof(Punto2), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Punto2 objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Punto2), 1, p) == true){
if(objE.getEstado()){
    objE.mostrar();
    cout << endl;
}
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
//    Punto2 obj;
//    FILE *p;
//    p = fopen(nombre,"rb");
//    if(p == NULL){
//       cout<<"No se pudo abrir el archivo";
//       //cout<<"En la Linea: "<<__LINE__<<endl;
//    }
//    while(fread(&obj,sizeof(Punto2),1,p)){
//       if((obj.getDNI()==dni)&&(obj.getEstado())){
//          fclose(p);
//          return true;
//       }
//    }
//    fclose(p);
//    return false;
// }


};

void punto2(){


    talleres objT;
    Archivotalleres ARobjT;

    reparaciones objR;
    Archivoreparaciones ARobjR;

    int tam1 = ARobjT.contarRegistros();
    int tam2 = ARobjR.contarRegistros();

    Punto2 objP;
    ArchivoPunto2 ARobjP;
    ARobjP.BorrarArchivo();

    bool bandNoReparacion = true;
    int Anio;
    cout<<"Ingrese el anio: "; cin>>Anio;


    for(int i=0; i<tam1; i++){
        bandNoReparacion = true;
        objT = ARobjT.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objR = ARobjR.leerRegistro(j);

            if(objT.getCodigoDeTaller()==objR.getCodigoDeTaller()){
                if(objR.getFecha().getAnio()==Anio){
                        bandNoReparacion = false;
                        break;
                }
            }
        }
        if(bandNoReparacion==true){
            objP.setearTodo(objT.getCodigoDeTaller(), objT.getNombreDeTaller(),objT.getEstado());
            ARobjP.GuardarArchivo(objP);
        }
    }
    //ARobjP.mostrarArchivo();
}

void punto4(){
    talleres objT;
    Archivotalleres ARobjT;
    int tam1 = ARobjT.contarRegistros();
    reparaciones objR;
    Archivoreparaciones ARobjR;
    int tam2 = ARobjR.contarRegistros();

    reparaciones *vec;
    vec = new reparaciones[tam1];
    if(vec==NULL){
        cout<<"no se pudo crear el vector"<<endl;
        exit(1);
    }

    for(int i=0; i<tam1; i++){
        objT = ARobjT.leerRegistro(i);

        for(int j=0; j<tam2; j++){
            objR = ARobjR.leerRegistro(j);

            if(objR!=objT){
                vec[i] = ARobjR.leerRegistro(i);
                vec[i].mostrar();
            }
        }
        cout<<endl;
    }


    delete [] vec;
}



int main(){

    punto1();
    //punto2();
    //punto4();

    return 0;
}