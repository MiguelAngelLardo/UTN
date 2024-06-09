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
    void Cargar(){
        cin>>DNI;
        cargarCadena(nombre,24);
        cargarCadena(apellido,29);
        cargarCadena(email, 29);
        cin>>telefono;
        cin>>claustro;
        cin>>idDeporte;
        cin>>idEquipo;
        inscripcion.Cargar();
        cin>>matricula;
        estado=true;
    }
   int getDNI(){return DNI;}
   int getClaustro(){return claustro;}
   int getIdDeporte(){return idDeporte;}
   int getIdEquipo(){return idEquipo;}
   const char *getNombre(){return nombre;}
   const char *getApellido(){return apellido;}
   bool getEstado(){return estado;}
   Fecha getFechaInscirpcion(){return inscripcion;}

   void setEstado(bool e){estado=e;}

   void Mostrar(){
        cout<< "dni: " << DNI<<endl;
        cout<< "nombre: "  << nombre<<endl;
        cout << "apellido: " <<apellido<<endl;
        cout<< "email: " << email<<endl;
        cout<<"telefono: "  <<  telefono<<endl;
        cout<< "claustro: " << claustro<<endl;
        cout<< "idDeporte: " << idDeporte<<endl;
        cout<< "idEquipo: "  << idEquipo<<endl;
        cout << "fecha inscripcion: " <<endl;
        inscripcion.Mostrar();
        cout<<"matricula: " << matricula<<endl;
   }
};

class Deporte{
private:
    int idDeporte, anioOrigen, idCategoria;
    char nombre[30];
    bool estado;
public:
    void Cargar(){
        cin>>idDeporte;
        cargarCadena(nombre, 29);
        cin>>idCategoria;
        cin>>anioOrigen;
        estado=true;
    }
   int getIdDeporte(){return idDeporte;}
   int getIdCtegoria(){return idCategoria;}
   const char *getNombre(){return nombre;}
   bool getEstado(){return estado;}
    int getAnioOrigen(){return anioOrigen;}
   void setEstado(bool e){estado=e;}
   void Mostrar(){
        cout<< "idDeporte: " << idDeporte<<endl;
        cout<<"nombre deporte: " << nombre<<endl;
        cout<< "idCtegoria: " << idCategoria<<endl;
        cout<< "anioOrigen: " << anioOrigen<<endl;
   }

};

class Equipo{
private:
    int IdEquipo, nivel;
    char nombre[30];
    bool estado;
public:
    void Cargar(){
        cin>>IdEquipo;
        cargarCadena(nombre,29);
        cin>>nivel;
        estado=true;
    }
    int getIdEquipo(){return IdEquipo;}
    int getNivel(){return nivel;}
    const char *getNombre(){return nombre;}
    bool getEstado(){return estado;}

    void setEstado(bool e){estado=e;}
    void Mostrar(){
        cout<< "idEquipo: " << IdEquipo<<endl;
        cout<< "nombre equipo: " << nombre<<endl;
        cout<<"nivel: " << nivel<<endl;
   }
};

class ArchivoJugadores{
private:
    char nombre[30];
public:
    ArchivoJugadores(const char *n){
        strcpy(nombre, n);
    }
    Jugador leerRegistro(int pos){
        Jugador reg;
        reg.setEstado(false);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Jugador);
    }
    void grabarRegistro(Jugador reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return;
        fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return ;
    }

void listarRegistros(){
  Jugador obj;
  FILE *p;
  p = fopen("Jugadores.dat", "rb");
  if (p == NULL){
    cout << "Error de apertura";
    return;
  }

  while (fread(&obj, sizeof(Jugador), 1, p) == 1){
    obj.Mostrar();
    cout << endl;
  }
  fclose(p);
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
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Deporte);
    }
    void grabarRegistro(Deporte reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return;
        fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return;
    }

  void listarRegistros(){
  Deporte obj;
  FILE *p;
  p = fopen("deportes.dat", "rb");
  if (p == NULL){
    cout << "Error de apertura";
    return;
  }

  while (fread(&obj, sizeof(Deporte), 1, p) == 1){
    obj.Mostrar();
    cout << endl;
  }
  fclose(p);
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
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Equipo);
    }
    bool grabarRegistro(Equipo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

void listarRegistros(){
  Equipo obj;
  FILE *p;
  p = fopen("equipos.dat", "rb");
  if (p == NULL){
    cout << "Error de apertura";
    return;
  }

  while (fread(&obj, sizeof(Equipo), 1, p) == 1){
    obj.Mostrar();
    cout << endl;
  }
  fclose(p);
}
};

#endif // PARCIAL1L_H_INCLUDED
