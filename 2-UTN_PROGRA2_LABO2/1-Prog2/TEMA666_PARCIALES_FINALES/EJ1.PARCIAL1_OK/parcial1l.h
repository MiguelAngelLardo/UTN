#ifndef PARCIAL1L_H_INCLUDED
#define PARCIAL1L_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
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
    int dia,mes, anio;
public:
    void Cargar(){
        cin>>dia;
        cin>>mes;
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}

};

class Jugador{
private:
    int DNI, claustro, idDeporte, idEquipo;
    char nombre[25], apellido[30];
    char email[30];
    int telefono;
    Fecha inscripcion;
    float matricula;
    bool estado;
public:
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIdDeporte(){return idDeporte;}
   int getIdEquipo(){return idEquipo;}
   int getTelefono(){return telefono;}
   float getMatricula(){return matricula;}
   const char *getNombre(){return nombre;}
   const char *getApellido(){return apellido;}
   const char *getEmail(){return email;}
   bool getEstado(){return estado;}
   Fecha getFechaInscirpcion(){return inscripcion;}

   void setEstado(bool e){estado=e;}

   void Mostrar(){
        // cout<<"DNI: "<<getDNI()<<endl;
        // cout<<"claustro: "<<getClaustro()<<endl;
        // cout<<"idDeporte: "<<getIdDeporte()<<endl;
        // cout<<"idEquipo: "<<getIdEquipo()<<endl;
        // cout<<"nombre: "<<getNombre()<<endl;
        // cout<<"apellido: "<<getApellido()<<endl;
        // cout<<"Estado: "<<getEstado()<<endl<<endl;
    
        cout<<"DNI: "<<getDNI()<<endl;
        cout<<"nombre: "<<getNombre()<<endl;
        cout<<"apellido: "<<getApellido()<<endl;
        cout<<"Email: "<<getApellido()<<endl;
        cout<<"Telefono: "<<getTelefono()<<endl;
        cout<<"claustro: "<<getClaustro()<<endl;
        cout<<"idDeporte: "<<getIdDeporte()<<endl;
        cout<<"idEquipo: "<<getIdEquipo()<<endl;
        inscripcion.Mostrar();
        cout<<"Estado: "<<getEstado()<<endl<<endl;
   }
   void Cargar(){

        cout<<"DNI: ";
        cin>>DNI;
        cout<<"nombre: ";
        cargarCadena(nombre,25);
        cout<<"apellido: ";
        cargarCadena(nombre,25);
        cout<<"email: ";
        cargarCadena(email,30);
        cout<<"telefono: ";
        cin>>telefono;
        cout<<"claustro: ";
        cin>>claustro;
        cout<<"idDeporte: ";
        cin>>idDeporte;
        cout<<"idEquipo: ";
        cin>>idEquipo;

        int dia,mes,anio;

        cout<<"DIA";
        cin>>dia;
        inscripcion.setDia(dia);
        cout<<"MES";
        cin>>mes;
        inscripcion.setMes(mes);
        cout<<"ANIO";
        cin>>anio;
        inscripcion.setAnio(anio);

        cout<<"Estado: ";
        cin>>estado;
        
        cout<<endl;
   }
} ;

class Deporte{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
   int getIdDeporte(){return idDeporte;}
   int getIdCtegoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}

   void setEstado(bool e){estado=e;}
   void Mostrar(){
    // cout<<"idDeporte: "<<getIdDeporte()<<endl;
    // cout<<"Nombre: "<<getNombre()<<endl;
    // cout<<"idCategoria: "<<getIdCtegoria()<<endl;
    // cout<<"estado: "<<getEstado()<<endl<<endl;

    cout<<"idDeporte: "<<getIdDeporte()<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"idCategoria: "<<getIdCtegoria()<<endl;
    cout<<"estado: "<<getEstado()<<endl<<endl;
    }

    void Cargar(){
    cout<<"idDeporte: ";
    cin>>idDeporte;
    cout<<"Nombre: ";
    cargarCadena(nombre,30);
    cout<<"idCategoria: ";
    cin>>idCategoria;
    cout<<"estado: ";
    cin>>estado;
    }

};

class Equipo{
private:
    int IdEquipo, nivel;
    char nombre[30];
    bool estado;
public:
    int getIdEquipo(){return IdEquipo;}
    int getNivel(){return nivel;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setEstado(bool e){estado=e;}
    void Mostrar(){
   }
};

class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }///
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
             cout<<"error1"<<endl;
             return reg;
        }
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"error2"<<endl;
            return -1;
        } 
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    bool grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"error3"<<endl;
        return false;
        }
        
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};


class ArchivoDeportes{
private:
    char nombre[30];
public:
    ArchivoDeportes(const char *n){
        strcpy(nombre, n);
    }
    Deporte leerRegistro(int pos){
        Deporte reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"error4"<<endl;
            return reg;
        } 
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"error5"<<endl;
            return -1;
        }
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }
    bool grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"error6"<<endl;
            return false;
        }
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

class ArchivoEquipos{
private:
    char nombre[30];
public:
    ArchivoEquipos(const char *n){
        strcpy(nombre, n);
    }
    Equipo leerRegistro(int pos){
        Equipo reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"error7"<<endl;
            return reg;
        }
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL){
            cout<<"error7"<<endl;
            return -1;
        }
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL){
            cout<<"error8"<<endl;
            return false;
        }
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
};

#endif // PARCIAL1L_H_INCLUDED
