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

class Vendedores{

    private:
        char CodigoDeVendedor[5];
        char NombreVendedor[30];
        int Rubro;
        int Calificacion;
        int provicina;
    public:
    //setters y getters
    void setCodigoDeVendedor(const char* CodigoDeVendedor){strcpy(this->CodigoDeVendedor, CodigoDeVendedor);}
    const char* getCodigoDeVendedor(){return CodigoDeVendedor;}
    void setNombreVendedor(const char* NombreVendedor){strcpy(this->NombreVendedor, NombreVendedor);}
    const char* getNombreVendedor(){return NombreVendedor;}
    void setRubro(int Rubro){this->Rubro=Rubro;}
    int getRubro(){return Rubro;}
    void setCalificacion(int Calificacion){this->Calificacion=Calificacion;}
    int getCalificacion(){return Calificacion;}
    void setProvincia(int provicina){this->provicina=provicina;}
    int getProvicina(){return provicina;}
    //metodos
    void mostrar(){
        cout<<"Codigo de vendedor: "<<CodigoDeVendedor<<endl;
        cout<<"Nombre de vendedor: "<<NombreVendedor<<endl;
        cout<<"Rubro: "<<Rubro<<endl;
        cout<<"Calificacion: "<<Calificacion<<endl;
        cout<<"Provincia: "<<provicina<<endl;
    }

    void cargar(){
        cout<<"Codigo de vendedor: "; cargarCadena(CodigoDeVendedor, 5);
        cout<<"Nombre de vendedor: "; cargarCadena(NombreVendedor, 30);
        cout<<"Rubro: "; cin>>Rubro;
        cout<<"Calificacion: "; cin>>Calificacion;
        cout<<"Provincia: "; cin>>provicina;
    }

    //constructor
    Vendedores(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Vendedores(){}

};

class ArchivoVendedores{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoVendedores(const char* nombre="Vendedores.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Vendedores& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Vendedores),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Vendedores);
    }

Vendedores leerRegistro(int pos){
        Vendedores reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Vendedores& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Vendedores), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Vendedores), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Vendedores objE;
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
    fwrite(&objE, sizeof(Vendedores), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Vendedores objE;
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
    fwrite(&objE, sizeof(Vendedores), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Vendedores objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Vendedores), 1, p) == true){
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
    void mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }

    void cargar(){
        cout<<"Dia: "; cin>>dia;
        cout<<"Mes: "; cin>>mes;
        cout<<"Anio: "; cin>>anio;
    }

    //constructor
    Fecha(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Fecha(){}



};

class Ventas{

    private:
        int NumeroDeCompra;
        char CodigoDeVendedor[5];
        char CodigoDeUsuario[5];
        float Importe;
        Fecha FechaDeVenta;
        int TipoDePago;
        int Provincia;
    public:

    //setters y getters
    void setNumeroDeCompra(int NumeroDeCompra){this->NumeroDeCompra=NumeroDeCompra;}
    void setCodigoDeVendedor(const char* CodigoDeVendedor){strcpy(this->CodigoDeVendedor, CodigoDeVendedor);}
    void setCodigoDeUsuario(const char* CodigoDeUsuario){strcpy(this->CodigoDeUsuario, CodigoDeUsuario);}
    void setImporte(float Importe){this->Importe=Importe;}
    void setFecha(Fecha FechaDeVenta){this->FechaDeVenta=FechaDeVenta;}
    void setTipoDePago(int TipoDePago){this->TipoDePago=TipoDePago;}
    void setProvincia(int Provincia){this->Provincia=Provincia;}

    int getNumeroDeCompra(){return NumeroDeCompra;}
    const char* getCodigoDeVendedor(){return CodigoDeVendedor;}
    const char* getCodigoDeUsuario(){return CodigoDeUsuario;}
    float getImporte(){return Importe;}
    Fecha& getFecha(){return FechaDeVenta;}
    int getTipoDePago(){return TipoDePago;}
    int getProvincia(){return Provincia;}
    //metodos
    void mostrar(){
        cout<<"Numero de compra: "<<NumeroDeCompra<<endl;
        cout<<"Codigo de vendedor: "<<CodigoDeVendedor<<endl;
        cout<<"Codigo de usuario: "<<CodigoDeUsuario<<endl;
        cout<<"Importe: "<<Importe<<endl;
        cout<<"Fecha: "; FechaDeVenta.mostrar();
        cout<<"Tipo de pago: "<<TipoDePago<<endl;
        cout<<"Provincia: "<<Provincia<<endl;
    }

    void cargar(){
        cout<<"Numero de compra: "; cin>>NumeroDeCompra;
        cout<<"Codigo de vendedor: "; cargarCadena(CodigoDeVendedor, 5);
        cout<<"Codigo de usuario: "; cargarCadena(CodigoDeUsuario, 5);
        cout<<"Importe: "; cin>>Importe;
        cout<<"Fecha: "<<endl; FechaDeVenta.cargar();
        cout<<"Tipo de pago: "; cin>>TipoDePago;
        cout<<"Provincia: "; cin>>Provincia;
    }

    //constructor
    Ventas(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Ventas(){}

//SOBRECARGA DE OPERADORES
    bool operator==(int anio){
        if (anio == this->getFecha().getAnio()){
            return true;
        }
        else {
            return false;
        }
    }

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


};

class Usuarios{

    private:
        char CodigoDeUsuario[5];
        char NombreDeUsuario[20];
        int DNI;
        Fecha FechaDeRegistracion;
    public:

    //setters y getters
    void setCodigoDeUsuario(char CodigoDeUsuario[]){strcpy(this->CodigoDeUsuario, CodigoDeUsuario);}
    void setNombreDeUsuario(char NombreDeUsuario[]){strcpy(this->NombreDeUsuario, NombreDeUsuario);}
    void setDNI(int DNI){this->DNI=DNI;}
    void setFecha(Fecha FechaDeRegistracion){this->FechaDeRegistracion=FechaDeRegistracion;}

    const char* getCodigoDeUsuario(){return CodigoDeUsuario;}
    const char* getNombreDeUsuario(){return NombreDeUsuario;}
    int getDNI(){return DNI;}
    Fecha& getFecha(){return FechaDeRegistracion;}
    //metodos
    void mostrar(){
        cout<<"Codigo de usuario: "<<CodigoDeUsuario<<endl;
        cout<<"Nombre de usuario: "<<NombreDeUsuario<<endl;
        cout<<"DNI: "<<DNI<<endl;
        cout<<"Fecha de registracion: "; FechaDeRegistracion.mostrar();
    }

    void cargar(){
        cout<<"Codigo de usuario: "; cin>>CodigoDeUsuario;
        cout<<"Nombre de usuario: "; cin>>NombreDeUsuario;
        cout<<"DNI: "; cin>>DNI;
        cout<<"Fecha de registracion: "; FechaDeRegistracion.cargar();
    }

    //constructor
    Usuarios(){}

    //destructor  ---> aveces no funciona, por eso ahi que tener cuidado
   // ~Usuarios(){}

};

class ArchivoUsuarios{

    private:
        char nombre[30];
    public:
        //constructor
        ArchivoUsuarios(const char* nombre="Usuarios.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Usuarios& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Usuarios),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Usuarios);
    }

Usuarios leerRegistro(int pos){
        Usuarios reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Usuarios& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Usuarios), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Usuarios), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Usuarios objE;
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
    fwrite(&objE, sizeof(Usuarios), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Usuarios objE;
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
    fwrite(&objE, sizeof(Usuarios), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Usuarios objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Usuarios), 1, p) == true){
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