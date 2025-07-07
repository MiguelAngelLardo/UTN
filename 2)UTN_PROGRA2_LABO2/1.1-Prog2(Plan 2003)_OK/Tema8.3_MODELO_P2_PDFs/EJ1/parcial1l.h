#ifndef PARCIAL1L_H_INCLUDED
#define PARCIAL1L_H_INCLUDED
void cargarCadena(char *pal, int tam)
{
  int i;
  fflush(stdin);
  for (i = 0; i < tam; i++)
  {
    pal[i] = cin.get();
    if (pal[i] == '\n')
      break;
  }
  pal[i] = '\0';
  fflush(stdin);
}

class Fecha
{
private:
  int dia, mes, anio;

public:
  void Cargar()
  {
    cin >> dia;
    cin >> mes;
    cin >> anio;
  }
  void Mostrar()
  {
    cout << dia << "/";
    cout << mes << "/";
    cout << anio << endl;
  }
  int getDia() { return dia; }
  int getMes() { return mes; }
  int getAnio() { return anio; }
  void setDia(int d) { dia = d; }
  void setMes(int m) { mes = m; }
  void setAnio(int a) { anio = a; }
};

class Deporte
{
private:
  int idDeporte, anioOrigen, idCategoria;
  char nombre[30];
  bool estado;

public:
  int getAnioOrigen() { return anioOrigen; }
  int getIDdeporte() { return idDeporte; }
  int getIDcategoria() { return idCategoria; }
  const char *getNombre() { return nombre; }
  bool getEstado() { return estado; }
  void setEstado(bool e) { estado = e; }
  void Mostrar()
  {
    cout<<"ID deporte: "<<idDeporte<<endl;
    cout<<"Anio de origen: "<<anioOrigen<<endl;
    cout<<"ID categoria: "<<idCategoria<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    //cout<<"Estado: "<<estado<<endl;
  }

  void Cargar(){
    cout<<"ID deporte: "; cin>>idDeporte;
    cout<<"Nombre: "; cargarCadena(nombre, 30);
    cout<<"ID categoria: "; cin>>idCategoria;
    cout<<"Anio de origen: "; cin>>anioOrigen;
    estado=true;
  }

};
class Equipo
{
private:
  int IdEquipo, nivel;
  char nombre[30];
  bool estado;

public:
  int getIDequipo() { return IdEquipo; }
  int getNivel() { return nivel; }
  const char *getNombre() { return nombre; }
  bool getEstado() { return estado; }
  void setEstado(bool e) { estado = e; }
  void setNivel(int n) { nivel = n; }
  void Mostrar()
  {
    cout<<"ID equipo: "<<IdEquipo<<endl;
    cout<<"Nivel: "<<nivel<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    //cout<<"Estado: "<<estado<<endl;
  }

  void Cargar(){
    cout<<"ID equipo: "; cin>>IdEquipo;
    cout<<"Nombre: "; cargarCadena(nombre, 30);
    cout<<"Nivel: "; cin>>nivel;
    estado=true;
  }
};

class ArchivoDeportes
{
private:
  char nombre[30];

public:
  ArchivoDeportes(const char *n)
  {
    strcpy(nombre, n);
  }


void crearArchivo(int tam=1){
    Deporte objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.Cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Deporte), 1, p);
    }

    fclose(p);
}



  Deporte leerRegistro(int pos)
  {
    Deporte reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return reg;
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
  }
  int contarRegistros()
  {
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Deporte);
  }
  bool grabarRegistro(Deporte reg)
  {
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL)
      return false;
    int escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
  }
};
class ArchivoEquipos
{
private:
  char nombre[30];

public:
  ArchivoEquipos(const char *n)
  {
    strcpy(nombre, n);
  }


void crearArchivo(int tam=1){
    Equipo objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.Cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Equipo), 1, p);
    }

    fclose(p);
}


  Equipo leerRegistro(int pos)
  {
    Equipo reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return reg;
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
  }
  int contarRegistros()
  {
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Equipo);
  }
  bool grabarRegistro(Equipo reg)
  {
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL)
      return false;
    int escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
  }
};


