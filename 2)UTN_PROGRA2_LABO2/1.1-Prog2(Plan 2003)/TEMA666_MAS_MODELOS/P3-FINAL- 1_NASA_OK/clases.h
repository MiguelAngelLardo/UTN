

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
};

/*
Astronautas.dat: DNI (int), nombre y apellido (char[50]), país (entero entre 1 y 50), y
categoría (1 a15).
*/

class Nasa{
private:
  int _DNI;
  char _nombreApellido[50];
  int _pais;//1 a 50
  int _categoria;//1 a 15

public:
  void setDNI(int dni){_DNI=dni;}
  void setNombreApellido(const char* nombreApellido){strcpy(_nombreApellido, nombreApellido);}
  void setPais(int pais){_pais=pais;}
  void setCategoria(int categoria){_categoria=categoria;}

  int getDNI(){return _DNI;}
  const char* getNombreApellido(){return _nombreApellido;}
  int getPais(){return _pais;}
  int getCategoria(){return _categoria;}

  void cargar(){
    cout <<"DNI: "; cin>>_DNI;
    cout <<"Nombre y Apellido: "; cargarCadena(_nombreApellido, 50);
    cout <<"Pais: "; cin>>_pais;
    cout <<"Categoria: "; cin>>_categoria;
  }

  void mostrar(){
    cout <<"DNI: "<<_DNI<<endl;
    cout <<"Nombre y Apellido: "<<_nombreApellido<<endl;
    cout <<"Pais: "<<_pais<<endl;
    cout <<"Categoria: "<<_categoria<<endl;
  }

};

class ArchivoNasa{
    private:
        char nombre[30];
    public:
        //constructor
        ArchivoNasa(const char* nombre="Nasa.dat"){
            strcpy(this->nombre, nombre);
        }

//metodos

void GuardarArchivo(Nasa& obj){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Nasa),1,p);
   fclose(p);
}

int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Nasa);
    }

Nasa leerRegistro(int pos){
        Nasa reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Nasa& reg, int posicionAReemplazar){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Nasa), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Nasa), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1){
    Nasa objE;
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
    fwrite(&objE, sizeof(Nasa), 1, p);
    }

    fclose(p);
}

void crearArchivo(int tam=1){
    Nasa objE;
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
    fwrite(&objE, sizeof(Nasa), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(){
    Nasa objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Nasa), 1, p) == true){
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

bool ExisteDNI(int dni){
   Nasa obj;
   FILE *p;
   p = fopen(nombre,"rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   while(fread(&obj,sizeof(Nasa),1,p)){
      if(obj.getDNI()==dni){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}

/*
bool ExisteDNIchar(const char* dni){
   Nasa obj;
   FILE *p;
   p = fopen(nombre,"rb");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   while(fread(&obj,sizeof(Nasa),1,p)){
      if(strcmp(obj.getDNI(),dni)==0){
         fclose(p);
         return true;
      }
   }
   fclose(p);
   return false;
}*/


};

/*Misiones.dat: Número de misión, DNI del astronauta (int), fecha de inicio(día, mes y año),
cargo (1a 10).*/

class Mision{

private:
    int _numeroMision;
    int _DNIAstronauta;
    Fecha _fechaInicio;
    int _cargo;//1 a 10

public:
  void setNumeroMision(int numeroMision){_numeroMision=numeroMision;}
  void setDNIAstronauta(int DNIAstronauta){_DNIAstronauta=DNIAstronauta;}
  void setFechaInicio(Fecha fechaInicio){_fechaInicio=fechaInicio;}
  void setCargo(int cargo){_cargo=cargo;}

  int getNumeroMision(){return _numeroMision;}
  int getDNIAstronauta(){return _DNIAstronauta;}
  Fecha getFechaInicio(){return _fechaInicio;}
  int getCargo(){return _cargo;}

  void cargar(){
    cout <<"Numero de Mision: "; cin>>_numeroMision;
    cout <<"DNI del Astronauta: "; cin>>_DNIAstronauta;
    cout <<"Fecha de Inicio: "; _fechaInicio.cargar();
    cout <<"Cargo: "; cin>>_cargo;
  }
    void mostrar(){
      cout <<"Numero de Mision: "<<_numeroMision<<endl;
      cout <<"DNI del Astronauta: "<<_DNIAstronauta<<endl;
      cout <<"Fecha de Inicio: "; _fechaInicio.mostrar();
      cout <<"Cargo: "<<_cargo<<endl;
    }

};

class ArchivoMision{

    public:
//metodos

void GuardarArchivo(Mision& obj,const char* nombre = "Mision.dat"){
   FILE *p;
   p = fopen(nombre,"ab");
   if(p == NULL){
      cout<<"No se pudo abrir el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fwrite(&obj,sizeof(Mision),1,p);
   fclose(p);
}

int contarRegistros(const char* nombre="Mision.dat"){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return -1;}
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Mision);
    }

Mision leerRegistro(int pos,const char* nombre="Mision.dat"){
        Mision reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return reg;}
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

bool reemplazarRegistro(Mision& reg, int posicionAReemplazar,const char* nombre="Mision.dat"){
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL){/*cout<<"Error en Linea: "<<__LINE__<<endl;*/  return false;}
    fseek(p, posicionAReemplazar * sizeof(Mision), SEEK_SET);
    bool pudoEscribir = fwrite(&reg, sizeof(Mision), 1, p);
    fclose(p);
    return pudoEscribir;
}

void cargarArchivo(int tam=1,const char* nombre="Mision.dat"){
    Mision objE;
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
    fwrite(&objE, sizeof(Mision), 1, p);
    }
    fclose(p);
}

void crearArchivo(int tam=1,const char* nombre="Mision.dat"){
    Mision objE;
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
    fwrite(&objE, sizeof(Mision), 1, p);
    }

    fclose(p);
}

void mostrarArchivo(const char* nombre="Mision.dat"){
    Mision objE;
    FILE *p;
    p = fopen(nombre,"rb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo mostrarArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }
while (fread(&objE, sizeof(Mision), 1, p) == true){
    objE.mostrar();
    cout << endl;
}
    fclose(p);
}

void BorrarArchivo(const char* nombre="Mision.dat"){
   FILE *p;
   p = fopen(nombre,"wb");
   if(p == NULL){
      cout<<"No se pudo borrar el archivo";
      //cout<<"En la Linea: "<<__LINE__<<endl;
   }
   fclose(p);
}



};