class Jugador
{
private:
  int DNI, claustro, idDeporte, idEquipo;
  char nombre[25], apellido[30];
  char email[30];
  int telefono;
  Fecha inscripcion;
  float matricula;
  bool estado;

public:
  int getDNI() { return DNI; }
  int getClaustro() { return claustro; }
  int getIDdeporte() { return idDeporte; }
  int getIDequipo() { return idEquipo; }
  const char *getNombre() { return nombre; }
  const char *getApellido() { return apellido; }
  bool getEstado() { return estado; }
  Fecha getFechaInscirpcion() { return inscripcion; }
  void setEstado(bool e) { estado = e; }
  float getMatricula() { return matricula;}
  void setClaustro(int c) { claustro = c; }
  void Mostrar()
  {
    cout<<"DNI: "<<DNI<<endl;
    cout<<"Claustro: "<<claustro<<endl;
    cout<<"ID deporte: "<<idDeporte<<endl;
    cout<<"ID equipo: "<<idEquipo<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Email: "<<email<<endl;
    cout<<"Telefon: "<<telefono<<endl;
    cout<<"Fecha de inscripion: ";
    inscripcion.Mostrar();
    cout<<"Matricula: "<<matricula<<endl;
   // cout<<"Estado: "<<estado<<endl;
  }

  //sobrecargas de operadores

  bool operator==(Deporte &d){
    if(idDeporte == d.getIDdeporte()){
      return true;
    }return false;
  }

  void Cargar(){
    cout<<"DNI: "; cin>>DNI;
    cout<<"Nombre: "; cargarCadena(nombre, 25);
    cout<<"Apellido: "; cargarCadena(apellido, 30);
    cout<<"Email: "; cargarCadena(email, 30);
    cout<<"Telefon: "; cin>>telefono;
    cout<<"Claustro: "; cin>>claustro;
    cout<<"ID deporte: "; cin>>idDeporte;
    cout<<"ID equipo: "; cin>>idEquipo;
    cout<<"Fecha de inscripion: ";
    inscripcion.Cargar();
    cout<<"Matricula: "; cin>>matricula;
    estado=true;
  }

  //sobre carga > => verdadero cuando el anio inscripcion del que RECIBE es mayor al PARAMETRO

  bool operator > (Jugador &objJ){
        
    if((this->inscripcion.getAnio()) > (objJ.getFechaInscirpcion().getAnio())){
      return true;
    }else{
      return false;
    }
  }

  //pto F c) Sobrecargar el operador == para la clase Jugador, que reciba un valor entero y lo compare con el Id de claustro
  bool operator == (int numClaustro){
    if(this->claustro == numClaustro){
      return true;
    }else{
      return false;
    }
  }


};
class ArchivoJugadores
{
private:
  char nombre[30];

public:
  ArchivoJugadores(const char *n)
  {
    strcpy(nombre, n);
  }


void crearArchivo(int tam=1){
    Jugador objE;
    FILE *p;
    p = fopen(nombre,"wb");
    if(p==NULL){
        cout << "No se pudo abrir el archivo crearArchivo" << endl;
        //cout<<"En la Linea: "<<__LINE__<<endl;
        exit(1);
    }

    for(int i=0; i<tam; i++){
    objE.Cargar();
    cout<<endl;
    fwrite(&objE, sizeof(Jugador), 1, p);
    }

    fclose(p);
}


  Jugador leerRegistro(int pos)
  {
    Jugador reg;
    reg.setEstado(false);
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return reg;
    fseek(p, sizeof reg * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
  }
  int contarRegistros()
  {
    FILE *p;
    p = fopen(nombre, "rb");
    if (p == NULL)
      return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Jugador);
  }
  bool grabarRegistro(Jugador reg)
  {
    FILE *p;
    p = fopen(nombre, "ab");
    if (p == NULL)
      return false;
    int escribio = fwrite(&reg, sizeof reg, 1, p);
    fclose(p);
    return escribio;
  }
};


#endif // PARCIAL1L_H_INCLUDED
